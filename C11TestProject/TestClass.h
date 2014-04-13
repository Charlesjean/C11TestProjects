#pragma once
#include <iostream>
using namespace std;
class TestClass
{
public:
	TestClass(char* _array) : array_pointer(_array){ 
		cout << "Constructor Invoked" << std::endl; 
	}
	~TestClass(){
		cout << "Destructor is InVoked" << std::endl;
		delete array_pointer; 
	}
	//This is move consturctor, transfer ownership
	TestClass(TestClass&& rhs){
		cout << "Move Construct is Invoked" << std::endl;
		this->array_pointer = rhs.array_pointer; 
		rhs.array_pointer = nullptr;
	}
	TestClass(const TestClass& rhs){
		cout << "Copy Constructor is Invoked" << std::endl;
		size_t len = strlen(rhs.array_pointer) + 1;
		this->array_pointer = new char[len];
		memcpy(this->array_pointer, rhs.array_pointer, len);
	}
	//pass by value for assign operator
	TestClass& operator=(TestClass rhs){
		cout << "Assign operator and Transfer ownership" << std::endl;
		std::swap(this->array_pointer, rhs.array_pointer);
		return *this;
	}

	friend TestClass operator+(const TestClass& lhs, const TestClass& rhs){
		cout << "+ operator is Invoked" << std::endl;
		size_t len = strlen(lhs.array_pointer) + strlen(rhs.array_pointer) + 1;
		char* str = new char[len];
		memcpy(str, lhs.array_pointer, strlen(lhs.array_pointer));
		memcpy(str + strlen(lhs.array_pointer), rhs.array_pointer, strlen(rhs.array_pointer));
		TestClass tmp(str);
		return tmp;	
	}
	char* getArray(){ return array_pointer; }
private:
	char* array_pointer;
};



