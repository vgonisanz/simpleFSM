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

		class State
		{
		private:
			std::string _name;					///< Name of the state
			std::string _description;			///< Small description of the state
			std::string _eventDescription;		///< Small description of the event
			bool _locked;						///< If true this state cannot be used
			Fsm* _fsm;							///< All states are associated to a FSM
			std::vector<ActionBase*> _actions;
			std::vector<Transition*> _transitions;
			// events

		public:
			State(std::string name, Fsm* fsm);
			~State();

			/**
			 * \brief Create a event to move to another state
			 */
			bool setEvent(std::string name, std::string description);
			/**
			 * \brief Create a transition to another state
			 */
			bool setTransition(std::string event, std::string target);
			/**
			 * \brief If true parameter is provided, set the state locked only if is not, and viceversa
			 */
			bool setLocked(bool lock);
			/**
			 * \brief Allow to change name to a state
			 */
			void setName(std::string name);

			/**
			 * \brief Get name
			 */
			std::string getName();
			/**
			 * \brief Get description
			 */
			std::string getDescription();
			/**
			 * \brief Get the event to change state by name
			 */
			std::string getEvent(std::string name);
			/**
			 * \brief Get a vector with all events
			 */
			std::vector<Event> getEvents();
			/**
			 * \brief Get the transition to a event
			 */
			std::string getTransition(std::string event);
			/**
			 * \brief Get all transitions
			 */
			std::vector<Transition*> getTransitions();

			/**
			 * \brief Remove a transition from the state
			 */
			bool removeTransition(std::string event);

			/**
			 * \brief When FSM go to a state, this function is called automatically.
			 */
			void init();
			/**
			 * \brief When FSM is going to change to another state, this function is called automatically.
			 */
			void stop();
			/**
			 * \brief Update the state TODO
			 */
			std::string update();
			/**
			 * \brief Propagate the event TODO
			 */
			std::string propagateEvent(std::string event);
			/**
			 * \brief Add action in a position TODO
			 */
			bool addAction(ActionBase* action, int position);
			/**
			 * \brief Return vector with all actions TODO
			 */
			std::vector<ActionBase*> getActions();
			/**
			 * \brief Create a state from a JSON object
			 *
			 * This function is called automatically if use FSM deserialize
			 */
			State* deserialize(JSON state);
			/**
			 * \brief Create a state from a JSON object, providing a FSM to TODO
			 */
			State* deserialize(JSON state, Fsm* fsm);
		};
}
