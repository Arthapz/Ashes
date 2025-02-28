/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#include "renderer/GlRenderer/Core/GlDebugReportCallback.hpp"

#include "renderer/GlRenderer/Core/GlInstance.hpp"

#include "ashesgl_api.hpp"

namespace ashes::gl
{
	namespace
	{
		static const uint32_t GL_PIXEL_TRANSFER_IS_SYNC_WITH_RENDERING = 0x00020052;
		static const uint32_t GL_USE_OF_DEVICE_LOCAL_MEMORY_FOR_CPU_TRANSFERS = 0x00020071;
		static const uint32_t GL_COPY_BUFFER_FROM_VIDEO_TO_HOST_MEMORY = 0x00020072;
		static const uint32_t GL_SHADER_PROGRAM_IS_RECOMPILED_BASED_ON_GL_STATE = 0x00020092;

		char const * convert( GlDebugSource source )
		{
			switch ( source )
			{
			case GL_DEBUG_SOURCE_API:
				return "OpenGL";
			case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
				return "Window System";
			case GL_DEBUG_SOURCE_SHADER_COMPILER:
				return "Shader compiler";
			case GL_DEBUG_SOURCE_THIRD_PARTY:
				return "Third party";
			case GL_DEBUG_SOURCE_APPLICATION:
				return "Application";
			case GL_DEBUG_SOURCE_OTHER:
				return "Other";
			default:
				return "Unknown";
			}
		}

		char const * convert( GlDebugCategory category )
		{
			switch ( category )
			{
			case GL_DEBUG_CATEGORY_API_ERROR_AMD:
				return "OpenGL";
			case GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD:
				return "Window System";
			case GL_DEBUG_CATEGORY_DEPRECATION_AMD:
				return "Deprecation";
			case GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD:
				return "Undefined Behavior";
			case GL_DEBUG_CATEGORY_PERFORMANCE_AMD:
				return "Performance";
			case GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD:
				return "Shader Compiler";
			case GL_DEBUG_CATEGORY_APPLICATION_AMD:
				return "Application";
			case GL_DEBUG_CATEGORY_OTHER_AMD:
				return "Other";
			default:
				return "Unknown";
			}
		}

		bool isIgnored( uint32_t id )
		{
			static const std::set< uint32_t > ignoredIds
			{
				GL_PIXEL_TRANSFER_IS_SYNC_WITH_RENDERING,
				GL_USE_OF_DEVICE_LOCAL_MEMORY_FOR_CPU_TRANSFERS,
				GL_COPY_BUFFER_FROM_VIDEO_TO_HOST_MEMORY,
				GL_SHADER_PROGRAM_IS_RECOMPILED_BASED_ON_GL_STATE,
			};
			return ignoredIds.end() != ignoredIds.find( id );
		}

		bool isIgnored( GlDebugType type )
		{
			static const std::set< GlDebugType > ignoredTypes
			{
				GL_DEBUG_TYPE_POP_GROUP,
				GL_DEBUG_TYPE_PUSH_GROUP,
				GL_DEBUG_TYPE_MARKER,
			};
			return ignoredTypes.end() != ignoredTypes.find( type );
		}

		bool isIgnored( uint32_t id
			, GlDebugType type )
		{
			return isIgnored( id )
				|| isIgnored( type );
		}
	}

#if VK_EXT_debug_utils

	namespace
	{
		VkDebugUtilsMessageTypeFlagsEXT getTypeFlags( GlDebugType type )
		{
			switch ( type )
			{
			case GL_DEBUG_TYPE_ERROR:
			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
				return VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT;
			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
			case GL_DEBUG_TYPE_PORTABILITY:
				return VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;
			case GL_DEBUG_TYPE_PERFORMANCE:
				return VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
			default:
				return VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT;
			}
		}

		VkDebugUtilsMessageTypeFlagsEXT getTypeFlags( GlDebugCategory type )
		{
			switch ( type )
			{
			case GL_DEBUG_CATEGORY_API_ERROR_AMD:
			case GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD:
			case GL_DEBUG_CATEGORY_APPLICATION_AMD:
			case GL_DEBUG_CATEGORY_OTHER_AMD:
				return VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT;
			case GL_DEBUG_CATEGORY_DEPRECATION_AMD:
			case GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD:
			case GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD:
				return VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;
			case GL_DEBUG_CATEGORY_PERFORMANCE_AMD:
				return VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
			default:
				return VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT;
			}
		}

