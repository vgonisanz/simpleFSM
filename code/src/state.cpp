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
		_eventDescription(std::string("None")),
		_locked(false)
		{
			_fsm = nullptr;
			_actions.clear();
			_transitions.clear();
		}

		State::~State()
		{
			while(!_actions.empty()) delete _actions.back(), _actions.pop_back();
			_actions.clear();

			while(!_transitions.empty()) delete _transitions.back(), _transitions.pop_back();
			_transitions.clear();

			delete _fsm;
		}
		std::string State::getName()
		{
			return _name;
		}
		std::string State::getDescription()
		{
			return _description;
		}
}
