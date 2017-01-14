#include <simulation/solver.hpp>

namespace InterSim
{
	Solver::Solver(std::shared_ptr<State> state_)
		: state(state_)
	{

	}

	MatrixSolver::MatrixSolver(std::shared_ptr<State> state_) : Solver(state_)
	{

	}

	void MatrixSolver::solve()
	{

	}
}