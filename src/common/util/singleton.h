#ifndef RRG_SINGLETON_H
#define RRG_SINGLETON_H

namespace RRG {

    template <typename T> class Singleton {
        static T* ptrSingleton;

    public:

        Singleton(T* ptr) {
            CS_ASSERT(ptrSingleton == 0);
            ptrSingleton = ptr;
        }

        // Use this constructor only when the derived class is only deriving from Singleton

        Singleton(void) {
            CS_ASSERT(ptrSingleton == 0);
            ptrSingleton = (T*) (this);
        }

        ~Singleton() {
            CS_ASSERT(ptrSingleton != 0);
            ptrSingleton = NULL;
        }

        static T& GetSingleton(void) {
            return *ptrSingleton;
        }

        static T* GetSingletonPtr(void) {
            return ptrSingleton;
        }
    };
    template <typename T> T* Singleton<T>::ptrSingleton = 0;

}

#endif