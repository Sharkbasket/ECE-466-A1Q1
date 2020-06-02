#include "systemc.h"
#include "monitor.h"

void monitor::report_values() {
    while (true) {
        std::cout << setw(15) << sc_time_stamp()
                  << setw(15) << x->read() << setw(15) << y->read() << endl;
        wait();
    }
}
