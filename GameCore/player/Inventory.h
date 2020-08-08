#include <stddef.h>


class Player;

class Inventory {
public:
	Inventory() {};
	~Inventory() {};
	void init(Player * player);
	void update();
private:
	Player * player = NULL;
};
