#include "Button.h"

class QuitButton : public Button
{
public:
	QuitButton();

	bool isClicked() override;
	void clickReact() override;
	void focusReact() override;

	void Init(GameObject* owner) override;
	void Draw() override;
	void Destroy() override;
};
