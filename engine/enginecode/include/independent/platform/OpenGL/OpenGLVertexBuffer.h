/* \OpenGLVertexBuffer.h */
#pragma once

#include "rendering/bufferLayout.h"

namespace Engine 
{
	class OpenGLVertexBuffer
	{
	public:
		OpenGLVertexBuffer(void* vertices, uint32_t size, BufferLayout layout);
		~OpenGLVertexBuffer();
		void edit(void* vertices, uint32_t size, uint32_t offset);
		inline uint32_t getRenderID() { return m_OpenGL_ID; }
		inline const BufferLayout& getLayout() const { return m_layout; }

	private:
		uint32_t m_OpenGL_ID; //!< OpenGL ID
		BufferLayout m_layout;
	};
}