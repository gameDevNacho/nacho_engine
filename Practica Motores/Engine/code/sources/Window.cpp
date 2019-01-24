#pragma once
#include "Window.hpp"
#include <SDL.h>
#include <OpenGL.hpp>
#include <cassert>

namespace engine
{
	Window::Window(const std::string & title, int width, int height, bool fullscreen)
	{
		window = nullptr;
		gl_context = nullptr;

		if (SDL_Init(SDL_INIT_VIDEO))
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

			#ifdef __APPLE__
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG, GL_TRUE); //Fix compilation on OS X
			#endif

			window = SDL_CreateWindow
			(
				title.c_str(),
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width,
				height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
			);

			assert(window != nullptr);

			if (window)
			{
				gl_context = SDL_GL_CreateContext(window);

				assert(gl_context != nullptr);

				if (gl_context && glt::initialize_opengl_extensions())
				{
					if (fullscreen)
					{
						SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					}
				}
			}
			
		}
	}

	Window::~Window()
	{
		if (gl_context)
		{
			SDL_GL_DeleteContext(gl_context);
		}

		if (window)
		{
			SDL_DestroyWindow(window);
		}
	}

	void Window::enable_vsync()
	{
		if (gl_context)
		{
			SDL_GL_SetSwapInterval(1);
		}
	}

	void Window::disable_vsync()
	{
		if (gl_context)
		{
			SDL_GL_SetSwapInterval(0);
		}
	}

	unsigned Window::get_width() const
	{
		int width = 0, height;

		if (window)
		{
			SDL_GetWindowSize(window, &width, &height);
		}

		return unsigned(width);
	}

	unsigned Window::get_height() const
	{
		int width, height = 0;

		if (window)
		{
			SDL_GetWindowSize(window, &width, &height);
		}

		return unsigned(height);
	}

	void Window::clear() const
	{
		if (gl_context)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}

	void Window::swap_buffers() const
	{
		if (gl_context)
		{
			SDL_GL_SwapWindow(window);
		}
	}
}
