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



int main()
{
    //Loading and initialisation data
    DataModule data("Data.txt");

    Player player(data.getPlayerName(), data.getPlayerData());
    Resource res(data.getRecourcesData());


    char g_Select = '0';
    bool g_Exit = false;

    while (!g_Exit)
    {
        res.printResourcesCount();

        std::cin >> g_Select;

        switch (g_Select)
        {
        case 'e':
            ResourcesEtract::extract(res.log, res.wood, res.wood);
            break;
        case 's':
            std::cout << "Skiped (0  )/\\(0  )!" << std::endl;
            break;
        case 'x':
            g_Exit = true;
            break;
        default:
            std::cout << "Incorrect input!!!" << std::endl;
            break;
        }
    }
   


    return 0;
}
