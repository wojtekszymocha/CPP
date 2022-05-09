#pragma once

#include <iostream>

struct NullPtrDereferenceException : public std::runtime_error {
    NullPtrDereferenceException()
        : std::runtime_error{"Fatal error, cannot dereference nullptr"} {}
};


template <typename T>
class Unique_ptr
{
private:
    T *ptr_{nullptr};

public:
    Unique_ptr(T *ptr = nullptr);

    Unique_ptr(const Unique_ptr<T>&) = delete;
    Unique_ptr<T>& operator=(const Unique_ptr<T>&) = delete;


    Unique_ptr(Unique_ptr<T> &&other_ptr);
    Unique_ptr<T>& operator=(Unique_ptr<T> &&other_ptr);

    T& operator*() const;  
    T* operator->() const;
    T* get() const;
    T* release();
    void reset(T *tempPtr);
    ~Unique_ptr();
};

template <typename T>
Unique_ptr<T>::Unique_ptr(T *ptr)
    : ptr_(ptr) {
}

template <typename T>
Unique_ptr<T>::Unique_ptr(Unique_ptr<T> &&other_ptr)
    : ptr_(other_ptr.release()) {
}

template <typename T>
Unique_ptr<T> &Unique_ptr<T>::operator=(Unique_ptr<T> &&other_ptr) {
    if (this != &other_ptr)
    {
        delete ptr_;
        ptr_ = other_ptr.ptr_;
        other_ptr.ptr_ = nullptr;
    }
    return *this;
}

template <typename T>
T& Unique_ptr<T>::operator*() const {
    if (!ptr_) {
        throw NullPtrDereferenceException();
    }
    return *ptr_;
}

template <typename T>
T* Unique_ptr<T>::operator->() const {
    return ptr_;
}

template <typename T>
T* Unique_ptr<T>::get() const {
    return ptr_;
}

template <typename T>
T* Unique_ptr<T>::release() {
    T *tempPtr = ptr_;
    ptr_ = nullptr;
    return tempPtr;
}

template <typename T>
void Unique_ptr<T>::reset(T *tempPtr) {
    delete ptr_;
    ptr_ = tempPtr;
}

template <typename T>
Unique_ptr<T>::~Unique_ptr() {
    delete ptr_;
}

