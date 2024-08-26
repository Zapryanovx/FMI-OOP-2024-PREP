#include <iostream>

template<typename T>
class MyQueue
{
	T* data;
	size_t capacity;
	size_t size;

	size_t get;
	size_t put;

	void resize();

	void copyFrom(const MyQueue& other);
	void moveFrom(MyQueue&& other);
	void free();

public:
	MyQueue();

	MyQueue(const MyQueue<T>& other);
	MyQueue<T>& operator=(const MyQueue<T>& other);

	MyQueue(MyQueue<T>&& other) noexcept; 
	MyQueue<T>& operator=(MyQueue<T>&& other) noexcept;

	void push(const T& obj);
	void push(T&& obj);
	void pop();

	const T& peek() const;
	bool isEmpty() const;

	~MyQueue();
};

template<class T>
void MyQueue<T>::copyFrom(const MyQueue<T>& other)
{
	data = new T[other.capacity];
	for (int i = 0; i < other.capacity; i++)
	{
		data[i] = other.data[i];
	}

	size = other.size;
	capacity = other.capacity;

	get = other.get;
	put = other.put;

}

template<class T>
void MyQueue<T>::moveFrom(MyQueue<T>&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;

	get = other.get;
	put = other.put;

	other.size = other.capacity = 0;
}

template<class T>
void MyQueue<T>::free()
{
	delete[] data;
}

template<class T>
void MyQueue<T>::resize()
{
	T* newData = new T[capacity * 2];
	for (int i = 0; i < capacity; i++)
	{
		newData[i] = data[get];
		(++get) %= capacity;
	}

	delete[] data;
	data = newData;
	capacity *= 2;

	get = 0;
	put = size;

}

template<typename T>
MyQueue<T>::MyQueue()
{
	capacity = 4;
	data = new T[capacity];
	size = 0;
	get = put = 0;
}

template<typename T>
MyQueue<T>::MyQueue(const MyQueue& other)
{
	copyFrom(other);
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
MyQueue<T>::MyQueue(MyQueue<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
MyQueue<T>::~MyQueue()
{
	free();
}

template<typename T>
void MyQueue<T>::push(const T& obj)
{
	if (size == capacity)
	{
		resize();
	}

	data[put] = obj; //operator=
	(++put) %= capacity;
	size++;
}

template<typename T>
void MyQueue<T>::push(T&& obj)
{
	if (size == capacity)
	{
		resize();
	}

	data[put] = std::move(obj); //move operator=
	(++put) %= capacity;
	size++;
}

template<typename T>
bool MyQueue<T>::isEmpty() const
{
	return size == 0;
}

template<typename T>
const T& MyQueue<T>::peek() const
{
	if(isEmpty())
	{
		throw std::logic_error("Empty queue!");
	}

	return data[get];
}

template<typename T>
void MyQueue<T>::pop()
{
	if (isEmpty())
	{
		throw std::logic_error("Empty queue!");
	}

	(++get) %= capacity;
	size--;
}