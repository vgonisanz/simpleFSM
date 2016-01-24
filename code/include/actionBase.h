#pragma once

#include <memory>
#include <map>

#include "state.h"
#include "JSON.h"

namespace simplefsm
{
		/**
		 * \brief A virtual class to be overrided a in inheritance hierarchy
		 *
		 * \description Base to create your own actions
		 *
		 * \param[in] name
		 * \param[in] description
		 *
		 */
		class ActionBase
		{
		private:
			std::string _name;
			bool _runned;
			bool _runAlways;
			State* _state;
			std::map<std::string, std::string> _properties;

		public:
			ActionBase();
			ActionBase(State* state);
			virtual ~ActionBase() = 0;

			virtual std::string getName();
			virtual std::string getProperty(std::string id);
			virtual State* getState();

			virtual void setName(std::string name);

			virtual void init() = 0;
			virtual void stop() = 0;
			virtual bool run() = 0;
			virtual bool needsToRun();
			virtual ActionBase* createAction(std::string& name) = 0;
			virtual ActionBase* deserialize(JSONObject action, State* state) = 0;

			virtual bool registerAction(std::string& name, ActionBase* (*constructor)() ) = 0;
			virtual bool unRegisterAction(std::string& name) = 0;
		};
}
