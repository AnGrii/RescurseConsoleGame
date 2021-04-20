#pragma once
#include<iostream>
#include<vector>
#include<string>



class Resource
{
public:
	Resource() : count(0), value(0), name("NoName"){}
	void Reinitialisate(std::string name,
		std::vector<uint64_t> dataList);
	std::vector<uint64_t> UploadData();

	uint64_t getCount();
	uint64_t& getCountLink();

	void add(uint64_t count);
	void reduce(uint64_t count);
	void set(uint64_t count);

	uint64_t getValue();

	std::string getName();

	std::string getNameAndCountInfo();

private:
	static const uint16_t RESOURCES_DATA_COUNT = 2;

	uint64_t count, value;
	std::string name;
};



