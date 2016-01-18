/*
  Template class
 */

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
		State* Fsm::addState(State& state)
		{
			return nullptr;
		}
		State* Fsm::createState(const std::string& name)
		{
			return nullptr;
		}
		State* Fsm::deserialize(const std::string& fsmString)
		{
			return nullptr;
		}
		State* Fsm::deserializeFile(const std::string& filePath)
		{
			return nullptr;
		}
		Fsm* Fsm::deserializeFsm(const JSON& fsmString)
		{
			return nullptr;
		}
		void Fsm::setInitialState(State& state)
		{

		}
		State* Fsm::getInitialState()
		{
			return nullptr;
		}
		State* Fsm::getActiveState()
		{
			return nullptr;
		}
		State* Fsm::getTransitionToState()
		{
			return nullptr;
		}
		std::vector<State*> Fsm::getStates()
		{
			return _states;
		}
		State* Fsm::getState(const std::string& name)
		{
			return nullptr;
		}
		bool Fsm::removeState(const std::string& name)
		{
			return false;
		}
		State* Fsm::propagueEvent(const std::string& name)
		{
			return nullptr;
		}
		State* Fsm::startFsm()
		{
			return nullptr;
		}
		void Fsm::update()
		{

		}
}
