#include<iostream>
#include<math.h>
#include<string>
#include<fstream>

using namespace std;

struct Adress {

	int num;
	char city[30];
	char street[30];
};

void FillOnePeace(Adress* peace)
{
	cout << endl;
	cout << "Введите город: "; cin >> peace->city;
	cout << "Введите улицу: "; cin >> peace->street;
	cout << "Введите номер: "; cin >> peace->num;
	cout << endl;
}

void CreatArray(const int size, Adress* date)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl;
		cout << "Введите город: "; cin >> date[i].city;
		cout << "Введите улицу: "; cin >> date[i].street;
		cout << "Введите номер: "; cin >> date[i].num;
		cout << endl;
	}
}

void ShowArray(const int size, Adress* date)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl;
		cout << "Город: " << date[i].city << "     ";
		cout << "Улицу: " << date[i].street << "      ";
		cout << "Номер: " << date[i].num;
		cout << endl;
	}
}

int CheckStreet(const int size, Adress* date, char streetcheck[]) {
	int N = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(date[i].street,streetcheck))
		{
			N++;
		}
	}
	return N;
}

Adress* PushMiddle(Adress* date, Adress *data1, int size, int const temp)
{
	Adress value;
	FillOnePeace(&value);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (i != (temp))
		{
			data1[i] = date[i];
		}
		else
		{
			data1[i] = value;
			break;
		}
	}
	for (int j = i + 1; j < size; j++)
	{
		data1[j] = date[j - 1];
	}

	return data1;
}

void Swap(Adress* date, int fplace, int secplace)
{
	Adress temp;
	temp = date[secplace];
	date[secplace] = date[fplace];
	date[fplace] = temp;
}

void OutpFile(Adress *data, int const size) {
	string path = "Adressnormal.txt";
	ofstream  fout;
	fout.open(path);

	if (!fout.is_open())
	{
		cout << "Error open" << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			fout << endl;
			fout << "Введите город: "; cin >> data[i].city;
			fout << "Введите улицу: "; cin >> data[i].street;
			fout << "Введите номер: "; cin >> data[i].num;
			fout << endl;
		}
	}
	fout.close();
};

int main()
{
	setlocale(LC_ALL, "ukr");
	int sizem;
	int c, N, temp;
	cout << "Введите размер масива" << endl;
	cin >> sizem;
	Adress* data = new Adress[sizem];

	while (1) {
		printf("0 - exit\n");
		printf("1 - Заполнение масива\n");
		printf("2 - Вивести масив\n");
		printf("3 - Сортировка по улице\n");
		printf("4 - Додавання кк елементу\n");
		printf("5 - Перестановка місць\n");
		printf("6 - Виведення в файл\n");
		cout << endl;
		cin >> c;

		if (c == 0) {
			return 0;
		}
		switch (c) {
		case 1: {
			CreatArray(sizem, data);
			break; }
		case 2: {
			ShowArray(sizem, data);
			break; }
		case 3: {
			char street[30];
			cout << "Улицу для проверки" << endl;
			cin >> street;
			cout << CheckStreet(sizem, data, street) << endl;
		}
				break;
		case 4: {
			sizem++;
			cout << "Введите индекс нового массива в который хотите вставить новый елемент: ";
			cin >> temp;
			Adress* data1 = new Adress[sizem];
			if (temp < sizem)
			{
				data1 = PushMiddle(data, data1, sizem, temp);
				delete[] data;
				data = data1;
			}
			else
			{
				cout << endl << "Дурак, запусти прогу заново и введи число, которое меньше/равное размеру нового массива" << endl;
				return 0;
			}
			cout << endl;
			break;
		}
		case 5: {
			int firsts, seconds;
			cout << "Введите индекс первого елемента: ";
			cin >> firsts;
			cout << "Введите индекс второго елемента: ";
			cin >> seconds;
			if (seconds < sizem)
			{
				Swap(data, firsts, seconds);
			}
			else
			{
				cout << endl << "Дурак, запусти прогу заново и введи число, которое меньше/равное размеру нового массива" << endl;
				return 0;
			}
			cout << endl;
			break;
		}
		case 6: {
			OutpFile(data, sizem);
			break; }
		break;
		}
	}

	delete data;

	return 0;
}
