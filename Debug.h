/**
* @file Debug.h
* @brief In this file are implemented all methods used for debug
* @author Salvatore Muoio
*/

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include<iostream>
#include "Types.h"

using namespace std;

//#define DEBUG_INFO(exp) ((exp) ? debug_::dbg_info() : debug_::dummy())
#define DEBUG_DISPLAY(enable, exp) if(enable) debug_::dbg_display(exp)
#define DEBUG_ENABLE(exp) if(exp)
#define FUNCTION_NAME __func__


namespace debug_
{
	extern type_::UINT8 enable;
	void dbg_info(void);
	template <typename T> T dbg_display(T &x ){
	 std::cout<<x<<std::endl;
	}
	void dummy(void);
}

class debug
{
	public:
	debug();
	void debuginfo(void);
	virtual ~debug(){};
	
};

#endif


