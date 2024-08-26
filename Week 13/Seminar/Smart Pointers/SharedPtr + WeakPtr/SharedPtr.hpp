#pragma once
#include <iostream>

struct Counter
{
	unsigned useCount = 0;
	unsigned weakCount = 0;

	void removeSharedPtr()
	{
		useCount--;
		if (useCount == 0)
		{
			weakCount--;
		}
	}

	void removeWeakPtr()
	{
		weakCount--;
	}

	void addSharedPtr()
	{
		useCount++;
		if (useCount == 1)
		{
			weakCount++;
		}
	}

	void addWeakPtr()
	{
		weakCount++;
	}
};

template<typename T>
class SharedPtr
{
	template <typename T> friend class WeakPtr;

	T* data = nullptr;
	Counter* counter = nullptr;

	void copyFrom(const SharedPtr<T>& other);
	void moveFrom(SharedPtr<T>&& other);
	void free();

public:

	SharedPtr() = default;
	SharedPtr(T* data);

	SharedPtr(const SharedPtr<T>& other);
	SharedPtr& operator=(const SharedPtr<T>& other);

	SharedPtr(SharedPtr<T>&& other) noexcept;
	SharedPtr& operator=(SharedPtr<T>&& other) noexcept;

	~SharedPtr();

	const T& operator*() const;
	T& operator*();

	const T* operator->() const;
	T* operator->();

	bool IsInitialized() const;

};

template<typename T>
void SharedPtr<T>::copyFrom(const SharedPtr<T>& other)
{
	data = other.data;
	counter = other.counter;

	//появява се нов shared ptr към същия обект и го добавяме към counter-а
	if (counter)
	{
		counter->addSharedPtr();
	}
}

template<typename T>
void SharedPtr<T>::moveFrom(SharedPtr<T>&& other)
{
	data = other.data;
	other.data = nullptr;

	counter = other.counter;
	other.counter = nullptr;
}

template<typename T>
void SharedPtr<T>::free()
{
	if (!data && !counter)
	{
		return;
	}

	counter->removeSharedPtr();

	if (counter->useCount == 0)
	{
		delete data;
	}

	if (counter->weakCount == 0)
	{
		delete counter;
	}
}

template<typename T>
SharedPtr<T>::SharedPtr(T* data)
{
	if (data)
	{
		this->data = data;

		counter = new Counter();
		counter->addSharedPtr();
	}
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& other)
{
	copyFrom(other);
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
SharedPtr<T>::~SharedPtr()
{
	free();
}

template<typename T>
const T& SharedPtr<T>::operator*() const
{
	if (!IsInitialized())
	{
		throw std::exception("Nullptr");
	}

	return *data;
}

template<typename T>
T& SharedPtr<T>::operator*()
{
	if (!IsInitialized())
	{
		throw std::exception("Nullptr");
	}

	return *data;
}

template<typename T>
const T* SharedPtr<T>::operator->() const
{
	return data;
}

template<typename T>
T* SharedPtr<T>::operator->()
{
	return data;
}

template<typename T>
bool SharedPtr<T>::IsInitialized() const
{
	return data != nullptr;
}
