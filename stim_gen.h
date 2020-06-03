#include "systemc.h"


// Stimulus generator module
SC_MODULE(stim_gen)
{
    // Ports
    sc_in_clk clock;
    sc_out<float> x;
    sc_out<bool> reset;
    
    // Constructor
    stim_gen(sc_module_name n);
    
    // Processes
    void clock_thread();
};
