/** \file application.cpp
*/

#include "engine_pch.h"

// Temp
#include <glad/glad.h>

#include "core/application.h"
#include "platform/GLFW/GLFWCodes.h"
#include <GLFW/glfw3.h>

#ifdef NG_PLATFORM_WINDOWS
#include "platform/GLFW/GLFWSystem.h"
#endif

namespace Engine {
	// Set static vars
	Application* Application::s_instance = nullptr;

	Application::Application()
	{
		if (s_instance == nullptr)
		{
			s_instance = this;
		}

		//Start systems

		//Start log
		m_logSystem.reset(new Log);
		m_logSystem->start();

		// Start the windows System
#ifdef NG_PLATFORM_WINDOWS
		m_windowSystem.reset(new GLFWSystem);
#endif
		m_windowSystem->start();

		// Start Timer
		m_timer.reset(new ChronoTimer);
		m_timer->start();
		WindowProperties props("Game Engine V1", 820, 420);
		m_window.reset(Window::create(props));
		InputPoller::setNative(m_window->getNativeWindow());
		//m_window->getEventHandler;

		m_window->getEventHandler().setOnCloseCallback(std::bind(&Application::onClose, this, std::placeholders::_1));
		m_window->getEventHandler().setOnResizeCallback(std::bind(&Application::onResize, this, std::placeholders::_1));
		m_window->getEventHandler().setOnFocusCallback(std::bind(&Application::onFocus, this, std::placeholders::_1));
		m_window->getEventHandler().setOnLostFocusCallback(std::bind(&Application::onLostFocus, this, std::placeholders::_1));
		m_window->getEventHandler().setOnWindowMovedCallback(std::bind(&Application::onMoved, this, std::placeholders::_1));

		m_window->getEventHandler().setOnKeyPressedCallback(std::bind(&Application::onKeyPressed, this, std::placeholders::_1));
		m_window->getEventHandler().setOnKeyReleasedCallback(std::bind(&Application::onKeyReleased, this, std::placeholders::_1));

		m_window->getEventHandler().setOnButtonPressedCallback(std::bind(&Application::onButtonPressed, this, std::placeholders::_1));
		m_window->getEventHandler().setOnButtonReleasedCallback(std::bind(&Application::onButtonReleased, this, std::placeholders::_1));
		m_window->getEventHandler().setOnMouseMovedCallback(std::bind(&Application::onMouseMoved, this, std::placeholders::_1));
		m_window->getEventHandler().setOnMouseWheelCallback(std::bind(&Application::onMouseWheel, this, std::placeholders::_1));
		
		m_timer->reset();
	}

	bool Application::onClose(WindowCloseEvent & e)
	{
		e.handle(true);
		Log::info("Window Close Works!!");
		m_running = false;
		return e.handled();
	}

	bool Application::onResize(WindowResizeEvent &e)
	{
		e.handle(true);
		Log::info("Resize Works!! {0} {1}", e.getWidth(), e.getHeight());
		return e.handled();
	}

	bool Application::onFocus(e_WindowFocus & e)
	{
		e.handle(true);
		Log::info("GAME RESUMED!");
		return e.handled();
	}

	bool Application::onLostFocus(e_WindowLostFocus & e)
	{
		e.handle(true);
		Log::info("GAME PAUSED!");
		return e.handled();
	}

	bool Application::onMoved(e_WindowMoved & e)
	{
		e.handle(true);
		Log::info("Window Moved! - {0} - {1}", e.getXPos(), e.getYPos());
		return e.handled();
	}

	bool Application::onKeyPressed(e_KeyPressed & e)
	{
		e.handle(true);
		return e.handled();
	}

	bool Application::onKeyReleased(e_KeyReleased & e)
	{
		e.handle(true);
		return e.handled();
	}

	bool Application::onButtonPressed(e_MouseButtonPressed & e)
	{
		e.handle(true);
		return e.handled();
	}

	bool Application::onButtonReleased(e_MouseButtonReleased & e)
	{
		e.handle(true);
		return e.handled();
	}

	bool Application::onMouseMoved(e_MouseMoved & e)
	{
		e.handle(true);
		return e.handled();
	}

	bool Application::onMouseWheel(e_MouseScrolled & e)
	{
		e.handle(true);
		return e.handled();
	}

	Application::~Application()
	{
		//Stop systems.

		//Stop log
		m_logSystem->stop();

		m_windowSystem->stop();
	}


	void Application::run()
	{
		float timestep = 0.0f;
		float accumTime = 0.f;

		glClearColor(1.0f, 0.f, 1.f, 0.f);
		while (m_running)
		{
			glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
			m_window->onUpdate(timestep);
			//Log::debug(InputPoller::isKeyPressed(NG_KEY_W));
			if (InputPoller::isKeyPressed(NG_KEY_W))
			{
				Log::debug("W Pressed");
			}
			else if (InputPoller::isMouseButtonPressed(NG_MOUSE_BUTTON_1))
			{
				Log::debug("Mouse 1 Pressed");
			}
			timestep = m_timer->getElapsedTime();
			m_timer->reset();
			//Log::trace("FPS {0}", 1.0f / timestep);
			accumTime += timestep;

			//Log::debug("Mouse X: {0} - Y: {1}", InputPoller::getMX(), InputPoller::getMY());
			//Log::debug(InputPoller::isMouseButtonPressed(NG_MOUSE_BUTTON_1));

			if (accumTime > 1.f)
			{
				/*WindowCloseEvent close;
				WindowResizeEvent r(820, 940);
				auto& callback1 = m_window->getEventHandler().getOnResizeCallback();
				auto& callback = m_window->getEventHandler().getOnCloseCallback();
				callback1(r);
				callback(close);*/
			}
			// Do frame stuff

		};
	}

}
