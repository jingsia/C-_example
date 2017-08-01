
#include<iostream>
using namespace std;

int main()
{
    int* a = new int(100);
    std::cout << *a << " " << a << std::endl;

    //情况1 普通变量b
    /*
     * 结果
     * 100 0x440f010
     * 100 0x7fff6ff320d4
     */
#if 0
    int b = *a;
    std::cout << b << " " << &b << std::endl;
#endif

    //情况2 普通变量b delete a
    /*
     * 结果
     * 100 0x5fc2010
     * 100 0x7fff3b6d7384
     */
#if 0
    int b = *a;
    delete a;
    std::cout << b << " " << &b << std::endl;
#endif

    //情况3 指针变量b
    /*
     * 结果
     * 100 0x12094010
     * 100 0x12094010
     */
#if 0
    int* b = a;
    std::cout << *b << " " << b << std::endl;
#endif

    //情况4 指针变量b delete a
    /*
     * 结果
     * 100 0xdc28010
     * 0 0xdc28010
     */
#if 0
    int* b = a;
    delete a;
    std::cout << *b << " " << b << std::endl;
#endif

    //情况5 new指针变量b
    /*
     * 结果
     * 100 0x10066010
     * 0 0x10066030
     * 100 0x10066010
     */
#if 0
    int* b = new int();
    std::cout << *b << " " << b << std::endl;
    b = a;
    std::cout << *b << " " << b << std::endl;
#endif

    //情况6 new指针变量b delete a
    /*
     * 结果
     * 100 0x2c18010
     * b Value::0 b ptr::  0x2c18030
     * b Value::0 b ptr::  0x2c18010
     * a Value::0 a ptr::  0x2c18010
     */
#if 0
    int* b = new int();
    std::cout << "b Value::" <<  *b << " b ptr::  " << b << std::endl;
    b = a;
    delete a;
    std::cout << "b Value::" <<  *b << " b ptr::  " << b << std::endl;
    std::cout << "a Value::" <<  *a << " a ptr::  " << a << std::endl;
#endif

    //情况7 new指针变量b delete b
    /*
     * 结果
     * 100 0x81d8010
     * b Value::0 b ptr::  0x81d8030
     * b Value::0 b ptr::  0x81d8010
     * a Value::0 a ptr::  0x81d8010
     */
#if 0
    int* b = new int();
    std::cout << "b Value::" <<  *b << " b ptr::  " << b << std::endl;
    b = a;
    delete b;
    std::cout << "b Value::" <<  *b << " b ptr::  " << b << std::endl;
    std::cout << "a Value::" <<  *a << " a ptr::  " << a << std::endl;
#endif
    return 0;
}
