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
		State::State(std::string name, Fsm* fsm):
		_name(std::string("None")),
		_description(std::string("None")),
		_eventDescription(std::string("None")),
		_locked(false)
		{
			_fsm = fsm;
			_actions.clear();
			_transitions.clear();
		}

		State::~State()
		{
			while(!_actions.empty()) delete _actions.back(), _actions.pop_back();
			_actions.clear();

			while(!_transitions.empty()) delete _transitions.back(), _transitions.pop_back();
			_transitions.clear();

			while(!_events.empty()) delete _events.back(), _events.pop_back();
			_events.clear();

			//delete _fsm; // fsm will free itself, no delete!
		}
		bool State::setEvent(std::string name, std::string description)
		{
			// Check transition is valid
			if(!name.compare(""))
			{
				LOGE("name is invalid in setTransition");
				return false;
			}
			if(!description.compare(""))
			{
				LOGE("description is invalid in setTransition");
				return false;
			}
			// Check transitions
			for (std::vector<Event*>::iterator it = _events.begin();
								it != _events.end();
								it++)
			{
				// Update target
				if((*it)->name.compare(name) == 0)
				{
					(*it)->name = name;
					return true;
				}
			}
			// No exist transition, create new one
			Event* event = new Event();
			event->name = name;
			event->description = description;
			_events.push_back(event);
			return true;
		}
		bool State::setTransition(std::string event, std::string target)
		{
			// Check transition is valid
			if(!event.compare(""))
			{
				LOGE("event is invalid in setTransition");
				return false;
			}
			if(!target.compare(""))
			{
				LOGE("target is invalid in setTransition");
				return false;
			}
			// Check transitions
			for (std::vector<Transition*>::iterator it = _transitions.begin();
								it != _transitions.end();
								it++)
			{
				// Update target
				if((*it)->event.compare(event) == 0)
				{
					(*it)->target = target;
					return true;
				}
			}
			// No exist transition, create new one
			Transition* transition = new Transition();
			transition->event = event;
			transition->target = target;
			_transitions.push_back(transition);
			return true;
		}
		void State::setName(std::string name)
		{
			_name = name;
		}
		std::string State::getName()
		{
			return _name;
		}
		std::string State::getDescription()
		{
			return _description;
		}
		std::string State::getEvent(std::string name)
		{
			for (std::vector<Event*>::iterator it = _events.begin();
											it != _events.end();
											it++)
			{
				// Update target
				if((*it)->name.compare(name) == 0)
				{
					return (*it)->description;
				}
			}
			return "";
		}
		std::string State::getTransition(std::string event)
		{
			for (std::vector<Transition*>::iterator it = _transitions.begin();
											it != _transitions.end();
											it++)
			{
				// Update target
				if((*it)->event.compare(event) == 0)
				{
					return (*it)->target;
				}
			}
			return "";
		}
		std::vector<Transition*> State::getTransitions()
		{
			return _transitions;
		}
		bool State::removeTransition(Event* event)
		{
			bool found = false;
			for (std::vector<Transition*>::iterator it = _transitions.begin();
					it != _transitions.end();
					/*it++*/) // Manually advance
			{
				if((*it)->event == event->name)
				{
					found = true;
					it = _transitions.erase(it);
					LOGD("Removing transition: %s", event->name.c_str());
				}
				else
				{
					++it;
				}
			}
			// Report behavior
			if(!found)
			{
				LOGD("State %s no exist, cannot remove", event->name.c_str());
			}
			return found;
		}
		void State::init()
		{
			// Initialize all actions
			for (std::vector<ActionBase*>::iterator it = _actions.begin();
								it != _actions.end();
								it++)
			{
				(*it)->init();
			}
		}
		void State::stop()
		{
			// Stop all actions
			for (std::vector<ActionBase*>::iterator it = _actions.begin();
								it != _actions.end();
								it++)
			{
				(*it)->stop();
			}
		}
		std::string State::update()
		{
			bool actionFinished = true;
			// Run all actions
			for (std::vector<ActionBase*>::iterator it = _actions.begin();
											it != _actions.end();
											it++)
			{
				if((*it)->needsToRun())
				{
					actionFinished = false;
					// Run it if needed
					if((*it)->run())
					{
						if(_fsm->getTransitionToState() != nullptr)
						{
							// No transition, no run
							return "";
						}
					}
					else
					{
						// No runned, no propagate
						return "";
					}
				}
			}
			if(actionFinished)
			{
				return _fsm->getTransitionToState()->getName();
			}
			// No propagate
			return "";
		}
		std::string State::propagateEvent(std::string event)
		{

		}
		bool State::addAction(ActionBase* action, int position)
		{

		}
		ActionBase* State::getAction(int position)
		{
			if(!_actions.empty() || position < 0)
			{
				return nullptr;
			}
			if(position <= _actions.size())
			{
				return _actions.at(position);
			}
			else
			{
				return nullptr;
			}
		}
		std::vector<ActionBase*> State::getActions()
		{
			return _actions;
		}
}
