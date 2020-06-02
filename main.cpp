#include "systemc.h"
#include "filter.h"
#include "stim_gen.h"
#include "monitor.h"


int sc_main(int argc, char* argv[]) {
    // Channels
    sc_signal<float> x, y;
    sc_signal<bool> reset;
    sc_clock clock("clock", 10.0, SC_NS);
    
    // Instantiate modules
    filter filter_i("filter_i");
    filter_i.x(x);
    filter_i.y(y);
    filter_i.reset(reset);
    filter_i.clock(clock);
    
    stim_gen stim_gen_i("stim_gen_i");
    stim_gen_i.x(x);
    stim_gen_i.reset(reset);
    stim_gen_i.clock(clock);
    
    monitor monitor_i("monitor_i");
    monitor_i.x(x);
    monitor_i.y(y);
    monitor_i.clock(clock);
    
    // Set up waveform tracing
    sc_trace_file* tf = sc_create_vcd_trace_file("filter_traces");
    tf->set_time_unit(1, SC_NS);
    sc_trace(tf, x, "x");
    sc_trace(tf, y, "y");
    sc_trace(tf, reset, "reset");
    sc_trace(tf, clock, "clock");
    
    // Print column headers
    std::cout << std::setw(15) << "timestamp" 
              << std::setw(15) << "X"
              << std::setw(15) << "Y" << endl << endl;
    
    sc_start(130, SC_NS);
    sc_close_vcd_trace_file(tf);
    
    return 0;
}
