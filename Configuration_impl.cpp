/**
* @file Configuration_impl.cpp
* @brief in this file are implmented the methods used to work with Configuration file
* @author Salvatore Muoio
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Debug.h"
#include "libxl.h"
#include "Configuration_impl.h"
#include "Util.h"
#include "BuildTeloc.h"

using namespace libxl;

using namespace std;
static ofstream myfile;


void (*lookuptableTeloc[2])(const type_::CHAR * const s, std::ofstream &myfile) = {&lookuptableTeloc1500, &lookuptableTeloc2500};

Sheet *sheet;

configimpl_::t_configstructimpl *getaccescfgimpl(void)
{
	static configimpl_::t_configstructimpl configstructimpl;
	return(&configstructimpl);
}


void config::configimpl::extract_filename(std::string line, type_::CHAR *filename)
{
	//DEBUG_INFO(1);
  	static char key = ':';
    std::cout<<FUNCTION_NAME<<std::endl;
    std::cout<<line.length()<<std::endl;
    size_t pos = line.find(key);
    //cout<<"pos:"<<pos<<endl;
    DEBUG_DISPLAY(debug_::enable, pos);
    //debug_::dbg_display(pos);
    memcpy(filename, &line.at(pos+1), line.length());
	//filename = name;
	DEBUG_DISPLAY(debug_::enable, filename);
  
}

void config::configimpl::extract_column_compare(std::string line, type_::CHAR *col)
{
	std::cout<<FUNCTION_NAME<<std::endl;
	if(col)
	{
		static char key = ':';
		size_t pos = line.find(key);
		DEBUG_DISPLAY(debug_::enable, pos);
		memcpy(col, &line.at(pos+1), line.length());
		//*col = line.at(pos+1);
		DEBUG_DISPLAY(debug_::enable, col);
	}
}

type_::ebool config::configimpl::find_column(const type_::CHAR *title,  const type_::CHAR *col)
{
	type_::ebool ret = type_::FALSE;
	std::cout<<FUNCTION_NAME<<std::endl;
	if ( strcmp( title, col ) == 0 )
	{
		ret = type_::TRUE;
		DEBUG_DISPLAY(debug_::enable, title);
		DEBUG_DISPLAY(debug_::enable, col);
	}
	return(ret);
}

type_::ebool config::configimpl::parser_kenfile(const type_:: CHAR *col, std::string filename)
{
	type_::ebool find = type_::FALSE;
//	static type_::UINT64 column = 0x0U;
	std::cout<<FUNCTION_NAME<<std::endl;
	std::cout<<"parser_kenfile::filename == "<<filename<<std::endl;
	Book *book = xlCreateXMLBook();
	if(book->load(filename.c_str()))
	{
		std::cout<<"file xlsx"<<std::endl;
		//set the right column where are all teloc components
		// open sheet 0
		sheet = book->getSheet(0);
		for(type_::UINT64 jj = sheet->firstCol(); jj < sheet->lastCol(); ++jj)
		{
			CellType cellType = sheet->cellType(0, jj);
        	const char* s = sheet->readStr(0, jj);
        	std::cout << (s ? s : "null") << " [string]"<<std::endl;
        	if(find_column(s, col) == type_::TRUE)
        	{
				//set column!!!
				getaccescfgimpl()->findcolumn = jj;
				DEBUG_DISPLAY(debug_::enable, getaccescfgimpl()->findcolumn);
		//		column = jj;
			//	DEBUG_DISPLAY(debug_::enable, jj);
				find = type_::TRUE;
				break;		
			}
		}//for
		//scroll_column(column);
	}
	else
		std::cout<<"not file xlsx"<<std::endl;
	return(find);
}

void config::configimpl::scroll_column(const std::string telocode)
{
	//!!!
	std::cout<<FUNCTION_NAME<<std::endl;
	DEBUG_DISPLAY(debug_::enable, getaccescfgimpl()->findcolumn);
	//std::cout<<"telocode == "<<telocode<<std::endl;
	//std::cout<<"convert == "<<util_::ConverTelocCode2Num(telocode)<<std::endl;
	myfile.open ("Teloc.txt",ios::app);
	if(myfile.is_open())
	{
		myfile<< "Teloc is "<<telocode;
		myfile<<"  "<<sheet->name()<<endl;
		for(type_::UINT64 row = sheet->firstRow()+1; row < sheet->lastRow(); row++)
		{
		//
			CellType cellType = sheet->cellType(row, getaccescfgimpl()->findcolumn);
        	const char* s = sheet->readStr(row, getaccescfgimpl()->findcolumn);
        	//std::cout << (s ? s : "null") << " [string]"<<std::endl;
        	// check the code in the string with data for the teloc
        	lookuptableTeloc[util_::ConverTelocCode2Num(telocode)](s, myfile);

		}//for
	}//if
}
