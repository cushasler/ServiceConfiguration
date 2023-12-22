/**
* @file Util.cpp
* @brief In this file are implemented all methods util
* @authore Salvatore Muoio
*/
#include <iostream>
#include <string.h>
#include "Debug.h"
#include "Util.h"

type_::ebool util_::charpointer_compare(const type_::CHAR *a, const type_::CHAR *b)
{
	type_::ebool ret = type_::TRUE;
	for(int i = 0; strlen(a) < strlen(b) ? *a!= '\0' : *b!= '\0'; i++, *a++, *b++ )
	{
		if(*a != *b)
			return(type_::FALSE);
	}
}

type_::e_result util_::CheckArg(void *pArg)
{
	return((pArg != 0) ? type_::RESULT_OK : type_::RESULT_POINTER_NOT_ADDRESSED);
}

type_::UINT64 util_::ConverTelocCode2Num(std::string teloccode)
{
//	std::cout<<FUNCTION_NAME<<std::endl;
//	std::cout<<teloccode<<endl;
	return( ((teloccode == "Teloc 1500") ? 0 : 1));
}
