#pragma once

namespace simplefsm
{
		/**
		 * \brief A event called by a State.
		 *
		 * \description This event is called automatically by a State when must be executed
		 *
		 * \param[in] name
		 * \param[in] description
		 *
		 */
		struct Event
		{
		public:
			std::string name;
			std::string description;

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
