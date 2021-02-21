#include "Player.h"

void Player::SaveData(std::string& name, std::vector<uint64_t>& data)
{
	name = this->name;
	data[0] = balance;
}
