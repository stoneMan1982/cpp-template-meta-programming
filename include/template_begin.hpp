//
// Created by 杨文宇 on 2018/11/27.
//
#pragma once

template <typename T>
T add(T a,T b) {
    return a + b;
}

template <typename T>
T get() {
    return static_cast<T>(0);
}

// int a = get_value();编译器会报错：无法推断T类型。原因在于：编译器是没有办法通过返回值推断类型的，因此通过返回值类型对模板参数进行绑定是没办法实例化模板类型的。
// 此时正确写法是显示实例化模板 int a = get_value<int>();




