/**
* @file ServiceTool.cpp
* @brief main of sw project
* @author Salvatore Muoio
*/
#include <iostream>
#include "config.h"
#include "Configuration.h"
#include "Types.h"
//#include "libxl.h"

using namespace std;
//using namespace libxl;


template <class T>
class CodeT4
{
	private:
		T T4Code;
	public:
		//T create_T4code(T main_code);
};



int main(int argc, char **argv) {
//	Book *book = xlCreateXMLBook();
//	type_::ebool find = type_::FALSE;
	config &obj = config::getinstance();
	obj.readfileconfig();
	CodeT4<int> T4Code;
	std::cout << "Service Tool" << std::endl;
	std::cout << "Version " << ServiceTool_VERSION_MAJOR << "." << ServiceTool_VERSION_MINOR << std::endl;
	return 0;
}
