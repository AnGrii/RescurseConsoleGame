#pragma once
#include<iostream>
#include<vector>


class Resource
{
public:
	Resource();
	Resource(std::vector<uint64_t> dataList);
	void SaveData(std::vector<uint64_t>& dataList);

private:
	ResTmp log, wood, stone;
};


class ResTmp
{
public:
	ResTmp() { count = 0; }

	ResTmp(uint64_t count) : count(count) {}
	void Reinitialisate(uint64_t count) { this->count = count; }

	uint64_t getCount();
	void add(uint64_t count);
	void reduce(uint64_t count);
	void set(uint64_t count);

private:
	uint64_t count;
};