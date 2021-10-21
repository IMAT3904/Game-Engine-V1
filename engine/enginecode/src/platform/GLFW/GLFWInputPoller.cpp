#include "engine_pch.h"
#include "platform/GLFW/GLFWInputPoller.h"
#include "platform/GLFW/GLFWCodes.h"


	GLFWwindow* Engine::GLFWInputPoller::s_window = nullptr;

	bool Engine::GLFWInputPoller::isKeyPressed(int32_t keyCode)
	{
		return glfwGetKey(s_window, keyCode);
		/*if (s_window)
		{
			auto state = glfwGetKey(s_window, keyCode);
			return state == NG_KEY_PRESS || state == NG_KEY_REPEAT;
		}
		return false;*/
	}

	bool Engine::GLFWInputPoller::isMouseButtonPressed(int32_t mouseButton)
	{
		if (s_window)
		{
			auto state = glfwGetKey(s_window, mouseButton);
			return state == NG_BUTTON_PRESS || state == NG_BUTTON_REPEAT;
		}
		return false;
	}

	glm::vec2 Engine::GLFWInputPoller::getMousePosition()
	{
		double x, y;
		if (s_window)
		{
			glfwGetCursorPos(s_window, &x, &y);
			return glm::vec2(x, y);
		} else return glm::vec2(-1, -1);
	}
