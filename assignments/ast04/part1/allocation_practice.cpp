#include <iostream>
//TODO: For practice, do your own includes up here. 
//Please include the item header file so you can use the item class

using namespace std;

int readInteger(istream&);

int main()
{
	//---------------------- Example Code ----------------------
	//First, some example code for how things would be done without pointers
	Item yoyo = Item("Yoyo", 5, 1.25); //Makes a yoyo that costs 1.25, of which there are 5 in stock
	Item items[4]; //Makes an array of 4 uninitialized Items
	//When declaring a non-pointer variable, the C++ compiler will ALWAYS allocate an object for that variable.
	//That is, even if we didn't explicitly call the constructor for something like the Yoyo above, 
	//the compiler is going to construct one anyways, whether we like it or not. The same things goes for arrays of objects.
	
	//Static arrays, like the one above, have to have a fixed size and be known before running the program. This
	//can be good for efficiency since the size is consistent and can be allocated when the program starts rather
	//than waiting until later. However, we are locked into this array always being 4 no matter what.
	//Dynamic arrays can be allocated during the run of the program to a size not known ahead of time. When allocating
	//a dynamic array, a pointer to here the array was allocated will be returned.
	
	//The next two sections will practice with the dynamic allocation of an object and an array as practice.
	
	//---------------------- Object Allocation ----------------------
	Item* tv; //Alternatively ItemRef tv (using the directive from the header)
	
	//TODO: Write the code to allocate an Item for a TV that costs $600.00 and a quantity of 4
	//Then, write a line to print that TV's info using the printItemInfo() function
	//Please be sure to look through the Item header file!
	
	
	
	//---------------------- Array Allocation ----------------------
	int itemCount;
	cout << "How big should the item array be?" << endl;
	itemCount = readInteger(cin);
	Item* arr;
	//TODO: Write code to practice allocating an array
	//The above prompt will read the size of the array. Allocate an array of that size
	//And then print all of the items in that array (they should all be blank, but it's fine)


	
	//---------------------- Array of Pointers Allocation ----------------------
	Item** itemsArr; //This is a 1D array of Item*s! Alternatively ItemRef* itemsArr.
	int halfSize = itemCount / 2;
	//TODO: Practice allocating an array of pointers
	//Allocate a 1D array of pointers to items. Then, fill half of the array with 
	//Keyboard items that cost $25.50 and a quantity of 1
	//Afterwards, print these keyboards
	
	//While this method can seem tricky at first, it can be more efficient. Since pointers do not allocate the Item
	//they will point to (unlike normal object declarations) an Item does not always need to be created.
	//Since this array only fills up half with keyboard items, it will need (roughly) half the memory that
	//the previous array did, which always fills any spaces with blank Items. Here, those spaces are left as
	//nullptr, but do not point to any actual Item objects.
	
	
	
	//---------------------- Deallocation ----------------------
	//This will be provided as an example. Any dynamically allocated memory needs to be deallocated before
	//the program finishes, or else a memory leak will occur
	//Basically, any memory that we as programmers allocate will also need to be deallocated by the programmer
	
	delete tv; //Deallocating the tv. delete is used to deallocate objects
	delete[] arr; //Deallocating the array of Items. delete[] is used for deallocating arrays
	//Deallocating the array of Item*s
	for(int i = 0; i < halfSize; i++) //First, deallocate the items in the array
		delete itemsArr[i]; //Deallocate each item, which is an object and needs delete
	delete[] itemsArr; //Delete the array that held the items afterwards

	return 0;
}

//Helper function to read a positive integer from a stream with error checking
int readInteger(istream& in)
{
	int value;
	cin >> value;
	while(cin.fail() || value < 1)
	{
		cout << "Error, please enter a positive integer" << endl;
		in.ignore(1024);
		in.clear();
		in >> value;
	}
	
	return value;
}


