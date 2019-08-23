#include "CsvFileParser.h"

#include <vector>
#include <string>
#include <sstream>


const CustomTypes::IntMatrix CsvFileParser::parseTo2DimVector(const CustomTypes::StringMatrix const & _vectorOfSting) const
{
	CustomTypes::IntMatrix twoDimVectorWithMatrix(_vectorOfSting.size());
	std::string elementOfMatrix;

	size_t gorizontalSizeOfMatrix = _vectorOfSting.size();

	for (size_t i = 0; i < gorizontalSizeOfMatrix; i++)
	{
		size_t verticalSizeOfMatrix = _vectorOfSting[i].size();

		for (size_t j = 0; j <= verticalSizeOfMatrix; j++)
			if (_vectorOfSting[i][j] == ',' || j == verticalSizeOfMatrix)
			{
				twoDimVectorWithMatrix[i].push_back(stoi(elementOfMatrix));
				elementOfMatrix.clear();
			}
			else
				elementOfMatrix.push_back(_vectorOfSting[i][j]);
	}

	return twoDimVectorWithMatrix;
}


//Alternative way
/*
std::stringstream iss;
	std::string empty = "";

	for (size_t i = 0; i < _vectorOfSting.size(); i++)
	{
		iss.str(empty);
		iss.clear();

		iss << _vectorOfSting[i];
		std::string s;

		while (getline(iss, s, ','))
		{
			int var = stoi(s);
			twoDimVectorWithMatrix[i].push_back(var);
		}
	}
*/