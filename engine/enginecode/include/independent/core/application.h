/** \file application.h
*/
#pragma once

#include "systems/log.h"
#include "core/timer.h"
#include "events/events.h"
#include "events/eventHandler.h"
#include "core/window.h"

namespace Engine {

	/**
	\class Application
	Fundemental class of the engine. A singleton which runs the game loop infinitely.
	Provides ...
	*/

	class Application
	{
	protected:
		Application(); //!< Constructor
#		
		std::shared_ptr<Log> m_logSystem; //!< Log System
		std::shared_ptr<Timer> m_timer; //!< Timer
		std::shared_ptr<System> m_windowSystem; //!< Windows System

		std::shared_ptr<Window> m_window; //!< Window
		EventHandler m_handler;

		bool onClose(WindowCloseEvent& e);
	private:
		static Application* s_instance; //!< Singleton instance of the application
		bool m_running = true; //!< Is the application running?
		
	public:
		virtual ~Application(); //!< Deconstructor
		inline static Application& getInstance() { return *s_instance; } //!< Instance getter from singleton pattern
		void run(); //!< Main loop
		
	};

	// To be defined in users code
	Application* startApplication(); //!< Function definition which provides an entry hook
}