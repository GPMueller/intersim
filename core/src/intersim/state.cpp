#include <intersim/state.h>
#include <data/state.hpp>

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

	state->f->setZero(nx*ny*nz);
    
    // Return
    return state;
}

void State_Delete(State * state)
{
	delete(state);
}