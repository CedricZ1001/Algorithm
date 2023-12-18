#pragma once
#include"Factory.h"
namespace CedricZ {
namespace reflect {

	class Register{
	public:
		Register(const string& className, create_object method) {
			Factory* factory = Singleton<Factory>::instance();
			factory->register_class(className, method);

			//Singleton<Factory>::instance()->register_class(className, method);
		}
	};

#define REGISTER_CLASS(className)										 \
	Object * createObject##className()									 \
	{																	 \
		Object* obj = new className();									 \
		return obj;														 \
	}																	 \
	Register myRegister##className(#className, createObject##className)	 \

}
}