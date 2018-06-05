/*
This file belongs to RendererLib.
See LICENSE file in root folder.
*/
#pragma once

#include <RendererPrerequisites.hpp>

namespace gl_renderer
{
	enum GlInternal
		: GLenum
	{
		/**
		*\~english
		*name
		*	Colour formats.
		*\~french
		*name
		*	Formats de couleur.
		*/
		/**@{*/
		GL_INTERNAL_R4G4B4A4_UNORM_PACK16 = 0x8056,
		GL_INTERNAL_R5G6B5_UNORM_PACK16 = 0x8D62,
		GL_INTERNAL_R5G5B5A1_UNORM_PACK16 = 0x8057,
		GL_INTERNAL_R8_UNORM = 0x8229,
		GL_INTERNAL_R8_SNORM = 0x8F94,
		GL_INTERNAL_R8_UINT = 0x8232,
		GL_INTERNAL_R8_SINT = 0x8231,
		GL_INTERNAL_R8_SRGB = 0x8FBD,
		GL_INTERNAL_R8G8_UNORM = 0x822B,
		GL_INTERNAL_R8G8_SNORM = 0x8F95,
		GL_INTERNAL_R8G8_UINT = 0x8238,
		GL_INTERNAL_R8G8_SINT = 0x8237,
		GL_INTERNAL_R8G8_SRGB = 0x8FBE,
		GL_INTERNAL_R8G8B8_UNORM = 0x8051,
		GL_INTERNAL_R8G8B8_SNORM = 0x8F96,
		GL_INTERNAL_R8G8B8_UINT = 0x8D7D,
		GL_INTERNAL_R8G8B8_SINT = 0x8D8F,
		GL_INTERNAL_R8G8B8_SRGB = 0x8C41,
		GL_INTERNAL_R8G8B8A8_UNORM = 0x8058,
		GL_INTERNAL_R8G8B8A8_SNORM = 0x8F97,
		GL_INTERNAL_R8G8B8A8_UINT = 0x8D7C,
		GL_INTERNAL_R8G8B8A8_SINT = 0x8D8E,
		GL_INTERNAL_R8G8B8A8_SRGB = 0x8C43,
		GL_INTERNAL_B8G8R8A8_UNORM = 0x93A1,
		GL_INTERNAL_A2R10G10B10_UNORM_PACK32 = 0x8059,
		GL_INTERNAL_A2R10G10B10_UINT_PACK32 = 0x906F,
		GL_INTERNAL_R16_UNORM = 0x822A,
		GL_INTERNAL_R16_SNORM = 0x8F98,
		GL_INTERNAL_R16_UINT = 0x8234,
		GL_INTERNAL_R16_SINT = 0x8233,
		GL_INTERNAL_R16_SFLOAT = 0x822D,
		GL_INTERNAL_R16G16_UNORM = 0x822C,
		GL_INTERNAL_R16G16_SNORM = 0x8F99,
		GL_INTERNAL_R16G16_UINT = 0x823A,
		GL_INTERNAL_R16G16_SINT = 0x8239,
		GL_INTERNAL_R16G16_SFLOAT = 0x822F,
		GL_INTERNAL_R16G16B16_UNORM = 0x8054,
		GL_INTERNAL_R16G16B16_SNORM = 0x8F9A,
		GL_INTERNAL_R16G16B16_UINT = 0x8D77,
		GL_INTERNAL_R16G16B16_SINT = 0x8D89,
		GL_INTERNAL_R16G16B16_SFLOAT = 0x881B,
		GL_INTERNAL_R16G16B16A16_UNORM = 0x805B,
		GL_INTERNAL_R16G16B16A16_SNORM = 0x8F9B,
		GL_INTERNAL_R16G16B16A16_UINT = 0x8D76,
		GL_INTERNAL_R16G16B16A16_SINT = 0x8D88,
		GL_INTERNAL_R16G16B16A16_SFLOAT = 0x881A,
		GL_INTERNAL_R32_UINT = 0x8236,
		GL_INTERNAL_R32_SINT = 0x8235,
		GL_INTERNAL_R32_SFLOAT = 0x822E,
		GL_INTERNAL_R32G32_UINT = 0x823C,
		GL_INTERNAL_R32G32_SINT = 0x823B,
		GL_INTERNAL_R32G32_SFLOAT = 0x8230,
		GL_INTERNAL_R32G32B32_UINT = 0x8D71,
		GL_INTERNAL_R32G32B32_SINT = 0x8D83,
		GL_INTERNAL_R32G32B32_SFLOAT = 0x8815,
		GL_INTERNAL_R32G32B32A32_UINT = 0x8D70,
		GL_INTERNAL_R32G32B32A32_SINT = 0x8D82,
		GL_INTERNAL_R32G32B32A32_SFLOAT = 0x8814,
		GL_INTERNAL_B10G11R11_UFLOAT_PACK32 = 0x8C3A,
		GL_INTERNAL_E5B9G9R9_UFLOAT_PACK32 = 0x8C3D,
		/**@}*/
		/**
		*\~english
		*name
		*	Depth / stencil formats.
		*\~french
		*name
		*	Formats de profondeur / stencil.
		*/
		/**@{*/
		GL_INTERNAL_D16_UNORM = 0x81A5,
		GL_INTERNAL_D24_UNORM = 0x81A6,
		GL_INTERNAL_D32_SFLOAT = 0x8CAC,
		GL_INTERNAL_S8_UINT = 0x8D48,
		GL_INTERNAL_D24_UNORM_S8_UINT = 0x88F0,
		GL_INTERNAL_D32_SFLOAT_S8_UINT = 0x8CAD,
		/**@}*/
		/**
		*\~english
		*name
		*	BC compressed formats.
		*\~french
		*name
		*	Formats de compression BC.
		*/
		/**@{*/
		GL_INTERNAL_BC1_RGB_UNORM_BLOCK = 0x83F0,
		GL_INTERNAL_BC1_RGB_SRGB_BLOCK = 0x8C4C,
		GL_INTERNAL_BC1_RGBA_UNORM_BLOCK = 0x83F1,
		GL_INTERNAL_BC1_RGBA_SRGB_BLOCK = 0x8C4D,
		GL_INTERNAL_BC2_UNORM_BLOCK = 0x83F2,
		GL_INTERNAL_BC2_SRGB_BLOCK = 0x8C4E,
		GL_INTERNAL_BC3_UNORM_BLOCK = 0x83F3,
		GL_INTERNAL_BC3_SRGB_BLOCK = 0x8C4F,
		GL_INTERNAL_BC4_UNORM_BLOCK = 0x8DBB,
		GL_INTERNAL_BC4_SNORM_BLOCK = 0x8DBC,
		GL_INTERNAL_BC5_UNORM_BLOCK = 0x8DBD,
		GL_INTERNAL_BC5_SNORM_BLOCK = 0x8DBE,
		GL_INTERNAL_BC6H_UFLOAT_BLOCK = 0x8E8F,
		GL_INTERNAL_BC6H_SFLOAT_BLOCK = 0x8E8E,
		GL_INTERNAL_BC7_UNORM_BLOCK = 0x8E8C,
		GL_INTERNAL_BC7_SRGB_BLOCK = 0x8E8D,
		/**@}*/
		/**
		*\~english
		*name
		*	ETC compressed formats.
		*\~french
		*name
		*	Formats de compression ETC.
		*/
		/**@{*/
		GL_INTERNAL_ETC2_R8G8B8_UNORM_BLOCK = 0x9274,
		GL_INTERNAL_ETC2_R8G8B8_SRGB_BLOCK = 0x9275,
		GL_INTERNAL_ETC2_R8G8B8A1_UNORM_BLOCK = 0x9276,
		GL_INTERNAL_ETC2_R8G8B8A1_SRGB_BLOCK = 0x9277,
		GL_INTERNAL_ETC2_R8G8B8A8_UNORM_BLOCK = 0x9278,
		GL_INTERNAL_ETC2_R8G8B8A8_SRGB_BLOCK = 0x9279,
		/**@}*/
		/**
		*\~english
		*name
		*	ETC compressed formats.
		*\~french
		*name
		*	Formats de compression ETC.
		*/
		/**@{*/
		GL_INTERNAL_EAC_R11_UNORM_BLOCK = 0x9270,
		GL_INTERNAL_EAC_R11_SNORM_BLOCK = 0x9271,
		GL_INTERNAL_EAC_R11G11_UNORM_BLOCK = 0x9272,
		GL_INTERNAL_EAC_R11G11_SNORM_BLOCK = 0x9273,
		/**@}*/
		/**
		*\~english
		*name
		*	ASTC compressed formats.
		*\~french
		*name
		*	Formats de compression ASTC.
		*/
		/**@{*/
		GL_INTERNAL_ASTC_4x4_UNORM_BLOCK = 0x93B0,
		GL_INTERNAL_ASTC_4x4_SRGB_BLOCK = 0x93D0,
		GL_INTERNAL_ASTC_5x4_UNORM_BLOCK = 0x93B1,
		GL_INTERNAL_ASTC_5x4_SRGB_BLOCK = 0x93D1,
		GL_INTERNAL_ASTC_5x5_UNORM_BLOCK = 0x93B2,
		GL_INTERNAL_ASTC_5x5_SRGB_BLOCK = 0x93D2,
		GL_INTERNAL_ASTC_6x5_UNORM_BLOCK = 0x93B3,
		GL_INTERNAL_ASTC_6x5_SRGB_BLOCK = 0x93D3,
		GL_INTERNAL_ASTC_6x6_UNORM_BLOCK = 0x93B4,
		GL_INTERNAL_ASTC_6x6_SRGB_BLOCK = 0x93D4,
		GL_INTERNAL_ASTC_8x5_UNORM_BLOCK = 0x93B5,
		GL_INTERNAL_ASTC_8x5_SRGB_BLOCK = 0x93D5,
		GL_INTERNAL_ASTC_8x6_UNORM_BLOCK = 0x93B6,
		GL_INTERNAL_ASTC_8x6_SRGB_BLOCK = 0x93D6,
		GL_INTERNAL_ASTC_8x8_UNORM_BLOCK = 0x93B7,
		GL_INTERNAL_ASTC_8x8_SRGB_BLOCK = 0x93D7,
		GL_INTERNAL_ASTC_10x5_UNORM_BLOCK = 0x93B8,
		GL_INTERNAL_ASTC_10x5_SRGB_BLOCK = 0x93D8,
		GL_INTERNAL_ASTC_10x6_UNORM_BLOCK = 0x93B9,
		GL_INTERNAL_ASTC_10x6_SRGB_BLOCK = 0x93D9,
		GL_INTERNAL_ASTC_10x8_UNORM_BLOCK = 0x93BA,
		GL_INTERNAL_ASTC_10x8_SRGB_BLOCK = 0x93DA,
		GL_INTERNAL_ASTC_10x10_UNORM_BLOCK = 0x93BB,
		GL_INTERNAL_ASTC_10x10_SRGB_BLOCK = 0x93DB,
		GL_INTERNAL_ASTC_12x10_UNORM_BLOCK = 0x93BC,
		GL_INTERNAL_ASTC_12x10_SRGB_BLOCK = 0x93DC,
		GL_INTERNAL_ASTC_12x12_UNORM_BLOCK = 0x93BD,
		GL_INTERNAL_ASTC_12x12_SRGB_BLOCK = 0x93DD,
		/**@{*/
	};
	enum GlFormat
		: GLenum
	{
		GL_FORMAT_S = 0x1901,
		GL_FORMAT_D = 0x1902,
		GL_FORMAT_R = 0x1903,
		GL_FORMAT_RGB = 0x1907,
		GL_FORMAT_RGBA = 0x1908,
		GL_FORMAT_ABGR = 0x8000,
		GL_FORMAT_BGR = 0x80E0,
		GL_FORMAT_BGRA = 0x80E1,
		GL_FORMAT_RG = 0x8227,
		GL_FORMAT_DS = 0x84F9,
	};
	enum GlType
		: GLenum
	{
		GL_TYPE_I8 = 0x1400,
		GL_TYPE_UI8 = 0x1401,
		GL_TYPE_I16 = 0x1402,
		GL_TYPE_UI16 = 0x1403,
		GL_TYPE_I32 = 0x1404,
		GL_TYPE_UI32 = 0x1405,
		GL_TYPE_F32 = 0x1406,
		GL_TYPE_F16 = 0x140B,
		GL_TYPE_US4444 = 0x8033,
		GL_TYPE_US5551 = 0x8034,
		GL_TYPE_UI8888 = 0x8035,
		GL_TYPE_UI_10_10_10_2 = 0x8036,
		GL_TYPE_UI_2_10_10_10 = 0x8368,
		GL_TYPE_UI565 = 0x8363,
		GL_TYPE_UI24_8 = 0x84FA,
		GL_TYPE_32F_UI24_8 = 0x8DAD,
		GL_UI_5_9_9_9 = 0x8C3E,
		GL_UI_10F_11F_11F = 0x8C3B,
	};
	std::string getName( GlInternal value );
	std::string getName( GlFormat value );
	std::string getName( GlType value );
	/**
	*\~french
	*\brief
	*	Dit si le renderer::Format donné est un format utilisable pour les tampons de profondeur et stencil.
	*\param[in] format
	*	Le renderer::Format à tester.
	*\return
	*	\p true s'il l'est...
	*\~english
	*\brief
	*	Tells if the given renderer::Format is usable in depth and stencil buffers.
	*\param[in] format
	*	The renderer::Format.
	*\return
	*	\p true if it is usable in depth and stencil buffers.
	*/
	bool isDepthStencilFormat( GlInternal format )noexcept;
	/**
	*\~french
	*\brief
	*	Dit si le renderer::Format donné est un format utilisable pour les tampons de stencil.
	*\param[in] format
	*	Le renderer::Format à tester.
	*\return
	*	\p true s'il l'est...
	*\~english
	*\brief
	*	Tells if the given renderer::Format is usable in stencil buffers.
	*\param[in] format
	*	The renderer::Format.
	*\return
	*	\p true if it is usable in stencil buffers.
	*/
	bool isStencilFormat( GlInternal format )noexcept;
	/**
	*\~french
	*\brief
	*	Dit si le renderer::Format donné est un format utilisable pour les tampons de profondeur.
	*\param[in] format
	*	Le renderer::Format à tester.
	*\return
	*	\p true s'il l'est...
	*\~english
	*\brief
	*	Tells if the given renderer::Format is usable in depth buffers.
	*\param[in] format
	*	The renderer::Format.
	*\return
	*	\p true if it is usable in depth buffers.
	*/
	bool isDepthFormat( GlInternal format )noexcept;
	/**
	*\brief
	*	Convertit un renderer::Format en GlInternal.
	*\param[in] format
	*	Le renderer::Format.
	*\return
	*	Le GlInternal.
	*/
	GlInternal getInternal( renderer::Format const & format )noexcept;
	/**
	*\brief
	*	Convertit un renderer::Format en GlFormat.
	*\param[in] format
	*	Le renderer::Format.
	*\return
	*	Le GlFormat.
	*/
	GlFormat getFormat( GlInternal format )noexcept;
	/**
	*\brief
	*	Convertit un renderer::Format en GlType.
	*\param[in] format
	*	Le renderer::Format.
	*\return
	*	Le GlType.
	*/
	GlType getType( GlInternal format )noexcept;
	/**
	*\brief
	*	Convertit un GlInternal en renderer::Format.
	*\param[in] format
	*	Le GlInternal.
	*\return
	*	Le renderer::Format.
	*/
	renderer::Format convert( GlInternal format )noexcept;
	/**
	*\return
	*	le nombre de composantes du format donné.
	*\param[in] format
	*	Le renderer::Format.
	*/
	uint32_t getCount( renderer::Format format )noexcept;
}
