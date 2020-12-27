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

    template <class T>
    constexpr auto controller = [](T time_interval, T const low, T const high, T const k_p, T const k_i, T const k_d) {
        T previous_deviation{0};
        T running_integral{0};
        return [time_interval, low, high, k_p, k_i, k_d, previous_deviation, running_integral](
                T target, T read, T replace_time_interval=T{0}) mutable {
            if (replace_time_interval != T{0}) time_interval = replace_time_interval;
            T deviation = target - read;
            running_integral += deviation * time_interval;  // update integration

            T change = k_p * deviation
                       + k_i * running_integral
                       + k_d * (deviation - previous_deviation) / time_interval;

            previous_deviation = deviation;  // keep deviation for next iteration derivative

            return std::clamp(change, low, high);
        };
    };

    template <class T>
    constexpr auto controller_inverting = [](T time_interval, T const low, T const high, T const k_p, T const k_i, T const k_d) {
        T previous_deviation{0};
        T running_integral{0};
        return [time_interval, low, high, k_p, k_i, k_d, previous_deviation, running_integral](
                T target, T read, T replace_time_interval=T{0}) mutable {
            if (replace_time_interval != T{0}) time_interval = replace_time_interval;
            T deviation = read - target;
            running_integral += deviation * time_interval;  // update integration

            T change = k_p * deviation
                       + k_i * running_integral
                       + k_d * (deviation - previous_deviation) / time_interval;

            previous_deviation = deviation;  // keep deviation for next iteration derivative

            return std::clamp(change, low, high);
        };
    };

}
