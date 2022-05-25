#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>

class Pedometer {
private:
    typedef struct entry {
        int date[3] = {1, 1, 1970};
        int startTime[2] = {0, 0};
        int endTime[2] = {23, 59};
        int count = 0;
    } entry;
    int startDate[3] = {1, 1, 1970};
    int startTime[2] = {0, 0};
    std::vector <entry> body;
    void getTime(std::string _time, int* hours, int* minutes) {         // функция получения времени
        char* time = new char[_time.size() + 1];
        strcpy(time, _time.c_str());              // первод строки в массив символов
        char* tmp = strtok(time, ": .-");
        *hours = atoi(tmp);                // перевод массив символов в число
        tmp = strtok(NULL, ": .-");
        *minutes = atoi(tmp);
        delete[] time;
    }
    void getDate(std::string _date, int* day, int* month, int* year) {      // функция получения даты
        char* date = new char[_date.size() + 1];
        strcpy(date, _date.c_str());
        char* tmp = strtok(date, ": .-");
        *day = atoi(tmp);
        tmp = strtok(NULL, ": .-");
        *month = atoi(tmp);
        tmp = strtok(NULL, ": .-");
        *year = atoi(tmp);
        delete[] date;
    }
    void showInfo(entry _entry) {                                // функция вывода данных о подсчете
        std::cout << "Дата: ";
        if (_entry.date[0] < 10) std::cout << "0";
        std::cout << _entry.date[0] << "-";
        if (_entry.date[1] < 10) std::cout << "0";
        std::cout << _entry.date[1] << "-" << _entry.date[2] << " ";
        std::cout << "Начало: ";
        if (_entry.startTime[0] < 10) std::cout << "0";
        std::cout << _entry.startTime[0] << ":";
        if (_entry.startTime[1] < 10) std::cout << "0";
        std::cout << _entry.startTime[1] << " ";
        std::cout << "Конец: ";
        if (_entry.endTime[0] < 10) std::cout << "0";
        std::cout << _entry.endTime[0] << ":";
        if (_entry.endTime[1] < 10) std::cout << "0";
        std::cout << _entry.endTime[1] << " ";
        std::cout << "Шаги: " << _entry.count << '\n';
    }
public:
    Pedometer(std::string _time, std::string _date) {
        getTime(_time, &(startTime[0]), &(startTime[1]));
        getDate(_date, &(startDate[0]), &(startDate[1]), &(startDate[2]));
    }

    void showStart() {                                                                       // вывод начальных даты и времени
        std::cout << "Начальное время: " << startTime[0] << ":" << startTime[1] << '\n';
        std::cout << "Начальнвя дата: ";
        if (startDate[0] < 10) std::cout << "0";
        std::cout << startDate[0] << "-";
        if (startDate[1] < 10) std::cout << "0";
        std::cout << startDate[1] << "-" << startDate[2] << '\n';
    }

    void addEntry(std::string _startTime, std::string _endTime, std::string _date, int count) {    // добавление подсчета
        entry _entry;
        getTime(_startTime, &(_entry.startTime[0]), &(_entry.startTime[1]));
        getTime(_endTime, &(_entry.endTime[0]), &(_entry.endTime[1]));
        getDate(_date, &(_entry.date[0]), &(_entry.date[1]), &(_entry.date[2]));
        _entry.count = count;
        body.push_back(_entry);
    }

    void showAll() {                               // вывод всех ролученных данных
        for (int i = 0; i < body.size(); i++) {
            showInfo(body[i]);
        }
    }

    void showRange(std::string _date, std::string _start, std::string _end) {       // вывод всех записей по дате и в диапазоне времен
        int day, month, year; 
        int shours, sminutes;
        int ehours, eminutes;
        int mark = 0;
        getDate(_date, &day, &month, &year);
        getTime(_start, &shours, &sminutes);
        getTime(_end, &ehours, &eminutes);
        for (int i = 0; i < body.size(); i++) {
            if (body[i].date[0] == day && body[i].date[1] == month && body[i].date[2] == year) {
                if (body[i].startTime[0] >= shours && body[i].startTime[1] >= sminutes && body[i].endTime[0] <= ehours && body[i].endTime[1] <= eminutes) {
                    showInfo(body[i]);
                    mark = 1;
                }
            }
        }
        if (!mark) std::cout << "Нет таких подсчетов\n";
    }

