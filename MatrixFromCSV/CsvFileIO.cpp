#include "CsvFileIO.h"
#include "Messages.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>


const void CsvFileIO::isOpen(const std::fstream const & _stream) const
{
	if (!_stream.is_open())
		throw std::ios_base::failure(Messages::AccessException);
};

void CsvFileIO::createDefaultCsv(const std::string & _path2Csv) const
{
	std::fstream stream(_path2Csv, std::ios::out);

	isOpen(stream);
			
	stream << m_defaultData;
	
	stream.close();
}

const std::vector<std::string> CsvFileIO::getData(const std::string & _path2Csv) const
{
	std::vector<std::string> vectorOfString;
	std::string lineFromStream;

	std::fstream stream(_path2Csv, std::ios::in);

	isOpen(stream);

	while (std::getline(stream, lineFromStream))
		vectorOfString.push_back(lineFromStream);

	return vectorOfString;
}
