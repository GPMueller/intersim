#include <intersim/state.h>
#include <memory>

// Main
int main(int argc, char ** argv)
{
    auto state = std::shared_ptr<State>(State_Setup(), State_Delete);
}