#pragma once
#include <iostream>

template<typename T>
class Matrix
{
private:
	T** matrix;
	unsigned rows;
	unsigned cols;

	void copyFrom(const Matrix& other);
	void moveFrom(Matrix&& other);
	void free();
	void fill(unsigned rows, unsigned cols);

public:
	Matrix();
	Matrix(unsigned rows, unsigned cols);

	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);

	Matrix(Matrix&& other) noexcept;
	Matrix& operator=(Matrix&& other) noexcept;

	~Matrix();

	void setAt(unsigned x, unsigned y, const T& element);
	void setAt(unsigned x, unsigned y, T&& element);

	const T& getAt(unsigned int x, unsigned y) const;
	T& getAt(unsigned x, unsigned y);


	void transpose();
};

template<typename T>
void Matrix<T>::copyFrom(const Matrix<T>& other)
{
	fill(other.rows, other.cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

template<typename T>
void Matrix<T>::moveFrom(Matrix<T>&& other)
{
	matrix = other.matrix;
	other.matrix = nullptr;

	rows = other.rows;
	cols = other.cols;

	other.rows = other.cols = 0;
}

template<typename T>
void Matrix<T>::free()
{
	for (int i = 0; i < rows; i++)
	{
		delete matrix[i];
	}

	delete[] matrix;
}

template<typename T>
void Matrix<T>::fill(unsigned rows, unsigned cols)
{
	this->rows = rows;
	this->cols = cols;

	matrix = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new T[cols];
	}
}

template<typename T>
Matrix<T>::Matrix()
{
	fill(2, 2);
}

template<typename T>
Matrix<T>::Matrix(unsigned rows, unsigned cols)
{
	fill(rows, cols);
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other)
{
	copyFrom(other);
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}


template<typename T>
Matrix<T>::Matrix(Matrix<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
Matrix<T>::~Matrix()
{
	free();
}

template<typename T>
void Matrix<T>::setAt(unsigned x, unsigned y, const T& element)
{
	x--;
	y--;

	if (x >= rows || y >= cols)
	{
		throw std::out_of_range("Invalid index");
	}

	matrix[x][y] = element;
}

template<typename T>
void Matrix<T>::setAt(unsigned x, unsigned y, T&& element)
{
	x--;
	y--;

	if (x >= rows || y >= cols)
	{
		throw std::out_of_range("Invalid index");
	}

	matrix[x][y] = std::move(element);
}

template<typename T>
const T& Matrix<T>::getAt(unsigned x, unsigned y) const
{
	x--;
	y--;

	if (x >= rows || y >= cols)
	{
		throw std::out_of_range("Invalid index");
	}

	return matrix[x][y];
}

template<typename T>
T& Matrix<T>::getAt(unsigned x, unsigned y)
{
	x--;
	y--;

	if (x >= rows || y >= cols)
	{
		throw std::out_of_range("Invalid index");
	}

	return matrix[x][y];
}

template<typename T>
void Matrix<T>::transpose()
{
	T** newMatrix = new T * [cols];
	for (int i = 0; i < cols; i++)
	{
		newMatrix[i] = new T[rows];
		for (int j = 0; j < rows; j++)
		{
			newMatrix[i][j] = matrix[j][i];
		}
	}

	free();
	matrix = newMatrix;
	newMatrix = nullptr;

	std::swap(rows, cols);
}

