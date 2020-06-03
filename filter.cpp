#include "systemc.h"
#include "filter.h"


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


void filter::produce_output()
{
    y->write((s2.read() * 0.24) + (s4.read() * 0.2) + (s5.read() * 0.25));
}


void filter::handle_input()
{
    s1.write(x->read() + (s2.read() * 0.4));
    s3.write(x->read() + (s4.read() * -0.8) + (s5.read() * -0.5));
}


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
        // Read current inputs
        s2.write(s1.read());
        s4.write(s3.read());
        s5.write(s4.read());
        wait();
    }
}
