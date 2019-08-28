#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "LkList.h"

using namespace std;


int main() 
{
	LkList list, list2;
//
//	//------------------------
//
	list.merge(list2);
	
	cout << "Merge #1 (empty merge): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << "Connections Test for List 1: ";
	list.testConnections();
	cout << "Connections Test for List 2: ";
	list2.testConnections();
	cout << endl << endl << endl;
	
//
//
//	////------------------------
//
//
	list2.insert({ 0, 10, 20, 30, 40 });

	list.merge(list2);

	cout << "Merge #2 (into an empty list): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << "Connections Test for List 1: ";
	list.testConnections();
	cout << "Connections Test for List 2: ";
	list2.testConnections();
	cout << endl << endl << endl;

	list.clear();
	list2.clear();


	cout << endl << endl;
//	////------------------------
//
//
	
	list.insert( { 0, 5, 10, 15, 20, 25, 30, 35, 40} );
	
	
	list.merge(list2);
	
	cout << "Merge #3 (from an empty list): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << "Connections Test for List 1: ";
	list.testConnections();
	cout << "Connections Test for List 2: ";
	list2.testConnections();
	cout << endl << endl << endl;
	
	
	list.clear();
	list2.clear();
//	
//	//------------------------
//
//
//
//
	list.insert( { 1, 3, 40, 47, 54, 61, 68 } );
	
	list2.insert( { 0, 3, 6, 9, 12, 15, 18 } );


	list.merge(list2);

	cout << "Merge #4(source before destination): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << "Connections Test for List 1: ";
	list.testConnections();
	cout << "Connections Test for List 2: ";
	list2.testConnections();
	cout << endl << endl << endl;
	
	
	list.clear();
	list2.clear();
////	
//
//	//------------------------
//
	list.insert( { 10, 17, 21, 28 } );
	
	list2.insert( { 50, 53, 56, 59, 62, 65 } );	
	
	list.merge(list2);
	
	cout << "Merge #5(source after destination): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << "Connections Test for List 1: ";
	list.testConnections();
	cout << "Connections Test for List 2: ";
	list2.testConnections();
	cout << endl << endl << endl;
	

	list.clear();
	list2.clear();

//	//------------------------
//
	list.insert( { 0, 9, 18, 27 } );
	
	list2.insert( { -6, -4, -2, 0, 2, 4, 6, 8, 10, 12, 16, 
	                 18, 20, 22, 24, 26, 28, 30, 32, 34 } );	
	
	list.merge( list2 );
	
	cout << "Merge #6(source overlaps destination):\n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << "Connections Test for List 1: ";
	list.testConnections();
	cout << "Connections Test for List 2: ";
	list2.testConnections();
	cout << endl << endl << endl;
	

	list.clear();
	list2.clear();
//
//
//	//------------------------
//
	list.insert( { -6, 2, 10, 18, 26, 34 } );
	
	list2.insert( { 10, 13, 16, 19, 22, 25 } );	
	
	list.merge( list2 );
	
	cout << "Merge #7(source within destination):\n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << "Connections Test for List 1: ";
	list.testConnections();
	cout << "Connections Test for List 2: ";
	list2.testConnections();
	cout << endl << endl << endl;
	
	
	list.clear();
	list2.clear();
//*/
//
//	//------------------------



	system("pause");
	return 0;
}


