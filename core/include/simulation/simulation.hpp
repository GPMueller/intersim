#ifndef INTERSIM_SIMULATION_H
#define INTERSIM_SIMULATION_H

#include <memory>
#include <data/state.hpp>

namespace Simulation
{
	template <class SimulationType, class Solver>
	class Simulation : public SimulationType, public Solver
	{
	public:
		Simulation(std::shared_ptr<State> state_);

	private:
		std::shared_ptr<State> state;
		//Solver solver;
	};

    void test();
}

#endif