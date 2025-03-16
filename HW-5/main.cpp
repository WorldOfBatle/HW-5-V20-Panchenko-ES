#include <iostream>
#include <cmath>

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

    std::cout << "Результат S = " << sum << std::endl;
}

void task2()
{
    std::cout << "Задача 2. Введите k (натуральное) и x (вещественное): ";
    int k = 0;
    double x = 0.0;
    std::cin >> k >> x;

    if (k < 0)
    {
        std::cout << "Некорректное значение k!\n";
        return;
    }

    // Начальное значение произведения P
    double P = 1.0;

    // Цикл n от 0 до k
    for (int n = 0; n <= k; n++)
    {
        // Вычисляем знак: (-1)^(n-1)
        double sign = std::pow(-1.0, double(n - 1));

        // x^(2n)
        double xPow = std::pow(x, 2.0 * n);

        // (n+2)(n+1)
        double denom = (n + 2.0) * (n + 1.0);

        double bracket = 1.0 + (sign * xPow / denom);

        // Умножаем в общее произведение
        P *= bracket;
    }

    std::cout << "Результат P = " << P << std::endl;
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
    task2();
    return 0;
}