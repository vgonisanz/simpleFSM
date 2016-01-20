#pragma once

#include <string>
#include <vector>

#include "JSON.h"

namespace simplefsm
{
		// Forward declaration
		class ActionBase;
		class Fsm;
		class Transition;
		class Event;
		class Action;

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

			bool setEvent(std::string name, std::string description);
			std::string getEvent(std::string name);
			std::vector<Event> getEvents();
			bool setTransition(std::string event, std::string target);
			std::string getTransition(std::string event);

			void init();
			void stop();
			std::string update();
			std::string propagateEvent(std::string event);
			bool addAction(Action* action, int position);
			std::vector<Action*> getActions();
			State* deserialize(JSON state);
			State* deserialize(JSON state, Fsm* fsm);
		};
}
