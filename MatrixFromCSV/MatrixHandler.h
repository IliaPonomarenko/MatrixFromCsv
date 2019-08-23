#ifndef __MATRIX_HENDLER_HPP__
#define __MATRIX_HENDLER_HPP__


#include "CustomTypes.h"

#include <string>
#include <vector>


class MatrixHandler
{

private:

	

	unsigned m_MatrixSize;

	static const int m_defaultForbiddenValue = 0;

	int * m_verticalIndexesOfForbiddenValue;

	int * m_gorizontalIndexesOfForbiddenValue;

	void calculateMatrixSize(const CustomTypes::IntMatrix const & _arrayWithMatrix) { m_MatrixSize = _arrayWithMatrix.size(); };

	void findIndexesOfForbiddenValue(const CustomTypes::IntMatrix const & _arrayWithMatrix,	const int const & _forbiddenValue = m_defaultForbiddenValue);


public:

	~MatrixHandler();

	void showLinesWithoutForbiddenValue(const CustomTypes::IntMatrix const & _arrayWithMatrix);


};


#endif