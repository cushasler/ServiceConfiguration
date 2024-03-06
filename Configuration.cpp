/**
* @file Configuration.cpp
* @brief in this file are implmented the methods used to work with Configuration file
* @author Salvatore Muoio
*/
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include <sstream>
#include <string>
#include "libxl.h"
#include "Debug.h"
#include "Configuration.h"
#include "Configuration_impl.h"
#include "Compare.h"

using namespace libxl;
using namespace std;
//using namespace debug_;


ifstream fname("Config.ini", ios_base::in);


config::config()
{
    // constructor
	//std::cout<<FUNCTION_NAME<<std::endl;
	pimpl = new(configimpl);
}


config_::t_configstruct * config::getconfigstruct(void)
{
	static config_::t_configstruct configstruct;
    return(&configstruct);
}

config_::t_telocstrcut * config::gettelocstruct(void)
{
	static config_::t_telocstrcut telocstruct;
    return(&telocstruct);
}

config &config::getinstance()
{
    // TODO: insert return statement here
    static config instance;
    std::cout<<"getinstance"<<std::endl;
    return instance;
}



void config::readfileconfig(void)
{
	//read configuration file
   //std::string line;
/*   Book* book  = xlCreateXMLBook();
   Book* obook = xlCreateXMLBook();*/
   type_::UINT64 number_of_Teloc = 0x0U;

   std::ofstream MatrixTeloc("Teloc_Matrix.csv");
   pimpl->create_template(MatrixTeloc);
   if(fname.is_open()){
   getline(fname, getconfigstruct()->line);
   std::cout<<"line :: "<<getconfigstruct()->line<<std::endl;
  gettelocstruct()->kindofTeloc = whoamI(getconfigstruct()->line);
   pimpl->extract_filename(getconfigstruct()->line, getconfigstruct()->filename,
					       &getconfigstruct()->assemblycode[number_of_Teloc][0]);
   std::cout<<"getconfigstruct()->filename:: "<<getconfigstruct()->filename<<std::endl;
  ifstream Data(getconfigstruct()->filename, ifstream::in);
  if(Data.is_open()){
	  std::cout<<"Enter in the loop"<<std::endl;
	  getline(Data, getconfigstruct()->title);

	  while(getline(Data, getconfigstruct()->line))
			//getline(Data, getconfigstruct()->line);
	  {
				//std::cout<<"line = "<<getconfigstruct()->line<<std::endl;
				std::stringstream rowStream(getconfigstruct()->line);
				std::string draft;
				std::vector<std::string> cols;
				while(getline(rowStream, draft, ';')){
			//getconfigstruct()->assemblyteloc[ii++] = draft;
				cols.push_back(draft);
				}
				pimpl->create_output_file(cols, MatrixTeloc);
		}
  }
  }
  MatrixTeloc.close();
  //open the file in reading mode
  ifstream CompareTeloc("Teloc_Matrix.csv", ifstream::in);
  pimpl->compare_create_configuration(CompareTeloc);
}

static string findteloccode(std::string line)
{
 	static char key = '.';
 	std::string teloccode;
    std::cout<<FUNCTION_NAME<<std::endl;
    size_t pos = line.find(key);
	teloccode = line.substr(pos+1, (4));
	//DEBUG_DISPLAY(debug_::enable, teloccode);
	return(teloccode);
}

static string lookuptable(std::string teloccode)
{
	 std::string lret = "unknown";
	 static std::string table[2][2] = {{"2421","Teloc 1500"},
								       {"2620","Teloc 2500"}};

	for(type_::UINT8 jj = 0; jj < 2; jj++)
	{
		if(table[jj][0] == teloccode)
		{
			lret = table[jj][1];
			break;
		}//if
	}//for
	return(lret);
}

string config::whoamI(std::string line)
{
	std::string teloc = findteloccode(line);
	std::cout<<FUNCTION_NAME<<std::endl;
	//DEBUG_DISPLAY(debug_::enable, teloc);
	return(lookuptable(teloc));
}
