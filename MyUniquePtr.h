#ifndef MYUNIQUEPTR_H
#define MYUNIQUEPTR_H

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



#endif