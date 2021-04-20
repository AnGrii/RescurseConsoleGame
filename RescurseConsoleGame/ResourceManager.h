#pragma once
#include<iostream>
#include<vector>

#include"Resource.h"

class ResourceManager
{
public:
	static const uint16_t RESOURCES_COUNT = 11;

	Resource log, wood, stone, coal, copper, tin, bronze,
		silver, gold, platina, diamond;

	Resource* ReosourcesVector[11]{
		&log, &wood, &stone,
		&coal, &copper, &tin,
		&bronze, &silver, &gold,
		&platina, &diamond
	};

	ResourceManager(std::vector<std::string> nameList,
		std::vector< std::vector<uint64_t>> dataList);
	std::vector< std::vector<uint64_t>> UploadData();

	void printResourcesCount();
};

