#include "Player.h"

#include <iostream>

Player::Player() {

}

void Player::Draw() {
}

GameObject* Player::clone() const {
	return new Player();
}

void Player::Update() {
}
