#pragma once

#include "GameObject.h"

namespace tge {

	const unsigned MAX_OBJECTS = 100000; //! ������������ ���������� �������� �� ����� ������� ����
	const unsigned LAYERS_COUNT = 2; //! ���������� ���� �������� �� ����� ������� ����

	//! �������� ���� ���� (��� ��������)
	enum LayerNames {
		BASE, TEST_LAYER
	};

	//! ���������, �������� ��� �������� � ������ ���� ������� (�� ID)
	struct KilledArray
	{
		int obj_id[MAX_OBJECTS]; //! ������ ID �������� ��������. -1 �������� ���������� �������
		unsigned top; //! ���-�� �������� ��������
	};

	//! ������ ��� ������� �� ������ ����
	struct Layer {
		int obj_id[MAX_OBJECTS]; //! ������ ID �������� �� ������ ����. -1 �������� ���������� �������
		unsigned top; //! ���-�� �������� �� ����
	};

	//! ������ �� ����� ���������� �������
	struct ObjectData
	{
		GameObject* obj; //! ��������� �� ������
		/*!
		* ��������� ������ ������� � ��������������� ����.
		* -1, ���� ������ ����������� � ��������������� ����
		*/
		int layer_pos[LAYERS_COUNT];
	};

	//! ������ ��� ���� �������� �� ������� ����, � ���� ����� � �� ��������, ���������� ��������
	struct ObjectsArray
	{
		ObjectData obj[MAX_OBJECTS]; //! ������ ������ ���� ��������. ������������ ID ������� - ������� ��� ������ � ���� �������
		Layer layers[LAYERS_COUNT]; //! ������ ������ ��� ���� �����
		KilledArray to_kill; //! �������, ���������� �������� �� ��������� �����
		unsigned top; //! ���-�� ���� �������� �� ������� ����
	};
}

//! ������, ������� ���������� ������������ �������� ����, ����� �������� � ���� ������
struct GameobjectSpawnData
{
	GameObject* obj; //! ��������� �� ��� ��������� ������, �������� �������� ������ � ������� ���������������
	bool is_on_layer[tge::LAYERS_COUNT]; //! ���������� � ���, �� ����� ����� �� ������������
};
