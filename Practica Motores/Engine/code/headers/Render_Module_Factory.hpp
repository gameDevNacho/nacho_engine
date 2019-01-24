#pragma once
#include "Module_Factory.hpp"
#include "Render_Module.hpp"

namespace engine
{
	class Render_Module_Factory : public Module_Factory
	{
	public:

		Render_Module_Factory()
		{
			Module::register_module("render", this);
		}

		std::shared_ptr<Module> create_module() override
		{
			return std::shared_ptr<Module>(new Render_Module);
		}
	};
}