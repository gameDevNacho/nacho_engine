#pragma once
#include <string>
#include "Entity.hpp"

namespace engine
{
	class Component
	{
		protected:

			Entity * parent;

		public:

			Component(Entity * parent) : parent(parent) {}

			virtual ~Component() 
			{
				if (parent)
				{
					parent = nullptr;
				}
			}

			virtual bool initialize() = 0;

			virtual bool parse_property(const std::string& name, const std::string & value) = 0;
	};
}