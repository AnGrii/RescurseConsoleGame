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
#include "ResAutoBuy.h"
#include "ResAutoSell.h"


/// SAVE_DATA turn on / off saving of game
/// Function Reset will be off together with saving!!!
/// For including new data and testing new features
#define SAVE_DATA
// RESET_METHOD turn on / off reset
// For prevent losing new data for new components while it's in development progress
#define RESET_METHOD


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

    ResAutoBuy resAutoBuy(data.setResAutoBuyData());

    ResAutoSell resAutoSell(data.setResAutoSellData());

    bool g_Exit = false;

    while (not g_Exit)
    {
        GameMessages::keywordHelp(settings.getShowKeywordHelpStatus());


        buildings.updateBuildingsQueue();

        buildings.work(resManager);

        buildings.brokeEvent();


        resAutoBuy.countBuy(player, resManager);

        resAutoBuy.levelBuy(player, resManager);


        resAutoSell.countSell(player, resManager);

        resAutoSell.percentSell(player, resManager);


        player.printBalance();

        resManager.printResourcesCount();
        

        char g_Select = SafetyInput::cinAndReturnChar("Input: ");

        switch (g_Select)
        {
        case 'e':
           resExtract.extract(resManager.log, resManager.wood, resManager.stone);
            break;
        case 'g':
            resExtract.upgradeResourceExtractionMenu(player);
            break;
        case 'n':
            GameMessages::skipLine();
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            break;
        case 'b':
            buildings.buildMenu(resManager);
            break;
        case 'u':
            buildings.upgradeMenu(player);
            break;
        case 'q':
            buildings.printQueueStatus();
            break;
        case 'k':
            buildings.skipBuildingMenu(player);
            break;
        case 'i':
            buildings.printBuildingsInfo();
            break;
        case 'p':
            buildings.productivitySettingMenu();
            break;
        case 'm':
            market.Menu(player, resManager);
            break;
        case 't':
            resAutoSell.Menu(resManager);
            break;
        case 'o':
            resAutoBuy.Menu(resManager);
            break;
        case 'r':
#ifdef SAVE_DATA
#ifdef RESET_METHOD
            data.resetDataWithSecurity(g_DataFileName);
#endif // RESET_METHOD
#endif // SAVE_DATA
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

            data.setMarketData(market.UploadData());

            data.setSettingsData(settings.UploadData());

            data.setResAutoBuyData(resAutoBuy.UploadData());

            data.setResAutoSellData(resAutoSell.UploadData());

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
