/*
  Template class
 */

#include "state.h"

#include "logger.h"
#define LOG_TAG "State"

#include "actionBase.h"
#include "fsm.h"
#include "transition.h"
#include "event.h"

namespace simplefsm
{
		State::State():
		_name(std::string("None")),
		_description(std::string("None")),
		_eventDescription(std::string("None"))
		{
			_fsm = nullptr;
			_actions.clear();
			_transitions.clear();
		}

		State::~State()
		{
			std::vector<ActionBase*>::iterator actionIt = _actions.begin();
			std::vector<Transition*>::iterator transitionIt = _transitions.begin();

			delete _fsm;

			for (actionIt = _actions.begin(); actionIt != _actions.end(); ++actionIt)
			{
				delete *actionIt;
			}
			_actions.clear();

			for (transitionIt = _transitions.begin(); transitionIt != _transitions.end(); ++transitionIt)
			{
				delete *transitionIt;
			}
			_transitions.clear();
		}
}
