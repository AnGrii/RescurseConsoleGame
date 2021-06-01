#pragma once
#include<iostream>
#include<string>
#include<vector>

class Player
{
public:
	Player(std::vector<std::string> nameVector, std::vector<uint64_t> dataVector):
		name(nameVector[0]), balance(dataVector[0]) {}
	void SaveData(std::vector<std::string>& name, std::vector<uint64_t>& data);
	
	std::vector<std::string> getPlayerNameData();
	std::vector<uint64_t> getPlayerData();


	void printBalance();
	void addBalance(uint64_t count);
	void reduceBalance(uint64_t count);
	uint64_t getBalance();
	uint64_t& getBalanceLink();
	bool tryPay(uint64_t count);

	std::string getName();
	void setNewName(std::string newName);
private:
	const uint64_t MAX_PARAM_VALUE = 15'000'000'000'000'000'000;

	uint64_t balance;
	std::string name;
};

