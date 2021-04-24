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
    ResourceManager resManager(data.getRecourcesNameData(),
        data.getRecourcesData());

    ResourcesExtract resExtract(data.getResourcesExtractData());
    BuildingsManager buildings(data.getBuildingsNameData(),
        data.getBuildingsData());

    Market market(data.getMarketData());


    char g_Select = '0';
    bool g_Exit = false;

    while (!g_Exit)
    {
        GameMessages::keywordHelp(true);

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
            GameMessages::skipLine();
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
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
        case 'u':
            buildings.upgradeMenu(player);
            break;
        case 'p':
            buildings.productivitySettingMenu();
            break;
        case 'i':
            buildings.printBuildingsInfo();
            break;
        case 'm':
            market.buySellMenu(player, resManager);
            break;
        case 'r':
            data.resetDataWithSecurity(g_DataFileName);
            break;
        case 'a':
            GameMessages::About();
            break;
        case 'x': 
        {
            data.setPlayerName(player.getPlayerNameData());
            data.setPlayerData(player.getPlayerData());
            data.setRecourcesData(resManager.UploadData());
            data.setBuildingsData(buildings.UploadData());
            data.setResourcesExtractData(resExtract.UploadData());
            data.setMarketData(market.UploadData());

            data.saveData(g_DataFileName);
            g_Exit = true;
            break;

        }
        default:
            GameMessages::incorrectInput();
            break;
        }
    }

    return 0;
}
