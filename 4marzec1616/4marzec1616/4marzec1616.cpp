// Funkcje4marzec16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node { // struktura listy
	int val;
	node * next;
};

void add(node *&, int &);
void display(node *);
void clean(node *&);
int delete_last(node *&);
void bubble(node *&);
void delete_x(node *&);
void swap_x(node *&, int);

int main()
{
	node * H = NULL;	//definicja + deklaracja Heada
	int choice = 0, counter = 0;
	while (choice != 6)
	{
		system("CLS");
		cout << "Co chcesz zrobic z lista" << endl
			<< "1. Dodac element?\t\t\t" << "2. Skasowac element <ostatni z listy>" << endl
			<< "3. Wyswietlic pelna liste\t\t4. Posprzatac" << endl << "5. Bubblesort\t\t6.Wyjsc" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			add(H, counter);
			break;
		case 2:
			try
			{
				cout << "Sciagniety element to " << delete_last(H) << endl;
			}
			catch (int)
			{
				cout << "Brak elementow" << endl;
			}
			system("PAUSE");
			break;
		case 3:
			display(H);
			break;
		case 4:
			delete_last(H);
			break;
		case 5:
			bubble(H);
		default:
			break;
		}

	}
	clean(H);
	delete H;
	return 0;
}

/*Sekcja funkcji do maina <te z switcha>*/
void add(node *&H, int &counter)
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
void display(node *H)
{
	while (H != NULL)
	{
		cout << H->val << " ";
		H = H->next;
	}
	cout << endl;
	system("PAUSE");
}
void clean(node *&H)
{
	while (H != NULL)
	{
		node * p = H;
		H = p->next;
		delete p;
	}
}
int delete_last(node *&H)
{
	node * p = H;
	int x;
	if (H == NULL) throw 1;
	else if (H->next == NULL)
	{
		x = H->val;
		p = H;
		H = NULL;
		delete p;
		return x;
	}
	else
	{
		while (p->next->next != NULL)
			p = p->next;
		x = p->next->val;
		delete p->next;
		p->next = NULL;
		return x;
	}
}
//commity
void bubble(node *&)
{

}
void delete_x(node *&)
{

}
void swap_x(node *&H, int x)
{

}