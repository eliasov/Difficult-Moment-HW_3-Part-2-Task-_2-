#pragma once
#include "Task_2 Class(Part 2).h"

template<typename T>
Matrix<T>::Matrix(int size, std::vector<T> values)
{
	size_ = size;
	matrix_.resize(size);
	for (int i = 0; i < size; ++i)
	{
		int offset = i * size, counter = 0;
		while (counter < size)
		{
			matrix_[i].push_back(values[offset]);
			++offset; ++counter;
		}
	}
}

template<typename T>
std::vector <std::vector<T>> Matrix<T>::GetMinor(int line, int row)
{
	std::vector <std::vector<T>> copiedMatrix(2);
	int lineOffset = 0;
	for (int i = 0; i < size_ - 1; ++i)
	{
		if (i == line)
			lineOffset = 1;
		int rowOffset = 0;
		for (int j = 0; j < size_ - 1; ++j)
		{
			if (j == row)
				rowOffset = 1;
			copiedMatrix.at(i).push_back(matrix_[i + lineOffset][j + rowOffset]);
		}
	}
	return copiedMatrix;
}

template<typename T>
std::vector<std::vector<T>> Matrix<T>::GetMatrix() const
{
	return matrix_;
}

template<typename T>
T Matrix<T>::Determinant(int size, std::vector<std::vector<T>>& matrix)
{
	std::vector<std::vector<T>> tmpMatrix;
	int sign = 1, decrementedSize = size - 1;
	T result = 0;

	if (size == Dimensions::One_Dimensional)
		return matrix.at(0).at(0);
	else if (size == Dimensions::Two_Dimensional)
		return ((matrix.at(0).at(0) * matrix.at(1).at(1)) - (matrix.at(1).at(0) * matrix.at(0).at(1)));
	else
	{
		for (int i = 0; i < size; ++i)
		{
			tmpMatrix = GetMinor(i, 0);
			result += sign * matrix.at(i).at(0) * Determinant(decrementedSize, tmpMatrix);
			sign = -sign;
		}
		std::cout << "Determinant: ";
	}
	return result;
	
}

template<typename T>
void Matrix<T>::PrintMatrix()
{
	for (auto line : matrix_)

	{
		for (T value : line)
			std::cout << value << " ";
		std::cout << std::endl;
	}
}
 
template<typename T>
void Matrix<T>::PrintMatrix(std::vector<std::vector<T>>& matrix)
{
	for (auto line : matrix)
	{
		for (T value : line)
			std::cout << value << " ";
		
	}
}