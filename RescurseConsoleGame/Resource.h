#pragma once
#include<iostream>
#include<vector>

class ResTemplate
{
public:
	ResTemplate();
	ResTemplate(uint64_t count, uint64_t value) : count(count), value(value) {}
	void Reinitialisate(uint64_t count, uint64_t value);


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

	Resource();
	Resource(std::vector<uint64_t> dataList);
	void SaveData(std::vector<uint64_t>& dataList);

	void printResourcesCount();
};


