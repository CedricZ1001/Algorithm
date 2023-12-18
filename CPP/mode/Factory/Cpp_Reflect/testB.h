#pragma once
#pragma once
#include<iostream>
#include<string>
using namespace std;

#include"Register.h"
using namespace CedricZ::reflect;
class B:public Object {
public:
	B() {}
	~B() {}

	void show() {
		cout << "B" << endl;
	}

	string m_name;
};
REGISTER_CLASS(B);