#pragma once
#include<iostream>
#include<string>
#include<vector>

class Player
{
public:
	Player(std::string name, std::vector<uint64_t> data):
		name(name), balance(data[0]) {}

	void SaveData(std::string& name, std::vector<uint64_t>& data);

	std::string getName();
	void setNewName(std::string newName);

private:
	uint64_t balance;
	std::string name;
};

