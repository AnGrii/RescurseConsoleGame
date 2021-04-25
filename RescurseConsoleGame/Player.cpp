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

void Player::addBalance(uint64_t count)
{
	uint64_t limit = UINT64_MAX - this->balance;

	if (limit > count) {
		this->balance += count;
	}
	else {
		this->balance = UINT64_MAX;
	}
}

void Player::reduceBalance(uint64_t count)
{
	if (this->balance > count) {
		this->balance -= count;
	}
	else {
		this->balance = 0;
	}
}

uint64_t Player::getBalance()
{
	return balance;
}

uint64_t& Player::getBalanceLink()
{
	return balance;
}

bool Player::tryPay(uint64_t count)
{
	if (this->balance >= count) {
		this->balance -= count;
		return true; 
	}
	return false;
}

std::string Player::getName()
{
	return name;
}

void Player::setNewName(std::string newName)
{
	bool notEmptyName = (newName != "");
	bool notEmptyOneSpace = (newName != " ");
	//bool not = (newName != );

	if (notEmptyName and notEmptyOneSpace) {
		this->name = newName;
	}
}

std::vector<std::string> Player::getPlayerNameData()
{
	std::vector<std::string> dataVector;

	dataVector.push_back(name);

	return dataVector;
}

std::vector<uint64_t> Player::getPlayerData()
{
	std::vector<uint64_t> dataVector;

	dataVector.push_back(balance);

	return dataVector;
}
