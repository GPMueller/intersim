#ifndef INTERSIM_SIMULATION_TYPE_WAVE_H
#define INTERSIM_SIMULATION_TYPE_WAVE_H

#include <memory>
#include <Data/State.hpp>
#include <Simulation/Simulation_Type.hpp>

namespace InterSim
{
	class Simulation_Type_Wave : public Simulation_Type
	{
	public:
		Simulation_Type_Wave(std::shared_ptr<State> state_);

		void calculate_forces() override;
	};
}

#endif