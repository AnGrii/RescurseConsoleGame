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
#include <functional>


#include "DataModule.h"
#include "Player.h"
#include "Resource.h"
#include "ResourceManager.h"
#include "ResourcesExtract.h"
#include "Buildings.h"
#include "BuildingsManager.h"
#include "Market.h"
#include "GameHelper.h"


int main()
{
    srand(static_cast<uint64_t>(NULL));

    const std::string g_DataFileName = "Data.txt";

    DataModule data(g_DataFileName);

    Player player(data.getPlayerName(), data.getPlayerData());
    ResourceManager resManager(data.getRecourcesData());
    ResourcesExtract resExtract(data.getResourcesExtractData());
    BuildingsManager buildings(
        data.getBuildingsNameData(),
        data.getBuildingsData());
    Market market(data.getMarketData());

    char g_Select = '0';
    bool g_Exit = false;

    while (!g_Exit)
    {
        GameMessage::keywordHelp(true);

        buildings.updateBuildingsQueue();
        buildings.work(resManager);
        buildings.brokeEvent();

        player.printBalance();

        resManager.printResourcesCount();
        
        std::cout << "Input: ";
        std::cin >> g_Select;
        std::cout << std::endl;

        switch (g_Select)
        {
        case 'e':
           resExtract.extract(resManager.log, resManager.wood, resManager.stone);
            break;
        case 'n':
            GameMessage::skipLine();
            break;
        case 'g':
            resExtract.upgradeResourceExtractionMenu(player);
            break;
        case 'q':
            buildings.printQueueStatus();
            break;
        case 's':
            buildings.SkipBuildingMenu(player);
            break;
        case 'b':
            buildings.buildMenu(resManager);
            break;
        case 'i':
            buildings.printBuildingsInfo();
            break;
        case 'm':
            market.buySellMenu(player, resManager);
            break;
        case 'x': 
            data.saveData(g_DataFileName);
            g_Exit = true;
            break;
        case 'r':
            data.restoreData(g_DataFileName);
            break;
        default:
            GameMessage::incorrectInput();
            break;
        }
    }
   
    return 0;
}
