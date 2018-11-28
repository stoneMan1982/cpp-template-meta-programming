#include <iostream>
#include <template_begin.hpp>
#include <template_specialize.hpp>
#include <cassert>
#include <complex>

int main() {

    int a = 5;
    int b = 3;
    int result = add(a,b);

    int x = get<int>();

    std::cout << type_to_id<int8_t>::id << std::endl;
    std::cout << type_to_id<int32_t>::id << std::endl;
    std::cout << type_to_id<float>::id << std::endl;
    std::cout << type_to_id<void*>::id << std::endl;
    std::cout << type_to_id<float*>::id << std::endl;
    std::cout << type_to_id<type_to_id<float*>::same_as_type>::id << std::endl;

    static_assert((comb_to_id<double,double>::id == 1));
    static_assert((comb_to_id<float*,int>::id == 5));
    static_assert(comb_to_id<double*,int>::id == 5);
    static_assert(comb_to_id<float*,double*>::id == 6);
    static_assert(comb_to_id<float*,float*>::id == 9);

    std::cout << safe_divide<float>::divide(1.1,1.2) << std::endl;
    std::cout << safe_divide<int>::divide(1,0) << std::endl;
    std::cout << safe_divide<char>::divide(1,0) << std::endl;
    std::cout << safe_divide<std::complex<float>>::divide({1.f,2.f},{1.f,-2.f});


    return 0;
}