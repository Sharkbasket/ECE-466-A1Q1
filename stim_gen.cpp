#include "systemc.h"
#include "stim_gen.h"


void stim_gen::clock_thread() {
    // Clear x and assert reset
    x->write(0.0);
    reset->write(true);
    wait();
    
    // De-assert reset and send a unit pulse to x
    reset->write(false);
    x->write(1.0);
    wait();
    x->write(0.0);
    
    while (true) {
        wait();
    }
}
