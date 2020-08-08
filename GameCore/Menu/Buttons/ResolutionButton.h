#include "Button.h"

class ResolutionButton: public Button {
public:
	ResolutionButton();

	void clickReact() override;
	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;
};
