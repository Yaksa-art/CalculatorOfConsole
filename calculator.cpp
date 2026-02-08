#include <iostream>
#include <windows.h>

using namespace std;

// Прототипы функций
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, int exp);
double squareRoot(double num);
double percentage(double num, double percent);

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    int choice;
    double num1, num2, result;

    cout << "====== КАЛЬКУЛЯТОР =======н" << endl;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 0) {
            cout << "Выход из программы!" << endl;
            break;
        }

        switch (choice) {
        case 1: // Сложение
            cout << "Введите первое число: ";
            cin >> num1;
            cout << "Введите второе число: ";
            cin >> num2;
            result = add(num1, num2);
            cout << "Результат: " << result << endl << endl;
            break;

        case 2: // Вычитание
            cout << "Введите первое число: ";
            cin >> num1;
            cout << "Введите второе число: ";
            cin >> num2;
            result = subtract(num1, num2);
            cout << "Результат: " << result << endl << endl;
            break;

        case 3: // Умножение
            cout << "Введите первое число: ";
            cin >> num1;
            cout << "Введите второе число: ";
            cin >> num2;
            result = multiply(num1, num2);
            cout << "Результат: " << result << endl << endl;
            break;

        case 4: // Деление
            cout << "Введите делимое: ";
            cin >> num1;
            cout << "Введите делитель: ";
            cin >> num2;
            if (num2 != 0) {
                result = divide(num1, num2);
                cout << "Результат: " << result << endl << endl;
            }
            else {
                cout << "ОШИБКА: Деление на ноль!" << endl << endl;
            }
            break;

        case 5: // Возведение в степень
            cout << "Введите основание: ";
            cin >> num1;
            int exp;
            cout << "Введите степень (целое число): ";
            cin >> exp;
            result = power(num1, exp);
            cout << "Результат: " << result << endl << endl;
            break;

        case 6: // Квадратный корень
            cout << "Введите число: ";
            cin >> num1;
            if (num1 >= 0) {
                result = squareRoot(num1);
                cout << "Результат: " << result << endl << endl;
            }
            else {
                cout << "ОШИБКА: Корень из отрицательного числа!" << endl << endl;
            }
            break;

        case 7: // Процент
            cout << "Введите число: ";
            cin >> num1;
            cout << "Введите процент: ";
            cin >> num2;
            result = percentage(num1, num2);
            cout << "Результат: " << result << endl << endl;
            break;

        default:
            cout << "Неверный выбор! Попробуйте снова." << endl << endl;
        }
    }

    return 0;
}

// Функция отображения меню
void displayMenu() {
    cout << "========== МЕНЮ ==========" << endl;
    cout << "1. Сложение" << endl;
    cout << "2. Вычитание" << endl;
    cout << "3. Умножение" << endl;
    cout << "4. Деление" << endl;
    cout << "5. Возведение в степень" << endl;
    cout << "6. Квадратный корень" << endl;
    cout << "7. Процент" << endl;
    cout << "0. Выход" << endl;
    cout << "==========================" << endl;
    cout << "Выберите операцию: ";
}

// Сложение
double add(double a, double b) {
    return a + b;
}

// Вычитание
double subtract(double a, double b) {
    return a - b;
}

// Умножение
double multiply(double a, double b) {
    return a * b;
}

// Деление
double divide(double a, double b) {
    return a / b;
}

// Возведение в степень (без библиотеки cmath)
double power(double base, int exp) {
    double result = 1.0;
    bool negative = exp < 0;

    if (negative) {
        exp = -exp;
    }

    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    if (negative) {
        result = 1.0 / result;
    }

    return result;
}

// Квадратный корень (метод Ньютона, без cmath)
double squareRoot(double num) {
    if (num == 0) return 0;

    double x = num;
    double y = 1.0;
    double epsilon = 0.000001; // точность

    while (x - y > epsilon) {
        x = (x + y) / 2;
        y = num / x;
    }

    return x;
}

// Вычисление процента
double percentage(double num, double percent) {
    return (num * percent) / 100.0;
}