		VkDebugUtilsMessageSeverityFlagBitsEXT getSeverityFlag( GlDebugSeverity severity )
		{
			switch ( severity )
			{
			case GL_DEBUG_SEVERITY_HIGH:
				return VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
			case GL_DEBUG_SEVERITY_MEDIUM:
				return VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT;
			case GL_DEBUG_SEVERITY_LOW:
				return VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT;
			default:
				return VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT;
			}
		}

		void GLAPIENTRY messengerDebugLog( uint32_t source
			, uint32_t type
			, uint32_t id
			, uint32_t severity
			, int length
			, const char * message
			, DebugUtilsMessengerEXT * userParam )
		{
			if ( !isIgnored( id, GlDebugType( type ) ) )
			{
				userParam->report( GlDebugSource( source )
					, GlDebugType( type )
					, id
					, GlDebugSeverity( severity )
					, length
					, message );

				if ( type == GlDebugType::GL_DEBUG_TYPE_ERROR
					|| type == GlDebugType::GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR )
				{
					logError( message );
				}
			}
		}

		void GLAPIENTRY messengerDebugLogAMD( uint32_t id
			, uint32_t category
			, uint32_t severity
			, int length
			, const char * message
			, DebugUtilsMessengerEXT * userParam )
		{
			if ( !isIgnored( id ) )
			{
				userParam->report( id
					, GlDebugCategory( category )
					, GlDebugSeverity( severity )
					, length
					, message );

				if ( category == GlDebugCategory::GL_DEBUG_CATEGORY_API_ERROR_AMD
					|| category == GlDebugCategory::GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD )
				{
					logError( message );
				}
			}
		}
	}

	DebugUtilsMessengerEXT::DebugUtilsMessengerEXT( VkAllocationCallbacks const * callbacks
		, VkInstance instance
		, VkDebugUtilsMessengerCreateInfoEXT createInfo )
		: m_instance{ instance }
		, m_createInfo{ std::move( createInfo ) }
	{
		auto glinstance = get( m_instance );
		glinstance->registerDebugMessenger( get( this ), PFNGLDEBUGPROC( &messengerDebugLog ), this );
		glinstance->registerDebugMessengerAMD( get( this ), PFNGLDEBUGAMDPROC( &messengerDebugLogAMD ), this );
	}

	DebugUtilsMessengerEXT::~DebugUtilsMessengerEXT()
	{
	}

	void DebugUtilsMessengerEXT::submit( VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity
		, VkDebugUtilsMessageTypeFlagsEXT messageTypes
		, VkDebugUtilsMessengerCallbackDataEXT const & callbackData
		, void * userData )
	{
		m_createInfo.pfnUserCallback( messageSeverity
			, messageTypes
			, &callbackData
			, userData );
	}

	void DebugUtilsMessengerEXT::report( GlDebugSource source
		, GlDebugType type
		, uint32_t id
		, GlDebugSeverity severity
		, int length
		, const char * const message )
	{
		auto layer = convert( source );
		VkDebugUtilsMessengerCallbackDataEXT data
		{
			VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT,
			nullptr,
			0u,
			layer,
			int32_t( id ),
			message,
			0u,
			nullptr,
			0u,
			nullptr,
			0u,
			nullptr,
		};
		m_createInfo.pfnUserCallback( getSeverityFlag( severity )
			, getTypeFlags( type )
			, &data
			, m_createInfo.pUserData );
	}

	void DebugUtilsMessengerEXT::report( uint32_t id
		, GlDebugCategory category
		, GlDebugSeverity severity
		, int length
		, const char * const message )
	{
		auto layer = convert( category );
		VkDebugUtilsMessengerCallbackDataEXT data
		{
			VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT,
			nullptr,
			0u,
			layer,
			int32_t( id ),
			message,
			0u,
			nullptr,
			0u,
			nullptr,
			0u,
			nullptr,
		};
		m_createInfo.pfnUserCallback( getSeverityFlag( severity )
			, getTypeFlags( category )
			, &data
			, m_createInfo.pUserData );
	}

#endif
#if VK_EXT_debug_report

