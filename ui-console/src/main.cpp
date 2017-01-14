#include <intersim/state.h>
#include <simulation/simulation.hpp>
#include <simulation/simulation_type.hpp>
#include <simulation/solver.hpp>

// Main
int main(int argc, char ** argv)
{
	std::shared_ptr<State> state(State_Setup());
	Simulation::Simulation<WaveSimulation, MatrixSolver> simulation(state);
}