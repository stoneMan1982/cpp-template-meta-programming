//
// Created by 杨文宇 on 2018/11/27.
//
#pragma once

#include <type_traits>
#include <cstdint>
#include <memory>
#include <iostream>

//模板的一般形式或主体
template <typename T>
struct add_float_or_mul_int {};


//int特化
template <>
struct add_float_or_mul_int<int> {
    static int do_work(int a, int b) {
        return a * b;
    }
};

//float特化
template <>
struct add_float_or_mul_int<float> {
    static float do_work(float a,float b) {
        return a + b;
    }
};

template <typename T>
struct type_to_id {
    static const int id = -1;
};

template <typename T>
struct type_to_id<T*> {
    typedef T same_as_type;
    static const int id = 0x80;
};

template <>
struct type_to_id<int8_t> {
    static const int id = 0;
};

template <>
struct type_to_id<uint8_t> {
    static const int id = 1;
};

template <>
struct type_to_id<int16_t> {
    static const int id = 2;
};

template <>
struct type_to_id<float> {
    static const int id = 3;
};

template <>
struct type_to_id<void*> {
    static const int id = 4;
};

//原型
template <typename T> struct worker;

template <> struct worker<int>{};

template <> struct worker<float>{};

template <typename T> struct worker<T*>{};

//原型
template <typename T,typename U> struct comb_to_id;

template <typename T>
struct comb_to_id<T,T> {
    static const int id = 1;
};

template <typename T>
struct comb_to_id<T*,T> {

    static const int id = 2;
};

template <typename T>
struct comb_to_id<T,T*> {
    static const int id = 3;
};

template <typename U>
struct comb_to_id<U,int> {
    static const int id = 4;
};

template <typename U>
struct comb_to_id<U*,int> {
    static const int id = 5;
};

template <typename U,typename T>
struct comb_to_id<U*,T*> {
    static const int id = 6;
};

template <typename U,typename T>
struct comb_to_id<U,T*> {
    static const int id = 7;
};

template <typename T>
struct comb_to_id<std::unique_ptr<T>,std::shared_ptr<T>> {
    static const int id = 8;
};

template <typename T>
struct comb_to_id<T*,T*> {
    static const int id = 9;
};

template <typename T>
T custom_div(T left_op,T right_op) {
    std::cout << "custom div" << std::endl;
    return static_cast<T>(0);
}

template <typename T,typename Enable = std::true_type>
struct safe_divide {
    static T divide(T left_op,T right_op) {
        return custom_div(left_op,right_op);
    }
};

template <typename T>
struct safe_divide <T,typename std::is_floating_point<T>::type> {
    static T divide(T left_op,T right_op) {
        return left_op / right_op;
    }
};

template <typename T>
struct safe_divide<T,typename std::is_integral<T>::type> {
    static T divide(T left_op,T right_op) {
        return left_op;
    }
};