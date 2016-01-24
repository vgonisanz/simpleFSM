/*
  Template class
 */

#include "actionBase.h"

// Includes
#include "logger.h"
#define LOG_TAG "ActionBase"

namespace simplefsm
{
	ActionBase::ActionBase():
	_name(std::string("None")),
	_runned(false),
	_runAlways(false),
	_state(nullptr)
	{
	}

	ActionBase::ActionBase(State* state):
	_name(std::string("None")),
	_runned(false),
	_runAlways(false),
	_state(state)
	{

	}

	std::string ActionBase::getName()
	{
		return _name;
	}

	std::string ActionBase::getProperty(std::string id)
	{
		auto it = _properties.find(id);
		if ( it == _properties.end() )
		{
			LOGD("Property %s no exist!", id.c_str());
			return "Not found";
		}
		else
		{
			return (*it).second;
		}
	}

	State* ActionBase::getState()
	{
		return _state;
	}

	void ActionBase::setName(std::string name)
	{
		_name = name;
	}

	bool ActionBase::needsToRun()
	{
		return _runned;
	}
	/*ActionBase::~ActionBase()
	{

	}*/
/*
	bool ActionBase::foo(int fooInt)
	{
		return true;
	}*/
}
