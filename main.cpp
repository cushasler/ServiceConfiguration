#include <iostream>
#include "Configuration.h"
//#include "libxl.h"

//using namespace libxl;
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//first step read the config file to read the file to parser
	config &obj = config::getinstance();
	obj.readfileconfig();
	int jj = 0x0;
	cin>>jj;
	return 0;
}
