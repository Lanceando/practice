#include <iostream>
#include <string>
#include <cstring>

std::string sum(std::string a, std::string b) // ф-ция сложение двух больщих чисел
{
    std::string c;
    
    while (a.size() != b.size()) // уравниваем разряды
    {
        if (a.size() < b.size())
            a = "0" + a;
        else
            b = "0" + b;
    }
    a = "0" + a;
    b = "0" + b;
    
    int sum; // сумма по разрядам(как в столбик)
    int r = 0; // остаток от суммы по разрядам

    for (int i = a.size() - 1; i > -1; i--) // начинаем сложение с конца
    {
        sum = a[i] - '0' + b[i] - '0' + r; // сложение двух цифр и остатка
        r = sum / 10; // находим десятки
        c = char(sum % 10 + '0') + c; // с конца до начала ставим сумму
    }
    if (c[0] == '0')
        c.erase(0, 1);
    return c;
}


int main()
{
    setlocale(LC_ALL, "rus");
    std::string a, b;
    std::cin >> a;
    std::cin >> b;

    if (a.size() < b.size())
    {
        std::string temp = a;
        a = b;
        b = temp;
    }
    std::cout << "Сумма: " << sum(a, b) << std::endl;

    std::string a2 = a;
    std::string c = "1";
    
    while (c != b) // число а прибавляется самому себе до тех пор, пока "счётчик" c не дойдёт до числа b(кол-во раз, сколько над умножить).
    {
        a2 = sum(a2, a);
        c = sum(c, "1");
    }
    std::cout << "Произведение: " << a2 << std::endl;
}
