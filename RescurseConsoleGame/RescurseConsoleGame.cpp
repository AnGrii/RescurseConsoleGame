#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <math.h>
#include <conio.h>
#include <thread>
#include <mutex>


#include "DataModule.h"
#include "Player.h"
#include "Resource.h"
#include "ResourceManager.h"
#include "ResourcesEtract.h"
#include "Buildings.h"
#include "BuildingsManager.h"
#include "Shop.h"
#include "GameHelper.h"


int main()
{
    srand(static_cast<uint64_t>(NULL));

    DataModule data("Data.txt");

    Player player(data.getPlayerName(), data.getPlayerData());
    ResourceManager res(data.getRecourcesData());
    //ResourcesEtract
    BuildingsManager buildings(
        data.getBuildingsNameData(),
        data.getBuildingsData());

    char g_Select = '0';
    bool g_Exit = false;

    while (!g_Exit)
    {
        GameMessage::keywordHelp(true);

        buildings.updateBuildingsQueue();
        buildings.work(res);
        buildings.brokeEvent();

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
            GameMessage::skipLine();
            break;
        case 'q':
            buildings.printQueueStatus();
            break;
        case 's':
            std::cout << "SHOP!" << std::endl;
            break;
        case 'b':
            buildings.buildMenu(res);
            break;
        case 'i':
            buildings.printBuildingsInfo();
            break;
        case 'x': 
            g_Exit = true;
            break;
        default:
            GameMessage::incorrectInput();
            break;
        }
    }
   


    return 0;
}
