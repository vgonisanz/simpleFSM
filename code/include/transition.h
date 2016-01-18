#pragma once

namespace simplefsm
{
		struct Transition
		{
		public:
			std::string event;
			std::string target;

			Transition():
			event(std::string("None")),
			target(std::string("None"))
			{
			}
		};
}
