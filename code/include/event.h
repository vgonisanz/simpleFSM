#pragma once

namespace simplefsm
{
		/**
		 * \brief A event is a condition or trigger that change the state to another one.
		 *
		 * This event will move to another state the FSM when is trigged
		 *
		 * \param[in] Name of the event
		 * \param[in] Description when and how the event happen
		 *
		 */
		struct Event
		{
		public:
			std::string name;			///< Name of the event
			std::string description;	///< Description of the event

			Event():
			name(std::string("None")),
			description(std::string("None"))
			{
			}

			Event(std::string gname, std::string gdescription = ""):
			name(gname),
			description(gdescription)
			{
			}
		};
}
