#pragma once

#include "event.h"

namespace simplefsm
{
		/**
		 * \brief A transition is the condition to go from an state to another
		 *
		 *
		 * \param[in] Event that trigger the transition
		 * \param[in] The target state
		 */
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
