#pragma once

#include <SDL.h>
#include <cstdint>

namespace engine
{
	class Timer
	{
		private:

			uint32_t start_ticks;

		public:

			Timer()
			{
				start();
			}

			void start()
			{
				start_ticks = SDL_GetTicks();
			}

			float elapsed_seconds() const
			{
				return float(elapsed_milliseconds()) / 1000.f;
			}

			uint32_t elapsed_milliseconds() const
			{
				return SDL_GetTicks() - start_ticks;
			}

	};
}
