#pragma once

#include <cstdio>

class Encodable {
public:
	Encodable() {}

	virtual void code(char*& buffer) = 0;
	virtual void decode(char*& buffer) = 0;

	virtual ~Encodable() {}
};
