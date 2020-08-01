#include "../../../Engine/Gameplay/GameObject.h"

class ImageWidget : public GameObject
{

public:
	virtual void Init(GameObject* owner) override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Destroy() override;
	virtual GameObject* clone() override;
};
