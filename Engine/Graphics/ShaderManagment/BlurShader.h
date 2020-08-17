#pragma once
#include "Shader.h"

//! ����� ������ "��������"
class BlurShader : public tge::Shader
{
public:
	BlurShader();
	~BlurShader();
	//! ������������ ������� ��������. ����� �����, ������� 0.01
	void SetBlurRadius(float r);
	float GetBlurRadius();

private:
	void ApplyParameters(sf::Shader* shader) override;
	float _radius;
};
