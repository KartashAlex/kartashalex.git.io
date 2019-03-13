#include<iostream>
#include<string>
#include<cassert>



int mMenu()
{

	using namespace std;

	cout << "1) V V O D " << '\n';
	cout << "2) V bl V O D " << '\n';
	cout << "3) U D A L E N I E " << '\n';
	cout << "4) V S T A V K A " << '\n';
	cout << "5) P R O V E R K A " << '\n';

	int a;
	cin >> a;
	return a;

}

//ввод массива
void prog1(int * &array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << "Enter number #" << i + 1 << ": ";
		std::cin >> array[i];
	}


}

//вывод массива
void prog2(int * &array, int length)
{
	for (int i = 0; i < length; ++i)
		std::cout << "Number #" << i + 1 << ": " << array[i] << '\n';
}

//удаление всех последующих вхождений наибольшего элемента
void prog3(int * array, int * &array2, int length, int &nLength)
{
	//находим макс элемент
	int maxIndex;
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{

		maxIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (array[currentIndex] > array[maxIndex])
				maxIndex = currentIndex;
		}

	}
	//длина нового массива
	nLength = length;

	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		if (array[startIndex] == array[maxIndex])
			--nLength;
	}
	nLength++;
	array2 = new int[nLength];
	int Index = 0;
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
			if (startIndex <= maxIndex)
			{
				array2[Index] = array[startIndex];
				++Index;
			}
			else if (array[startIndex] != array[maxIndex])
			{
				array2[Index] = array[startIndex];
				++Index;
			}

		
	}
}

void prog4(int * array, int * &array2, int length)
{
}

bool prog5(int * array, int length)
{
	for (int startIndex = 0; startIndex < length-1; ++startIndex)
	{
		if (array[startIndex] > array[startIndex + 1])
			return false;
	}
	return true;
}

int main()
{
	int length;
	std::cout << "vvedite dlinu :  " << '\n';
	std::cin >> length;
	int *array = new int[length];
	int nLength=0;
	int *array2 = nullptr;

	bool tsikle(true);
	while (tsikle)
	{
		int menu;
		menu = mMenu();

		switch (menu)
		{
		case 1:
			prog1(array,length);
			break;
		case 2:
			prog2(array, length);
			break;
		case 3:
			prog3(array,array2, length, nLength);
			prog2(array2, nLength);

			break;

		case 4:

			prog4(array, array2, length);
			prog1(array2, length);
			break;

		case 5:

			if (prog5(array, length))
				std::cout << "po vozrostaniyu" << '\n';
			else
				std::cout << "Ne po vozrostaniyu" << '\n';

			break;

		}

	}
	
	std::cout << "All work, maybe correctly";
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;

}

