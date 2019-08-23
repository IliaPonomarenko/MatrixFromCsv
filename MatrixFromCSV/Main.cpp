#include "CsvFileIO.h"
#include "CsvFileParser.h"
#include "MatrixHandler.h"
#include "CustomTypes.h"

#include <string>
#include <vector>


int main()
{
	CsvFileIO file;
	CsvFileParser parser;
	MatrixHandler matrix;

	file.createDefaultCsv("matrix.csv");
	
	CustomTypes::StringMatrix stringMatrix = file.getData("matrix.csv");

	CustomTypes::IntMatrix vectorMatrix = parser.parseTo2DimVector(stringMatrix);

	matrix.showLinesWithoutForbiddenValue(vectorMatrix);
}