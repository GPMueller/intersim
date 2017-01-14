#ifndef INTERSIM_SOLVER_H
#define INTERSIM_SOLVER_H

#include <memory>
#include <data/state.hpp>

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
	void solve() override;
};

#endif