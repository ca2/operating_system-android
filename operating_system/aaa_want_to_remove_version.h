#pragma once



#include "v_w32.h"

#ifndef _X86_
	#include "v_cpu.h"
#endif



#ifndef CDECL
	#define CDECL __cdecl
#endif


#ifndef __CDECL
	#define __CDECL __cdecl
#endif


#include "v_cpu.h"



#include <winreg.h>
#include <winnls.h>
#include <stddef.h>
#include <limits.h>
#include <malloc.h>
#include <___new.h>
#include <eh.h>



#define MAX_DWORD_PTR (0xffffffff)
