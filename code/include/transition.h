#pragma once

namespace simplefsm
{
		struct Transition
		{
		public:
			std::string event;		///< Event that trigger the transition
			std::string target;		///< State at end

			Transition():
			event(std::string("None")),
			target(std::string("None"))
			{
			}
		};
}
