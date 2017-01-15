#ifndef INTERSIM_SOLVER_MATRIX_H
#define INTERSIM_SOLVER_MATRIX_H

#include <memory>
#include <Eigen/Sparse>
#include <Data/State.hpp>
#include <Solver/Solver.hpp>

namespace InterSim
{
	class Solver_Matrix : public Solver
	{
	public:
		Solver_Matrix(std::shared_ptr<State> state_);

		void solve() override;

	private:
		void set_matrix();

		sparse_solver solver;
		sparse_matrix A;
		std::shared_ptr<field> b;
		std::shared_ptr<field> x;
	};
}

#endif