#include "Player.h"

void Player::SaveData(std::vector<std::string>& name, std::vector<uint64_t>& data)
{
	name[0] = this->name;
	data[0] = balance;
}

void Player::printBalance()
{
	std::cout << "Current balance: " << balance << std::endl << std::endl;
}
