/*************************************************************************
	> File Name: a.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Tue 20 Jun 2017 07:00:32 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

template<typename Type>
class Singleton
{
	public:
		static Type& Instance()
		{
			if(s_Instance == 0)
			{
				s_Instance = new(Type)();
				atexit(Destroy);
			}

			return *s_Instance;
		}
	protected:
		Singleton() {}
		virtual ~Singleton() {}
	private:
		static void Destroy()
		{
			if(s_Instance != 0)
			{
				delete(s_Instance);
				s_Instance = 0;
			}
		}
		static Type* volatile s_Instance;
};

template<typename Type>
Type* volatile Singleton<Type>::s_Instance = 0;

template<typename type>
class B
{
static type* b;
};

template<typename type>
type* B<type>::b = 0;





class A : public Singleton<A>
{
	public:
	void GetA()
	{
		std::cout << "1111111" << std::endl;
	}
};

#define GLOBAL() A::Instance()
#define BUF1 ("HELLO WORLD!")
#define BUF2 ("MY NAME IS JACK!")

int main()
{
	GLOBAL().GetA();

	char str[512];
	memset(str, 0, 512);
	memcpy(str, BUF1, strlen(BUF1));

	printf("str = %s\n", str);
	memcpy(str + strlen(BUF1), BUF2, strlen(BUF2));
	printf("str = %s\n", str);

	return 0;
}

