#pragma once

template<typename T>
class Optional
{
	T* data = nullptr;
	
	void copyFrom(const Optional& other);
	void free();

public:

	Optional() = default;
	Optional(const T& obj);

	Optional(const Optional& other);
	Optional& operator=(const Optional& other);

	const T& operator*() const;
	T& operator*();

	operator bool() const;

	const T& value() const;
	bool has_value() const;
	const T& value_or(const T& obj) const;

	void reset();

	~Optional();
};

template<typename T>
void Optional<T>::copyFrom(const Optional<T>& other)
{
	if (other.has_value())
	{
		data = new T(*other.data);
	}

	else
	{
		data = nullptr;
	}
}

template<typename T>
void Optional<T>::free()
{
	delete data;
	data = nullptr;
}

template<typename T>
Optional<T>::Optional(const T& obj) : data(new T(obj)){}

template<typename T>
Optional<T>::Optional(const Optional<T>& other)
{
	copyFrom(other);
}

template<typename T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
const T& Optional<T>::operator*() const
{
	if (!has_value())
	{
		throw std::runtime_error("No value");
	}

	return *data;
}

template<typename T>
T& Optional<T>::operator*()
{
	if (!has_value())
	{
		throw std::runtime_error("No value");
	}

	return *data;
}

template<typename T>
Optional<T>::operator bool() const
{
	return has_value();
}

template<typename T>
const T& Optional<T>::value() const
{
	if (!has_value())
	{
		throw std::runtime_error("No value");
	}

	return *data;
}

template<typename T>
bool Optional<T>::has_value() const
{
	return data != nullptr;
}

template<typename T>
const T& Optional<T>::value_or(const T& obj) const
{
	if (has_value())
	{
		return *data;
	}

	return obj;
}

template<typename T>
void Optional<T>::reset()
{
	free();
}

template<typename T>
Optional<T>::~Optional()
{
	free();
}

