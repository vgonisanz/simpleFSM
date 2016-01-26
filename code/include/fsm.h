#pragma once

#include <string>
#include <vector>

#include "JSON.h"

namespace simplefsm
{
		// Forward declaration
		class State;

		/**
		 * \brief A finite-state machine (FSM) is a mathematical model of computation used to design both computer programs
		 *
		 * It is conceived as an abstract machine that can be in one of a finite number of states.
		 * The machine is in only one state at a time.
		 * The state it is in at any given time is called the current state.
		 * It can change from one state to another when initiated by a triggering event or condition;
		 * this is called a transition.
		 * A particular FSM is defined by a list of its states, and the triggering condition for each transition.
		 *
		 * TODO image
		 *
		 * \param[in] value
		 * \return value
		 */
		class Fsm
		{
		private:
			std::string _name;				///< Name of the FSM
			std::vector<State*> _states;	///< Vector with all state in FSM
			State* _initialState;			///< The first state set before call startFSM
			State* _activeState;			///< Current state
			State* _transitionState;		///< Is the next state to propage when update is called

		public:
			Fsm();
			~Fsm();

			/**
			 * \brief Add a existing state to FSM
			 *
			 * Add if exist anyway. Set as initial if is the first one.
			 *
			 */
			State* addState(State* state);
			/**
			 * \brief Create a new state to FSM or return existing one
			 *
			 *
			 */
			State* createState(const std::string& name);
			/**
			 * \brief Create a state from FSM in string format
			 *
			 * Use function TODO
			 */
			State* deserialize(const std::string& fsmString);	// Use buffer?
			/**
			 * \brief Create a state from a file
			 *
			 * This function is called automatically if use FSM deserialize
			 */
			State* deserializeFile(const std::string& filePath);
			/**
			 * \brief Create a FSM from a JSON object
			 */
			Fsm* deserializeFsm(const JSON& fsmString);
			/**
			 * \brief Change initial state of FSM
			 */
			void setInitialState(State* state);
			/**
			 * \brief Get initial state of FSM
			 */
			State* getInitialState();
			/**
			 * \brief Get active state of FSM
			 */
			State* getActiveState();
			/**
			 * \brief Get the state target of other state
			 */
			State* getTransitionToState();
			/**
			 * \brief Get all states in FSM
			 */
			std::vector<State*> getStates();
			/**
			 * \brief Get a state in FSM
			 *
			 * Return NULL if no exist
			 */
			State* getState(const std::string& name);
			/**
			 * \brief Remove a state and its transitions from FSM providing the name
			 *
			 * \return false if no exist, true if success
			 */
			bool removeState(const std::string& name);
			/**
			 * \brief Look for the current state what state is the target
			 *
			 * \param[in] Name of event target
			 */
			State* propagateEvent(const std::string& name);
			/**
			 * \brief Start the FSM
			 */
			State* startFsm();
			/**
			 * \brief Update the FSM, propagate actions
			 */
			void update();
		};
}
