#pragma once

namespace simplefsm
{
		/**
		 * \brief A event called by a State.
		 * \description This event is called automatically by a State when must be executed
		 * \param[in] value
		 * \return value
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
		};
}
