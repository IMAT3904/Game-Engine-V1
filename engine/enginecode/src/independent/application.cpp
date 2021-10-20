/** \file application.cpp
*/

#include "engine_pch.h"
#include "core/application.h"

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
		WindowProperties props("Game Engine V1", 1024, 800);

		m_window.reset(Window::create(props));

		m_handler.setOnCloseCallback(std::bind(&Application::onClose, this, std::placeholders::_1));

		m_timer->reset();
	}

	bool Application::onClose(WindowCloseEvent & e)
	{
		e.handle(true);
		m_running = false;
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
		while (m_running)
		{
			timestep = m_timer->getElapsedTime();
			m_timer->reset();
			//Log::trace("FPS {0}", 1.0f / timestep);
			accumTime += timestep;

			if (accumTime > 1.f)
			{
				WindowCloseEvent close;

				auto& callback = m_handler.getOnCloseCallback();
				callback(close);
			}
			// Do frame stuff

		};
	}

}
