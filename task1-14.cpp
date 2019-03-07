#include<iostream>
#include<math.h>
#include<string>
#include<fstream>

using namespace std;

struct Koor {

	double x, y;
	double mod;
};

void FillOnePeace(Koor* peace)
{
	cout << "Введите х: "; cin >> peace->x;
	cout << "Введите y: "; cin >> peace->y;
	peace->mod = sqrt(peace->x * peace->x + peace->y * peace->y);
	cout << endl;
}

void CreatArray(const int size, Koor* date)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Введите х: "; cin >> date[i].x;
		cout << "Введите y: "; cin >> date[i].y;
		date[i].mod = sqrt(date[i].x * date[i].x + date[i].y * date[i].y);
		cout << endl;
	}
}

void ShowArray(const int size, Koor* date)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl;
		cout << "x: " << date[i].x << ";";
		cout << "y: " << date[i].y << ";";
		cout << endl;
	}
}

void Sortlenght(const int size, Koor* date)
{
	Koor tmp;
	for (int j = 0; j <= (size - 1); j++)
	{
		for (int i = j-1; i >= 0; i++)
		{
			if (date[i].mod < date[i + 1].mod)
			{
				tmp = date[i];
				date[i] = date[i + 1];
				date[i + 1] = tmp;
			}
		}
	}
}

int Checkparam(const int size, Koor* date, double par){
	int N=0;
	for (int i = 0; i < size; i++)
	{
		N += (int)(date[i].mod > par);
	}
	return N;
}

Koor* PushMiddle(Koor* date, Koor *data1, int size, int const temp)
{
	Koor value;
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

void OutpFile(Koor *data, int const size) {
	string path = "Coornormal.txt";
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
			fout << "x: " << data[i].x << ";";
			fout << "y: " << data[i].y << ";";
			fout << endl;
		}
		fout.close();
	}
};

Koor* PopMiddle(Koor* date,Koor* date2, int size, const int temp)
{
	int i = 0;
	for ( i = 0; i < size; i++)
	{
		if (i != temp)
		{
			date2[i] = date[i];
		}
		else
		{
			date2[i] = date[i + 1];
			break;
		}
	}
	for (int j = i+1; j < size; j++)
	{
		date2[j] = date[j + 1];
	}
	return date2;
}

void OutpBF(Koor data[], int size)
{
	string path = "Coornormalbf.txt";
	ofstream  fout;
	fout.open(path);

	if (!fout.is_open())
	{
		cout << "Error open" << endl;
	}
	else
	{
		ofstream outstrm("c:/binfiles/oonumber1.bin", std::ios::binary);
		if (outstrm.is_open())
		{
			for (int i = 0; i < size; i++)
				outstrm.write((char *)&data[i], sizeof(int));
			outstrm.close();
		}
		fout.close();
	}
	printf("Congratulations! Mass succesfully added in binary file.\n");
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int sizem;
	int c, temp;
	cout << "Введите размер масива" << endl;
	cin >> sizem;
	Koor* data = new Koor[sizem];

	while (1) {
		printf("0 - exit\n");
		printf("1 - Заполнение масива\n");
		printf("2 - Вивести масив\n");
		printf("3 - Елементи дальше перменной\n");
		printf("4 - Сортировка елементов за ростоянием\n");
		printf("5 - Додавання кк елементу\n");
		printf("6 - Видалення кк елементу\n");
		printf("7 - Вивести в файл\n");
		printf("8 - Вивести в файл2\n");
		cin >> c;

		if (c == 0) {
			return 0;
		}
		switch (c) {
		case 1: {
			CreatArray(sizem, data);
			break; 
		}
		case 2: {
			ShowArray(sizem, data);
			break; 
		}
		case 3: {
			double parametr;
			cout << "Введите параметр" << endl;
			cin >> parametr;
			cout << Checkparam(sizem, data, parametr) << endl;
		}
			break;
		case 4: {
			Sortlenght(sizem, data);
			break; 
		}
		case 5: {
			sizem++;
			cout << "Введите индекс нового массива в который хотите вставить новый елемент: ";
			cin >> temp;
			Koor* data1 = new Koor[sizem];
			if ((temp < sizem)&&(temp>=0))
			{
				data1 = PushMiddle(data,data1, sizem, temp);
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
		case 6: {
			sizem--;
			Koor* data2 = new Koor[sizem];
			cout << "Введите индекс из который хотите удалить новый елемент: ";
			cin >> temp;
			if ((temp <= sizem)&&(temp>=0))
			{
				data2=PopMiddle(data, data2, sizem, temp);
				delete[] data;
				data = data2;
			}
			else
			{
				cout << endl << "Дурак, запусти прогу заново и введи число, которое меньше/равное размеру нового массива" << endl;
				return 0;
			}
			cout << endl;
			break;
		}
		case 7: {
			OutpFile(data, sizem);
			break; 
		}
		case 8: {
			OutpBF(data, sizem);
			break;
		}
		}
	}

	delete[] data;
	return 0;	
}
