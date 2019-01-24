#pragma once
#include <map>
#include <string>
#include "Module.hpp"
#include "Kernel.hpp"
#include "Entity.hpp"

namespace engine
{
	class Scene
	{
		private:

			typedef std::map<std::string, std::shared_ptr<Module>> Module_Map;
			typedef std::map<std::string, std::shared_ptr<Entity>> Entity_Map;

			Module_Map modules;
			static Kernel& kernel; // Is this correct?
			Entity root;

		public:

			Scene(const std::string & scene_description_file_path)
			{
				kernel = Kernel::instance();
			}

	private:

		void load(const std::string & scene_description_file_path)
		{
			const Module::Module_Map & factories = Module::get_module_map();

			// ...
			// Parseando identidades

			std::shared_ptr<Entity> entity(new Entity);

			// ...
			// Parseando componentes de entidades

			// TODO
		}

		void init_kernel()
		{
			for (Module_Map::iterator i = modules.begin(); i != modules.end(); ++i)
			{
				Task * task = i->second->get_task();

				if (task)
				{
					kernel.add_task(*task);
				}
			}
		}
	};
}
