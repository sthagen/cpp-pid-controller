#pragma once

#include <algorithm>  // for: std::clamp

namespace pid {

    template<typename T>
    class naive {
        // Control process variable in [low, high] value range in given time intervals < zero
        //   per proportional, integral, and derivative coefficients/gains (naive)
        //   eventually reversing direction of control
    public:
        naive(T time_interval, T low, T high, T k_p, T k_i, T k_d, bool reverse=false)
                : time_interval(time_interval),
                  low(low),
                  high(high),
                  proportional_gain(k_p),
                  integral_gain(k_i),
                  derivative_gain(k_d),
                  reverse(reverse),
                  previous_deviation(T{0}),
                  running_integral(T{0}) { }

        ~naive() {}

        // Returns the change commanded to the controlled variable given target and read value
        // The optional parameter replace_time_interval allows for updating the time interval
        T calculate(T target, T read, T replace_time_interval=T{0}) {

            if (replace_time_interval != T{0}) time_interval = replace_time_interval;
            T deviation = reverse ? read - target : target - read;
            running_integral += deviation * time_interval;  // update integration

            T change = proportional_gain * deviation
                       + integral_gain * running_integral
                       + derivative_gain * (deviation - previous_deviation) / time_interval;

            previous_deviation = deviation;  // keep deviation for next iteration derivative

            return std::clamp(change, low, high);
        }

    private:
        T time_interval;
        T low;
        T high;
        T proportional_gain;
        T integral_gain;
        T derivative_gain;
        bool reverse;
        T previous_deviation;  // state variable for evaluation of derivative control aspect
        T running_integral;  // state variable for evaluation of integral control aspect
    };

}
