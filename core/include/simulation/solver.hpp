#ifndef INTERSIM_SOLVER_H
#define INTERSIM_SOLVER_H

class Solver
{
    Solver(std::shared_ptr<State> state);

    void solve();
}

#endif