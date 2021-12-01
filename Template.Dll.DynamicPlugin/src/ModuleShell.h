
#include "StdAfx.h"
#include "ModuleInterface.h"
#include <iostream>

#ifndef __MODULE_SHELL_H__
#define __MODULE_SHELL_H__

class PluginShellModule : public IPluginModuleInterface
{
public:
	
	void Create();
	void Destroy(void);
	void Start(void);
	void Stop(void);
	bool IsRunning();
	void ProcessMessage(unsigned int messageId);
};

// DLL export funcs
MODULEDLL_API std::unique_ptr<PluginShellModule> GetPluginModule(void);
MODULEDLL_API std::string  GetModuleName(void);
MODULEDLL_API std::string  GetModuleVersion(void);

#endif //__MODULE_SHELL_H__