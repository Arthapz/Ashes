/*
This file belongs to RendererLib.
See LICENSE file in root folder.
*/
#include "GlCommandBase.hpp"

namespace gl_renderer
{
	CommandBase::CommandBase( Device const & device )
		: m_device{ device }
	{
	}

	CommandBase::~CommandBase()noexcept
	{
	}
}
