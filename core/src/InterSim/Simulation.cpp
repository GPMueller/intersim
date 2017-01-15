#include <InterSim/Simulation.h>
#include <Data/State.hpp>

void Simulation_Start(State *state)
{
    // Starts Simulation Iterate
}

void Simulation_Stop(State *state)
{
    // Set iteration_allowed to false or whatever
}

void Simulation_SingleShot(State *state)
{
    // The idea is to do only a single iteration, e.g. for unit testing
}