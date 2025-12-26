#ifndef MYUNIQUEPTR_H
#define MYUNIQUEPTR_H
#include <utility>

template <typename T>
class MyUniquePtr {
private:
    T* ptr;

public:
    // Constructor
    explicit MyUniquePtr(T* p = nullptr) : ptr(p) {

    }

    // Destructor
    ~MyUniquePtr() {
        if(ptr != nullptr){
            delete ptr;
        ptr = nullptr;
        }
    }

    // Prohibit copy constructor and copy assignment
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    MyUniquePtr(MyUniquePtr&& other) noexcept {
        ptr = other.ptr; //1. Steal the resource
        other.ptr = nullptr; //2. Leave other in a valid state
    }

    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other)
            if (this != nullptr)
                delete ptr;
        ptr = other.ptr; 
        other.ptr = nullptr; 
        return *this;
    }

    T * get() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    
};

template <typename T, typename... Args>
MyUniquePtr<T> my_make_unique(Args&&... args) {
    return MyUniquePtr<T>(new T(std::forward<Args>(args)...));
}

#endif