//
// Created by Dave Smith on 11/5/20.
//

#ifndef FIBONACCILAB_TIMER_H
#define FIBONACCILAB_TIMER_H
#include <chrono>

class Timer {

private:
    typedef std::chrono::high_resolution_clock Clock;
    typedef Clock::time_point Time;
    Time getCurrentTime();
    Time t1, t2;
public:
    void start();
    void end();
    double getDuration();
};


#endif //FIBONACCILAB_TIMER_H
