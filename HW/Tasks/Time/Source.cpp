/*
Task 1 (вариант 5): Разработать класс Time для работы с временем в формате, представленным в виде тройки
hours, minutes, seconds. Класс должен содержать: конструкторы/деструктор
оперции: присваивания, сложения, вычитания, сравнения, вывод/ввод.
*/

#include<iostream>
#include <string>
#define DAYSEC 86400 // Количество секунд в сутках

class Time {
private:
	int hours, minutes, seconds; // Основные переменные
public:
	int day = 0; // Счетчик дней 
	Time() { hours = minutes = seconds = 0; } // Конструктор по умолчанию
	// Конструктор инициализации
	Time(std::string str) {
		for (int i = 0, _switch = hours = minutes = seconds = 0; i < str.length(); i++) {
			if (str[i] == ':' || str[i] == ' ') { _switch++; }
			if (_switch == 0 && !(str[i] == ':' || str[i] == ' ')) { hours = hours * 10 + str[i] - 0x30; }
			else if (_switch == 1 && !(str[i] == ':' || str[i] == ' ')) { minutes = minutes * 10 + str[i] - 0x30; }
			else if (_switch == 2 && !(str[i] == ':' || str[i] == ' ')) { seconds = seconds * 10 + str[i] - 0x30; }
		}
	}
	// Конструктор копирования
	Time(const Time& time) {
		hours = time.hours;
		minutes = time.minutes;
		seconds = time.seconds;
	}
	// Вывод
	void print() {
		std::cout << "День " << day << " - " << "Время: " << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << std::endl;
	}
	// Обновление времени и приведение к правильному формату
	void update() {
		day += ((hours + (minutes + (seconds / 60)) / 60) / 24);
		hours = (hours + ((minutes + (seconds / 60)) / 60)) % 24;
		minutes = (minutes + (seconds / 60)) % 60;
		seconds %= 60;
	}
	// Сложение
	void plus(const Time& time) {
		seconds = (seconds + (((hours * 60) + minutes) * 60)) + (time.seconds + (((time.hours * 60) + time.minutes) * 60));
		hours = minutes = 0;
		update();
	}
	// Вычитание
	void minus(const Time& time) {
		seconds = (seconds + (((hours * 60) + minutes) * 60)) - (time.seconds + (((time.hours * 60) + time.minutes) * 60));
		hours = minutes = 0;
		if (seconds < 0) {
			while (seconds < 0) {
				day--;
				seconds += DAYSEC;
			}
		}
		update();
	}
	// Изменение
	void change(const Time& time) {
		seconds = (time.seconds + (((time.hours * 60) + time.minutes) * 60));
		hours = minutes = 0;
		update();
	}
	// Сравнение
	void compare(const Time& time) {
		int tfirst = seconds + (((hours * 60) + minutes) * 60);
		int tsecond = time.seconds + (((time.hours * 60) + time.minutes) * 60);
		char cmp = ' ';
		if (tfirst > tsecond) cmp = '>';
		else if (tfirst < tsecond) cmp = '<';
		else cmp = '=';
		std::cout << "Сравнение: (" << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds <<
			") " << cmp << " (" << (time.hours < 10 ? "0" : "") << time.hours << ":" << (time.minutes < 10 ? "0" : "") << time.minutes << ":" << (time.seconds < 10 ? "0" : "") << time.seconds << ")\n";
	}
	~Time() {} // Деструктор
};

int main() {
	std::string str;
	int option;
	std::cout << "Введите время в формате (ч:м:с) или (ч м с): ";
	getline(std::cin, str);
	Time time_one(str);
	while (true) {
		std::cout << "Выберите операцию: \n" << "1 - Увеличить время\n" << "2 - Уменьшить время\n" << "3 - Изменить время\n" << "4 - Сравнить время\n" << "0 - Выход\n";
		std::cin >> option;
		if (option == 0) { break; }
		std::cout << "Введите время в формате (ч:м:с) или (ч м с): ";
		std::cin.ignore();
		getline(std::cin, str);
		system("cls"); // Очистка экрана
		Time time_two(str);
		switch (option) {
		case 1:
			time_one.plus(time_two);
			break;
		case 2:
			time_one.minus(time_two);
			break;
		case 3:
			time_one.change(time_two);
			break;
		case 4:
			time_one.compare(time_two);
			break;
		}
		time_one.print();
	}

}
