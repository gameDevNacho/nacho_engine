#pragma once

#include <string>
#include "internal/declarations.hpp"

namespace engine
{
	class Window
	{
		private:

			SDL_Window * window;
			SDL_GLContext gl_context;

		public:

			Window(const std::string & title, int width, int height, bool fullscreen = false);
			~Window();

		public:

			//Returns the width of the window.
			unsigned get_width() const;

			//Returns the height of the window.
			unsigned get_height() const;

			void enable_vsync();

			void disable_vsync();

			//Clears the window buffer using OpenGL.
			void clear() const;

			//Swaps between the front buffer and the back buffer.
			void swap_buffers() const;
	};
}