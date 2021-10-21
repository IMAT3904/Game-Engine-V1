#include "engine_pch.h"
#include "independent/core/inputPoller.h"
#include "platform/GLFW/GLFWInputPoller.h"

bool Engine::InputPoller::isKeyPressed(int32_t keyCode)
{
	return GLFWInputPoller::isKeyPressed(keyCode);
}

bool Engine::InputPoller::isMouseButtonPressed(int32_t mouseButton)
{
	return GLFWInputPoller::isMouseButtonPressed(mouseButton);
}

glm::vec2 Engine::InputPoller::getMousePos()
{
	return GLFWInputPoller::getMousePosition();
}

void Engine::InputPoller::setNative(void * window)
{
	GLFWInputPoller::setCurrentWindow(reinterpret_cast<GLFWwindow*>(window));
}
