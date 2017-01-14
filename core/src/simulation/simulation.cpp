#include <simulation/simulation.hpp>
#include <intersim/state.h>
#include <simulation/solver.hpp>
#include <simulation/simulation_type.hpp>

namespace Simulation
{
    Simulation<class SimulationType, class Solver>::Simulation(std::shared_ptr<State> state_)
		: Solver(state_)
		, SimulationType(state_)
		, state(state_)
		//, solver(state_)
    {
    }

    void test()
    {
        int x = 0;
    }
}