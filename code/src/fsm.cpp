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
#include "transition.h"

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
			// Null?
			if(state == nullptr)
			{
				LOGE("State is null, cannot add");
				return nullptr;
			}
			const std::string name = state->getName();
			LOGD("Adding state: %s", name.c_str());

			// Exist?
			for (std::vector<State*>::iterator it = _states.begin();
								it != _states.end();
								it++)
			{
				if((*it)->getName() == name)
				{
					LOGW("Found existing state: %s, adding anyway", name.c_str());
				}
			}
			// Add state
			_states.push_back(state);

			// First is initial by default
			if(_states.size() == 1)
			{
				setInitialState(state);
			}
			return nullptr;
		}
		State* Fsm::createState(const std::string& name)
		{
			LOGD("Creating state with name: %s", name.c_str());

			// Exist?
			for (std::vector<State*>::iterator it = _states.begin();
								it != _states.end();
								it++)
			{
				if((*it)->getName() == name)
				{
					// No need to create, already exist
					LOGD("createState already exist: %s", name.c_str());
					return (*it);
				}
			}
			// No exist, creating...
			State* newState = new State(name, this);
			_states.push_back(newState);
			return newState;
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
			// Delete state if exist
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
			// Report behavior
			if(!found)
			{
				LOGD("State %s no exist, cannot remove", name.c_str());
				return false;
			}
			else
			{
				// Delete transitions from rest states
				for (std::vector<State*>::iterator it = _states.begin();
									it != _states.end();
									it++)
				{
					// Check all transitions
					std::vector<Transition*> transitions = (*it)->getTransitions();
					for (int i = 0; i < transitions.size(); i++)
					{
						// Delete transition to erased target state
						if(transitions.at(i)->target == name)
						{
							(*it)->removeTransition(transitions.at(i)->event);
						}
					}
				}
			}
			return found;
		}
		State* Fsm::propagateEvent(const std::string& name)
		{
			LOGD("Propagating event %s", name.c_str());
			if(_activeState == nullptr)
			{
				LOGE("Current state is null, cannot propagate");
				return nullptr;
			}
			else
			{
				std::string targetName = _activeState->propagateEvent(name);
				State* targetState = getState(targetName);
				if(targetState == nullptr)
				{
					return nullptr;
				}
				else
				{
					_transitionState = targetState;
					return targetState;
				}
			}
		}
		State* Fsm::startFsm()
		{
			LOGD("Starting FSM...");
			if(_initialState == nullptr)
			{
				LOGE("Initial state is empty");
				return nullptr;
			}
			else
			{
				_transitionState = _initialState;
				return _initialState;
			}
		}
		void Fsm::update()
		{
			LOGD("Updating FSM...");
			if(_transitionState != nullptr)
			{
				// Stop current state if exist
				if(_activeState != nullptr)
				{
					_activeState->stop();
				}
				// Update active state and null transition
				_activeState = _transitionState;
				_activeState->init();
				_transitionState = nullptr;
			}

			if(_activeState != nullptr)
			{
				// Update transition state
				std::string stateName = _activeState->update();
				State* targetState = getState(stateName);
				if(targetState != nullptr)
				{
					_transitionState = targetState;
				}
			}
		}
}
