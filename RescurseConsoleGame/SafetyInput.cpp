#include "SafetyInput.h"

char SafetyInput::cinAndReturnChar(std::string inputMSG = "Input:")
{
	char input = '0';

	std::cout << inputMSG;
	std::cin >> input;
	std::cout << std::endl;
	
	return input;
}

uint16_t SafetyInput::cinAndReturnCharID(std::string inputMSG,
	std::vector<char> nameIdLIst, const size_t MAXIMAL_ID_VALUE)
{	
	char input = '0';

	std::cout << inputMSG;
	std::cin >> input;
	std::cout << std::endl;

	uint16_t output = 0;
	for (size_t i = 0; i < nameIdLIst.size(); i++)
	{
		if (nameIdLIst[i] == input) {
			output = uint16_t(i);
		}
	}

	if (output > MAXIMAL_ID_VALUE - 1) {
		output = 0;
	}

	return output;
}

uint64_t SafetyInput::cinAndReturnUI64T(std::string inputMSG)
{
	std::string str_number = "0";
	uint64_t number = 0;

	std::cout << inputMSG;
	std::cin >> str_number;
	std::cout << std::endl;

	// Check first symbol for correctness 
	// Method of converting string to number - create error if first symbol isn't a number 
	bool charCoincidence = false;
	if (str_number.size() > 0) {
		char numCharList[]{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

		for (auto& ch : numCharList)
		{
			if (ch == str_number[0]) {
				charCoincidence = true;
				break;
			}
		}
	}
	
	if (charCoincidence == true) {
		number = std::stoull(str_number);
		if (number > MAX_PARAM_VALUE) {
			number = MAX_PARAM_VALUE;
		}
	}
	else {
		number = 0;
	}	

	return number;
}

