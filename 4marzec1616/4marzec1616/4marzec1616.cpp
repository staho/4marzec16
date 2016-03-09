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
void delete_x(node *&, int);
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
			<< "3. Wyswietlic pelna liste\t\t4. Posprzatac" << endl << "5. Bubblesort\t\t\t6. Usunac x" << endl
			<< "7. Zamienic x\t\t\t8. Usunac" << endl;
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
			break;
		case 6:
			{
				int x;
				cout << "Podaj x" << endl;
				cin >> x;
				delete_x(H, x);
			}
			break;
		case 7:
			{
				int x;
				cout << "Podaj x" << endl;
				cin >> x;
				swap_x(H, x);
			}
		break;
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
void delete_x(node *&H, int x)
{
	if (H != NULL)
	{
		node *p = H;
		if (p->val == x)
		{
			H = p->next;
			delete p;
		}
		else
		{
			while (p->next != NULL && p->next->val != x)
				p = p->next;
			if (p->next != NULL)
			{
				node *d = p->next;
				p->next = d->next;
				delete d;
			}
		}

	}
}
void swap_x(node *&H, int x)
{
	if (H != NULL && H->next != NULL)
	{
		if (H->val = x)
		{
			node * p = H->next;
			H = H->next;
			p->next = H->next;
			H->next = p;
		}
		else
		{
			node * p = H;
			while (p->next != NULL && p->next->val != x)
				p = p->next;
			if (p->next != NULL && p->next->next != NULL)
			{
				node * d = p->next;
				p->next = d->next;
				d->next = d->next->next;
				p->next = d->next->next;
				p->next->next = d;
			}
		}
	}
	else
	{
		cout << "Nie ma x'a" << endl;
		system("PAUSE");
	}
}