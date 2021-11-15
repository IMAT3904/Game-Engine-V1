/* \file VertexArray.h */
#pragma once

#include "vertexBuffer.h"
#include "indexBuffer.h"

namespace Engine
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void addVertextBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
		virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

		static VertexArray* create();

		virtual inline uint32_t getRenderID() const = 0;
		virtual inline uint32_t getDrawCount() const = 0;

	private:
		std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffer;
		std::shared_ptr<IndexBuffer> m_indexBuffer;
	};
}