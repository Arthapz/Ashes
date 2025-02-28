/*
This file belongs to Ashes.
See LICENSE file in root folder.
*/
#ifndef ___AshesPP_AttributeFormat_HPP___
#define ___AshesPP_AttributeFormat_HPP___
#pragma once

#include <cassert>
#include <cstdint>
#include <stdexcept>
#include <string>

namespace ashes
{
	/**
	*\brief
	*	The suppported attribute formats list.
	*/
	enum class ConstantFormat
	{
		eFloat,
		eVec2f,
		eVec3f,
		eVec4f,
		eMat2f,
		eMat3x2f,
		eMat4x2f,
		eMat2x3f,
		eMat3f,
		eMat4x3f,
		eMat2x4f,
		eMat3x4f,
		eMat4f,
		eInt,
		eVec2i,
		eVec3i,
		eVec4i,
		eUInt,
		eVec2ui,
		eVec3ui,
		eVec4ui,
		eColour,
	};
	/**
	*\brief
	*	Gets the size of the given element type.
	*\param[in] value
	*	The element type.
	*\return
	*	The size.
	*/
	inline uint32_t getSize( ConstantFormat value )
	{
		switch ( value )
		{
		case ConstantFormat::eFloat:
			return uint32_t( 1u * sizeof( float ) );
		case ConstantFormat::eVec2f:
			return uint32_t( 2u * sizeof( float ) );
		case ConstantFormat::eVec3f:
			return uint32_t( 3u * sizeof( float ) );
		case ConstantFormat::eVec4f:
			return uint32_t( 4u * sizeof( float ) );
		case ConstantFormat::eMat2f:
			return uint32_t( 2u * 2u * sizeof( float ) );
		case ConstantFormat::eMat3f:
			return uint32_t( 3u * 3u * sizeof( float ) );
		case ConstantFormat::eMat4f:
			return uint32_t( 4u * 4u * sizeof( float ) );
		case ConstantFormat::eColour:
			return uint32_t( 4 * sizeof( uint8_t ) );
		case ConstantFormat::eInt:
			return uint32_t( 1u * sizeof( int32_t ) );
		case ConstantFormat::eVec2i:
			return uint32_t( 2u * sizeof( int32_t ) );
		case ConstantFormat::eVec3i:
			return uint32_t( 3u * sizeof( int32_t ) );
		case ConstantFormat::eVec4i:
			return uint32_t( 4u * sizeof( int32_t ) );
		case ConstantFormat::eUInt:
			return uint32_t( 1u * sizeof( uint32_t ) );
		case ConstantFormat::eVec2ui:
			return uint32_t( 2u * sizeof( uint32_t ) );
		case ConstantFormat::eVec3ui:
			return uint32_t( 3u * sizeof( uint32_t ) );
		case ConstantFormat::eVec4ui:
			return uint32_t( 4u * sizeof( uint32_t ) );
		default:
			assert( false && "Unsupported vertex buffer attribute type." );
			throw std::runtime_error{ "Unsupported vertex buffer attribute type" };
		}
	}
	/**
	*\brief
	*	Gets the name of the given element type.
	*\param[in] value
	*	The element type.
	*\return
	*	The name.
	*/
	inline std::string getName( ConstantFormat value )
	{
		switch ( value )
		{
		case ConstantFormat::eFloat:
			return "float";
		case ConstantFormat::eVec2f:
			return "vec2f";
		case ConstantFormat::eVec3f:
			return "vec3f";
		case ConstantFormat::eVec4f:
			return "vec4f";
		case ConstantFormat::eMat2f:
			return "mat2f";
		case ConstantFormat::eMat3f:
			return "mat3f";
		case ConstantFormat::eMat4f:
			return "mat4f";
		case ConstantFormat::eInt:
			return "int";
		case ConstantFormat::eVec2i:
			return "vec2i";
		case ConstantFormat::eVec3i:
			return "vec3i";
		case ConstantFormat::eVec4i:
			return "vec4i";
		case ConstantFormat::eUInt:
			return "uint";
		case ConstantFormat::eVec2ui:
			return "vec2ui";
		case ConstantFormat::eVec3ui:
			return "vec3ui";
		case ConstantFormat::eVec4ui:
			return "vec4ui";
		case ConstantFormat::eColour:
			return "colour";
		default:
			assert( false && "Unsupported ConstantFormat." );
			throw std::runtime_error{ "Unsupported ConstantFormat" };
		}

		return "unknown";
	}
}

#endif
