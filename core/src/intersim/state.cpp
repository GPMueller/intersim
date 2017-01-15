#include <InterSim/State.h>
#include <Data/State.hpp>

State * State_Setup()
{
    // Create the State
    State * state = new State();

	int nx = 10;
	int ny = 10;
	int nz = 1;
	state->nx = nx;
	state->ny = ny;
	state->nz = nz;

	//state->data.emplace_back(nx*ny*nz);
    
    // Return
    return state;
}

void State_Delete(State * state)
{
	delete(state);
}