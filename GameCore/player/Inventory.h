class Player;

class Inventory {
public:
	Inventory();
	virtual ~Inventory();
	void init(Player * player);
	void update();
private:
	Player * player;
};
