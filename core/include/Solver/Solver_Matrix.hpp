#ifndef INTERSIM_SOLVER_MATRIX_H
#define INTERSIM_SOLVER_MATRIX_H

#include <memory>
#include <Data/State.hpp>
#include <Solver/Solver.hpp>

namespace InterSim
{
	class Solver_Matrix : public Solver
	{
	public:
		Solver_Matrix(std::shared_ptr<State> state_);

		void solve() override;
	};
}

#endif