//This file exists to test your ShoppingCart class.
//Nothing needs to be added here, the makefile will use this to build a testing program
#include "../item.h"
#include "../shopping_cart.h"
#include <iostream>

using namespace std;

int readInteger(istream&);

int main()
{
	ShoppingCart cart = ShoppingCart(3); //Make a shopping cart to hold 3 things
	
	cout << "Adding the first item..." << endl;
	cart.addItem(new Item("Tonkotsu", 1, 9.50));
	
	cout << "Adding the second item..." << endl;
	cart.addItem(new Item("Tacos Al Pastor", 6, 2.20));
	
	cout << "Adding the third item..." << endl;
	cart.addItem(new Item("Cacio e Pepe", 2, 12.34));
	
	cout << "Adding the fourth item. which should resize..." << endl;
	cart.addItem(new Item("Big Burger", 1, 14.67));
	
	cart.printCart();
	
	cout << "The shopping cart will now delete its items" << endl;

	return 0;
}



