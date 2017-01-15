#include <InterSim/State.h>
#include <Data/State.hpp>

State * State_Setup()
{
    // Create the State
    State * state = new State();

	// Multithreaded console logger(with color support)
	state->log = spdlog::stdout_color_mt("console");
	state->log->info("Welcome to InterSim!");

	// Data Grid
	int nx = 10;
	int ny = 10;
	int nz = 1;
	state->log->info("Data grid size: {}x{}x{}", nx, ny, nz);

	state->nx = nx;
	state->ny = ny;
	state->nz = nz;

	//state->data.emplace_back(nx*ny*nz);
    
    // Return
    return state;
}

void State_Delete(State * state)
{
	state->log->info("Deleting InterSim State...");
	delete(state);
}