/**
* @file Configuration.cpp
* @brief in this file are implmented the methods used to work with Configuration file
* @author Salvatore Muoio
*/
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "Debug.h"
#include "Configuration.h"
#include "Configuration_impl.h"

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
   
   std::cout<<FUNCTION_NAME<<std::endl;
   if(fname.is_open())
   {
        std::cout<<"read filename"<<std::endl;
        
 /*  while ( getline (fname,line) )
    {
      cout << line << '\n';
    }*/
	getline(fname, getconfigstruct()->line);
	cout<<getconfigstruct()->line<<endl;
	gettelocstruct()->kindofTeloc = whoamI(getconfigstruct()->line);
	std::cout<<"kindofteloc == "<<gettelocstruct()->kindofTeloc<<std::endl;
	pimpl->extract_filename(getconfigstruct()->line, getconfigstruct()->filename);
    getline(fname, getconfigstruct()->line);
	cout<<getconfigstruct()->line<<endl;
	pimpl->extract_column_compare(getconfigstruct()->line, getconfigstruct()->column);
//	DEBUG_DISPLAY(1, getconfigstruct()->filename);
	if(pimpl->parser_kenfile(getconfigstruct()->column, getconfigstruct()->filename) == type_::TRUE)
	{
		// scroll column found
		pimpl->scroll_column(gettelocstruct()->kindofTeloc);
	}
	    
    //extract_filename(getconfigstruct()->filename, getconfigstruct()->kenfile);
    //  }
    //else
    // {
      //  std::cout<<"Error open file Config.ini"<<std::endl;
        //debug_::DEBUG_INFO("Configuration.cpp", 15);
        //DEBUG_INFO();
    }
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
