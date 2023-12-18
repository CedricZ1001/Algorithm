#include <iostream>
using namespace std;

#include "Factory.h"
using namespace CedricZ::reflect;

#include"testA.h"
#include"testB.h"
int main() {
	Factory* factory = Singleton<Factory>::instance();

	Object* a = factory->create_class("A");
	a->show();

	Object* b = factory->create_class("B");
	b->show();

	return 0;
}