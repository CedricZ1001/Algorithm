#include <mutex>

namespace CedricZ {
    namespace utility {

        template <typename T>
        class Singleton {
        public:
            static T* instance() {
                std::call_once(initFlag, &Singleton::init);
                return m_instance;
            }

        private:
            Singleton() {}
            Singleton(const Singleton<T>&) = delete;
            Singleton<T>& operator=(const Singleton<T>&) = delete;
            ~Singleton() {}

            static void init() {
                m_instance = new T();
            }

            static std::once_flag initFlag;
            static T* m_instance;
        };

        template <typename T>
        std::once_flag Singleton<T>::initFlag;

        template <typename T>
        T* Singleton<T>::m_instance = nullptr;

    } // namespace utility
} // namespace CedricZ
