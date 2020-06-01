#include "systemc.h"


SC_MODULE(monitor) {
    // Ports
    sc_in<float> x, y;
    sc_in_clk clock;
    
    // Processes
    void report_values();
    
    // Constructor
    SC_CTOR(monitor) {
        SC_CTHREAD(report_values, clock.pos());
        dont_initialize();
    }
};
