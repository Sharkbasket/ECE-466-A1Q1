#include <iostream>
#include "systemc.h"
#include "monitor.h"

void monitor::report_values() {
    while (true) {
        std::cout << "timestamp: " << sc_time_stamp() << endl;
        std::cout << "x = " << x->read() << endl;
        std::cout << "y = " << y->read() << endl << endl;
        wait();
    }
}
