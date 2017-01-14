#include <simulation/simulation.hpp>
#include <intersim/state.h>
#include <simulation/solver.hpp>

namespace InterSim
{
	template <class T_Solver>
    Simulation<T_Solver>::Simulation(std::shared_ptr<State> state_)
		: T_Solver(state_)
		, state(state_)
		//, solver(state_)
    {
    }

    void test()
    {
        int x = 0;
    }
}