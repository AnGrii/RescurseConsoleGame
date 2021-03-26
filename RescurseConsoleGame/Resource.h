#pragma once
#include<iostream>
#include<vector>

class Resource
{
public:
	Resource() : count(0), value(0){}
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



