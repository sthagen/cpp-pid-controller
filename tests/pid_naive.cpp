#include "catch.hpp"
#include "../controller/pid.hpp"

TEST_CASE("naive PID controller from example is constructable.", "[positive]") {
    using reading = double;
    reading d_t = .1, lo = -21., hi = +21., k_p = .1, k_i = .5, k_d = .01;
    auto controller = pid::naive<reading>(d_t, lo, hi, k_p, k_i, k_d);
    REQUIRE(controller.calculate(reading{0}, reading{3.14156}, reading{0}) < reading{0});
}
