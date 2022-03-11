#include <iostream>
#include <string>

class Octal {
private:
    int* value;
    int sizef;
public:
    Octal(int size) {
        sizef = size;
        value = new int[size];
        for (int i = 0; i < size; i++) value[i] = 0;
    }

    void operator=(int num) {
        int i = 0;
        while (num > 0) {
            value[i++] = num % 10;
            num /= 10;
        }
    }
    Octal operator=(const Octal& other) {
        if (sizef != other.sizef) {
            std::cout << "error\n";
            return 0;
        }
        for (int i = 0; i < sizef; i++) this->value[i] = other.value[i];
    }
    Octal operator+(const Octal& other) {
        int min = (sizef < other.sizef) ? sizef : other.sizef;
        int max = (sizef > other.sizef) ? sizef : other.sizef;
        Octal temp(max + ((this->value[sizef - 1] + other.value[other.sizef - 1] > 7) ? 1 : 0));
        for (int i = 0; i < min; i++) {
            int tmp = this->value[i] + other.value[i];
            temp.value[i] += tmp % 8;
            if (tmp / 8 > 0) {
                temp.value[i + 1] += tmp / 8;
            }
        }
        for (int i = min; i < max; i++) {
            temp.value[i] += (sizef > other.sizef) ? this->value[i] : other.value[i];
        }
        return temp;
    }
    Octal operator-(const Octal& other) {
        if (sizef < other.sizef) {
            std::cout << "error\n";
            return 0;
        }
        if (sizef == other.sizef) {
            for (int i = sizef; i >= 0; i--) {
                if (value[i] > other.value[i]) {
                    break;
                }
                else if (value[i] < other.value[i]) {
                    std::cout << "error\n";
                    return 0;
                }
            }
        }
        int sizep = sizef;
        if (sizef == other.sizef) {
            for (int i = sizef - 1; i >= 0 && value[i] == other.value[i]; i--) sizep--;
        }
        else {
            if (other.value[other.sizef - 1] > value[other.sizef - 1]) {
                if ((other.sizef == sizef - 1 && value[other.sizef] == 1) || (value[other.sizef] == 0 && value[sizef - 1] == 1))
                    sizep--;
            }
        }
        Octal temp(sizep);
        for (int i = 0; i < sizep; i++) {
            if (i < other.sizef) {
                if (value[i] - other.value[i] >= 0) temp.value[i] = value[i] - other.value[i];
                else {
                    value[i + 1] -= 1;
                    value[i] += 8;
                    temp.value[i] = value[i] - other.value[i];
                }
            }
            else {
                if (value[i] <= 0) {
                    value[i + 1] -= 1;
                    value[i] += 8;
                }
                temp.value[i] = value[i];
            }
        }
        return temp;
    }
    bool operator==(const Octal& other) {
        if (sizef != other.sizef) return false;
        for (int i = 0; i < sizef; i++) {
            if (value[i] != other.value[i]) return false;
        }
        return true;
    }
    bool operator>(const Octal& other) {
        if (sizef > other.sizef) return true;
        else if (sizef < other.sizef) return false;
        else {
            for (int i = sizef - 1; i >= 0; i--) {
                if (value[i] > other.value[i]) return true;
            }
            return false;
        }
    }
    bool operator<(const Octal& other) {
        if (sizef < other.sizef) return true;
        else if (sizef < other.sizef) return false;
        else {
            for (int i = sizef - 1; i >= 0; i--) {
                if (value[i] < other.value[i]) return true;
            }
            return false;
        }
    }

    void print() {
        for (int i = sizef - 1; i >= 0; i--) std::cout << value[i];
        std::cout << '\n';
    }

    ~Octal() {}
};

int main() {
    int option;
    int x;
    std::cout << "������ ������� �����: ";
    std::cin >> x;
    Octal num1(x);
    std::cout << "������ ������� �����: ";
    std::cin >> x;
    Octal num2(x);
    while (true) {
        system("cls");
        std::cout << "num1 = "; num1.print();
        std::cout << "num2 = "; num2.print();
        std::cout << "����� �����:\n1 - ������������\n2 - ��������\n3 - ���������\n4 - ���������\n5 - �����\n�����: ";
        std::cin >> option;
        switch (option) {
        case 1:
            int num, x;
            std::cout << "1 - ������ �����, 2 - ������ �����: ";
            std::cin >> num;
            std::cout << "��������: ";
            std::cin >> x;
            switch (num) {
            case 1:
                num1 = x;
                break;
            case 2:
                num2 = x;
                break;
            }
            break;
        case 2:
            (num1 + num2).print();
            system("pause");
            break;
        case 3:
            (num1 - num2).print();
            system("pause");
            break;
        case 4:
            char sign;
            std::cout << "���� (>, <, =): ";
            std::cin >> sign;
            switch (sign) {
            case '>':
                std::cout << ((num1 > num2) ? "True" : "False") << std::endl;
                break;
            case '<':
                std::cout << ((num1 < num2) ? "True" : "False") << std::endl;
                break;
            case '=':
                std::cout << ((num1 == num2) ? "True" : "False") << std::endl;
                break;
            }
            system("pause");
            break;
        case 5:
            exit(0);
        }
    }
}