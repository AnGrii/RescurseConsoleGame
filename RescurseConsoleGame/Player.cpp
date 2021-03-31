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

void Player::addMoney(uint64_t count)
{
	uint64_t limit = UINT64_MAX - this->balance;

	if (limit > count) {
		this->balance += count;
	}
	else {
		this->balance = UINT64_MAX;
	}
}

void Player::reduceMoney(uint64_t count)
{
	if (this->balance > count) {
		this->balance -= count;
	}
	else {
		this->balance = 0;
	}
}

uint64_t& Player::getBalanceLink()
{
	return balance;
}

bool Player::payAndGetStatus(uint64_t count)
{
	if (this->balance > count) {
		this->balance -= count;
		return true; //exit branch
	}
	return false;//exit branch
}
