#pragma once
#include<iostream>
#include<string>
using namespace std;

#include"Register.h"
using namespace CedricZ::reflect;

class A : public Object{
public:
	A() {}
	~A() {}

	void show() {
		cout << "testA" <<endl;
	}

	string m_name;
};

REGISTER_CLASS(A);