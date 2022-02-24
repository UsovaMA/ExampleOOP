/*
Task 1 (������� 5): ����������� ����� Time ��� ������ � �������� � �������, �������������� � ���� ������
hours, minutes, seconds. ����� ������ ���������: ������������/����������
�������: ������������, ��������, ���������, ���������, �����/����.
*/

#include<iostream>
#include <string>
#define DAYSEC 86400 // ���������� ������ � ������

class Time {
private:
	int hours, minutes, seconds; // �������� ����������
public:
	int day = 0; // ������� ���� 
	Time() { hours = minutes = seconds = 0; } // ����������� �� ���������
	// ����������� �������������
	Time(std::string str) {
		for (int i = 0, _switch = hours = minutes = seconds = 0; i < str.length(); i++) {
			if (str[i] == ':' || str[i] == ' ') { _switch++; }
			if (_switch == 0 && !(str[i] == ':' || str[i] == ' ')) { hours = hours * 10 + str[i] - 0x30; }
			else if (_switch == 1 && !(str[i] == ':' || str[i] == ' ')) { minutes = minutes * 10 + str[i] - 0x30; }
			else if (_switch == 2 && !(str[i] == ':' || str[i] == ' ')) { seconds = seconds * 10 + str[i] - 0x30; }
		}
	}
	// ����������� �����������
	Time(const Time& time) {
		hours = time.hours;
		minutes = time.minutes;
		seconds = time.seconds;
	}
	// �����
	void print() {
		std::cout << "���� " << day << " - " << "�����: " << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << std::endl;
	}
	// ���������� ������� � ���������� � ����������� �������
	void update() {
		day += ((hours + (minutes + (seconds / 60)) / 60) / 24);
		hours = (hours + ((minutes + (seconds / 60)) / 60)) % 24;
		minutes = (minutes + (seconds / 60)) % 60;
		seconds %= 60;
	}
	// ��������
	void plus(const Time& time) {
		seconds = (seconds + (((hours * 60) + minutes) * 60)) + (time.seconds + (((time.hours * 60) + time.minutes) * 60));
		hours = minutes = 0;
		update();
	}
	// ���������
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
	// ���������
	void change(const Time& time) {
		seconds = (time.seconds + (((time.hours * 60) + time.minutes) * 60));
		hours = minutes = 0;
		update();
	}
	// ���������
	void compare(const Time& time) {
		int tfirst = seconds + (((hours * 60) + minutes) * 60);
		int tsecond = time.seconds + (((time.hours * 60) + time.minutes) * 60);
		char cmp = ' ';
		if (tfirst > tsecond) cmp = '>';
		else if (tfirst < tsecond) cmp = '<';
		else cmp = '=';
		std::cout << "���������: (" << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds <<
			") " << cmp << " (" << (time.hours < 10 ? "0" : "") << time.hours << ":" << (time.minutes < 10 ? "0" : "") << time.minutes << ":" << (time.seconds < 10 ? "0" : "") << time.seconds << ")\n";
	}
	~Time() {} // ����������
};

int main() {
	std::string str;
	int option;
	std::cout << "������� ����� � ������� (�:�:�) ��� (� � �): ";
	getline(std::cin, str);
	Time time_one(str);
	while (true) {
		std::cout << "�������� ��������: \n" << "1 - ��������� �����\n" << "2 - ��������� �����\n" << "3 - �������� �����\n" << "4 - �������� �����\n" << "0 - �����\n";
		std::cin >> option;
		if (option == 0) { break; }
		std::cout << "������� ����� � ������� (�:�:�) ��� (� � �): ";
		std::cin.ignore();
		getline(std::cin, str);
		system("cls"); // ������� ������
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
