#include "Button.h"

class QuitButton: public Button {
public:
	QuitButton();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Init(GameObject *owner) override;
	void Destroy() override;
};
