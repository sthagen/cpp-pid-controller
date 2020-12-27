#include <cmath>
#include <iostream>

#include "../controller/pid.hpp"

int main() {
    using reading = double;
    reading d_t = .1, lo = -21., hi = +21., k_p = .1, k_i = .5, k_d = .01;
    std::cout << "creating naive naive PID controller with:\n"
              << "    d_t = " << d_t << ", lo = " << lo << ", hi = " << hi
              << "\n  and the proportional, integral, as well as derivative coefficients:\n"
              << "    k_p = " << k_p << ", k_i = " << k_i << ", and k_d = " << k_d
              << "\n";
    auto controller = pid::naive<reading>(d_t, lo, hi, k_p, k_i, k_d);

    reading target = 0, read = 3.14156, do_not_replace_time_interval{0};
    std::cout << "  operating the controller with target " << target << " and start reading " << read << ":\n";
    for (int i = 0; i < 42; ++i) {
        auto norm = std::abs(target - read);
        auto change = controller.calculate(target, read, do_not_replace_time_interval);
        std::cout << "    read: " << read << ", ||delta||_2 = " << norm << " => change: " << change << " ->\n";
        read += change;
    }

    return 0;
}

