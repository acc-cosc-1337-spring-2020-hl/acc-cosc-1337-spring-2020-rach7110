#include<iostream>
#include "switch.h";

using std::cin;
using std::cout;

int main() 
{
	int number;

	cout << "Enter a number(1-4): ";
	cin >> number;

	cout << menu(number);

	return 0;
}