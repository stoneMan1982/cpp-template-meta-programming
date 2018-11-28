//
// Created by 杨文宇 on 2018/11/26.
//

#pragma once

#include <iostream>
#include <type_traits>
#include <utility>

class counter_interface {
public:
    virtual void increase() = 0;
    virtual ~counter_interface(){}
};

class counter : public counter_interface {
public:
    virtual void increase() override {
        std::cout << "counter interface implement" << std::endl;
    }
};

template <typename T>
void inc_counter(T &counter_obj,typename std::enable_if<std::is_base_of<counter_interface,T>::value,int>::type = 0) {
    counter_obj.increase();
}

template <typename T>
void inc_counter(T &int_type_counter, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr) {
    std::cout << "int type counter increase" << std::endl;
};
