#include "Button.h"

class ResolutionButton: public Button {
public:
	ResolutionButton();

	void rightClickReact() override;
	void leftClickReact() override;

	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;
};
