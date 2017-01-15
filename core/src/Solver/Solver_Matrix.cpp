#include <Solver/Solver_Matrix.hpp>

namespace InterSim
{
	Solver_Matrix::Solver_Matrix(std::shared_ptr<State> state_) : Solver(state_)
	{
		set_matrix();
	}

	void Solver_Matrix::solve()
	{
		//x.reset(solver.solve(*b));
	}

	void Solver_Matrix::set_matrix()
	{
		solver.compute(A);
	}
}