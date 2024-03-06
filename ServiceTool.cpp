#include <iostream>
#include "config.h"
#include "Configuration.h"
#include "Types.h"
//#include "libxl.h"

using namespace std;
//using namespace libxl;


int main(int argc, char **argv) {
//	Book *book = xlCreateXMLBook();
//	type_::ebool find = type_::FALSE;
	config &obj = config::getinstance();
	obj.readfileconfig();
	std::cout << "Service Tool" << std::endl;
	std::cout << "Version " << ServiceTool_VERSION_MAJOR << "." << ServiceTool_VERSION_MINOR << std::endl;
	return 0;
}
