/*
This file belongs to GlRenderer.
See LICENSE file in root folder.
*/
#include "GlEndQueryCommand.hpp"

#include "GlQueryPool.hpp"

namespace gl_renderer
{
	EndQueryCommand::EndQueryCommand( renderer::QueryPool const & pool
		, uint32_t query )
		: m_target{ convert( pool.getType() ) }
	{
	}

	void EndQueryCommand::apply()const
	{
		glEndQuery( m_target );
	}

	CommandPtr EndQueryCommand::clone()const
	{
		return std::make_unique< EndQueryCommand >( *this );
	}
}
