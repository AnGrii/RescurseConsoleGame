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
#include "Buildings.h"
#include "Shop.h"
#include "GameHelper.h"



int main()
{
    srand(static_cast<uint64_t>(NULL));

    DataModule data("Data.txt");

    Player player(data.getPlayerName(), data.getPlayerData());
    Resource res(data.getRecourcesData());
    Buildings buildings(data.getBuildingsData());



    char g_Select = '0';
    bool g_Exit = false;

    while (!g_Exit)
    {
        GameHelper::keywordHelp(true);

        buildings.updateBuildingsBuild();

        player.printBalance();

        res.printResourcesCount();
        
        std::cout << "Input: ";
        std::cin >> g_Select;
        std::cout << std::endl;

        switch (g_Select)
        {
        case 'e':
            ResourcesEtract::extract(res.log, res.wood, res.stone);
            break;
        case 'n':
            GameHelper::skipLine();
            break;
        case 's':
            std::cout << "SHOP!" << std::endl;
            break;
        case 'b':
            buildings.buildMenu(res);
            break;
        case 'x': 
            g_Exit = true;
            break;
        default:
            GameHelper::incorrectInputMSG();
            break;
        }
    }
   


    return 0;
}
