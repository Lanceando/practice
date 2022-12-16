#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

int main()
{
	SetConsoleCP('1251');
	SetConsoleOutputCP('1251');
    setlocale(LC_ALL, "rus");
   
    char a[33] = { 'а', 'б', 'в', 'г', 'д','е','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я','ё'};
    int count_a[33] = {};

    std::ifstream in("input.txt", std::ios::in);
    std::string text[1000];
    
    int ind_text = 0;
    while (!in.eof())
    {
        char word[250];
        in >> word;

        text[ind_text] = word;

        for (int i = 0; i < strlen(word) - 1; i++)
        {
            char temp = word[i];
            int ind = (int)static_cast<unsigned char>(temp); //берём индекс букв в текстке
            if (224 <= ind and ind <= 255) // коды строчных букв в кодировке ASCII
            {
                ind -= 32;
            }
            // подсчет букв
            if (192 <= ind and ind <= 223) // коды заглавных букв в кодировке ASCII
            {
                count_a[ind - 192] += 1;
            }
            if (ind == 184 or ind == 168)
            {
                count_a[32] += 1;
            }
        }
        ind_text += 1;
    }
    
    // сортируем буквы
    for (int i = 0; i < 32; i++)
    {
        for (int j = i + 1; j < 33; j++)
        {
            if (count_a[i] < count_a[j])
            {
                std::swap(count_a[i], count_a[j]);
                std::swap(a[i], a[j]);
            }
        }

    }
    
    // отбираем 4 самые популярные буквы
    char max_cnt_a[4];
    for (int i = 0; i < 4; i++)
    {
        max_cnt_a[i] = a[i];
    }

    std::cout << "четыре наиболее частро встречающиеся буквы в тексте:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << max_cnt_a[i] << ' ';
    }
    std::cout << std::endl;
    // сделать все слова строчными, чтобы увидеть пары.
    for (int i = 0; i < ind_text; i++)
    {
        for (int j = 0; j < text[i].size(); j++)
            text[i][j] = tolower(text[i][j]);
    }
    
    //какие-нибудь две из четырех наиболее часто встречающихся букв текста, записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы.
    for (int k = 0; k < ind_text; k++)
    {
        for (int i = 0; i < text[k].size(); i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int m = 0; m < 4; m++)
                {
                       if (text[k][i] == max_cnt_a[j] && text[k][i + 1] == max_cnt_a[m])
                       { 
                           text[k][i] = toupper(text[k][i]);
                           text[k][i + 1] = toupper(text[k][i + 1]);
                           if (text[k][text[k].size() - 1] == '.' || text[k][text[k].size() - 1] == '?' || text[k][text[k].size() - 1] == ',' || text[k][text[k].size() - 1] == '!')
                           {
                               char tmp;
                               tmp = text[k][text[k].size() - 1];
                               text[k] = text[k].erase(text[k].size()-1) + '(' + text[k][i] + text[k][i + 1] + ')' + tmp;
                           }
                       }
                  
                }
            }
        }
    }
    std::ofstream out("output.txt", std::ios::out);

    for (int i = 0; i < ind_text; i++)
    {
        out << text[i] << ' ';
    }

    


}