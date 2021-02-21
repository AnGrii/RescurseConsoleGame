#include <iostream>
#include <thread>
#include <ctime>
#include <string>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include <mutex>
#include <math.h>
#include <vector>
#include <list>

#include "DataModule.h"
#include "Player.h"
#include "Resource.h"
#include "ResourcesEtract.h"
#include "Factories.h"
#include "Shop.h"



int main()
{
    DataModule data("Data.txt");

    Player player(data.getPlayerName(), data.getPlayerData());
    
    std::cout << data.getRecourcesData()[0] << '\t' << data.getRecourcesData()[1] << '\t' << data.getRecourcesData()[2];


    return 0;
}
