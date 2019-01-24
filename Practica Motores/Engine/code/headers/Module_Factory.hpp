#pragma once
#include <memory>
#include "Module.hpp"

namespace engine
{
	class Module_Factory
	{
		public:

			virtual std::shared_ptr<Module> create_module() = 0;
	};
}