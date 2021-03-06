#pragma once
#include "../Object.h"
#include "../../Runtime.h"

class Function : public Object {
protected:
	size_t start, end;
	Scope* origin;
public:
	Function(string name, size_t start, size_t end, Scope* origin = nullptr) : Object("Function", nullptr, "Function." + name) {
		this->start = start;
		this->end = end;
		if (!origin)
			origin = scopes.front();
		this->origin = origin;
		krefs = 1;
	}
	static void Register(string name, Function* function);
	static void Register(string name, size_t start, size_t end);
	void* Eval() override;
};