	namespace
	{
		void GLAPIENTRY callbackDebugLog( uint32_t source
			, uint32_t type
			, uint32_t id
			, uint32_t severity
			, int length
			, const char * message
			, VkDebugReportCallbackEXT userParam )
		{
			if ( !isIgnored( id, GlDebugType( type ) ) )
			{
				get( userParam )->report( GlDebugSource( source )
					, GlDebugType( type )
					, id
					, GlDebugSeverity( severity )
					, length
					, message );
			}
		}

		void GLAPIENTRY callbackDebugLogAMD( uint32_t id
			, uint32_t category
			, uint32_t severity
			, int length
			, const char * message
			, VkDebugReportCallbackEXT userParam )
		{
			if ( !isIgnored( id ) )
			{
				get( userParam )->report( id
					, GlDebugCategory( category )
					, GlDebugSeverity( severity )
					, length
					, message );
			}
		}

		VkDebugReportFlagsEXT convert( GlDebugType type )
		{
			switch ( type )
			{
			case GL_DEBUG_TYPE_ERROR:
				return VK_DEBUG_REPORT_ERROR_BIT_EXT;
			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
			case GL_DEBUG_TYPE_PORTABILITY:
				return VK_DEBUG_REPORT_WARNING_BIT_EXT;
			case GL_DEBUG_TYPE_PERFORMANCE:
				return VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;
			default:
				return VK_DEBUG_REPORT_DEBUG_BIT_EXT;
			}
		}

		VkDebugReportFlagsEXT convert( GlDebugSeverity severity )
		{
			switch ( severity )
			{
			case GL_DEBUG_SEVERITY_HIGH:
				return VK_DEBUG_REPORT_ERROR_BIT_EXT;
			case GL_DEBUG_SEVERITY_MEDIUM:
				return VK_DEBUG_REPORT_WARNING_BIT_EXT;
			case GL_DEBUG_SEVERITY_LOW:
				return VK_DEBUG_REPORT_DEBUG_BIT_EXT;
			default:
				return VK_DEBUG_REPORT_INFORMATION_BIT_EXT;
			}
		}
	}

	DebugReportCallbackEXT::DebugReportCallbackEXT( VkAllocationCallbacks const * callbacks
		, VkInstance instance
		, VkDebugReportCallbackCreateInfoEXT createInfo )
		: m_instance{ instance }
		, m_createInfo{ std::move( createInfo ) }
	{
		auto glinstance = get( m_instance );
		glinstance->registerDebugMessageCallback( get( this ), PFNGLDEBUGPROC( &callbackDebugLog ), this );
		glinstance->registerDebugMessageCallbackAMD( get( this ), PFNGLDEBUGAMDPROC( &callbackDebugLogAMD ), this );
	}

	DebugReportCallbackEXT::~DebugReportCallbackEXT()
	{
	}

	void DebugReportCallbackEXT::report( VkDebugReportFlagsEXT flags
		, VkDebugReportObjectTypeEXT objectType
		, uint64_t object
		, size_t location
		, int32_t messageCode
		, const char * pLayerPrefix
		, const char * pMessage )
	{
		m_createInfo.pfnCallback( flags
			, objectType
			, object
			, location
			, messageCode
			, pLayerPrefix
			, pMessage
			, m_createInfo.pUserData );
	}

	void DebugReportCallbackEXT::report( GlDebugSource source
		, GlDebugType type
		, uint32_t id
		, GlDebugSeverity severity
		, int length
		, const char * const message )
	{
		auto layer = convert( source );
		auto flags = convert( type );
		flags |= convert( severity );
		m_createInfo.pfnCallback( flags
			, VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT
			, 0ull
			, 0u
			, int32_t( id )
			, layer
			, message
			, m_createInfo.pUserData );
	}

	void DebugReportCallbackEXT::report( uint32_t id
		, GlDebugCategory category
		, GlDebugSeverity severity
		, int length
		, const char * const message )
	{
		auto layer = convert( category );
		auto flags = convert( severity );
		m_createInfo.pfnCallback( flags
			, VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT
			, 0ull
			, 0u
			, int32_t( id )
			, layer
			, message
			, m_createInfo.pUserData );
	}

#endif
}
