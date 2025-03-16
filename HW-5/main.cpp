#include <iostream>

// Заготовки задач
void task1()
{
    std::cout << "Задача 1. Введите n (натуральное) и x (вещественное): ";
    int n = 0;
    double x = 0.0;
    std::cin >> n >> x;

    if (n <= 0)
    {
        std::cout << "Некорректное значение n!\n";
        return; // Прекращаем работу, так как n не подходит
    }
}

void task2()
{
}

void task3()
{
}

void task4()
{
}

int main()
{
    // Пока вызовем только task1() для теста
    task1();
    return 0;
}