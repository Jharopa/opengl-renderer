#pragma once

#include <assert.h>

template <class T>
class Singleton
{
    public:
        static T& getInstance()
        {
            if(!m_instance)
            {
                m_instance = new T();
            }
            
            assert(m_instance);

            return *m_instance;
        }

    protected:
        // Any derived class can implement thier own ctor/dtor
        Singleton() {}
        ~Singleton() {}

    protected:
        static T* m_instance;

    private:
        // Any derived class can't use copy operations
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
};

// Static class members must be instansiated
template <class T>
T* Singleton<T>::m_instance = nullptr;
