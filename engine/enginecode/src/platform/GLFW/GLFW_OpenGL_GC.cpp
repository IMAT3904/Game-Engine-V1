#include "engine_pch.h"

#include <glad/glad.h>
#include "platform\GLFW\GLFW_OpenGL_GC.h"


//#include <GLFW/glfw3.h>
#include "systems/log.h"
namespace Engine 
{
	void GLFW_OpenGL_GC::init()
	{
		glfwMakeContextCurrent(m_window);
		auto result = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
		if (!result) Log::error("Could not create OpenGL conntext for current GLFW Window: {0}", result);
	}

	void GLFW_OpenGL_GC::swapBuffers()
	{
		glfwSwapBuffers(m_window);
	}

}
