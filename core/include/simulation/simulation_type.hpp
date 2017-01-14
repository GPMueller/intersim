#ifndef INTERSIM_SIMULATION_TYPE_H
#define INTERSIM_SIMULATION_TYPE_H

#include <memory>
#include <data/state.hpp>

class SimulationType
{
public:
	SimulationType(std::shared_ptr<State> state_);

    virtual void calculate_forces() = 0;

private:
	std::shared_ptr<State> state;
};

class WaveSimulation : public SimulationType
{
public:
	void calculate_forces() override;
};

#endif