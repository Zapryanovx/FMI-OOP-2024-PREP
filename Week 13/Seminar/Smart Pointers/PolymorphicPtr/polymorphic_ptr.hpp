#pragma once

template<typename T>
class polymorphic_ptr
{
private:
	T* ptr = nullptr;

	void copyFrom(const polymorphic_ptr& other);
	void moveFrom(polymorphic_ptr&& other);
	void free();

public:
	polymorphic_ptr() = default;
	polymorphic_ptr(T* ptr);

	polymorphic_ptr(const polymorphic_ptr& other);
	polymorphic_ptr& operator=(const polymorphic_ptr& other);

	polymorphic_ptr(polymorphic_ptr&& other) noexcept;
	polymorphic_ptr& operator=(polymorphic_ptr&& other) noexcept;

	T* operator->();
	const T* operator->() const;

	T& operator*();
	const T& operator*() const;

	operator bool() const;

	T* get();
	const T* get() const;

	void reset();
	void reset(T* ptr);

	~polymorphic_ptr();
};

template<typename T>
void polymorphic_ptr<T>::copyFrom(const polymorphic_ptr<T>& other)
{
	ptr = (other.ptr == nullptr) ? nullptr : other.clone();
}

template<typename T>
void polymorphic_ptr<T>::moveFrom(polymorphic_ptr&& other)
{
	ptr = other.ptr;
	other.ptr = nullptr;
}

template<typename T>
void polymorphic_ptr<T>::free()
{
	delete ptr;
	ptr = nullptr;

}

template<typename T>
polymorphic_ptr<T>::polymorphic_ptr(T* ptr) : ptr(ptr) {}

template<typename T>
polymorphic_ptr<T>::polymorphic_ptr(const polymorphic_ptr<T>& other)
{
	copyFrom(other);
}

template<typename T>
polymorphic_ptr<T>& polymorphic_ptr<T>::operator=(const polymorphic_ptr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
polymorphic_ptr<T>::polymorphic_ptr(polymorphic_ptr&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
polymorphic_ptr<T>& polymorphic_ptr<T>::operator=(polymorphic_ptr&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
polymorphic_ptr<T>::~polymorphic_ptr()
{
	free();
}

template<typename T>
T* polymorphic_ptr<T>::operator->()
{
	return ptr;
}

template<typename T>
const T* polymorphic_ptr<T>::operator->() const
{
	return ptr;
}

template<typename T>
T& polymorphic_ptr<T>::operator*()
{
	if (!ptr)
	{
		throw std::exception("nullptr");
	}

	return *ptr;
}

template<typename T>
const T& polymorphic_ptr<T>::operator*() const
{
	if (!ptr)
	{
		throw std::exception("nullptr");
	}

	return *ptr;
}

template<typename T>
void polymorphic_ptr<T>::reset()
{
	free();
}

template<typename T>
void polymorphic_ptr<T>::reset(T* ptr)
{
	free();
	this->ptr = ptr;
}

template<typename T>
polymorphic_ptr<T>::operator bool() const
{
	return (ptr != nullptr);
}

template<typename T>
T* polymorphic_ptr<T>::get()
{
	return ptr;
}

template<typename T>
const T* polymorphic_ptr<T>::get() const
{
	return ptr;
}