    void avgSteps(int month) {                        // среднее количество шагов(если 0, то считается за весь период)
        int steps = 0, amount = 0;
        for (int i = 0; i < body.size(); i++) {
            if (month != 0 && body[i].date[1] != month) continue;
            steps += body[i].count;
            amount++;
        }
        if (steps == 0) std::cout << "Нет шагов за выбранный период\n";
        else {
            std::cout << "Среднее количество шагов ";
            if (month != 0) std::cout << "за месяц";
            std::cout << ": " << (double)steps/amount << '\n';
        }
    }

    void maxSteps(int month) {               // подсчет максимального количества шагов за месяц( если 0, то за весь период)
        int max = 0;
        int date[3];
        for (int i = 0; i < body.size(); i++) {
            if (month != 0 && body[i].date[1] != month) continue;
            if (body[i].count > max) {
                max = body[i].count;
                for (int d = 0; d < 3; d++) {
                    date[d] = body[i].date[d];
                }
            }
        }
        if (max == 0) std::cout << "Нет шагов за выбранный период\n";
        else {
            std::cout << "Максимальное количество шагов ";
            if (month != 0) std::cout << "за месяц ";
            std::cout << max << " было достигнуто ";
            if (date[0] < 10) std::cout << "0";
            std::cout << date[0] << "-";
            if (date[1] < 10) std::cout << "0";
            std::cout << date[1] << "-" << date[2] << '\n';
        }
    }

    void save(std::string path) {                        // запись данных в файл
        std::ofstream file(path);
        for (int i = 0; i < body.size(); i++) {
            if (body[i].date[0] < 10) file << "0";
            file << body[i].date[0] << "-";
            if (body[i].date[1] < 10) file << "0";
            file << body[i].date[1] << "-" << body[i].date[2] << " ";
            if (body[i].startTime[0] < 10) file << "0";
            file << body[i].startTime[0] << ":";
            if (body[i].startTime[1] < 10) file << "0";
            file << body[i].startTime[1] << " ";
            if (body[i].endTime[0] < 10) file << "0";
            file << body[i].endTime[0] << ":";
            if (body[i].endTime[1] < 10) file << "0";
            file << body[i].endTime[1] << " ";
            std::cout << body[i].count << '\n';
        }
        file.close();
        std::cout << "Данные сохранены\n";
    }

    void load(std::string path) {                 // чтение данных из файла
        std::ifstream file(path);
        std::string date, startTime, endTime;
        int count;
        while (file >> date >> startTime >> endTime >> count) {
            addEntry(startTime, endTime, date, count);
        }
        file.close();
        std::cout << "Данные загружены\n";
    }

    ~Pedometer() {}
};

void showMenu() {                                                     // меню
    std::cout << "0. Считать данные из файла\n"
            << "1. Узнать начальные дату и время\n"
            << "2. Добавить подсчет\n"
            << "3. Получить информацию о подсчете выбранному по дате и времени\n"
            << "4. Среднее число шагов в месяце\n"
            << "5. Среднее число шагов за всю историю наблюдений\n"
            << "6. Максимальное число шагов в месяце\n"
            << "7. Максимальное число шагов за всю историю наблюдений\n"
            << "8. Сохранить данные в файл\n"
            << "9. Выход\n";
}

int checkDate(std::string _date) {                     // проверка даты на вшивость
    char* date = new char[_date.size() + 1];
    strcpy(date, _date.c_str());
    char* tmp = strtok(date, ": .-");
    int day = atoi(tmp);
    tmp = strtok(NULL, ": .-");
    int month = atoi(tmp);
    tmp = strtok(NULL, ": .-");
    int year = atoi(tmp);
    delete[] date;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day > 0 && day < 32) return 1;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 0 && day < 31) return 1;
    }
    else if (month == 2) {
        if (day > 0 && day < 29) return 1;
    }
    return 0;
}

