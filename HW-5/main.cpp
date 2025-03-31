#include <iostream>
#include <cmath>

// Используем рекуррентное соотношение: T1 = sin(x), T(i+1) = sin(T(i))
void task1()
{
    std::cout << "Задача 1. Введите n (натуральное) и x (вещественное): ";
    int n = 0;
    double x = 0.0;
    std::cin >> n >> x;

    if (n <= 0)
    {
        std::cout << "Некорректное значение n!\n";
        return;
    }

    // Вычисляем первый член: T1 = sin(x)
    double term = std::sin(x);
    double sum = term;

    // Вместо вложенного цикла используем рекуррентное соотношение:
    // Для i от 2 до n: T(i) = sin(T(i-1))
    for (int i = 2; i <= n; i++)
    {
        term = std::sin(term);
        sum += term;
    }

    std::cout << "Результат S = " << sum << std::endl;
}

// Вместо повторных вызовов std::pow используем рекуррентное обновление переменных.
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

    double P = 1.0;
    // Инициализируем переменные для рекуррентного вычисления:
    double sign = -1.0; // Для n = 0: (-1)^(0-1) = -1
    double xPow = 1.0;  // x^(0) = 1

    // Обходим n от 0 до k
    for (int n = 0; n <= k; n++)
    {
        double denom = (n + 2.0) * (n + 1.0);
        double bracket = 1.0 + (sign * xPow / denom);
        P *= bracket;

        // Рекуррентное обновление: 
        // sign: вместо std::pow(-1, n-1) просто переключаем знак
        sign = -sign;
        // xPow: переходим от x^(2n) к x^(2(n+1)) домножением на x^2
        xPow *= (x * x);
    }

    std::cout << "Результат P = " << P << std::endl;
}

// Вместо использования std::pow для каждого члена, используем рекуррентное деление на sqrt(3)
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
    int count = 0;
    // Рекуррентное вычисление: первый член T1 = 1/√3
    double term = 1.0 / std::sqrt(3.0);

    // Продолжаем, пока очередной член не станет меньше eps
    while (term >= eps)
    {
        sum += term;
        count++;
        // Следующий член: делим текущий на √3 (так как 3^( (i+1)/2 ) = 3^(i/2) * √3)
        term /= std::sqrt(3.0);
    }

    std::cout << "Сумма = " << sum << std::endl;
    std::cout << "Число учтённых членов = " << count << std::endl;
}

void task4()
{
    std::cout << "Задача 4. Введите a, b, eps (вещественные). Шаг = 0.1\n";
    double a, b, eps;
    std::cin >> a >> b >> eps;

    if (eps <= 0.0)
    {
        std::cout << "Некорректное значение eps!\n";
        return;
    }

    std::cout << "----------------------------------------------\n";
    std::cout << " N  |    x     |     F(x)       | termsUsed\n";
    std::cout << "----------------------------------------------\n";

    int row = 1;
    // Идем по x от a до b с шагом 0.1 (учитываем погрешность)
    for (double x = a; x <= b + 1e-9; x += 0.1)
    {
        double sum = 0.0;
        int count = 0;
        // Рекуррентное вычисление ряда: T1 = x
        double T = x;
        while (true)
        {
            count++;
            // Останавливаем, если |T| < eps
            if (std::fabs(T) < eps)
            {
                break;
            }
            sum += T;
            // Вычисляем следующий член по рекуррентной формуле:
            // r = ((2*count - 1)^2 * x^2) / ((2*count) * (2*count + 1))
            double r = (std::pow(2.0 * count - 1, 2) * x * x) / ((2.0 * count) * (2.0 * count + 1));
            T *= r;
            if (count > 200)  // Защита от бесконечного цикла, если ряд сходится очень медленно
            {
                break;
            }
        }

        const double PI = 3.14159265358979323846;
        double Fx = -(PI / 2.0) * sum;

        std::cout << row << "  |  " << x << "  |  " << Fx << "  |  " << count << "\n";
        row++;
    }

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
