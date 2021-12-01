//===----------------------------------------------------------------------===//
// Bodycad 2019
// netlib - basic tcp/udp library
//
//	Guillaume Plante <gplante@bodycad.com>
//	Copyright(c) All rights reserved.
//===----------------------------------------------------------------------===//


#ifndef __MODULE_DEFINES_SYSTEM__
#define __MODULE_DEFINES_SYSTEM__


#include <stdint.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>


#ifdef MODULE_NETWORK_ENABLED
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")
#endif // MODULE_NETWORK_ENABLED


#ifdef IMPLEMENT_MODULE_DLL
# ifdef MODULE_EXPORTS
# define MODULEDLL_API __declspec(dllexport) 
# else
# define MODULEDLL_API __declspec(dllimport) 
# endif
#else
# define MODULEDLL_API 
#endif // IMPLEMENT_MODULE_DLL



#endif // __MODULE_DEFINES_SYSTEM__
