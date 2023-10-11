#include <iostream>
//#include <math.h>

#include <Windows.h>
#include <filesystem>
#include "API.h"
#include "BaseOperation.h"
#include <map>
#include <string>

//using Fp = double(*)(double);
typedef double(*Fp) (double);

int main() {
	//HINSTANCE load = LoadLibrary(L"./plugins\\Trigonometry.dll");

	//Fp sin = (Fp) GetProcAddress(load, "Sin");
	// 
	//double y = sin(x) + sin(x);
	//std::cout << sin(x) << std::endl;
	//FreeLibrary(load);

    OperationsDescription& operationDesc = OperationsDescription::GetInstance();
    LoadBase(operationDesc);
    std::string operationName = "+";
    if (operationDesc.CheckOperator(operationName)) {
        std::cout << "Operator " << operationName << " is valid." << std::endl;
    }
    operationName = "sin";
    if (operationDesc.CheckFunction(operationName)) {
        std::cout << "Yes! Yes! " << operationName << " is valid." << std::endl;
    }

    ModuleManager& moduleManager = ModuleManager::GetInstance();
    const std::string path{ "..\\Trigonometry.dll" };
    std::string dllPath = std::filesystem::current_path().string() + "\\" + path;
    //moduleManager.LoadDll(dllPath);
    operationName = "Trigonometry";
    if (operationDesc.CheckFunction(operationName)) {
        std::cout << "Yes! " << operationName << std::endl;
    }


	//Operation* plus = new Addition();
	//Operation* minus = new Subtraction();
	////Operation* sin = new SinFunction();
	//Operation* division = new Division();

	//std::map<std::string, Operation*> operations;
	//operations["+"] = plus;
	//operations["-"] = minus;
	//operations["/"] = division;
	////operations["sin"] = sin;


	return 0;
}
