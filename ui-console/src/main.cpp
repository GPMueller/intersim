#include <InterSim/State.h>
#include <Simulation/Simulation.hpp>
#include <Simulation/Simulation_Type_Wave.hpp>
#include <Solver/Solver_Matrix.hpp>

using namespace InterSim;

// Main
int main(int argc, char ** argv)
{
	std::shared_ptr<State> state(State_Setup(), State_Delete);
	Simulation<Simulation_Type_Wave, Solver_Matrix> Simulation(state);
}