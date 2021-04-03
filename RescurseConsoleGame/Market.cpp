#include "Market.h"

Market::Market(std::vector<double> dataList)
{
	uint16_t counter = 0;

	sellCOeficient = dataList[counter++];
}

void Market::buySellMenu(Player& p, ResourceManager &rm)
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
			buyResource(p, rm.log);
		}
		sellResource(p, rm.log);
		break;
	case '2':
		if (selectTransfer == 'b') {
			buyResource(p, rm.wood);
		}
		sellResource(p, rm.wood);
		break;
	case '3':
		if (selectTransfer == 'b') {
			buyResource(p, rm.stone);
		}
		sellResource(p, rm.stone);
		break;
	case '4':
		if (selectTransfer == 'b') {
			buyResource(p, rm.coal);
		}
		sellResource(p, rm.coal);
		break;
	case '5':
		if (selectTransfer == 'b') {
			buyResource(p, rm.copper);
		}
		sellResource(p, rm.copper);
		break;
	case '6':
		if (selectTransfer == 'b') {
			buyResource(p, rm.tin);
		}
		sellResource(p, rm.tin);
		break;
	case '7':
		if (selectTransfer == 'b') {
			buyResource(p, rm.bronze);
		}
		sellResource(p, rm.bronze);
		break;
	case '8':
		if (selectTransfer == 'b') {
			buyResource(p, rm.silver);
		}
		sellResource(p, rm.silver);
		break;
	case '9':
		if (selectTransfer == 'b') {
			buyResource(p, rm.gold);
		}
		sellResource(p, rm.gold);
		break;
	case 'a':
		if (selectTransfer == 'b') {
			buyResource(p, rm.platina);
		}
		sellResource(p, rm.platina);
		break;
	case 'b':
		if (selectTransfer == 'b') {
			buyResource(p, rm.diamond);
		}
		sellResource(p, rm.diamond);
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

void Market::buyResource(Player& p, Resource& res)
{
	uint64_t count = 0, transferValue = 0;

	std::cout << "Input count: ";
	std::cin >> count;
	std::cout << std::endl;

	transferValue = count * res.getValue();

	if (p.getBalance() >= transferValue) {
		res.add(count);
		p.reduceBalance(transferValue);
	}
	else
	{
		std::cout << "Not enough money!!!" << std::endl;
	}
}

void Market::sellResource(Player& p, Resource& res)
{
	uint64_t count = 0, transferValue = 0;

	std::cout << "Input count: ";
	std::cin >> count;
	std::cout << std::endl;

	transferValue = count * res.getValue() * sellCOeficient;

	if (res.getCount() >= count) {
		res.reduce(count);
		p.addBalance(transferValue);
	}
	else
	{
		std::cout << "Not enough count of resource!!!" << std::endl;
	}
}

void Market::printResourcesBuySellInfo(char nameId, std::string name, Resource res)
{
	std::cout << nameId << " - " << name << "\t" << res.getCount()
		<< "\t" << res.getValue()
		<< "\t" << uint64_t(res.getValue() * sellCOeficient)
		<< std::endl;
}
