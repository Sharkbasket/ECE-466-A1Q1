#include "systemc.h"


SC_MODULE(filter) {
    // Ports
    sc_in<float> x;
    sc_in<bool> reset;
    sc_in_clk clock;
    sc_out<float> y;
    
    // Internal signals
    sc_signal<float> s1, s2, s3, s4, s5;
    
    // Processes
    void produce_output();
    void handle_input();
    void clock_thread();
    
    // Constructor
    SC_CTOR(filter) {
        SC_METHOD(produce_output);
        sensitive << s2 << s4 << s5;
        
        SC_METHOD(handle_input);
        sensitive << x << s2 << s4 << s5;
        
        SC_CTHREAD(clock_thread, clock.pos());
        reset_signal_is(reset, true);
        dont_initialize();
    }
};
