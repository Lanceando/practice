#include <iostream>
#include <vector>


int main()
{
    std::vector<int>  a;
    
    
    // reserve() - задать вместимость вектора ( кол-во выделенной памяти )
    a.reserve(44);

    // resize() - задать вмесимость вектора ( кол-во элементов в массиве )
    a.resize(1);

    // capacity() - узнать вместимость вектора ( кол-во элементов в массиве )
    std::cout << a.capacity() << std::endl;
    // std::cout << "Вместимость массива:" << a.capacity << std::endl;
    
    // push_back() - добавить элемент в конец массива
    a.push_back(1);

    int c;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> c;
        a.push_back(c);
    }

    // shrink_to_fit() - удаляет все пустые эл. массива
    a.shrink_to_fit();
    
    // insert() - добавляет эл. в определённое место, сдвигает все элементы на +1
    a.insert(a.begin()+1, 10);
    
    // erase() - удаление элементов от одного идекса до другого
    a.erase(a.begin(), a.end() - 2);

    //clear() - очистить массив
    a.clear();

    //std::cout << a[i] << std::endl; - не покажет, массив пустой
    
    // emplace_back() - создаёт эл. в конце массива
    a.emplace_back(24);
    std::cout << a[0] << std::endl;

    





}

