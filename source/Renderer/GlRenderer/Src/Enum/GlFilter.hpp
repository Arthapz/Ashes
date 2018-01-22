/*
This file belongs to Renderer.
See LICENSE file in root folder.
*/
#pragma once

#include <Enum/Filter.hpp>

namespace gl_renderer
{
	enum GLFilter
		: GLenum
	{
		GL_FILTER_NEAREST = 0x2600,
		GL_FILTER_LINEAR = 0x2601,
		GL_FILTER_NEAREST_MIPMAP_NEAREST = 0x2700,
		GL_FILTER_LINEAR_MIPMAP_NEAREST = 0x2701,
		GL_FILTER_NEAREST_MIPMAP_LINEAR = 0x2702,
		GL_FILTER_LINEAR_MIPMAP_LINEAR = 0x2703,
	};
	/**
	*\brief
	*	Convertit un renderer::Filter en GLFilter.
	*\param[in] filter
	*	Le renderer::Filter.
	*\return
	*	Le GLFilter.
	*/
	GLFilter convert( renderer::Filter const & filter );
	/**
	*\brief
	*	Convertit un renderer::Filter en GLFilter, en tenant compte d'un mode de mipmapping.
	*\param[in] filter
	*	Le renderer::Filter.
	*\param[in] mode
	*	Le mode de mipmapping.
	*\return
	*	Le GLFilter.
	*/
	GLFilter convert( renderer::Filter const & filter, renderer::MipmapMode mode );
}
