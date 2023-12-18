#pragma once

#include <string>
#include <map>
#include"Singleton.h"

using namespace std;
using namespace CedricZ::utility;


namespace CedricZ {
namespace reflect {
	
	class Object {
	public:
		Object() {}
		virtual ~Object() {}

		virtual void show() = 0;
	};

	typedef Object* (*create_object)(void);

	class Factory {
		friend class Singleton<Factory>;
	public:
		void register_class(const string& className, create_object method);
		Object* create_class(const string& className);

	private:
		Factory() {}
		~Factory() {}

		map<string, create_object> m_classMap;
	};

}
}