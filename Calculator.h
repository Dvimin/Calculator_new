#pragma once

#include "API.h"
#include "Separator.h"

class VariableManager {
public:
	VariableManager(const VariableManager&) = delete;
	VariableManager(VariableManager&&) = delete;
	VariableManager operator=(const VariableManager&) = delete;
	VariableManager operator=(VariableManager&&) = delete;
	~VariableManager() = default;

	static VariableManager& GetInstance(void);

	bool CheckVariable(const std::string& name) const;

	void AddVariable(Variable var);

	Variable FindVariable(const std::string& name) const;
private:
	VariableManager() = default;
	static std::map<std::string, Variable> variableMap;
};

double Calculate(const std::string& expression);
