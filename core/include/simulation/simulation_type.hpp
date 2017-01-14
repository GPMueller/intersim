#ifndef INTERSIM_SIMULATION_TYPE_H
#define INTERSIM_SIMULATION_TYPE_H

#include <memory>
#include <data/state.hpp>

namespace InterSim
{
	class Simulation_Type
	{
	public:
		Simulation_Type(std::shared_ptr<State> state_) : state(state_) {};

		virtual void calculate_forces() = 0;

	private:
		std::shared_ptr<State> state;
	};
}

#endif