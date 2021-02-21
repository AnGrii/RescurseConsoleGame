#pragma once
#include<iostream>
#include<string>
#include<vector>

class Player
{
public:
	Player(std::string name, std::vector<uint64_t> data):
		name(name), balance(data[0]) {}
private:
	uint64_t balance;
	std::string name;
};

