#ifndef INTERSIM_WAVE_SIMULATION_H
#define INTERSIM_WAVE_SIMULATION_H

#include <memory>
#include <data/state.hpp>
#include <simulation/simulation_type.hpp>

namespace InterSim
{
	class WaveSimulation : public SimulationType
	{
	public:
		WaveSimulation(std::shared_ptr<State> state_);

		void calculate_forces() override;
	};
}

#endif