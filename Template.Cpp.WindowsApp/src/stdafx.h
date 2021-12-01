
//==============================================================================
//
//     stdafx.h : include file for standard system include files,
//           or project specific include files that are used frequently, but
//           are changed infrequently
//
//==============================================================================
//  Copyright (C) Guilaume Plante 2020 <cybercastor@icloud.com>
//==============================================================================


#ifndef __STDAFX_F__
#define __STDAFX_F__


#ifdef WIN32
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <process.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <AccCtrl.h>
#include <winbase.h>
#include <winsvc.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <wincrypt.h>
#include <tchar.h>
//#include <winsock2.h>
#include <shellapi.h>
#include "targetver.h"
#include "macros.h"
#include "nowarns.h"

#include <assert.h>
#define ASSERT(x)	assert(x)

#ifdef PLATFORM_PC
#include <conio.h>


#endif // PLATFORM_PC
#undef  STRICT
#define STRICT
#undef  NOMINMAX
#define NOMINMAX
#undef  UNICODE
#undef  MBCS        // Treat MBCS as an unsupported no-effect symbol.
#define UNICODE
#undef  WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#undef  OEMRESOURCE
#define OEMRESOURCE

#undef CCC_CALL_CONV
#undef CCC_INTERFACE_DEF_NOCC
#undef CCC_INTERFACE_DEF

#ifdef CCC_STATIC_LINKING
#  define CCC_CALL_CONV
#  define CCC_INTERFACE_DEF_NOCC
#  define CCC_INTERFACE_DEF(x)   x
#else
//#  define CCC_CALL_CONV  __stdcall
#  define CCC_CALL_CONV  __cdecl
#  ifdef CCC_EXPORTS
#    define CCC_INTERFACE_DEF_NOCC __declspec(dllexport)                    
#    define CCC_INTERFACE_DEF(x)   __declspec(dllexport) x CCC_CALL_CONV 
#  else
#    define CCC_INTERFACE_DEF_NOCC __declspec(dllimport)                    
#    define CCC_INTERFACE_DEF(x)   __declspec(dllimport) x CCC_CALL_CONV
#  endif
#endif


#endif //WIN32

#endif//__STDAFX_F__