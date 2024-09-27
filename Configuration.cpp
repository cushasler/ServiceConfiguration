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
   std::string name_matrix;
   std::ofstream MatrixTeloc;//("Teloc_Matrix.csv");
   if(fname.is_open()){
   getline(fname, getconfigstruct()->line);
   std::cout<<"line :: "<<getconfigstruct()->line<<std::endl;
  gettelocstruct()->kindofTeloc = whoamI(getconfigstruct()->line);
  std::cout<<"kindofTeloc ==: "<<gettelocstruct()->kindofTeloc<<std::endl;
   pimpl->extract_filename(getconfigstruct()->line, getconfigstruct()->filename,
					       &getconfigstruct()->assemblycode[number_of_Teloc][0]);
   name_matrix = getconfigstruct()->line.substr(15, 4);

   name_matrix = "Teloc_Matrix_"+name_matrix+".csv";
   std::cout<<"name_matrix = "<<name_matrix<<std::endl;
   ofstream MatrixTeloc(name_matrix);
   pimpl->create_template(MatrixTeloc, gettelocstruct()->kindofTeloc);

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
				//getconfigstruct()->index_row++;
		}
  }
  }
  MatrixTeloc.close();
  std::cout<<"index_row ="<<getconfigstruct()->index_row<<std::endl;
  //open the file in reading mode
  fstream CompareTeloc(name_matrix, ios::in|ios::out);
  if(CompareTeloc.is_open())
  pimpl->compare_create_configuration(CompareTeloc);
  else
	  std::cout<<"file not open"<<std::endl;

}

static string findteloccode(std::string line)
{
 	static char key = '_';
 	std::string teloccode;
    std::cout<<FUNCTION_NAME<<std::endl;
    size_t pos = line.find(key);
	teloccode = line.substr(pos+1, (4));
	//DEBUG_DISPLAY(debug_::enable, teloccode);
	std::cout<<"teloc = "<<teloccode<<std::endl;
	return(teloccode);
}

static string lookuptable(std::string teloccode)
{
	 std::string lret = "unknown";
	 static std::string table[2][2] = {{"1500","T1500"},
								       {"2500","T2500"}};

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
