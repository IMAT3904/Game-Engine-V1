/* \file renderAPI.cpp */

#include "engine_pch.h"

#include "rendering/RenderAPI.h"
#include "rendering/indexBuffer.h"

#include "platform/OpenGL/OpenGLIndexBuffer.h"

#include "systems/log.h"

namespace Engine
{
	RenderAPI::API Engine::RenderAPI::s_API = RenderAPI::API::OpenGL;

	IndexBuffer * IndexBuffer::create(uint32_t * indices, uint32_t count)
	{
		switch (RenderAPI::getAPI())
		{
		case RenderAPI::API::None:
			Log::error("No supported Rendering API");

		case RenderAPI::API::OpenGL:
			return new OpenGLIndexBuffer(indices, count);

		case RenderAPI::API::Direct3D:
			Log::error("Direct3D not currently Supported!");

		case RenderAPI::API::Vulkan:
			Log::error("Vulkan not currently Supported!");


		}
		
	}

}
