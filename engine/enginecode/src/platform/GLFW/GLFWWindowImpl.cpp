/* \file GLFWWindowImpl.cpp */

#include "engine_pch.h"
#include "platform/GLFW/GLFWWindowImpl.h"
#include "systems/log.h"

namespace Engine
{

#ifdef NG_PLATFORM_WINDOWS
	Window* Window::create(const WindowProperties& properties)
	{
		return new GLFWWindowImpl(properties);
	}
#endif

	GLFWWindowImpl::GLFWWindowImpl(const WindowProperties & properties)
	{
		init(properties);
	}

	void GLFWWindowImpl::init(const WindowProperties & properties)
	{
		m_props = properties;

		m_aspectRation = static_cast<float> (m_props.width) / static_cast<float>(m_props.height);

		if (m_props.isFullScreen)
		{
			Log::error("Fullscreen not yet implemented.");
		}
		else
		{
			m_native = glfwCreateWindow(m_props.width, m_props.height, m_props.title, nullptr, nullptr);
		}

		glfwSetWindowUserPointer(m_native, static_cast<void*>(&m_handler));

		glfwSetWindowCloseCallback(m_native,
			[](GLFWwindow* window) 
			{
				WindowCloseEvent e;
				EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));
				auto& callback = handler->getOnCloseCallback();
				callback(e);
			}
		);

		glfwSetWindowSizeCallback(m_native,
			[](GLFWwindow* window, int w, int h)

		{
			WindowResizeEvent e(w, h);
			EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));
			auto& callback = handler->getOnResizeCallback();
			callback(e);
		}
		);

		glfwSetWindowPosCallback(m_native,
			[](GLFWwindow* window, int x, int y)

		{
			e_WindowMoved e(x, y);
			EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));
			auto& callback = handler->getOnWindowMovedCallback();
			callback(e);
		}
		);

		/*glfwSetWindowFocusCallback(
			[](GLFWwindow* window)
		{
			e_WindowFocus e();
			EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));
			auto& callback = handler->getOnFocusCallback();
			callback(e);

		}
		);*/
	}

	void GLFWWindowImpl::close()
	{
		glfwDestroyWindow(m_native);
	}

	void GLFWWindowImpl::onUpdate(float timestep)
	{
		glfwPollEvents();
		
	}

	void GLFWWindowImpl::setVSync(bool VSync)
	{
		m_props.isVSync = VSync;

		if (VSync) { glfwSwapInterval(1); }
		else { glfwSwapInterval(0); }
	}

}