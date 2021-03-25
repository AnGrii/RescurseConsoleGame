#pragma once
#include<iostream>
#include<string>
#include<vector>

class Player
{
public:
	Player(std::vector<std::string> name, std::vector<uint64_t> data):
		name(name[0]), balance(data[0]) {}

	void SaveData(std::vector<std::string>& name, std::vector<uint64_t>& data);

	void printBalance();
	void addMoney(uint64_t count);
	void reduceMoney(uint64_t count);
	uint64_t& getBalanceLink();

	/*std::string getName();
	void setNewName(std::string newName);*/

private:
	uint64_t balance;
	std::string name;
};

