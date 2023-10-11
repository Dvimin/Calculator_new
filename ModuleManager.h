#pragma once

#include "API.h"
#include <iostream>
#include <windows.h>
#include <filesystem>

class ModuleManager {
public:
	using Func = void(*)(OperationsDescription& dstr);

	ModuleManager(const ModuleManager&) = delete;
	ModuleManager(ModuleManager&&) = delete;
	ModuleManager& operator= (const ModuleManager&) = delete;
	ModuleManager& operator= (ModuleManager&&) = delete;

	static ModuleManager& GetInstance();

	void LoadDll(OperationsDescription& dstr);

private:
	ModuleManager() = default;
	const std::string path{ "..\\Plugins" };
	const std::string funcName = "Load";
	static std::vector<HINSTANCE> linkedLibraries;
};
