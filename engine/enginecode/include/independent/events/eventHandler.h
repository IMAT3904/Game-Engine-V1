/** \file eventHandler.h*/
#pragma once

#include "events.h"

#include <functional>

namespace Engine
{
	class EventHandler
	{
	public:
		void setOnCloseCallback(const std::function<bool(WindowCloseEvent&)>& fn) { m_onCloseCallback = fn; }
		void setOnResizeCallback(const std::function<bool(WindowResizeEvent&)>& fn) { m_onResizeCallback = fn; }
		void setOnFocusCallback(const std::function<bool(e_WindowFocus&)>& fn) { m_onFocusCallback = fn; }
		void setOnLostFocusCallback(const std::function<bool(e_WindowLostFocus&)>& fn) {m_onLostFocusCallback = fn; }
		void setOnWindowMovedCallback(const std::function<bool(e_WindowMoved&)>& fn) { m_onWindowMovedCallback = fn; }
		void setOnKeyPressedCallback(const std::function<bool(e_KeyPressed&)>& fn) { m_onKeyDownCallback = fn; }
		void setOnKeyReleasedCallback(const std::function<bool(e_KeyReleased&)>& fn) {m_onKeyUpCallback = fn; }
		void setOnKeyTypedCallback(const std::function<bool(e_KeyTyped&)>& fn) {m_onKeyTypedCallback = fn; }
		void setOnButtonPressedCallback(const std::function<bool(e_MouseButtonPressed&)>& fn) {m_onMouseDownCallback = fn; }
		void setOnButtonReleasedCallback(const std::function<bool(e_MouseButtonReleased&)>& fn) {m_onMouseUpCallback = fn; }
		void setOnMouseMovedCallback(const std::function<bool(e_MouseMoved&)>& fn) {m_onMouseMovedCallback = fn; }
		void setOnMouseWheelCallback(const std::function<bool(e_MouseScrolled&)>& fn) {m_onMouseWheelCallback = fn; }


		std::function<bool(WindowCloseEvent&)>& getOnCloseCallback() { return m_onCloseCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnResizeCallback() { return m_onCloseCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnFocusCallback() { return m_onCloseCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnLostFocusCallback() { return m_onCloseCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnWindowMovedCallback() { return m_onCloseCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnKeyDownCallback() { return m_onCloseCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnKeyUpCallback() { return m_onCloseCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnKeyTypedCallback() { return m_onCloseCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnMouseDownCallback() { return m_onCloseCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnMouseUpCallback() { return m_onCloseCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnMouseMovedCallback() { return m_onCloseCallback; }
		std::function<bool(WindowCloseEvent&)>& getOnMouseWheelCallback() { return m_onCloseCallback; }

	private:
		std::function<bool(WindowCloseEvent&)> m_onCloseCallback = std::bind(&EventHandler::defaultOnClose, this, std::placeholders::_1);
		std::function<bool(WindowResizeEvent&)> m_onResizeCallback;
		std::function<bool(e_WindowFocus&)> m_onFocusCallback;
		std::function<bool(e_WindowLostFocus&)> m_onLostFocusCallback;
		std::function<bool(e_WindowMoved&)> m_onWindowMovedCallback;
		std::function<bool(e_KeyPressed&)> m_onKeyDownCallback;
		std::function<bool(e_KeyReleased&)> m_onKeyUpCallback;
		std::function<bool(e_KeyTyped&)> m_onKeyTypedCallback;
		std::function<bool(e_MouseButtonPressed&)> m_onMouseDownCallback;
		std::function<bool(e_MouseButtonReleased&)> m_onMouseUpCallback;
		std::function<bool(e_MouseMoved&)> m_onMouseMovedCallback;
		std::function<bool(e_MouseScrolled&)> m_onMouseWheelCallback;
		
		bool defaultOnClose(WindowCloseEvent& e) { return false; }
		bool defaultOnResize(WindowResizeEvent& e) { return false; }
		bool defaultOnResize(e_WindowFocus& e) { return false; }
		bool defaultOnResize(e_WindowLostFocus& e) { return false; }
		bool defaultOnResize(e_WindowMoved& e) { return false; }
		bool defaultOnResize(e_KeyPressed& e) { return false; }
		bool defaultOnResize(e_KeyReleased& e) { return false; }
		bool defaultOnResize(e_KeyTyped& e) { return false; }
		bool defaultOnResize(e_MouseButtonPressed& e) { return false; }
		bool defaultOnResize(e_MouseButtonReleased& e) { return false; }
		bool defaultOnResize(e_MouseMoved& e) { return false; }
		bool defaultOnResize(e_MouseScrolled& e) { return false; }
	};
}