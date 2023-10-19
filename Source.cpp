#include <iostream>


#include <Windows.h>
#include <filesystem>
#include <string>
#include "API.h"
#include "BaseOperation.h"
#include "Calculator.h"
#include "ModuleManager.h"
#include <map>

typedef double(*Fp) (double);


int main() {

    OperationsDescription& dstr = OperationsDescription::GetInstance();
    try {
        LoadBase(dstr);
        ModuleManager::GetInstance().LoadDll(dstr);
    }
    catch (const std::exception& except) {
        std::cout << except.what() << std::endl;
    }

    std::string str;
    while (std::getline(std::cin, str) && str != "exit") {
        try {
            if (str == "exit")
                return 0;
            std::cout << std::setiosflags(std::ios_base::fixed) << std::setprecision(6) << Calculate(str) << std::endl;
        }
        catch (const std::exception& except) {
            std::cout << except.what() << std::endl;
        }
        catch (...) {
            std::cout << "Unknown error" << std::endl;
        }
    }
    dstr.Clear();

	return 0;
}
