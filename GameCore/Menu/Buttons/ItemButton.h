#include "Button.h"

#include "../../items/Item.h"

class ItemButton: public Button {
	Item* item;
public:
	ItemButton(Item* _item);

	void clickReact() override;
	void focusReact() override;
	void disfocusReact() override;
	void Destroy() override;
	void Init(GameObject *owner) override;

	~ItemButton();
};
