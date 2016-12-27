#pragma once
#ifndef INTERSIM_STATE_H
#define INTERSIM_STATE_H
#include "DLL_Define_Export.h"

struct State;

/*
	State_Setup
	  Create the State and fill it with initial data
*/
DLLEXPORT State * State_Setup();

/*
	State_Delete
	  Correctly deletes a State
*/
DLLEXPORT void State_Delete(State * state);

#include "DLL_Undefine_Export.h"
#endif