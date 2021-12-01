
//===----------------------------------------------------------------------===
//  Defender-Service: A cybercastor R&D Project
//
//  Part of the windefsrv RAT suite (c) by <cybercastor@icloud.com>
//	The windefsrv service is a Remote Access Tool (RAT) designed to remotely 
//	monitor and control other computers through a secure encrypted connection
//
//  Quebec City, Canada, MMXXI
//===----------------------------------------------------------------------===

#include "resource.h"
#include "targetver.h"

#ifndef __MODULEVERSION_H__
#define __MODULEVERSION_H__


#define STRINGIZE2(s) #s
#define STRINGIZE(s) STRINGIZE2(s)

#define VERSION_MAJOR               1
#define VERSION_MINOR               0
#define VERSION_REVISION            2
#define VERSION_BUILD               5
#define VER_REALNAME_STR			"Module for ..."
#define VER_FILE_DESCRIPTION_STR    "USB Audio Class Driver"
#define VER_FILE_VERSION            VERSION_MAJOR, VERSION_MINOR, VERSION_REVISION, VERSION_BUILD
#define VER_FILE_VERSION_STR        STRINGIZE(VERSION_MAJOR)        \
                                    "." STRINGIZE(VERSION_MINOR)    \
                                    "." STRINGIZE(VERSION_REVISION) \
                                    "." STRINGIZE(VERSION_BUILD)    \

#define VER_COMPANYNAME_STR			"Microsoft"
#define VER_INTERNALNAME_STR		"USB Audio Class Driver"
#define VER_LEGALCOPYRIGHT_STR		"(C)Microsoft Corportation All rights reserved"
#define VER_LEGALTRADEMARKS1_STR
#define VER_LEGALTRADEMARKS2_STR
#define VER_ORIGINALFILENAME_STR	"Module.dll"
#define VER_PRODUCTNAME_STR			"Microsoft Windows Operating System"

#define VER_PRODUCT_VERSION         VER_FILE_VERSION
#define VER_PRODUCT_VERSION_STR     VER_FILE_VERSION_STR
#define VER_ORIGINAL_FILENAME_STR   "module.dll"
#define VER_INTERNAL_NAME_STR       VER_ORIGINAL_FILENAME_STR
#define VER_COPYRIGHT_STR           "Copyright (C) 2021"

#ifdef _DEBUG
#define VER_VER_DEBUG             VS_FF_DEBUG
#else
#define VER_VER_DEBUG             0
#endif

#define VER_FILEOS                  VOS_NT_WINDOWS32
#define VER_FILEFLAGS               VER_VER_DEBUG
#define VER_FILETYPE                VFT_DRV



#endif // __MODULEVERSION_H__
