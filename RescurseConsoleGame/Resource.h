#pragma once
#include<iostream>
#include<vector>
#include<string>



class Resource
{
public:
	Resource() : count(0), name("NoName"){}
	void Reinitialisate(std::string name,
		std::vector<uint64_t> dataList);

	std::vector<uint64_t> UploadData();


	uint64_t getCount();


	void add(uint64_t count);

	void reduce(uint64_t count);

	void set(uint64_t count);


	std::string getName();


	std::string getNameAndCountInfo();

private:
	const uint64_t MAX_PARAM_VALUE = 15'000'000'000'000'000'000;

	static const uint16_t RESOURCES_DATA_COUNT = 1;

	uint64_t count;
	std::string name;
};



