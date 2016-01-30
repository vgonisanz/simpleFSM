#pragma once

#include <string>
#include <vector>

#include "JSON.h"

namespace simplefsm
{
		// Forward declaration
		class State;

		/**
		 * \brief A finite-state machine (FSM) is a mathematical model of computation used to design computer programs based on states and transitions.
		 *
		 * The FSM is an abstract machine with a finite number of states and transitions between states.
		 * The machine is always at one state, called the current state.
		 * If an event triggers a transition, the FSM will change the state.
		 * A particular FSM is defined by a list of its states, a list of transitions for each state, and the events that trigger the transitions.
		 * In adition, this FSM performs actions in every update.
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
			std::vector<State*> _states;	///< Vector with all the states in FSM
			State* _initialState;			///< The first state when starting FSM
			State* _activeState;			///< Current state
			State* _transitionState;		///< The target state after the next update.

		public:
			Fsm();
			~Fsm();

			/**
			 * \brief Adds a existing state to FSM
			 *
			 * Adds if exist anyway. Set as initial if is the first one.
			 *
			 */
			State* addState(State* state);
			/**
			 * \brief Creates a new state to FSM or return existing one
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
			 * \brief Changes initial state of FSM
			 */
			void setInitialState(State* state);
			/**
			 * \brief Get initial state of FSM
			 */
			State* getInitialState();
			/**
			 * \brief Gets the current state of the FSM
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
			 * \brief Propagates the event throught the state. If a transition is triggered the transitionState is uodated.
			 *
			 * \param[in] Name of event target
			 */
			State* propagateEvent(const std::string& name);
			/**
			 * \brief Starts the FSM
			 */
			State* startFsm();
			/**
			 * \brief Updates the FSM, propagates actions
			 */
			void update();
		};
}
