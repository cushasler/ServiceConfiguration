/**
* @file Configuration_impl.cpp
* @brief in this file are implemented the methods used to work with Configuration file
* @author Salvatore Muoio
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <sstream>
#include "Debug.h"
#include "libxl.h"
#include "Configuration_impl.h"
#include "Util.h"
#include "BuildTeloc.h"

using namespace libxl;

using namespace std;
static ofstream myfile;

static void reset_filestruct(configimpl_::t_filestruct *ptr);
static void write_file(ofstream &file, configimpl_::t_filestruct *ptr);
void (*lookuptableTeloc[2])(const type_::CHAR * const s, type_::UINT64 index, std::ofstream &myfile) = {&lookuptableTeloc1500, &lookuptableTeloc2500};

Sheet *sheet;

configimpl_::t_configstructimpl *getaccescfgimpl(void)
{
	static configimpl_::t_configstructimpl configstructimpl;
	return(&configstructimpl);
}

configimpl_::t_filestruct *getfilestruct(void)
{
	static configimpl_::t_filestruct filestructimpl;
	return(&filestructimpl);
}

void closefile(void)
{
	myfile.close();
}


void config::configimpl::extract_filename(std::string line, type_::CHAR *filename, type_::CHAR* assemblycode)
{
	//DEBUG_INFO(1);
  	static char key = ':';
  	static type_::UINT64 len = 13;
    std::cout<<FUNCTION_NAME<<std::endl;
    std::cout<<line.length()<<std::endl;
    size_t pos = line.find(key);
    //cout<<"pos:"<<pos<<endl;
    //DEBUG_DISPLAY(debug_::enable, pos);
    //debug_::dbg_display(pos);
    std::cout<<"line :: "<<line<<std::endl;
    memcpy(filename, &line.at(pos+1), line.length());
	//filename = name;
 	//DEBUG_DISPLAY(debug_::enable, filename);
	memcpy(assemblycode, &line.at(pos+1), 13);

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
				//set colucreate_main_configmn!!!
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
	static type_::UINT64 index = 0;
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
        	lookuptableTeloc[util_::ConverTelocCode2Num(telocode)](s, index, myfile);

		}//for
	}//if
	index++;
}

type_::UINT64 config::configimpl::getsizeTeloc(void)
{
	return(TELOC_BOARD);
}

#define FAMILY_TELOC_1500_SIZE 11

void config::configimpl::create_template(ofstream &osheet)
{
	const char* table[FAMILY_TELOC_1500_SIZE] = FAMILY_TELOC_1500;
	const std::string separator = ";";
	char *s;
	// write the family
	if(osheet.is_open())
	{
		osheet<<"Asswmbly Code";
		osheet<<separator;
		osheet<<separator;
		for(type_::UINT64 ii = 0; ii < FAMILY_TELOC_1500_SIZE; ii++)
		{
			//std::cout<< "table["<<ii<<"] = "<<table[ii]<<std::endl;
			osheet<<table[ii];
			osheet<<separator;
		}//for
		osheet<<endl;
	}//if
}

void config::configimpl::create_teloc_assembly(const char *s, Sheet *osheet, type_::UINT64 row)
{
	static char assembly_code[13] = {0};
	{
		osheet->writeStr(row+1, 0, s);
	}//if

}

void write_file(ofstream &file, configimpl_::t_filestruct *ptr)
{

 	const std::string separator = ";";
	if(file.is_open())
	{
		file<<ptr->assembly_code;
		file<<separator;
		file<<ptr->spare;
		file<<separator;
		file<<ptr->posu;
		file<<separator;
		file<<ptr->core;
		file<<separator;
		file<<ptr->ioco;
		file<<separator;
		file<<ptr->daio;
		file<<separator;
		file<<ptr->rebo;
		file<<separator;
		file<<ptr->sabo;
		file<<separator;
		file<<ptr->mvb;
		file<<separator;
		file<<ptr->cpm;
		file<<separator;
		file<<ptr->sram;
		file<<separator;
		file<<ptr->flash;
		file<<separator;
		file<<ptr->backplane;
		file<<separator;
		file<<endl;
	}
	reset_filestruct(ptr);
}

void reset_filestruct(configimpl_::t_filestruct *ptr)
{
	ptr->assembly_code = "";
	ptr->spare = "";
	ptr->posu = "";
	ptr->core = "";
	ptr->ioco = "";
	ptr->daio = "";
	ptr->rebo = "";
	ptr->sabo = "";
	ptr->mvb = "";
	ptr->cpm = "";
	ptr->sram = "";
	ptr->flash = "";
	ptr->backplane = "";
}


void config::configimpl::create_output_file(std::vector<std::string> col, ofstream &file)
{
	//std::vector<std::string> row;
	static std::string assembly = "";
	//static type_::ebool toogle = type_::FALSE;
	//column = col;
	std::cout<<"function create_output_file "<<std::endl;
	std::cout<<col[0]<<std::endl;
	std::cout<<assembly<<std::endl;
	if(col[0] != "")
	{
		if(col[0] != assembly)
		{
		//toogle = type_::TRUE;
			std::cout<<"assembly = "<<assembly<<std::endl;
			std::cout<<"col[0] = "<<col[0]<<std::endl;
 			//column.push_back(col[0]);
			assembly = col[0];
 			write_file(file, getfilestruct());
			getfilestruct()->assembly_code = assembly;
		}
		std::cout<<"col[8] = "<<col[8]<<std::endl;
			extract_family(col[8], file, getfilestruct());
	}

}

void config::configimpl::extract_version(std::string code, std::string &variant)
{
	variant = code.substr(10,3);
	std::cout<<"extract_version::variant = "<<variant<<std::endl;

}



void config::configimpl::extract_family(std::string code, ofstream &osheet,configimpl_::t_filestruct *ptr)
{
	std::string family;
	std::string variant;
	std::string name;
	type_::UINT64 pos = 0x0U;
	family = code.substr(5,5);
	std::cout<<"family = "<<family<<std::endl;
	// verify
	//lookuptablefamily(family);
	if(lookuptablefamily(family, name) == type_::TRUE)
	{
		// extract the version
		extract_version(code, variant);
		pos = lookuptableposition(name);
		std::cout<<"pos = "<<pos<<std::endl;
		if(pos > 0)
		{
			//Check the right position
			std::string lcode = code.substr(7,7);
			std::cout<<"extract_family::variant = "<<variant<<std::endl;
			write_variant(pos, lcode, ptr);
			//osheet<<variant;
			//write variant in the file!!!

		}
	}
}

void config::configimpl::write_variant( type_::UINT64 pos, std::string variant, configimpl_::t_filestruct *ptr)
{
	const std::string common = ", ";
	std::string tmp = "";
	tmp = variant;
	switch(pos)
	{
		case 3:
			ptr->posu += tmp + common;
		break;
		case 4:
			ptr->core += tmp + common;
		break;
		case 5:
			ptr->ioco += tmp + common;
		break;
		case 6:
			ptr->daio += tmp + common;
		break;
		case 7:
			ptr->rebo += tmp + common;
		break;
		case 8:
			ptr->sabo += tmp + common;
		break;
		case 9:
			ptr->mvb += tmp + common;
		break;
		case 10:
			ptr->cpm += tmp + common;
		break;
		case 11:
			ptr->sram += tmp + common;
		break;
		case 12:
			ptr->flash += tmp + common;
		break;
		case 13:
			ptr->backplane += tmp + common;
		break;
		default:
			break;
	}
	tmp = "";
}

static vector<string> create_row(std::string line)
{
	vector<string> lrow;
	std::string word;
	std::cout<<"create_row line = "<<line<<std::endl;
	//getline()
	lrow.clear();
	stringstream s(line);
	while(getline(s, word, ';'))
	{
		lrow.push_back(word);
		std::cout<<"word = "<<word<<std::endl;
	}
	return(lrow);
}

static type_::UINT64 create_code(std::vector<string> row)
{
	type_::UINT64 lcode = 0x0U;
	if(row.at(0) != "")
	{
		for(type_::UINT64 jj = 2; jj < 12; jj++)
		{
			if (row.at(jj) != "")
				lcode += 1<<(jj-2);
		}
	}
	std::cout<<"lcode = "<<lcode<<std::endl;
	return(lcode);
}


static void create_main_config(std::string line)
{
	//--->>>
	vector<string> row;
	type_::UINT64 codeconfig = 0x0U;
	row = create_row(line);
	codeconfig = create_code(row);
}
void config::configimpl::compare_create_configuration(std::ifstream &osheet)
{
	std::string line;
	if(osheet.is_open())
	{
		//read first row, and set configuration teloc under test!!!!
		getline(osheet, line);
		getline(osheet, line);
		getline(osheet, line);
		create_main_config(line);
		while(!osheet.eof())
		{
			getline(osheet, line);
			std::cout<<" while line = "<<line<<std::endl;
			if(line != "")
				create_code(create_row(line));
		}
	}
	osheet.close();
}

