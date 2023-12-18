#include "Factory.h"
using namespace CedricZ::reflect;
void Factory::register_class(const string& className, create_object method){
	
	m_classMap[className] = method;
}

Object* Factory::create_class(const string& className)
{
	auto it = m_classMap.find(className);
	if(it == m_classMap.end()){
		return nullptr;
	}
	return it->second();
}
