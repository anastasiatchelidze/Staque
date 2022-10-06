#include <iostream>
#include "staque.h"

using namespace std;

//initializing static variables

int Staque::countOdd = 0;
int Staque::countEven = 0;
int Staque::count = 0;

int main() {
    Staque s;
    s.push(15);
    s.push(7);
    s.push(6);
    s.push(8);
    s.push(1);
    s.push(23);
    s.push(12);
    cout << "List after populating it with elements:" << endl;
    s.display(cout);
    cout << "List after deleting 2 even and 1 odd numbers:" << endl;
    s.pop(2,1);
    cout << s;
    cout << "List after deleting the last element:" << endl;
    s.pop();
    cout << s;
    
    Staque newList;
    newList.push(10);
    newList.push(1);
    newList.push(15);
    newList.push(20);
    newList.push(-7);
    newList.push(6);
    newList.push(11);
    newList.push(8);
    newList.push(64);
    newList.push(-72);
    newList.push(40);
    cout << endl;
    cout << "Outputting the new list:" << endl;
    cout << newList;
    cout << "New list after deleting the last 2 elements:" << endl;
    newList.pop(2);
    cout << newList;
    cout << "New list after deleting 3 even numbers:" << endl;
    newList.pop(3,0);
    cout << newList;
    cout << "New list after deleting 1 odd number:" << endl;
    newList.pop(0,1);
    cout << newList;
    cout << "Trying to delete 4 odd numbers from the list..." << endl;
    newList.pop(0,4);

    return 0;
}