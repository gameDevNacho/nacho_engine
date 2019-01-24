#pragma once
#include <list>
#include "Module.hpp"

namespace engine
{
	class Render_Module : public Module
	{
	private:

			/*static Render_Module_Factory factory
			list< Render_Component > render_components
			get_task() override
			create_component() override*/

		public:

			Task * get_task() override
			{
				//TODO
				return nullptr;
			}

		protected:

			std::shared_ptr<Component> create_component()
			{
				return nullptr;
			}
		
	};
}