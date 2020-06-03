#include "systemc.h"
#include "stim_gen.h"


// Constructor
SC_HAS_PROCESS(stim_gen);
stim_gen::stim_gen(sc_module_name n) : sc_module(n)
{
    SC_CTHREAD(clock_thread, clock.pos());
}


// Stimulus generation for testbench.
void stim_gen::clock_thread()
{
    // Clear x and assert reset.
    x->write(0.0);
    reset->write(true);
    wait();
    
    // De-assert reset and send a unit pulse to x.
    reset->write(false);
    x->write(1.0);
    wait();
    x->write(0.0);
    
    // Do nothing for remainder of simulation.
    while (true)
    {
        wait();
    }
}
