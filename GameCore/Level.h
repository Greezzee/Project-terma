#pragma once

#include <bits/types/FILE.h>

class Map;

//! ���� ����� ����� ���������� � ��������� � ���� ��� ���������� � ������� ������ ����
class Level {
public:
	virtual void generate(Map * map) = 0;

protected:
	void loadBlocksFromFile(Map * map, FILE * from);
};
