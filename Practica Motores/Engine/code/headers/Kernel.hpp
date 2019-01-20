#pragma once

#include <set>
#include "Task.hpp"
#include "Timer.hpp"

namespace engine
{
	class Kernel
	{
		private:

			std::multiset<Task * > tasks;

			bool exit;

		public:

			static Kernel & instance()
			{
				static Kernel kernel;
				return kernel;
			}

		private:

			Kernel() = default;

		public:

			void add_task(Task & task)
			{
				tasks.insert(&task);
				task.set_kernel(this);
			}

			void execute()
			{
				exit = false;

				for (auto task : tasks)
				{
					task->initialize();
				}

				float time = 1.f / 60.f;

				while (!exit)
				{
					Timer timer;

					for (auto task : tasks)
					{
						if (exit)
						{
							break;
						}

						task->do_step(time);
					}

					time = timer.elapsed_seconds();
				}

				for (auto task : tasks)
				{
					task->finalize();
				}
			}

			void stop()
			{
				exit = true;
			}
	};
}