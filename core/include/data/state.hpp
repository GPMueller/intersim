#ifndef INTERSIM_DATA_STATE_H
#define INTERSIM_DATA_STATE_H

#include <Eigen/Dense>
#include <memory>

typedef std::shared_ptr<Eigen::VectorXf> field;

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

	field f;
};

#endif