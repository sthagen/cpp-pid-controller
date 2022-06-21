# cpp-pid-controller

Experimental generic naive controller implementation.

## Usage

Generate build files:

```console
❯ cmake -S . -B build
# ...
```

Build (in parallel):

```console
❯ cmake --build build --parallel 2
[ 40%] Building CXX object tests/CMakeFiles/pid_controller_test.dir/test.cpp.o
[ 40%] Building CXX object examples/CMakeFiles/pid_naive.dir/pid_naive.cpp.o
[ 60%] Linking CXX executable pid_naive
[ 60%] Built target pid_naive
[ 80%] Building CXX object tests/CMakeFiles/pid_controller_test.dir/pid_naive.cpp.o
[100%] Linking CXX executable pid_controller_test
[100%] Built target pid_controller_test
```

Execute tests:

```console
❯ build/tests/pid_controller_test
===============================================================================
All tests passed (4 assertions in 4 test cases)
```

Execute example:

```console
❯ build/examples/pid_naive
creating naive naive PID controller with:
    d_t = 0.1, lo = -21, hi = 21
  and the proportional, integral, as well as derivative coefficients:
    k_p = 0.1, k_i = 0.5, and k_d = 0.01
  operating the controller with target 0 and start reading 3.14156:
    read: 3.14156, ||delta||_2 = 3.14156 => change: -0.78539 ->
    read: 2.35617, ||delta||_2 = 2.35617 => change: -0.431964 ->
    read: 1.92421, ||delta||_2 = 1.92421 => change: -0.520321 ->
    read: 1.40388, ||delta||_2 = 1.40388 => change: -0.529647 ->
    read: 0.874237, ||delta||_2 = 0.874237 => change: -0.519462 ->
    read: 0.354775, ||delta||_2 = 0.354775 => change: -0.486273 ->
    read: -0.131498, ||delta||_2 = 0.131498 => change: -0.43439 ->
    read: -0.565887, ||delta||_2 = 0.565887 => change: -0.367845 ->
    read: -0.933732, ||delta||_2 = 0.933732 => change: -0.291028 ->
    read: -1.22476, ||delta||_2 = 1.22476 => change: -0.208369 ->
    read: -1.43313, ||delta||_2 = 1.43313 => change: -0.124142 ->
    read: -1.55727, ||delta||_2 = 1.55727 => change: -0.0422866 ->
    read: -1.59956, ||delta||_2 = 1.59956 => change: 0.0337344 ->
    read: -1.56582, ||delta||_2 = 1.56582 => change: 0.10105 ->
    read: -1.46477, ||delta||_2 = 1.46477 => change: 0.157452 ->
    read: -1.30732, ||delta||_2 = 1.30732 => change: 0.201433 ->
    read: -1.10589, ||delta||_2 = 1.10589 => change: 0.232186 ->
    read: -0.873702, ||delta||_2 = 0.873702 => change: 0.249577 ->
    read: -0.624125, ||delta||_2 = 0.624125 => change: 0.254086 ->
    read: -0.370039, ||delta||_2 = 0.370039 => change: 0.246729 ->
    read: -0.12331, ||delta||_2 = 0.12331 => change: 0.228957 ->
    read: 0.105647, ||delta||_2 = 0.105647 => change: 0.202556 ->
    read: 0.308204, ||delta||_2 = 0.308204 => change: 0.169531 ->
    read: 0.477734, ||delta||_2 = 0.477734 => change: 0.131993 ->
    read: 0.609727, ||delta||_2 = 0.609727 => change: 0.0920614 ->
    read: 0.701789, ||delta||_2 = 0.701789 => change: 0.051759 ->
    read: 0.753548, ||delta||_2 = 0.753548 => change: 0.0129359 ->
    read: 0.766484, ||delta||_2 = 0.766484 => change: -0.0227995 ->
    read: 0.743684, ||delta||_2 = 0.743684 => change: -0.0541302 ->
    read: 0.689554, ||delta||_2 = 0.689554 => change: -0.0800618 ->
    read: 0.609492, ||delta||_2 = 0.609492 => change: -0.0999371 ->
    read: 0.509555, ||delta||_2 = 0.509555 => change: -0.113434 ->
    read: 0.396121, ||delta||_2 = 0.396121 => change: -0.120547 ->
    read: 0.275575, ||delta||_2 = 0.275575 => change: -0.121559 ->
    read: 0.154015, ||delta||_2 = 0.154015 => change: -0.117003 ->
    read: 0.0370123, ||delta||_2 = 0.0370123 => change: -0.107609 ->
    read: -0.0705966, ||delta||_2 = 0.0705966 => change: -0.0942576 ->
    read: -0.164854, ||delta||_2 = 0.164854 => change: -0.0779243 ->
    read: -0.242779, ||delta||_2 = 0.242779 => change: -0.0596263 ->
    read: -0.302405, ||delta||_2 = 0.302405 => change: -0.0403732 ->
    read: -0.342778, ||delta||_2 = 0.342778 => change: -0.0211223 ->
    read: -0.3639, ||delta||_2 = 0.3639 => change: -0.00274013 ->
```

## Status

Experimental

**Note**: The default branch is `default`.
