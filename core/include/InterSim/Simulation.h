#pragma once
#ifndef INTERSIM_SIMULATION_H
#define INTERSIM_SIMULATION_H
#include "DLL_Define_Export.h"

struct State;

// Start a simulation
DLLEXPORT void Simulation_Start(State *state);

// Stop a simulation
DLLEXPORT void Simulation_Stop(State *state);

// Single iteration
DLLEXPORT void Simulation_SingleShot(State *state);

#include "DLL_Undefine_Export.h"
#endif