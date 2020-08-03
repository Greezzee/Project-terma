/*
 * Inventory.h
 *
 *  Created on: Aug 3, 2020
 *      Author: timattt
 */

#ifndef GAMECORE_PLAYER_INVENTORY_H_
#define GAMECORE_PLAYER_INVENTORY_H_
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

#endif /* GAMECORE_PLAYER_INVENTORY_H_ */
