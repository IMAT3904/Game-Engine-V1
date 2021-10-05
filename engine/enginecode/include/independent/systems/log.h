/** \file log.h */
#pragma once

#include "systems/system.h"
#include <spdlog/spdlog.h>

/**
\Class Interface class for all system
*/

namespace Engine
{
	class Log : public System
	{
	public:
		virtual void start(SystemSignal init = SystemSignal::None, ...); //!< Start the logger.
		virtual void stop(SystemSignal close = SystemSignal::None, ...); //!< Stop the logger.

		template<class ...Args>
		static void debug(Args&&... args);

		template<class ...Args>
		static void error(Args&&... args);

		template<class ...Args>
		static void info(Args&&... args);

		template<class ...Args>
		static void trace(Args&&... args);

		template<class ...Args>
		static void warn(Args&&... args);
	private:
		static std::shared_ptr<spdlog::logger>s_consoleLogger; //!< Console logger.
	};

	template<class ...Args>
	static void debug(Args&&... args)
	{
		s_consoleLogger->debug(std::forward<Args>(args) ...);
	}

	template<class ...Args>
	static void error(Args&&... args)
	{
		s_consoleLogger->error(std::forward<Args>(args) ...);
	}

	template<class ...Args>
	static void info(Args&&... args)
	{
		s_consoleLogger->info(std::forward<Args>(args) ...);
	}

	template<class ...Args>
	static void trace(Args&&... args)
	{
		s_consoleLogger->trace(std::forward<Args>(args) ...);
	}

	template<class ...Args>
	static void warn(Args&&... args)
	{
		s_consoleLogger->warn(std::forward<Args>(args) ...);
	}
}