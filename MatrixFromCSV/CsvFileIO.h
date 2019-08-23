#ifndef __CSV_FILEIO_HPP__
#define __CSV_FILEIO_HPP__


#include <string>
#include <vector>


class CsvFileIO
{
	
private:


	const std::string m_defaultData
	{ 
		"1,2,3,4\n1,12,13,14\n0,3,4,5\n5,6,7,0" 
	};

	const void isOpen(const std::fstream const & _stream) const;


public:


	void createDefaultCsv(const std::string const & _path2Csv) const;

	const std::vector<std::string> getData(const std::string const & _path2Csv) const;
	
};

#endif
