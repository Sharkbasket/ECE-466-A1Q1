#include "systemc.h"
#include "monitor.h"

void monitor::report_values() {
    while (true) {
        std::cout << std::setw(15) << sc_time_stamp()
                  << std::setw(15) << x->read()
                  << std::setw(15) << y->read() << endl;
        wait();
    }
}