int checkTime(std::string _time) {                     // проверка времени на вшивость
    char* time = new char[_time.size() + 1];
    strcpy(time, _time.c_str());
    char* tmp = strtok(time, ": .-");
    int hours = atoi(tmp);
    tmp = strtok(NULL, ": .-");
    int minutes = atoi(tmp);
    if (hours < 0 || hours > 23) return 0;
    if (minutes < 0 || minutes > 59) return 0;
    return 1;
}

int checkRange(std::string _start, std::string _end) {    // проверка диапазона времени на вшивость
    char* start = new char[_start.size() + 1];
    char* end = new char[_end.size() + 1];
    strcpy(start, _start.c_str());
    strcpy(end, _end.c_str());
    char* tmp = strtok(start, ": .-");
    int shours = atoi(tmp);
    tmp = strtok(NULL, ": .-");
    int sminutes = atoi(tmp);
    tmp = strtok(end, ": .-");
    int ehours = atoi(tmp);
    tmp = strtok(NULL, ": .-");
    int eminutes = atoi(tmp);
    delete[] start;
    delete[] end;
    if (shours > ehours) return 0;
    else if (shours == ehours) {
        if (sminutes > eminutes) return 0;
    }
    return 1;
}

int main() {
    Pedometer ped("16:20", "21-06-2003");
    int option = -1;
    std::string date, time, start, end;
    int count = 0;
    int month = 0;
    showMenu();
    while (option != 9) {
        std::cout << "Выберите опцию: ";
        std::cin >> option;
        while (option < 0 || option > 9) {
            std::cout << "Введите корректное значение: ";
            std::cin >> option;
        }
        std::cin.ignore();
        std::cin.clear();                  // очистка буфера ввода
        switch (option) {
        case 0:
            ped.load("ped_in.txt");
            break;
        case 1:
            ped.showAll();
            break;
        case 2:
            std::cout << "Введите дату: ";
            std::getline(std::cin, date);
            if (!checkDate(date)) {
                std::cout << "Неверная дата!\n";
                break;
            }
            std::cout << "Введите начальное время: ";
            std::getline(std::cin, start);
            if (!checkTime(start)) {
                std::cout << "Неверное время!\n";
                break;
            }
            std::cout << "Введите конечное время: ";
            std::getline(std::cin, end);
            if (!checkTime(start)) {
                std::cout << "Неверное время!\n";
                break;
            }
            if (!checkRange(start, end)) {
                std::cout << "Неверный диапазон!\n";
                break;
            }
            std::cout << "Введите количество шагов: ";
            std::cin >> count;
            ped.addEntry(start, end, date, count);
            std::cout << "Подсчет добавлен\n";
            break;
        case 3:
            std::cout << "Введите дату: ";
            std::getline(std::cin, date);
            if (!checkDate(date)) {
                std::cout << "Неверная дата!\n";
                break;
            }
            std::cout << "Введите начальное время: ";
            std::getline(std::cin, start);
            if (!checkTime(start)) {
                std::cout << "Неверное время!\n";
                break;
            }
            std::cout << "Введите конечное время: ";
            std::getline(std::cin, end);
            if (!checkTime(start)) {
                std::cout << "Неверное время!\n";
                break;
            }
            if (!checkRange(start, end)) {
                std::cout << "Неверный диапазон!\n";
                break;
            }
            ped.showRange(date, start, end);
            break;
        case 4:
            std::cout << "Введите номер месяца: ";
            std::cin >> month;
            while (month < 1 || month > 12) {
                std::cout << "Введите корректное значение: ";
                std::cin >> month;
            }
            ped.avgSteps(month);
            break;
        case 5:
            ped.avgSteps(0);
            break;
        case 6:
            std::cout << "Введите номер месяца: ";
            std::cin >> month;
            while (month < 1 || month > 12) {
                std::cout << "Введите корректное значение: ";
                std::cin >> month;
            }
            ped.maxSteps(month);
            break;
        case 7:
            ped.maxSteps(0);
            break;
        case 8:
            ped.save("ped_out.txt");
            break;
        }
    }
}