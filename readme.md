## template meta programming

### template instantiation(模板实例化)
- 通过对模板参数进行类型绑定，使模板类型变成普通类型的过程称之为模板实例化。

### template type argument


### template argument deduce(模板类型推导)
- 编译器是没有办法通过返回值推断类型的，因此通过返回值类型对模板参数进行绑定是没办法实例化模板类型的。
- 在部分推导，部分指定的情况下，编译器对模板参数的顺序是有限制的：需要先写指定的模板参数，再把能推导出来的模板参数放在后面。
- 自动类型转换在模板类型推导中是有限制的
    1. 当所有的调用参数为引用类型时，在类型推导过程中是不做任何转换的，且用模板参数T声明的调用参数类型必须严格匹配。
    2. 当所有调用参数为值类型时，在类型推导的过程中仅仅支持类型decay(衰退)，如：忽略cv-qualifiers(const or volatile qualifier)，
    原始数组（raw arrays）或者函数（functions）会被转换成对应的指针类型，且用模板参数T声明的调用参数类型必须严格匹配T的decay类型。