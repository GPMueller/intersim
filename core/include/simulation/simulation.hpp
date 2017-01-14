#ifndef INTERSIM_SIMULATION_H
#define INTERSIM_SIMULATION_H

#include <memory>
#include <data/state.hpp>

namespace InterSim
{
	template <class T_SimulationType, class T_Solver>
	class Simulation : public T_SimulationType, public T_Solver
	{
	public:
		Simulation(std::shared_ptr<State> state_)
			: T_Solver(state_)
			, T_SimulationType(state_)
			, state(state_)
		{
		}

		void iteration()
		{
			T_SimulationType::calculate_forces();
			T_Solver::solve();
		}

	private:
		std::shared_ptr<State> state;
	};
}

#endif