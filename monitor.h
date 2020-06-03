#include "systemc.h"
#include <iostream>
#include <iomanip>


// Monitor module for reporting signal values to console.
SC_MODULE(monitor)
{
    // Ports
    sc_in<float> x, y;
    sc_in_clk clock;
    
    // Constructor
    monitor(sc_module_name n);
    
    // Processes
    void report_values();
};
