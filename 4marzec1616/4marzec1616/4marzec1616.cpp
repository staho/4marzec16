// Funkcje4marzec16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node { // struktura listy
	int val;
	node * next;
};

void dodaj(node *&, int &);
void wyswietl(node *);

int main()
{
	node * H = NULL;	//definicja + deklaracja Heada
	int choice = 0, counter = 0;
	while (choice != 5)
	{
		system("CLS");
		cout << "Co chcesz zrobic z lista" << endl
			<< "1. Dodac element?\t\t\t" << "2. Skasowac element <pierwszy z listy>" << endl
			<< "3. Wyswietlic pelna liste\t\t5.Wyjsc" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			dodaj(H, counter);
			break;
		case 2:
			break;
		case 3:
			wyswietl(H);
			break;
		default:
			break;
		}

	}
	delete H;
	return 0;
}

/*Sekcja funkcji do maina <te z switcha>*/
void dodaj(node *&H, int &counter)
{
	cout << "Podaj liczbe do wrzucenia" << endl;
	int x;
	cin >> x;
	node * p = new node;
	p->val = x;
	p->next = H;
	H = p;

	counter++;
}
void wyswietl(node *H)
{
	while (H != NULL)
	{
		cout << H->val << " ";
		H = H->next;
	}
	cout << endl;
	system("PAUSE");
}
