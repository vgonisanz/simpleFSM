#pragma once

#include <string>
#include <vector>

namespace simplefsm
{
		// Forward declaration
		class ActionBase;
		class Fsm;
		class Transition;

		class State
		{
		private:
			std::string _name;
			std::string _description;
			std::string _eventDescription;
			Fsm* _fsm;
			std::vector<ActionBase*> _actions;
			std::vector<Transition*> _transitions;
			// events

		public:
			State();
			~State();
		};
}
