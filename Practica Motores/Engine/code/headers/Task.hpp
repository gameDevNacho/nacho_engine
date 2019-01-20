#pragma once

#include "Kernel.hpp"

namespace engine
{
	class Task
	{
		protected:

			Kernel * kernel;

			int priority;

		public:

			Task(int priority) : priority(priority)
			{
				kernel = nullptr;
			}

			virtual ~Task()
			{
			}

			void set_kernel(Kernel * new_kernel)
			{
				kernel = new_kernel;
			}

		public:

			virtual bool initialize() = 0;
			virtual bool do_step(float time) = 0;
			virtual bool finalize() = 0;

		public:

			bool operator < (const Task & other) const
			{
				return this->priority < other.priority;
			}
	};
}