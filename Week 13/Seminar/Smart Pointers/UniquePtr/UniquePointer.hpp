#include <iostream>

template<typename T>
class UniquePointer
{
	T* ptr;

	void moveFrom(UniquePointer&& other);
	void free();

public:
	UniquePointer(const T* ptr);

	UniquePointer(const UniquePointer& other) = delete;
	UniquePointer& operator=(const UniquePointer& other) = delete;

	UniquePointer(UniquePointer&& other) noexcept;
	UniquePointer& operator=(UniquePointer&& other) noexcept;

	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;

	~UniquePointer();
  
};

template<typename T>
void UniquePointer<T>::moveFrom(UniquePointer<T>&& other)
{
	ptr = other.ptr;
	other.ptr = nullptr;
}

template<typename T>
void UniquePointer<T>::free()
{
	delete ptr;
}

template<typename T>
UniquePointer<T>::UniquePointer(const T* ptr): ptr(ptr) {}

template<typename T>
UniquePointer<T>::UniquePointer(UniquePointer<T>&& other) const
{
	moveFrom(std::move(other));
}

template<typename T>
UniquePointer<T>& UniquePointer<T>::operator=(UniquePointer<T>&& other) noexcept
{
	if(this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
T& UniquePointer<T>::operator*()
{
	(*ptr)++;
	return *ptr;
}

template<typename T>
const T& UniquePointer<T>::operator*() const
{
	return *ptr;
}

template <typename T>
T* UniquePointer<T>::operator->()
{
	return ptr;
}

template <typename T>
const T* UniquePointer<T>::operator->() const
{
	return ptr;
}

template<typename T>
UniquePointer<T>::~UniquePointer()
{
	free();
}
