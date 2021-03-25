#include <string>
#include <cstddef>
#include <array>
#pragma once
#define K 4
#define N 20

typedef std::array<size_t, K> EnigmaState;

typedef std::array<std::array<int, N>, K> Enigma;

std::string encrypt(
	std::string const& message,
	EnigmaState& state,
	Enigma const& enigma
);

std::string decrypt(
	std::string const& message,
	EnigmaState& state,
	Enigma const& enigma
);

Enigma generateMachine();

std::ostream& operator<<(std::ostream& os, EnigmaState& state);
std::istream& operator>>(std::istream& is, EnigmaState& state);

std::ostream& operator<<(std::ostream& os, Enigma& enigma);
std::istream& operator>>(std::istream& is, Enigma& enigma);