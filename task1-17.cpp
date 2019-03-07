
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;


struct Product
{
	char product_name[40];
	char number_of_products[40];
	int price;
};

void FillOne(Product* one)
{
	cout << endl;
	cout << "Введите наименование товара: ";			cin >> one->product_name;
	cout << "Введите количество товара: ";				cin >> one->number_of_products;
	cout << "Введите цену товара: ";					cin >> one->price;
	cout << endl;
}

void Fill_array(const int array_size, Product *data)
{
	for (int i = 0; i < array_size; i++)
	{
		cout << "Введите наименование товара: ";			cin >> data[i].product_name;
		cout << "Введите количество товара: ";				cin >> data[i].number_of_products;
		cout << "Введите цену товара: ";					cin >> data[i].price;
		cout << endl;
	}
}

void Show_array(const int array_size, Product *data)
{
	cout << endl << "Индекс" << "\tНазвание товара\t\tКоличество\t\tЦена" << endl << endl;
	for (int i = 0; i < array_size; i++)
	{
		cout << i << "\t" << data[i].product_name << "\t\t" << data[i].number_of_products << "\t\t" << data[i].price << endl;
	}
}

void Number_of_higher_price_products(const int array_size, Product *data,const int price_of_products)
{
	int amount = 0;

	for (int i = 0; i < array_size; i++)
	{
		if (data[i].price > price_of_products)
		{
			amount++;
		}
	}

	cout << "Количество елементов с ценой выше заданой: " << amount << endl;

}

void Bubble_price_sort(const int array_size, Product *data)
{
	Product temp;
	for (int i = 0; i < array_size - 1; i++)
	{ 
		for (int j = 0; j < array_size - i - 1; j++)
		{
			if (data[j].price > data[j + 1].price) 
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;

			}
		}
	}
}

Product* Push_middle(Product data[], Product new_array[], int const array_size, int index)
{
		Product value;
		FillOne(&value);
		int i = 0;
		for (i = 0; i < array_size; i++)
		{
			if (i != (index))
			{
				new_array[i] = data[i];
			}
			else
			{
				new_array[i] = value;
				break;
			}
			}
		for (int j = i + 1; j < array_size; j++)
		{
			new_array[j] = data[j - 1];
		}

	return new_array;

}

Product* Pop_middle(Product data[], Product new_array[], int const array_size, int index)
{
	for (int i = 0; i < array_size; i++)
	{
		if (i != index)
		{
			new_array[i] = data[i];
		}
		else
		{
			new_array[i] = data[i + 1];
			for (int j = i + 1; j < array_size; j++)
			{
				new_array[j] = data[j + 1];
			}break;
		}
	}
	
	return new_array;
}

int Menu()
{
	{
		int choice;
		cout << endl << "0 - выход" << endl;
		cout << "1 - Cоздание массива с выделением памяти под каждый его елемент и последующим заполнением с клавиатуры" << endl;
		cout << "2 - Вывод массива на экран" << endl;
		cout << "3 - Подсчет количества елементов с ценой выше заданой" << endl;
		cout << "4 - Сортировка по цене" << endl;
		cout << "5 - Добавить елемент k-ого" << endl;
		cout << "6 - Удалить елемент k-ого" << endl;
		cout << "7 - вивести в файл" << endl << endl;
		cout << "Ваш выбор: ";
		cin >> choice;
		cout << endl;
		return choice;
	}
}

void OutpFile(Product *data, int const size) {
	string path = "Adressnormal.txt";
	ofstream  fout;
	fout.open(path);

	if (!fout.is_open())
	{
		cout << "Error open" << endl;
	}
	else
	{
		cout << endl << "Индекс" << "\tНазвание товара\t\tКоличество\t\tЦена" << endl << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i << "\t" << data[i].product_name << "\t\t" << data[i].number_of_products << "\t\t" << data[i].price << endl;
		}
	}
	fout.close();
}

int main()
{
	int array_size;

	setlocale(LC_ALL, "rus");


	cout << "Укажите размер массива, с которым хотите работать: ";
	cin >> array_size;

	Product *data = new Product[array_size];

	while (1)
	{
		int option = Menu();
		
		switch (option)
		{
		case 1: {
			Fill_array(array_size, data);
			break; };
		case 2: {
			Show_array(array_size, data);
			break; }
		case 3: {
			int price_of_products;

			cout << "Введите цену: ";
			cin >> price_of_products;

			Number_of_higher_price_products(array_size, data, price_of_products);
			break; };
		case 4: {
			Bubble_price_sort(array_size, data);
			break; }
		case 5: {
			int index;
			++array_size;
			Product *new_array = new Product[array_size];

			cout << "Введите индекс массива, после которого вы хотите вставить елемент: ";
			cin >> index;

			if (index < array_size)
			{
				cout << endl;
				new_array = Push_middle(data, new_array, array_size, index);

				delete[] data;
				data = new_array;
			}
			else
			{
				cout << endl << "Запусти прогу заново и введи число, которое меньше/равное размеру нового массива" << endl;
				break;
			}

			break; };
		case 6: {
			int index;
			--array_size;

			Product *new_array = new Product[array_size];

			cout << "Введите индекс массива, после которого вы хотите удалить елемент: ";
			cin >> index;

			if (index <= array_size)
			{
				cout << endl;
				new_array = Pop_middle(data, new_array, array_size, index);

				delete[] data;	
				data = new_array;
			}
			else
			{
				cout << endl << "Запусти прогу заново и введи число, которое меньше/равное размеру нового массива" << endl;
			}

			break; };
		case 7: {
			OutpFile(data, array_size);
			break;
		}
		}		
	}
	delete[] data;

	return 0;
}

