/**
* @file Configuration.h
* @brief in this file are implmented the methods used to work with Configuration file
* @author Salvatore Muoio
*/
#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include"Types.h"
#include <string>

namespace config_
{
   typedef struct
    {
        std::string line;
        type_::CHAR filename[20];
        type_::CHAR column[60];
        //char *kindofTeloc;
    }t_configstruct;
	
	typedef struct
	{
		std::string kindofTeloc;
		type_::UINT64 Teloc; // 0->Teloc1500; 1->Teloc2500
	}t_telocstrcut;	
}

class config
{
    protected:
    static config_::t_configstruct *getconfigstruct(void);
    static config_::t_telocstrcut *gettelocstruct(void);
    private:  
	class configimpl;  
	configimpl *pimpl;
    config();
    virtual ~config(){};
    config(const config &);
    const config &operator = (const config &);
    std::string whoamI(std::string line); 
    public:
    static config &getinstance();
    void readfileconfig(void);
	
};


#endif
