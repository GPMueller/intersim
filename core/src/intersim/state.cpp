#include <intersim/state.h>
#include <data/state.hpp>

State * State_Setup()
{
    // Create the State
    State * state = new State();
    
    // Return
    return state;
}

void State_Delete(State * state)
{
	delete(state);
}