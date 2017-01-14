#include <intersim/state.h>
#include <simulation/simulation.hpp>
#include <simulation/wave_simulation.hpp>
#include <simulation/solver.hpp>

using namespace InterSim;

// Main
int main(int argc, char ** argv)
{
	std::shared_ptr<State> state(State_Setup(), State_Delete);
	Simulation<WaveSimulation, MatrixSolver> simulation(state);
}