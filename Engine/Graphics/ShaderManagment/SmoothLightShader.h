#pragma once
#include "Shader.h"

//! ������ �������� ���������
//! ��������� ����� ������������ LightManager
class SmoothLightShader : public tge::Shader
{
public:
	SmoothLightShader();
	~SmoothLightShader();

private:
	void ApplyParameters(sf::Shader* shader) override;
};
