#pragma once

#include <stdio.h>

class Map;

//! ���� ����� ����� ���������� � ��������� � ���� ��� ���������� � ������� ������ ����
class Level {
public:
	Level() {};
	virtual ~Level() {};

	virtual void generate(Map * map) = 0;
};
