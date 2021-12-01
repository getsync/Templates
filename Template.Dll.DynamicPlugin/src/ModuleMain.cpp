
#include "StdAfx.h"
#include "ModuleInterface.h"
#include <iostream>
#include "Version.h"
#include "ModuleShell.h"


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// attach to process
		// return FALSE to fail DLL load
		break;

	case DLL_PROCESS_DETACH:
		// detach from process
		break;

	case DLL_THREAD_ATTACH:
		// attach to thread
		break;

	case DLL_THREAD_DETACH:
		// detach from thread
		break;
	}
	return TRUE; // succesful
}

std::unique_ptr<PluginShellModule> GetPluginModule(void)
{
	return std::unique_ptr<PluginShellModule>(new PluginShellModule);
}

std::string GetModuleName(void)
{
	return "shell";
}

std::string GetModuleVersion(void)
{
	return "1.1";
}