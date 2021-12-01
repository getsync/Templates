
//==============================================================================
//
//     main.cpp
//
//============================================================================
//  Copyright (C) Guilaume Plante 2020 <cybercastor@icloud.com>
//==============================================================================


#include "stdafx.h"

#include <commctrl.h>       // InitCommonControlsEx, etc.
#include <stdexcept>

#include <direct.h>

#define BUFSIZE MAX_PATH
#define CODE_PATH_ENV TEXT("LOCALCODEPATH")
#define CODE_PATH TEXT("c:\\Code")
#define SCRIPTS_PATH_ENV TEXT("LOCALSCRIPTSPATH")
#define SCRIPTS_PATH TEXT("c:\\Scripts")
#define ERROR_RETURN -1
#define SUCCESS_RETURN 0

int SetPath(TCHAR *path)
{
	char command[1024];
	memset(command, 0, sizeof(command));
	sprintf(command, "pushd %s", path);
	printf("Changing directory to %s (%s).\n", path, command);
	system(command);
	return SUCCESS_RETURN;

}

int ChangeDirectory(TCHAR *path)
{
	if (_chdir(path))
	{
		switch (errno)
		{
		case ENOENT:
			printf("Unable to locate the directory: %s\n", path);
			break;
		case EINVAL:
			printf("Invalid buffer.\n");
			break;
		default:
			printf("Unknown error.\n");
		}
	}
	else {
		system("dir *.exe");
	}
	return SUCCESS_RETURN;
}

int main(int argc, TCHAR **argv)
{
	TCHAR Buffer[BUFSIZE];
	TCHAR EnvBuffer[BUFSIZE];
	DWORD dwRet, dwEnvRet;
	printf("Suppressing the abort message. If successful, this message"
		" will be the only output.\n");
	// Suppress the abort message
	//_set_abort_behavior(0, _WRITE_ABORT_MSG);
	//abort();
	dwEnvRet = GetEnvironmentVariable(CODE_PATH_ENV, EnvBuffer, BUFSIZE);
	if (dwEnvRet != 0 && dwEnvRet < BUFSIZE) {
		return SetPath(EnvBuffer);		
	}
	if (dwEnvRet == 0)
	{
		printf("GetEnvironmentVariable failed (%d) for '%s'. Using default.\n", GetLastError(), CODE_PATH_ENV);
	}
	if (dwEnvRet > BUFSIZE)
	{
		printf("Buffer too small; need %d characters\n", dwEnvRet);
		return ERROR_RETURN;
	}

	return SetPath(CODE_PATH);
}