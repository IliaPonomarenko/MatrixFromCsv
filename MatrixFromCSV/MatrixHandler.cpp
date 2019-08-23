#include "MatrixHandler.h"

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


MatrixHandler::~MatrixHandler()
{
	delete[] m_verticalIndexesOfForbiddenValue;
	delete[] m_gorizontalIndexesOfForbiddenValue;
}

void MatrixHandler::findIndexesOfForbiddenValue(const CustomTypes::IntMatrix const & _arrayWithMatrix, const int const & _forbiddenValue)
{
	m_verticalIndexesOfForbiddenValue = new int[m_MatrixSize];
	m_gorizontalIndexesOfForbiddenValue = new int[m_MatrixSize];

	for (size_t i = 0; i < m_MatrixSize; i++)
		for (size_t j = 0; j < m_MatrixSize; j++)
			if (_arrayWithMatrix[i][j] == _forbiddenValue)
			{
				m_verticalIndexesOfForbiddenValue[i] =  i;
				m_gorizontalIndexesOfForbiddenValue[j] = j;
			}
}

void MatrixHandler::showLinesWithoutForbiddenValue(const CustomTypes::IntMatrix const & _arrayWithMatrix)
{
	calculateMatrixSize(_arrayWithMatrix);

	findIndexesOfForbiddenValue(_arrayWithMatrix);

	for (size_t i = 0; i < m_MatrixSize; i++)
	{
		if (i != m_gorizontalIndexesOfForbiddenValue[i])
		{
			for (size_t j = 0; j < m_MatrixSize; j++)
				std::cout << _arrayWithMatrix[j][i] << ' ';

			std::cout << std::endl;
		}
		if (i != m_verticalIndexesOfForbiddenValue[i])
		{
			for (size_t j = 0; j < m_MatrixSize; j++)
				std::cout << _arrayWithMatrix[i][j] << ' ';
				std::cout << std::endl;
		}

	}

	for (size_t k = 0; k < m_MatrixSize * 2; k++) 
	{
		std::string diagonalWithoutForbidden;

		for (size_t j = 0; j <= k; j++) 
		{
			int i = k - j;

			if (i < m_MatrixSize && j < m_MatrixSize)
				if (_arrayWithMatrix[i][j] != 0)
				{
					auto x = std::to_string(_arrayWithMatrix[std::abs(i)][(j)]);
					x.push_back(' ');
					diagonalWithoutForbidden += x;
				}
				else
				{
					diagonalWithoutForbidden.clear();
					break;
				}
		}

		if(!diagonalWithoutForbidden.empty())
			std::cout << diagonalWithoutForbidden << std::endl;
	}

	int end = 0 - m_MatrixSize;
	for (int k = m_MatrixSize - 1; k > end; k--) 
	{
		std::string diagonalWithoutForbidden;

		for (int j = m_MatrixSize - 1; j >= k; j--)
		{
			int i = j - k;

			if (i < m_MatrixSize && j < m_MatrixSize )
				if (_arrayWithMatrix[std::abs(i)][std::abs(j)] != 0)
				{
					auto x = std::to_string(_arrayWithMatrix[std::abs(i)][std::abs(j)]);
					x.push_back(' ');
					diagonalWithoutForbidden += x;
				}
				else
				{
					diagonalWithoutForbidden.clear();
					break;
				}
		}
		if (!diagonalWithoutForbidden.empty())
			std::cout << diagonalWithoutForbidden << std::endl;
	}
}

