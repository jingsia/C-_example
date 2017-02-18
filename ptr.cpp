/*************************************************************************
	> File Name: ptr.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Sat 18 Feb 2017 09:01:25 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<string>
#include<memory>

using namespace std;

class Simple
{
	public:
		Simple(int p = 0)
		{
			number = p;
			std::cout << "Simple::" << number << std::endl;
		}

		~Simple()
		{
			std::cout << "~Simple::" << number << std::endl;
		}

		void PrintSomething()
		{
			std::cout << "PrintSomething:" << info_extend.c_str() << std::endl;
		}

		std::string info_extend;
		int number;
};

void TestAutoPtr()
{
	std::auto_ptr<Simple> my_memory(new Simple(1));
	if(my_memory.get())
	{
		my_memory->PrintSomething();

		my_memory.get()->info_extend = "Additon";
		my_memory->PrintSomething();

		(*my_memory).info_extend += "other";
		my_memory->PrintSomething();
	}
}
/*
 * 上述为正常使用 std::auto_ptr 的代码，一切似乎都良好，无论如何不用我们显示使用该死的 delete 了。
 * */

void TestAutoPtr2()
{
	std::auto_ptr<Simple> my_memory(new Simple(1));
	if(my_memory.get())
	{
		std::auto_ptr<Simple> my_memory2;
		my_memory2 = my_memory;
		my_memory2->PrintSomething();
		my_memory->PrintSomething();
	}
}
/*
 * 最终如上代码导致崩溃，如上代码时绝对符合 C++ 编程思想的，居然崩溃了，跟进 std::auto_ptr 的源码后，我们看到，罪魁祸首是“my_memory2 = my_memory”，这行代码，my_memory2 完全夺取了 my_memory 的内存管理所有权，导致 my_memory 悬空，最后使用时导致崩溃。
 * 所以，使用 std::auto_ptr 时，绝对不能使用“operator=”操作符。作为一个库，不允许用户使用，确没有明确拒绝[1]，多少会觉得有点出乎预料。
 * */

void TestAutoPtr3()
{
	std::auto_ptr<Simple> my_memory(new Simple(1));
	if(my_memory.get())
		my_memory.release();

}
/*
 * 执行结果为：
 * Simple: 1
 * 看到什么异常了吗？我们创建出来的对象没有被析构，没有输出“~Simple: 1”，导致内存泄露。当我们不想让 my_memory 继续生存下去，我们调用 release() 函数释放内存，结果却导致内存泄露（在内存受限系统中，如果my_memory占用太多内存，我们会考虑在使用完成后，立刻归还，而不是等到 my_memory 结束生命期后才归还）。
 * */

void TestAutoPtr4()
{
	std::auto_ptr<Simple> my_memory(new Simple(1));
	if(my_memory.get())
	{
		Simple* temp_memory = my_memory.release();
		delete temp_memory;
	}

}
void TestAutoPtr5()
{
	std::auto_ptr<Simple> my_memory(new Simple(1));
	if(my_memory.get())
	{
		my_memory.reset();
	}

}
/*
 * 原来 std::auto_ptr 的 release() 函数只是让出内存所有权，这显然也不符合 C++ 编程思想。
 * 总结：std::auto_ptr 可用来管理单个对象的对内存，但是，请注意如下几点：
 * （1）    尽量不要使用“operator=”。如果使用了，请不要再使用先前对象。
 * （2）    记住 release() 函数不会释放对象，仅仅归还所有权。
 * （3）    std::auto_ptr 最好不要当成参数传递（读者可以自行写代码确定为什么不能）。
 * （4）    由于 std::auto_ptr 的“operator=”问题，有其管理的对象不能放入 std::vector 等容器中。
 * （5）    ……
 * 使用一个 std::auto_ptr 的限制还真多，还不能用来管理堆内存数组，这应该是你目前在想的事情吧，我也觉得限制挺多的，哪天一个不小心，就导致问题了。
 * 由于 std::auto_ptr 引发了诸多问题，一些设计并不是非常符合 C++ 编程思想，所以引发了下面 boost 的智能指针，boost 智能指针可以解决如上问题。
 * */

//////////////////////////////////////////////////////////////

void TestSharedPtr()
{
	std::shared_ptr<Simple> my_memory(new Simple(1));
	if(my_memory.get())
	{
		my_memory->PrintSomething();

		my_memory.get()->info_extend = "Additon";
		my_memory->PrintSomething();

		(*my_memory).info_extend += "other";
		my_memory->PrintSomething();
	}

}
/*
 * 引入计数器 可从源码了解到
 * */

void TestSharedPtr2()
{
	std::shared_ptr<Simple> my_memory(new Simple(1));
	if(my_memory.get())
	{
		std::shared_ptr<Simple> my_memory2;
		my_memory2 = my_memory;
		my_memory2->PrintSomething();
		my_memory->PrintSomething();
		std::cout << "use_count--> " << my_memory.use_count() << std::endl;
	}
}

///////////////////////////////////////////////////

void TestUniquePtr()
{
	std::unique_ptr<Simple> my_memory(new Simple(1));
	if(my_memory.get())
	{
		my_memory->PrintSomething();

		my_memory.get()->info_extend = "Additon";
		my_memory->PrintSomething();

		(*my_memory).info_extend += "other";
		my_memory->PrintSomething();
	}

}

void TestUniquePtr2()
{
	std::unique_ptr<Simple> my_memory(new Simple(1));
	if(my_memory.get())
	{
		std::unique_ptr<Simple> my_memory2 = std::move(my_memory);
		my_memory2->PrintSomething();
		my_memory->PrintSomething();
	}
}
/*
 * 执行错误
 * Simple::1
 * PrintSomething:
 * Segmentation fault (core dumped)
 * 主要原因源指针转移给目标指针
 * std::unique_ptr实现了独享所有权的语义。一个非空的std::unique_ptr总是拥有它所指向的资源。转移一个std::unique_ptr将会把所有权也从源指针转移给目标指针（源指针被置空）。
 *
 * 在C++11环境下，auto_ptr被看做“遗留的”，他们有如下区别：
 * auto_ptr有拷贝语义，拷贝后源对象变得无效；unique_ptr则无拷贝语义，但提供了移动语义
 * auto_ptr不可作为容器元素，unique_ptr可以作为容器元素
 * auto_ptr不可指向动态数组(尽管不会报错，但不会表现出正确行为)，unique_ptr可以指向动态数组
 *
 * */

int main()
{
	TestUniquePtr2();
	return 0;
}


