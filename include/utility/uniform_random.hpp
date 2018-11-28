//
// Created by 杨文宇 on 2018/11/26.
//
#pragma once

#include <cstdlib>
#include <cmath>

class uniform_random {
public:
    static double random(double max = 1) {
        return ((double)std::rand() / (RAND_MAX))*max;
    }
};