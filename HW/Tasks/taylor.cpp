#include <iostream>
#include <fstream>
#include <cmath>

class Taylor {
public:
    double* koefs = nullptr;
    int size = 0;
    int x = 0;
    int parameter = 0;
    double answer = 0;
    unsigned int factorial(unsigned int n) {
        if (n == 0)
        return 1;
        return n * factorial(n - 1);
    }

    Taylor() { }

    Taylor(int num) {
        size = num;
        create();
    }

    void create() {                                                               // создание коэффициентов ряда Тейлора
        koefs = new double[size];
        for (int i = 0; i < size; i++) koefs[i] = exp(parameter)/factorial(i);
    }

    void getKoef(int index) {                                                      // вывод нужного коэффициента
        if (index < 0 || index > size) { std::cout << "error\n"; return; }
        std::cout << "koef " << index << ": " << koefs[index-1] << "x^" << index-1 << '\n';
    }

    void showFormula() {                                         // вывод ряда Тейлора
        for (int i = 0; i < size; i++) {
            std::cout << koefs[i];
            if (i != 0) std::cout << "x^" << i;
            std::cout << " ";
            if (i+1 != size) std::cout << "+ ";
            else std::cout << '\n';
        }
    }

    void solve() {                                             // решение 
        answer = 0;
        for (int i = 0; i < size; i++) answer += koefs[i]*pow(x,i);
    }

    void showDiff() {                                            // разница между эталонным значением и полученным
        double ethalon = exp(x);
        std::cout << "ethalon: " << ethalon << " diff: " << ethalon - answer << '\n';
    }

    ~Taylor() {}
};

std::ostream& operator<< (std::ostream &out, const Taylor &tay) {          // перегрузка записи в файл
    for (int i = 0; i < tay.size; i++) {
        out << tay.koefs[i];
        if (i != 0) out << "x^" << i;
        out << " ";
        if (i+1 != tay.size) out << "+ ";
        else out << '\n';
    }
    out << tay.answer;
    return out;
}

std::ifstream& operator>> (std::ifstream &in, Taylor &tay) {               // перегрузка чтения данных из файла
    in >> tay.x;
    in >> tay.parameter;
    in >> tay.size;
    return in;
}

void showMenu() {                                                          // меню
    std::cout << "1. Сгенерировать ряд Тейлора по данным из файла\n"
            << "2. Ввести данные вручную\n"
            << "3. Вывести ряд Тейлора и решение на экран\n"
            << "4. Вывести отклонения значения ряда\n"
            << "5. Получить коэффициент по индексу\n"
            << "6. Сохранить данные в файл\n"
            << "7. Выход\n";
}

int main() {
    Taylor tay;
    int option = 0;
    std::ifstream in;
    std::ofstream out;
    showMenu();
    while (option != 7) {
        std::cout << "Выберите опцию: ";
        std::cin >> option;
        while (option < 1 || option > 7) {
            std::cout << "Введите корректное значение: ";
            std::cin >> option;
        }
        switch (option) {
        case 1:
            in.open("in.txt");
            in >> tay;
            tay.create();
            in.close();
            std::cout << "Данные приняты\n";
            break;
        case 2:
            std::cout << "x: ";
            std::cin >> tay.x;
            std::cout << "a: ";
            std::cin >> tay.parameter;
            std::cout << "Количество членов: ";
            std::cin >> tay.size;
            tay.create();
            break;
        case 3:
            tay.showFormula();
            tay.solve();
            std::cout << tay.answer << '\n';
            break;
        case 4:
            tay.showDiff();
            break;
        case 5:
            int index;
            std::cout << "Индекс: ";
            std::cin >> index;
            tay.getKoef(index);
            break;
        case 6:
            out.open("out.txt");
            tay.solve();
            out << tay;
            out.close();
            std::cout << "Данные сохранены\n";
        }
    }
}