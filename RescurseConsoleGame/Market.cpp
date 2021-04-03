#include "Market.h"

Market::Market(std::vector<double> dataList)
{
	uint16_t counter = 0;

	sellCOeficient = dataList[counter++];
}

void Market::buySellMenu(ResourceManager &rm)
{
	showBuySellInfo(rm);

	char selectTransfer = '0', selectReosurce = '0';
	std::cout << "Input resource id and select of transfer: ( 4 b )" << std::endl
		<< "b - Buy" << std::endl
		<< "s - Sell" << std::endl
		<< "Any_key - exit" << std::endl;
	std::cin >> selectReosurce >> selectTransfer;
	std::cout << std::endl;


	switch (selectReosurce)
	{
	case '1':
		if (selectTransfer == 'b') {
			buyResource(rm.log);
		}
		sellResource(rm.log);
		break;
	case '2':
		if (selectTransfer == 'b') {
			buyResource(rm.log);
		}
		sellResource(rm.log);
		break;
	case '3':
		if (selectTransfer == 'b') {
			buyResource(rm.log);
		}
		sellResource(rm.log);
		break;
	case '4':
		if (selectTransfer == 'b') {
			buyResource(rm.log);
		}
		sellResource(rm.log);
		break;
	case '5':
		if (selectTransfer == 'b') {
			buyResource(rm.log);
		}
		sellResource(rm.log);
		break;
	case '6':
		if (selectTransfer == 'b') {
			buyResource(rm.log);
		}
		sellResource(rm.log);
		break;
	case '7':
		if (selectTransfer == 'b') {
			buyResource(rm.log);
		}
		sellResource(rm.log);
		break;
	case '8':
		if (selectTransfer == 'b') {
			buyResource(rm.log);
		}
		sellResource(rm.log);
		break;
	case '9':
		if (selectTransfer == 'b') {
			buyResource(rm.log);
		}
		sellResource(rm.log);
		break;
	case 'a':
		if (selectTransfer == 'b') {
			buyResource(rm.log);
		}
		sellResource(rm.log);
		break;
	case 'b':
		if (selectTransfer == 'b') {
			buyResource(rm.log);
		}
		sellResource(rm.log);
		break;
	default:
		std::cout << "Wrong input!" << std::endl << std::endl;
		break;
	}
}

void Market::showBuySellInfo(ResourceManager &rm)
{
	std::cout << "======\tMarket\t=====" << std::endl
		<< "Resource\tCount\tBuy\tSell" << std::endl;
		
	printResourcesBuySellInfo('1', "Log_", rm.log);
	printResourcesBuySellInfo('2', "Wood", rm.wood);
	printResourcesBuySellInfo('3', "Stone", rm.stone);
	printResourcesBuySellInfo('4', "Coal", rm.coal);
	printResourcesBuySellInfo('5', "Copper", rm.copper);
	printResourcesBuySellInfo('6', "Tin_", rm.tin);
	printResourcesBuySellInfo('7', "Bronze", rm.bronze);
	printResourcesBuySellInfo('8', "Silver", rm.silver);
	printResourcesBuySellInfo('9', "Gold", rm.gold);
	printResourcesBuySellInfo('a', "Platina", rm.platina);
	printResourcesBuySellInfo('b', "Diamond", rm.diamond);

	std::cout << std::endl;
}

void Market::printResourcesBuySellInfo(char nameId, std::string name, Resource res)
{
	std::cout << nameId << " - " << name << "\t" << res.getCount()
		<< "\t" << res.getValue()
		<< "\t" << uint64_t(res.getValue() * sellCOeficient)
		<< std::endl;
}
