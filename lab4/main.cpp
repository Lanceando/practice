#include <iostream>
#include <bitset>
#include <vector>


void compose(std::vector<char>& numbers) {
	std::string number;
	for (int i = 0; i < 64; i++) {	// переводим все числа в двоичную систему с макс длиной и складываем как строки
		std::string binary = std::bitset<6>(i).to_string();
		number += binary;
	}
	std::cout << "Все числа в двоичной системе: " << number << std::endl;
	std::string num = "";
	std::cout << std::endl << "Разбиваем по 8 знаков" << std::endl;
	int k = 1;
	for (int i = 0; i < number.length(); i++) { // разбиваем числа по массиву
		num += number[i];
		if ((num.length() % 8 == 0) || i == number.length() - 1) {
			unsigned char decimal = std::bitset<8>(num).to_ulong();
			numbers.push_back(decimal);
			std::cout << num << "\t" << k << std::endl;
			num = "";
			k++;
		}
	}
}

void unpucking(std::vector<char>& numbers) {
	std::cout << std::endl << "распаковка" << std::endl;
	std::string number;
	for (int i = 0; i < 48; i++) {	// переводим все числа в двоичную систему с макс длиной и складываем как строки
		std::string binary = std::bitset<8>(numbers[i]).to_string();
		number += binary;
	}
	std::cout << std::endl << number << std::endl;

	std::string num = "";
	int k = 1;
	for (int i = 0; i < number.length(); i++) { // разбиваем числа по массиву
		num += number[i];
		if ((num.length() % 6 == 0) || i == number.length() - 1) {
			unsigned int decimal = std::bitset<6>(num).to_ulong();
			std::cout << decimal << std::endl;
			num = "";
			k++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	int bbb[64] = { 0 };
	std::cout << "Исходный размер чисел от 0 до 63: " << sizeof(bbb) << std::endl;

	// 2^6 = 64

	std::vector<char> numbers;

	compose(numbers); // сжимаем числа

	for (int i = 0; i < 48; i++) {
		std::cout << numbers[i] << "\t" << i + 1 << std::endl;
	}

	std::cout << "После сжатия: " << numbers.size() << std::endl;

	unpucking(numbers);

}