#pragma once
#include "Shader.h"


//! ����� ������ ����������� ���������. 
//! ��������� ����� ������������ LightManager
class PixelLightShader : public tge::Shader
{
public:
	PixelLightShader();
	~PixelLightShader();

private:
	void ApplyParameters(sf::Shader* shader) override;
};
