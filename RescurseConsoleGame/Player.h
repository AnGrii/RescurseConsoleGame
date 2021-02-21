#pragma once
#include<iostream>
#include<string>

class Player
{
public:
	Player(std::string name, uint64_t balance):
		name(name), balance(balance) {}
private:
	uint64_t balance;
	std::string name;
};

