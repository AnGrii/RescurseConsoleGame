#pragma once
#include <iostream>
#include <vector>
//#include <>

#include "Resource.h"

class ResourcesEtract
{
public:
	static void extract(ResTemplate& log, ResTemplate& wood, ResTemplate& stone);

private:
	static void extractLog(ResTemplate& log);
	static void extractWood(ResTemplate& log, ResTemplate& wood);
	static void extractStone(ResTemplate& stone);
};

