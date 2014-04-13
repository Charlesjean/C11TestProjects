#include "TestClass.h"
int main()
{
	char* str = new char[15];
	std::fill(str, str + 15, 'a');

	char* str2 = new char[15];
	std::fill(str2, str2 + 15, 'b');

	cout << "=====TestClass A(str)=========================================================" << std::endl;
	TestClass A(str);
	cout << "=====TestClass B(str2)========================================================" << std::endl;
	TestClass B(str2);
	cout << "=====TestClass C(A)===========================================================" << std::endl;
	TestClass C(A);
	cout << "=====TestClass D = B==========================================================" << std::endl;
	TestClass D = B;
	cout << "=====D = A====================================================================" << std::endl;
	D = A;
	cout << "=====TestClass E = A + B======================================================" << std::endl;
	TestClass E = A + B;
	cout << "=====TestClass F(A)===========================================================" << std::endl;
	TestClass F(A);
	F = A + B;
	int i;
	cin >> i;
	return 0;

}
