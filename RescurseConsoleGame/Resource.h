#pragma once
#include<iostream>
#include<vector>

class ResTemplate
{
public:
	ResTemplate() : count(0), value(0){}
	void Reinitialisate(std::vector<uint64_t> dataList);

	uint64_t getCount();
	uint64_t& getCountLink();

	void add(uint64_t count);
	void reduce(uint64_t count);
	void set(uint64_t count);

	uint64_t getValue();

private:
	uint64_t count, value;
};


class Resource
{
public:
	ResTemplate log, wood, stone;


	Resource(std::vector< std::vector<uint64_t>> dataList);
	void SaveData(std::vector<uint64_t>& dataList);

	void printResourcesCount();
};


