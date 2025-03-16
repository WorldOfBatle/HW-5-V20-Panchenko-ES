#include <iostream>
#include <cmath> // для std::sin

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

    double sum = 0.0;

    // Внешний цикл: i от 1 до n
    for (int i = 1; i <= n; i++)
    {
        // val будет хранить промежуточный результат
        double val = x;

        // Внутренний цикл: j от 1 до i
        for (int j = 1; j <= i; j++)
        {
            val = std::sin(val);
        }

        // Добавляем к сумме
        sum += val;
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