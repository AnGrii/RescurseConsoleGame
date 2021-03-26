#pragma once
#include<iostream>
#include<vector>

#include"Resource.h"

class ResourceManager
{
public:
	Resource log, wood, stone, coal, copper, tin, bronze,
		silver, gold, platina, diamond;

	ResourceManager(std::vector< std::vector<uint64_t>> dataList);

	void printResourcesCount();
};

