#include<iostream>
#include "Array.h"
using namespace std;


int main()
{

	Array* arr1;
	int ch, arraySize;
	int element, index;

	cout << "Enter Size of Array: ";
	cin >> arraySize;
	arr1 = new Array(arraySize);

	do
	{
		cout << "\n\nMenu" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Search (binary search)" << endl;
		cout << "4. Reverse" << endl;
		cout << "5. Display" << endl;
		cout << "6.Exit" << endl;

		cout << "enter you choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1: cout << "Enter an element and index: ";
			cin >> element >> index;
			arr1->insert(index, element);
			break;
		case 2: cout << "Enter index: ";
			cin >> index;
			element = arr1->remove(index);
			cout << "Deleted Element is" << element;
			break;
		case 3:cout << "Enter element to search: ";
			cin >> element;
			index = arr1->binarySearch(element);
			cout << "Element index " << index;
			break;
		case 4: cout << "Reversing array: ";
			arr1->reverse();
			break;
		case 5:arr1->display();

		}
	} while (ch < 6);
	

	system("pause");
	return 0;
}