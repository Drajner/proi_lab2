#include "Enigma.h"
#include <string>
#include <cstddef>
#include <array>
#include <iostream>

Enigma generateMachine() {
	Enigma e{};
	for (auto& wheel : e)
	{
		int i = 0;
		for (auto& number : wheel) number = i++;
	}
	return e;
};

void plusState(EnigmaState& state) {

	for (int i = 0; i < K; i++)
	{
		if (state[i] == 19) state[i] = 0;
		else 
		{
			state[i]++;
			break;
		}
	}
}
void minusState(EnigmaState& state) {

	for (int i = 0; i < K; i++)
	{
		if (state[i] == 0) state[i] = 19;
		else
		{
			state[i]--;
			break;
		}
	}
}

std::string encrypt(
	std::string const& message,
	EnigmaState& state,
	Enigma const& enigma
)
{
	std::string encrypted;
	int wheelSum = 0;
	for (auto c : message)
	{
		wheelSum = 0;
		c -= ' ';
		for (int i = 0; i < K; i++)
		{
			wheelSum += enigma[i][state[i]];
		}
		wheelSum = (wheelSum + c) % '_';
		c = wheelSum;
		c += ' ';
		encrypted += c;
		plusState(state);
	}
	return encrypted;
}


std::string decrypt(
	std::string const& message,
	EnigmaState& state,
	Enigma const& enigma
)
{
	
	std::string decrypted;
	int wheelSum = 0;
	int text_size = message.length();
	int integerC;
	char c;
	for (int j = text_size-1; j>=0;j--)
	{
		minusState(state);
		wheelSum = 0;
		c = message[j];
		c -= ' ';
		for (int i = 0; i < K; i++)
		{
			wheelSum += enigma[i][state[i]];
		}
		integerC = c;
		integerC -= wheelSum;
		while (integerC < 0) integerC += '_';
		c = integerC;
		c += ' ';
		decrypted = c + decrypted;
	}
	return decrypted;
}

std::ostream& operator<<(std::ostream& os, EnigmaState& state)
{
	for (auto part : state)
	{
		os << part + 1 << " ";
	}
	os << std::endl;
	return os;
};
std::istream& operator>>(std::istream& is, EnigmaState& state)
{
	// kod dzia³a kiedy wpiszemy wszystkie liczby po przecinku: 1,2,3,4
	std::string input;
	getline(is, input);
	std::string number_to_be;
	std::array<int, K> new_state;
	int control_counter = 0;
	int iterator = 0;
	int input_length = input.length();
	bool end_of_string = false;
	bool number_not_complete = true;
	if (input[0])
	{
		while (control_counter < 4)
		{
			number_to_be = "";
			number_not_complete = true;
			while (number_not_complete)
			{
				if (input[iterator] <= '9' && input[iterator] >= '0')
				{
					number_to_be += input[iterator];
				}
				if (iterator + 1 < input.length())
				{
					if (input[iterator + 1] <= '9' && input[iterator + 1] >= '0')
					{
						iterator++;
						continue;
					}
					else
					{
						number_not_complete = false;
						new_state[control_counter] = stoi(number_to_be)-1;
						control_counter++;
						iterator++;
					}
				}
				else
				{
					number_not_complete = false;
					new_state[control_counter] = stoi(number_to_be) - 1;
					control_counter++;
					end_of_string = true;
					break;
				}
			}
			if (end_of_string)
			{
				if (new_state[3])
				{
					for (int i = 0; i < K; i++) state[i] = new_state[i];
					return is;
				}
				else return is;
			}
		}
	}
	else return is;
	if (new_state[3])
	{
		for (int i = 0; i < K; i++) state[i] = new_state[i];
		return is;
	}
	else return is;
	/*
	int input;
	for (int i = 0; i < K; i++)
	{
		std::cout << "Please enter " << i+1 << " wheel position:" << std::endl;
		std::cin >> input;
		state[i] = input-1;
	}
	return is;*/
};

std::ostream& operator<<(std::ostream& os, Enigma& enigma)
{
	for (auto wheel : enigma)
	{
		os << "[";
		for (auto number : wheel)
		{
			os << " " << number << " ";
		}
		os << "]" << std::endl;
	}
	return os;
};
std::istream& operator>>(std::istream& is, Enigma& enigma)
{
	// kod dzia³a kiedy wpiszemy wszystkie liczby po przecinku: 1,2,3,4
	std::string input;
	getline(is, input);
	std::string number_to_be;
	std::array<int, K*N> new_enigma;
	int control_counter = 0;
	int iterator = 0;
	int input_length = input.length();
	bool end_of_string = false;
	bool number_not_complete = true;
	int helping_number = 0;
	if (input[0])
	{
		while (control_counter < 4)
		{
			number_to_be = "";
			number_not_complete = true;
			while (number_not_complete)
			{
				if (input[iterator] <= '9' && input[iterator] >= '0')
				{
					number_to_be += input[iterator];
				}
				if (iterator + 1 < input.length())
				{
					std::cout << input[iterator + 1] << std::endl;
					if (input[iterator + 1] <= '9' && input[iterator + 1] >= '0')
					{
						iterator++;
						continue;
					}
					else
					{
						number_not_complete = false;
						new_enigma[control_counter] = stoi(number_to_be) - 1;
						control_counter++;
						iterator++;
					}
				}
				else
				{
					number_not_complete = false;
					new_enigma[control_counter] = stoi(number_to_be) - 1;
					control_counter++;
					end_of_string = true;
					break;
				}
			}
			if (end_of_string)
			{
				if (new_enigma[3])
				{
					for (int i = 0; i < K * N; i++)
					{
						helping_number = i / N;
						enigma[helping_number][i % N] = new_enigma[i];
					}
					return is;
				}
				else return is;
			}
		}
	}
	else return is;
	if (new_enigma[3])
	{
		for (int i = 0; i < K * N; i++)
		{
			helping_number = i / N;
			enigma[helping_number][i % N] = new_enigma[i];
		}
		return is;
	}
	else return is;
	/*int input;
	for (int i = 0; i < K; i++)
	{
		std::cout << "Please enter numbers for " << i+1 << " wheel." << std::endl;
		for (int j = 0; j < N; j++)
		{
			std::cout << "Please enter " << j+1 << " number:" << std::endl;
			std::cin >> input;
			enigma[i][j] = input;
		}
	}
	return is;*/
};