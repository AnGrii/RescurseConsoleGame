#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <list>
#include <math.h>
#include <conio.h>
#include <thread>
#include <mutex>
#include <functional>
#include <ctime>

#include "DataModule.h"
#include "Player.h"
#include "Resource.h"
#include "ResourceManager.h"
#include "ResourcesExtract.h"
#include "Buildings.h"
#include "BuildingsManager.h"
#include "Market.h"
#include "GameHelper.h"
#include "Settings.h"


// SAVE_DATA turn on / off saving, for including new data and testing, 
// Data in data file will be static
// Reset off together with saving!!!
#define SAVE_DATA 




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

    Settings settings(data.getSettingsData());

    char g_Select = '0';
    bool g_Exit = false;

    while (!g_Exit)
    {
        GameMessages::keywordHelp(settings.getShowKeywordHelpStatus());

        buildings.updateBuildingsQueue();
        buildings.work(resManager);
        buildings.brokeEvent();

        player.printBalance();
        resManager.printResourcesCount();
        
        std::cout << std::endl;
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
        case 'k':
            buildings.skipBuildingMenu(player);
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
            //market.buySellMenu(player, resManager);
            break;
        case 'r':
#ifdef SAVE_DATA
            data.resetDataWithSecurity(g_DataFileName);
#endif
            break;
        case 'a':
            GameMessages::About();
            break;
        case 's':
            settings.settingsMenu(settings, player);
            break;
        case 'x': 
        {
#ifdef SAVE_DATA
            data.setPlayerName(player.getPlayerNameData());
            data.setPlayerData(player.getPlayerData());
            data.setRecourcesData(resManager.UploadData());
            data.setBuildingsData(buildings.UploadData());
            data.setResourcesExtractData(resExtract.UploadData());
            //data.setMarketData(market.UploadData());
            data.setSettingsData(settings.UploadData());

            data.saveData(g_DataFileName);
#endif
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
