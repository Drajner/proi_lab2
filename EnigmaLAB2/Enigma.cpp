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
		c -= 32;
		for (int i = 0; i < K; i++)
		{
			wheelSum += enigma[i][state[i]];
		}
		wheelSum = (wheelSum + c) % 95;
		c = wheelSum;
		c += 32;
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
		c -= 32;
		for (int i = 0; i < K; i++)
		{
			wheelSum += enigma[i][state[i]];
		}
		integerC = c;
		integerC -= wheelSum;
		while (integerC < 0) integerC += 95;
		c = integerC;
		c += 32;
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
	int input;
	for (int i = 0; i < K; i++)
	{
		std::cout << "Please enter " << i+1 << " wheel position:" << std::endl;
		std::cin >> input;
		state[i] = input-1;
	}
	return is;
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
	int input;
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
	return is;
};