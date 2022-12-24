#include <iostream>

class Dyn_mas
{
	public:
		int size = 0;
		int* mass = new int;

		// 1
		void add_el(int num) // добавить элемент в конец
		{
			int* newMass = new int[size + 1];
			for (int i = 0; i < size; i++)
			{
				newMass[i] == mass[i];
			}
			newMass[size] = num; // массив обновлён( с новым эл. на конце)
			size++;
			delete[] mass; // освобождаем память
			mass = newMass; // возращаем привучную переменную 
		}
		
		// 2
		void CurrElements()
		{
			std::cout << "Текущее кол-во элементов в массиве: " << size << std::endl;
		}

		// 3
		void elementByInd(int ind)
		{
			std::cout << "Элемент с индексом " << ind << ": " << mass[ind] << std::endl;
		}

		// 4
		void changeByInd(int ind, int num)
		{
			mass[ind] = num;
		}

		//5
		void delByInde(int ind)
		{
			int* newMass = new int[size - 1]; // создаём уменьшенный массив
			bool flag = 0;
			for (int i = 0; i < size; i++)
			{
				if (i == ind) // чекаем индекс
				{
					flag == 1;
					continue;
				}
				newMass[i - flag] = mass[i]; // записываем новый массив без удалённого элемента
			}
			delete mass;
			size--;
			mass = newMass; // возращаем привычную переменную 
		}

		//6
		void insertByInd(int ind, int num)
		{
			int* newMass = new int[size + 1]; // добавляем доп место для эл.
			bool flag = 0;
			for (int i = 0; i < size + 1; i++)
			{
				if (i == ind)
				{
					flag = 1;
					newMass[i] == num;	  //добавли элемент по индексу
					continue;
				}
				newMass[i] = mass[i - flag];
			}
			delete mass;
			size++;
			mass = newMass;
		}
};

int main()
{
	setlocale(LC_ALL, "rus");

	Dyn_mas massive;
	massive.add_el(2);
	massive.add_el(-5);

	/*massive.CurrElements();
	massive.elementByInd(2);
	massive.changeByInd(3, 60);
	massive.delByInde(4);
	massive.insertByInd(4, 64);
	massive.elementByInd(4);*/
}

