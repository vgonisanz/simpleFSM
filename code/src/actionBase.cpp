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
	/*ActionBase::~ActionBase()
	{

	}*/
/*
	bool ActionBase::foo(int fooInt)
	{
		return true;
	}*/
}
