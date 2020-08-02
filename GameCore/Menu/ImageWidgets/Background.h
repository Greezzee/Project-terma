#include "ImageWidget.h"

class Background : public ImageWidget
{
public:
	Background();

	virtual void Init(GameObject* owner) override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Destroy() override;
};
