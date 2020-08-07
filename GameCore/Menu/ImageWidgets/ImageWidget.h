#include "../MenuWidget.h"

class ImageWidget : public MenuWidget
{
public:
	ImageWidget();

	virtual void Init(GameObject* owner) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Destroy() = 0;

	virtual ~ImageWidget();
};
