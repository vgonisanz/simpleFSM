/*
  FSM class
 */

#include <algorithm>
#include <vector>
#include <iterator>

#include "fsm.h"

// Includes
#include "logger.h"
#define LOG_TAG "Fsm"

#include "state.h"

namespace simplefsm
{
		Fsm::Fsm():
		_name(std::string("None"))
		{
			_states.clear();
			_initialState = nullptr;
			_activeState = nullptr;
			_transitionState = nullptr;
		}
		Fsm::~Fsm()
		{
			_states.clear();
			if(_initialState)
			{
				delete _initialState;
			}
			if(_activeState)
			{
				delete _activeState;
			}
			if(_transitionState)
			{
				delete _transitionState;
			}
		}
		State* Fsm::addState(State* state)
		{
			if(state == nullptr)
			{
				LOGE("State is null, cannot add");
				return nullptr;
			}
			const std::string name = state->getName();
			LOGD("Adding state: %s", name.c_str());
			// TODO
			return nullptr;
		}
		State* Fsm::createState(const std::string& name)
		{
			LOGD("Creating state with name: %s", name.c_str());
			return nullptr;
		}
		State* Fsm::deserialize(const std::string& fsmString)
		{
			LOGD("Deserializing FSM from string...");
			// TODO
			LOGD("Done!");
			return nullptr;
		}
		State* Fsm::deserializeFile(const std::string& filePath)
		{
			LOGD("Deserializing FSM from file: %s", filePath.c_str());
			// TODO
			LOGD("Done!");
			return nullptr;
		}
		Fsm* Fsm::deserializeFsm(const JSON& fsmString)
		{
			LOGD("Deserializing FSM from JSON object");
			// TODO
			LOGD("Done!");
			return nullptr;
		}
		void Fsm::setInitialState(State* state)
		{
			if(state == nullptr)
			{
				LOGE("State is null, cannot set initial");
				return;
			}
			const std::string name = state->getName();
			LOGD("Setting initial state: %s", name.c_str());
			// TODO
		}
		State* Fsm::getInitialState()
		{
			return _initialState;
		}
		State* Fsm::getActiveState()
		{
			return _activeState;
		}
		State* Fsm::getTransitionToState()
		{
			return _transitionState;
		}
		std::vector<State*> Fsm::getStates()
		{
			return _states;
		}
		State* Fsm::getState(const std::string& name)
		{
			// TODO TEST
			/*
			auto it = find_if(_states.begin(), _states.end(),
					[&name](const State* obj) { return (obj->getName()) == name;} );

			if (it != _states.end())
			{
			  return it; // found element.
			}
			*/
			// Alternative
			for (std::vector<State*>::iterator it = _states.begin();
					it != _states.end();
					it++)
			{
				if((*it)->getName() == name)
				{
					LOGD("Found state: %s", name.c_str());
					return *it;
				}
			}
			LOGD("State: %s no exist", name.c_str());
			return nullptr;
		}
		bool Fsm::removeState(const std::string& name)
		{
			/*
			State* state = getState(name);
			if(state == nullptr)
			{
				return false;
			}
			else
			{
				return true;
			}*/
			bool found = false;
			for (std::vector<State*>::iterator it = _states.begin();
					it != _states.end();
					/*it++*/) // Manually advance
			{
				if((*it)->getName() == name)
				{
					found = true;
					it = _states.erase(it);
					LOGD("State: %s removed from FSM", name.c_str());
				}
				else
				{
					++it;
				}
			}
			if(!found)
			{
				LOGD("State %s no exist, cannot remove", name.c_str());
			}
			return found;
		}
		State* Fsm::propagateEvent(const std::string& name)
		{
			LOGD("Propagating event %s", name.c_str());
			return nullptr;
		}
		State* Fsm::startFsm()
		{
			LOGD("Starting FSM...");
			return nullptr;
		}
		void Fsm::update()
		{
			LOGD("Updating FSM...");
		}
}
