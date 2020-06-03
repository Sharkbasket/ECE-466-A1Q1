#include "systemc.h"
#include "filter.h"


// Constructor
SC_HAS_PROCESS(filter);
filter::filter(sc_module_name n) : sc_module(n)
{
    SC_METHOD(produce_output);
    sensitive << s2 << s4 << s5;
    
    SC_METHOD(handle_input);
    sensitive << x << s2 << s4 << s5;
    
    SC_CTHREAD(clock_thread, clock.pos());
    reset_signal_is(reset, true);
}


// Compute filter output from the outputs of delay registers.
void filter::produce_output()
{
    y->write((s2.read() * 0.24) + (s4.read() * 0.2) + (s5.read() * 0.25));
}


// Compute inputs to delay registers.
void filter::handle_input()
{
    s1.write(x->read() + (s2.read() * 0.4));
    s3.write(x->read() + (s4.read() * -0.8) + (s5.read() * -0.5));
}


// Simulate delay registers. Transfer inputs to outputs on clock edges.
void filter::clock_thread()
{
    // Reset actions
    if (reset)
    {
        s2.write(0.0);
        s4.write(0.0);
        s5.write(0.0);
        wait();
    }
    
    while (true)
    {
        s2.write(s1.read());
        s4.write(s3.read());
        s5.write(s4.read());
        wait();
    }
}
