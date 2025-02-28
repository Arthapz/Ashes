set( ASHES_CONFIG_DIR ${CMAKE_CURRENT_BINARY_DIR} )

if ( ANDROID OR CMAKE_COMPILER_IS_GNUCXX )
	set( TARGET_COMPILE_OPTIONS
		-fdiagnostics-color=auto
		-fPIC
	)
elseif ( MSVC )
	set( TARGET_COMPILE_DEFINITIONS
		_CRT_SECURE_NO_WARNINGS
		_SCL_SECURE_NO_WARNINGS
		_ENFORCE_MATCHING_ALLOCATORS=0
	)
	if ( ASHES_ENABLE_ASAN )
		set( TARGET_COMPILE_OPTIONS
			$<$<CONFIG:Debug>:/fsanitize=address>
		)
	endif ()
endif ()

if ( EXISTS ${Ashes_SOURCE_DIR}/external/spirv_cross/spirv_cross.cpp )
	set( ASHES_BUILD_SPIRV_CROSS ON )
	set( ASHES_HAS_SPIRV_CROSS ON )
	set( SPIRV_CROSS_INCLUDE_DIR ${Ashes_SOURCE_DIR}/external )
	set( SPIRV_CROSS_DIR ${SPIRV_CROSS_INCLUDE_DIR}/spirv_cross )
elseif ( VCPKG_TOOLCHAIN )
	set( ASHES_BUILD_SPIRV_CROSS OFF )
	if ( VCPKG_TOOLCHAIN )
		if ( _VCPKG_INSTALLED_DIR )
			set( spirv_cross_core_DIR ${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/spirv_cross_core )
			set( spirv_cross_glsl_DIR ${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/spirv_cross_glsl )
			set( spirv_cross_hlsl_DIR ${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/spirv_cross_hlsl )
			set( spirv_cross_reflect_DIR ${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/spirv_cross_reflect )
			set( spirv_cross_util_DIR ${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/spirv_cross_util )
			set( spirv_cross_cpp_DIR ${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/spirv_cross_cpp )
		elseif ( SPIRV_ROOT_DIR )
			set( spirv_cross_core_DIR ${SPIRV_ROOT_DIR}/share/spirv_cross_core )
			set( spirv_cross_glsl_DIR ${SPIRV_ROOT_DIR}/share/spirv_cross_glsl )
			set( spirv_cross_hlsl_DIR ${SPIRV_ROOT_DIR}/share/spirv_cross_hlsl )
			set( spirv_cross_reflect_DIR ${SPIRV_ROOT_DIR}/share/spirv_cross_reflect )
			set( spirv_cross_util_DIR ${SPIRV_ROOT_DIR}/share/spirv_cross_util )
			set( spirv_cross_cpp_DIR ${SPIRV_ROOT_DIR}/share/spirv_cross_cpp )
		endif ()
		find_package( spirv_cross_core CONFIG REQUIRED )
		find_package( spirv_cross_glsl CONFIG REQUIRED )
		find_package( spirv_cross_hlsl CONFIG REQUIRED )
		find_package( spirv_cross_reflect CONFIG REQUIRED )
		find_package( spirv_cross_util CONFIG REQUIRED )
		find_package( spirv_cross_cpp CONFIG REQUIRED )
		if ( spirv_cross_core_FOUND
			AND spirv_cross_glsl_FOUND
			AND spirv_cross_reflect_FOUND
			AND spirv_cross_util_FOUND
			AND spirv_cross_cpp_FOUND )
			set( spirv-cross_FOUND ON )
		endif ()
	else ()
		find_package( spirv-cross REQUIRED COMPONENTS core cpp glsl hlsl reflect util )
	endif ()
	if ( spirv-cross_FOUND )
		set( ASHES_HAS_SPIRV_CROSS ON )
		set( SPIRV_CROSS_LIBRARIES
			spirv-cross-core
			spirv-cross-cpp
			spirv-cross-glsl
			spirv-cross-reflect
			spirv-cross-util
		)
		set( SPIRV_CROSS_HLSL_LIBRARIES
			spirv-cross-hlsl
		)
	else ()
		set( ASHES_HAS_SPIRV_CROSS OFF )
		message( FATAL_ERROR "Couldn't find spirv-cross" )
	endif ()
endif ()

add_subdirectory( ashes/common )

add_subdirectory( ashes )
set( ENABLED_RENDERERS ${ENABLED_RENDERERS} PARENT_SCOPE )
set( ENABLED_PDBS ${ENABLED_PDBS} PARENT_SCOPE )

add_subdirectory( ashespp )

if ( ASHES_BUILD_TESTS OR ASHES_BUILD_SAMPLES )
	add_subdirectory( util )
endif ()

set( Ashes_BINARY_LIBRARIES ${Ashes_BINARY_LIBRARIES} PARENT_SCOPE )

install(
	TARGETS ashes ashesCommon ashespp
	COMPONENT Ashes
	EXPORT Ashes
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
install(
	FILES ${ENABLED_PDBS}
	DESTINATION bin
	OPTIONAL
)
install( EXPORT Ashes
	COMPONENT Ashes
	FILE AshesConfig.cmake
	NAMESPACE ashes::
	DESTINATION lib/cmake/ashes
)
include(CMakePackageConfigHelpers)
write_basic_package_version_file( AshesConfigVersion.cmake
	VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_BUILD}
	COMPATIBILITY AnyNewerVersion
)
