#include "CppUnitTest.h"
#include"../EnigmaLAB2/Enigma.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EnigmaTest
{
	TEST_CLASS(EnigmaTest)
	{
	public:

		TEST_METHOD(TestEncrypt1)
		{
			Enigma enigma;
			enigma = generateMachine();
			EnigmaState state = { 0,0,0,0 };
			std::string checkedString = encrypt("abc", state, enigma);
			std::string correctString = "ace";
			Assert::IsTrue(checkedString == correctString);
		}
		TEST_METHOD(TestEncrypt2)
		{
			Enigma enigma;
			enigma = generateMachine();
			EnigmaState state = { 0,0,0,0 };
			std::string checkedString = encrypt("aaaaa", state, enigma);
			std::string correctString = "abcde";
			Assert::IsTrue(checkedString == correctString);
		}
		TEST_METHOD(TestEncrypt3)
		{
			Enigma enigma;
			enigma = generateMachine();
			EnigmaState state = { 8,0,3,0 };
			std::string checkedString = encrypt("11111", state, enigma);
			std::string correctString = "<=>?@";
			Assert::IsTrue(checkedString == correctString);
		}
		TEST_METHOD(TestEncrypt4)
		{
			Enigma enigma;
			enigma = generateMachine();
			EnigmaState state = { 5,0,0,0 };
			std::string checkedString = encrypt("~~~~~", state, enigma);
			std::string correctString = "$%&'(";
			Assert::IsTrue(checkedString == correctString);
		}
		TEST_METHOD(TestEncrypt5)
		{
			Enigma enigma;
			enigma = generateMachine();
			EnigmaState state = { 19,0,0,0 };
			std::string checkedString = encrypt("aaaaa", state, enigma);
			std::string correctString = "tbcde";
			Assert::IsTrue(checkedString == correctString);
		}
		TEST_METHOD(TestDecrypt1)
		{
			Enigma enigma;
			enigma = generateMachine();
			EnigmaState state = { 3,0,0,0 };
			std::string checkedString = decrypt("ace", state, enigma);
			std::string correctString = "abc";
			Assert::IsTrue(checkedString == correctString);
		}
		TEST_METHOD(TestDecrypt2)
		{
			Enigma enigma;
			enigma = generateMachine();
			EnigmaState state = { 5,0,0,0 };
			std::string checkedString = decrypt("abcde", state, enigma);
			std::string correctString = "aaaaa";
			Assert::IsTrue(checkedString == correctString);
		}
		TEST_METHOD(TestDecrypt3)
		{
			Enigma enigma;
			enigma = generateMachine();
			EnigmaState state = { 13,0,3,0 };
			std::string checkedString = decrypt("<=>?@", state, enigma);
			std::string correctString = "11111";
			Assert::IsTrue(checkedString == correctString);
		}
		TEST_METHOD(TestDecrypt4)
		{
			Enigma enigma;
			enigma = generateMachine();
			EnigmaState state = { 10,0,0,0 };
			std::string checkedString = decrypt("$%&'(", state, enigma);
			std::string correctString = "~~~~~";
			Assert::IsTrue(checkedString == correctString);
		}
		TEST_METHOD(TestDecrypt5)
		{
			Enigma enigma;
			enigma = generateMachine();
			EnigmaState state = { 4,1,0,0 };
			std::string checkedString = decrypt("tbcde", state, enigma);
			std::string correctString = "aaaaa";
			Assert::IsTrue(checkedString == correctString);
		}
		TEST_METHOD(TestGenerateMachine)
		{
			Enigma enigma;
			enigma = generateMachine();
			std::array<int, N> testEnigmaPart;
			testEnigmaPart = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
			Assert::IsTrue(enigma[0] == testEnigmaPart);
			Assert::IsTrue(enigma[1] == testEnigmaPart);
			Assert::IsTrue(enigma[2] == testEnigmaPart);
			Assert::IsTrue(enigma[3] == testEnigmaPart);
		}
	};
};
