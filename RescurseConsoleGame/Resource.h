#pragma once
#include<iostream>
#include<vector>


class Resource
{
public:
	Resource()
	{
		log = wood = stone = 0;
	}

	Resource(std::vector<uint64_t> dataList) 
	{
		log = dataList[0];
		wood = dataList[1];
		stone = dataList[2];
	}

	void SaveData(std::vector<uint64_t> dataList)
	{
		dataList[0] = log;
		dataList[1]= wood;
		dataList[2] = stone;
	}
	

	uint64_t getLog();
	void addLog(uint64_t count);
	void reduceLog(uint64_t count);
	void setLog(uint64_t count);

	uint64_t getWood();
	void addWood(uint64_t count);
	void reduceWood(uint64_t count);
	void setWood(uint64_t count);

	uint64_t getStone();
	void addstone(uint64_t count);
	void reduceStone(uint64_t count);
	void setStone(uint64_t count);

private:
	uint64_t log, wood, stone;
};

