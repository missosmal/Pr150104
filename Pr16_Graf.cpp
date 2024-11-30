#include <Windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib> // Для rand()
#include <ctime>   // Для srand()

using namespace std; // Использование namespace std

// Функция подсчета цифр в числе
int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

// Задача 1: Сравнение количества цифр в числах
void task1() {
    int num1, num2;
    cout << "Введите два числа: ";
    cin >> num1 >> num2;
    int count1 = countDigits(num1);
    int count2 = countDigits(num2);

    if (count1 > count2) {
        cout << "В первом числе больше цифр.\n";
    }
    else if (count2 > count1) {
        cout << "Во втором числе больше цифр.\n";
    }
    else {
        cout << "Оба числа имеют одинаковое количество цифр.\n";
    }
}

// Структура для хранения информации о лекарствах
struct Medicine {
    char name[50];
    int quantity;
    double price;
    int storageMonths;
};

// Задача 2: Работа с лекарствами
void task2() {
    int n;
    cout << "Введите количество лекарств: ";
    cin >> n;

    Medicine* medicines = new Medicine[n]; // Динамический массив структур
    for (int i = 0; i < n; i++) {
        cout << "Введите информацию о лекарстве " << i + 1 << ":\n";
        cout << "Наименование: ";
        cin >> medicines[i].name;
        cout << "Количество: ";
        cin >> medicines[i].quantity;
        cout << "Цена: ";
        cin >> medicines[i].price;
        cout << "Срок хранения (в месяцах): ";
        cin >> medicines[i].storageMonths;
    }

    double totalCost = 0, maxPrice = 0, minPrice = 1e9;
    int countLongStorage = 0;

    for (int i = 0; i < n; i++) {
        totalCost += medicines[i].price * medicines[i].quantity;
        if (medicines[i].price > maxPrice) maxPrice = medicines[i].price;
        if (medicines[i].price < minPrice) minPrice = medicines[i].price;
        if (medicines[i].storageMonths > 3) countLongStorage++;
    }

    cout << "Самая высокая цена: " << maxPrice << "\n";
    cout << "Самая низкая цена: " << minPrice << "\n";
    cout << "Количество препаратов с хранением более 3 месяцев: " << countLongStorage << "\n";
    cout << "Общая стоимость всех препаратов: " << totalCost << "\n";

    delete[] medicines; // Освобождение памяти
}

// Задача 3: Работа с двумерным массивом
void task3() {
    int m;
    cout << "Введите размер массива (M x M): ";
    cin >> m;

    // Динамическое выделение памяти для двумерного массива
    int** array = new int* [m];
    for (int i = 0; i < m; i++) {
        array[i] = new int[m];
    }

    srand(time(0)); // Инициализация генератора случайных чисел

    // Заполнение массива случайными числами
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            array[i][j] = rand() % 21 - 10; // Числа от -10 до 10
            cout << array[i][j] << "\t";
        }
        cout << "\n";
    }

    // Вычисление произведения положительных элементов выше главной диагонали
    int product = 1;
    bool hasPositive = false; // Проверяем, есть ли положительные элементы
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            if (array[i][j] > 0) {
                product *= array[i][j];
                hasPositive = true;
            }
        }
    }

    if (hasPositive) {
        cout << "Произведение положительных элементов выше главной диагонали: " << product << "\n";
    }
    else {
        cout << "Положительных элементов выше главной диагонали нет.\n";
    }

    // Освобождение выделенной памяти
    for (int i = 0; i < m; i++) {
        delete[] array[i];
    }
    delete[] array;
}
int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        int choice;
        cout << "\nВыберите задачу для решения (1-3) или 0 для выхода: ";
        cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: return 0;
        default: cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }
}

