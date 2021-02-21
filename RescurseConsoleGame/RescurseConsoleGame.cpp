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
    //Loading and initialisation data
    DataModule data("Data.txt");

    Player player(data.getPlayerName(), data.getPlayerData());
    
    Resource res(data.getRecourcesData());

    std::cout << res.log.getCount() << '\t' << res.log.getValue()
        << '\t' << res.wood.getCount() << '\t' << res.wood.getValue()
        << '\t' << res.stone.getCount() << '\t' << res.stone.getValue();

    return 0;
}
