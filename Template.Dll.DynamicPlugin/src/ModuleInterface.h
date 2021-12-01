

#ifndef __MODULEINTERFACE_H__
#define __MODULEINTERFACE_H__

#include <memory>
#include <string>
#include "ModuleDefs.h"
class IPluginModuleInterface {
public:
	virtual ~IPluginModuleInterface() = default;

	virtual void Create(void) = 0;
	virtual void Destroy(void) = 0;

	virtual void Start(void) = 0;
	virtual void Stop(void) = 0;
	virtual bool IsRunning() = 0;

	virtual void ProcessMessage( unsigned int messageId ) = 0;

};


#endif //__MODULEINTERFACE_H__