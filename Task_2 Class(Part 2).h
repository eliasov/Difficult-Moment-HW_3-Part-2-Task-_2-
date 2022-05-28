#pragma once
#include <iostream>
#include <list>
#include <vector>


template<typename T>
class Matrix
{
public:

	Matrix(int size, std::vector<T> values);

	std::vector <std::vector<T>> GetMinor(int line, int row);

	std::vector<std::vector<T>> GetMatrix() const;

	T Determinant(int size, std::vector<std::vector<T>>& matrix);

	void PrintMatrix();

	void PrintMatrix(std::vector<std::vector<T>>& matrix);

private:

	int size_;
	std::vector<std::vector<T>> matrix_;
	enum Dimensions
	{
		One_Dimensional = 1,
		Two_Dimensional
	};
};