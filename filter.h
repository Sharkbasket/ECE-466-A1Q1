#include "systemc.h"


SC_MODULE(filter)
{
    // Ports
    sc_in<float> x;
    sc_in<bool> reset;
    sc_in_clk clock;
    sc_out<float> y;
    
    // Internal signals
    sc_signal<float> s1, s2, s3, s4, s5;
    
    // Constructor
    filter(sc_module_name n);
    
    // Processes
    void produce_output();
    void handle_input();
    void clock_thread();
};
