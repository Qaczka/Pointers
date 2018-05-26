#include <iostream>

using namespace std;

void print_line() {
	cout << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
}

void increment_all(int* start, int* stop)
{
	int * current = start;
	while (current != stop)
	{
		++(*current); //increment value pointed
		++current;  //increment pointer
	}
}

void print_all(const int* start, const int* stop)
{
	const int * current = start;
	while (current != stop) {
		cout << *current << '\n';
		++current; //increment pointer
	}
}

void increase(void* data, int psize)
{
	if (psize == sizeof(char))
	{
		char* pchar; pchar = (char*)data; ++(*pchar);
	}
	else if (psize == sizeof(int))
	{
		int* pint; pint = (int*)data; ++(*pint);
	}
}

int addition(int a, int b)
{
	return (a + b);
}

int subtraction(int a, int b)
{
	return (a - b);
}

int operation(int x, int y, int(*functocall)(int, int))
{
	int g;
	g = (*functocall)(x, y);
	return (g);
}

int main(int argc, char* argv)
{
	int myvar = 25;
	int *foo = &myvar;

	//-----------------------------------------------------------------------------------------------------------------------//
	//Uzalezniamy zmienne od pointerow
	cout <<"Uzalezniamy zmienne od pointerow" << endl;

	int first, second;
	int * pointer1;
	// int *p1, *p2;
	pointer1 = &first;
	*pointer1 = 13;
	pointer1 = &second;
	*pointer1 = 18;

	cout << "The first one is: " << first << " and the second one is: " << second << endl;


	//-----------------------------------------------------------------------------------------------------------------------//
	//Przemieniamy pointery adresami
	print_line();
	cout << endl << "Przemieniamy pointery adresami" << endl;

	int* pointer2;
	pointer1 = &first;
	pointer2 = &second;
	*pointer2 = *pointer1;//second -> 13
	pointer1 = pointer2;//obydwa wskazuja na second
	*pointer1 = 20;
	cout << "The first one is: " << first << " and the second one is: " << second << endl;

	//-----------------------------------------------------------------------------------------------------------------------//
	//Przemieszczanie po adresach tablicy
	print_line();
	cout << endl << "Przemieszczanie po adresach tablicy" << endl;

	int array1[10];
	int *p3;
	p3 = array1;//bo array to tak jakby pointer tylko ze pointer w przeciwienstwie do arraya moze byc zmieniany (inny adres)
	*p3 = 10;
	p3++;//adres o ++
	*p3 = 15;
	p3 = &array1[2];
	*p3 = 24;
	p3 = array1 + 3;
	*p3 = 12;
	p3 = array1;
	*(p3 + 4) = 49;

	for (int i = 0; i < 5; i++) {
		cout << "Array element number " << i << " is: " << array1[i] << endl;
	}

	//jak operuje array?
	array1[5] = 0;
	//dziala tak samo jak:
	*(array1 + 5) = 0;

	//przy utworzeniu pointera mozna odrazu zapodac mu adres ale nie wartosc bo nie ma jej gdzie zapisac wiec:
	int *p4 = &first;
	//dopiero wartosc
	*p4 = 7;

	//-----------------------------------------------------------------------------------------------------------------------//
	//Wielkosci zmiennych i arytmetyka pointera
	print_line();
	cout << endl << "Wielkosci zmiennych i arytmetyka pointera" << endl;
	//pointery obejmuja tylko dodawanie i odejmowanie

	int wielkosc_int = sizeof(int);
	cout << "The size of an integer on this machine is: " << wielkosc_int << endl;
	int wielkosc_char = sizeof(char);
	cout << "The size of an character on this machine is: " << wielkosc_char << endl;
	int wielkosc_long = sizeof(long);
	cout << "The size of an long integer on this machine is: " << wielkosc_long << endl;

	char mychar_h;
	int myint_h;
	long mylong_h;

	char *mychar = &mychar_h;
	int *myint = &myint_h;
	long *mylong = &mylong_h;

	cout << "Adress of an integer before: " << myint << endl;
	cout << "Adress of an character before: " << mychar << endl;
	cout << "Adress of an long before: " << mylong << endl;

	++mychar;
	++myint;
	++mylong;

	cout << "Adress of an integer after: " << myint << endl;
	cout << "Adress of an character after: " << mychar << endl;
	cout << "Adress of an long after: " << mylong << endl;


	/*
	int *p5;
	p5 = &first;

	*p5++   // same as *(p++): increment pointer, and dereference unincremented address
	*++p5   // same as *(++p): increment pointer, and dereference incremented address
	++*p5   // same as ++(*p): dereference pointer, and increment the value it points to
	(*p5)++ // dereference pointer, and post-increment the value it points to 
	*/

	//-----------------------------------------------------------------------------------------------------------------------//
	//Const i pointery
	print_line();
	cout << endl << "Const i pointery" << endl;

	int array2[] = { 10,20,30 };
	increment_all(array2, array2 + 3);
	print_all(array2, array2 + 3); // the pointers can still be incremented or assigned different addresses, although they cannot modify the content they point to.

	/*
	int x;
	int *       p1 = &x;  // non-const pointer to non-const int
	const int *       p2 = &x;  // non-const pointer to const int
	int * const p3 = &x;  // const pointer to non-const int
	const int * const p4 = &x;  // const pointer to const int 
	*/

	//-----Wielopoziomowy pointer-------//
	char a;
	char * b;
	char ** c;
	a = 'z';
	b = &a;
	c = &b;

	int * p = 0;
	int * q = nullptr;//obydwa to nullptr
	int * r = NULL;

	//-----------------------------------------------------------------------------------------------------------------------//
	//Funkcja do funkcji
	print_line();
	cout << endl << "Funkcja do funkcji" << endl;

	int m, n;
	int(*minus)(int, int) = subtraction;

	m = operation(7, 5, addition);
	n = operation(20, m, minus);
	cout << n;


	system("PAUSE");
	return 0;
}