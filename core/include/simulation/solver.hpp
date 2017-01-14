#ifndef INTERSIM_SOLVER_H
#define INTERSIM_SOLVER_H

#include <memory>
#include <data/state.hpp>

namespace InterSim
{
	class Solver
	{
	public:
		Solver(std::shared_ptr<State> state_);

		virtual void solve() = 0;

	private:
		std::shared_ptr<State> state;
	};

	class MatrixSolver : public Solver
	{
	public:
		MatrixSolver(std::shared_ptr<State> state_);

		void solve() override;
	};
}

#endif