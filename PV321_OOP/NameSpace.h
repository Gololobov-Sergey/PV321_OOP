#pragma once
#include<iostream>

using namespace std;

//void foo()
//{
//	cout << "foo1" << endl;
//}


namespace boo
{
	void foo()
	{
		cout << "foo2" << endl;
	}

	namespace doo
	{
		void foo()
		{
			cout << "foo2" << endl;
		}
	}
}

namespace Const
{
	const double PI = 3.141592;
}


namespace Containers
{
	template<class T>
	class list
	{

	};
}

