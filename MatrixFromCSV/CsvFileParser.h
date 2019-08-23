#ifndef __CSV_FILE_PARSER_HPP__
#define __CSV_FILE_PARSER_HPP__


#include "CustomTypes.h"

#include <string>
#include <vector>


class CsvFileParser 
{

public:
	
	const CustomTypes::IntMatrix parseTo2DimVector(const CustomTypes::StringMatrix const & _vectorOfSting) const;

};


#endif
