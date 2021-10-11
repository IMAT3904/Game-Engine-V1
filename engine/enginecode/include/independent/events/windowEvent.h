/* \file windowsEvents.h */
#pragma once

#include "event.h"

#include <glm/glm.hpp>

namespace Engine
{
	class WindowCloseEvent : public Event
	{
	public:
		static EventType getStaticType() { return EventType::WindowClose; } //!< Return static type
		virtual inline EventType getEventType() const override { return EventType::WindowClose; };
		virtual int32_t getCategoryFlags() const override { return EventCategoryWindow; } //!< Get the event type category type
		
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int32_t width, int32_t height) : m_width(width), m_height(height) {}
		static EventType getStaticType() { return EventType::WindowResize; } //!< Return static type
		virtual inline EventType getEventType() const override { return EventType::WindowResize; };
		virtual int32_t getCategoryFlags() const override { return EventCategoryWindow; } //!< Get the event category type
	private:
		int32_t m_width;
		int32_t m_height;
	};
}