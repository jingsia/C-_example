/*************************************************************************
	> File Name: e.cpp
	> Author: yangjx
	> Mail: yangjx@126.com 
	> Created Time: Thu 16 Mar 2017 01:14:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include <vector>

using namespace std;

template<typename TAV>
class Container
{
	private:
		vector<TAV> m_List;
	public:
		void add(TAV node)
		{
			m_List.push_back(node);
		}

		void Get()
		{
			for(typename vector<TAV>::iterator it = m_List.begin(); it != m_List.end(); ++it)
			{
				std::cout << *it << std::endl;
			}
		}
};

int main()
{
	Container<int> t;
	t.add(1);
	t.Get();
}
