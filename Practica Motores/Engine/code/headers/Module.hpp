#pragma once
#include <map>
#include <string>
#include "Module_Factory.hpp"
#include "Task.hpp"
#include "Scene.hpp"
#include "Component.hpp"

namespace engine
{
	class Module
	{
		private:

			static std::map<std::string, std::shared_ptr<Module_Factory>> module_factories;

			Scene * owner;

		public:

			virtual Task * get_task() = 0;

			static void register_module(const std::string & id, Module_Factory * factory)
			{
				module_factories[id] = std::make_shared<Module_Factory>(factory);
			}

		protected:

			Module() = default;

			Module(Scene * owner) : owner(owner) {}

			virtual ~Module() 
			{
				if (owner)
				{
					owner = nullptr;
				}
			}

			static std::map<std::string, std::shared_ptr<Module_Factory>> & get_module_map()
			{
				return module_factories;
			}

			virtual std::shared_ptr<Component> create_component() = 0;
	};
}