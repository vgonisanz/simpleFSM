#pragma once

#include <string>
#include <vector>

#include "JSON.h"

namespace simplefsm
{
		// Forward declaration
		class State;

		/**
		 * \brief Description
		 * \description long description
		 * \param[in] value
		 * \return value
		 */
		class Fsm
		{
		private:
			std::string _name;
			std::vector<State*> _states;
			State* _initialState;
			State* _activeState;
			State* _transitionState;

		public:
			Fsm();
			~Fsm();
			State* addState(State& state);
			State* createState(const std::string& name);
			State* deserialize(const std::string& fsmString);	// Use buffer?
			State* deserializeFile(const std::string& filePath);
			Fsm* deserializeFsm(const JSON& fsmString);

			void setInitialState(State& state);

			State* getInitialState();
			State* getActiveState();
			State* getTransitionToState();
			std::vector<State*> getStates();
			State* getState(const std::string& name);

			bool removeState(const std::string& name);

			State* propagueEvent(const std::string& name);
			State* startFsm();
			void update();
		};
}
