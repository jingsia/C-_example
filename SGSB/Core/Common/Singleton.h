#ifndef SIGLETON_INC
#define SIGLETON_INC

#include <stdlib.h>

template <typename Type>
class Singleton
{
public:
	static Type& Instance()
	{
		if(s_Instance == 0)
		{
			s_Instance = new(Type) ();
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

template <typename Type>
Type* volatile Singleton<Type >::s_Instance = 0;

#endif
