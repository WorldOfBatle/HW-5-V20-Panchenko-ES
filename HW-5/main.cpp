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
    std::cout << "Задача 3. Введите точность eps (вещественное, > 0): ";
    double eps = 0.0;
    std::cin >> eps;

    if (eps <= 0.0)
    {
        std::cout << "Некорректное значение eps!\n";
        return;
    }

    double sum = 0.0;
    int i = 1;
    int count = 0; // число прибавленных членов

    while (true)
    {
        // Вычисляем i-й член: 1 / sqrt(3^i) = 1 / 3^(i/2)
        double term = 1.0 / std::pow(3.0, i / 2.0);

        if (term < eps)
        {
            // Если член меньше eps, считаем, что дальше можно остановиться
            break;
        }

        sum += term;
        count++;
        i++;
    }

    std::cout << "Сумма = " << sum << std::endl;
    std::cout << "Число учтённых членов = " << count << std::endl;
}

// Функция для n-го члена: Tn, для задачи №4
double getTerm(int n, double x)
{
    if (n == 1)
    {
        // T1 = x
        return x;
    }
    else if (n == 2)
    {
        // T2 = x^3 / (2*3)
        double power = std::pow(x, 3);
        double denom = 2.0 * 3.0;
        return power / denom;
    }
    else
    {
        // n >= 3
        // 1) Вычисляем x^(2n-1)
        double power = std::pow(x, 2.0 * n - 1.0);

        // 2) Числитель
        long long numProd = 1;
        for (int odd = 3; odd <= 2 * n - 3; odd += 2)
        {
            numProd *= odd;
        }

        // 3) Знаменатель
        long long denProd = 1;

        for (int evenVal = 2; evenVal <= 2 * (n - 1); evenVal += 2)
        {
            denProd *= evenVal;
        }

        denProd *= (2 * n - 1);

        // Tn = x^(2n-1) * (numProd) / (denProd)
        double term = power * (double)numProd / (double)denProd;
        return term;
    }
}

void task4()
{
    std::cout << "Задача 4. Введите a, b, eps (вещественные). Шаг = 0.1\n";
    double a, b, eps;
    std::cin >> a >> b >> eps;

    // Проверяем корректность eps > 0
    if (eps <= 0.0)
    {
        std::cout << "Некорректное значение eps!\n";
        return;
    }

    // Шапка таблицы
    std::cout << "----------------------------------------------\n";
    std::cout << " N  |    x     |     F(x)       | termsUsed\n";
    std::cout << "----------------------------------------------\n";
}

int main()
{
    task1();
    task2();
    task3();
    task4();
    return 0;
}