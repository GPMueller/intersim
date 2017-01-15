#ifndef INTERSIM_DATA_STATE_H
#define INTERSIM_DATA_STATE_H

#include <Core_Defines.h>

#include <Eigen/Dense>
#include <Eigen/Sparse>

#include <memory>
#include <vector>

namespace InterSim
{
	typedef Eigen::Matrix<scalar, Eigen::Dynamic, Eigen::Dynamic> field;
	typedef Eigen::SparseMatrix<scalar> sparse_matrix;
	typedef Eigen::SparseLU<sparse_matrix> sparse_solver;
}

/*
State
The State struct is passed around in an application to make the
simulation's state available.
The State contains all necessary system information and
provides a few utilities (pointers) to commonly used contents.
*/
struct State
{
	int nx;
	int ny;
	int nz;

	std::vector<InterSim::field> data;
};

#endif