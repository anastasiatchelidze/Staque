#ifndef STAQUE_H
#define STAQUE_H

using namespace std;

int typedef myType;

class Staque {
    class Node {
    public:
        myType data;
        Node* next;
        Node* prev;
        int order;
        Node(myType val, int Order, Node* ptr1 = nullptr, Node* ptr2 = nullptr) : data(val), order(Order), next(ptr1), prev(ptr2) { }
    };
    
    int size;
    Node* top;
    Node* back;
    
public:
    static int countOdd;
    static int countEven;
    static int count; // variable for keeping track of orders of inserting elements to the list
    
    Staque(); // default constuctor
    bool isEmpty(); // predicate function to check whether the list is empty or not
    Staque(Staque &); // copy constuctor
    Staque& operator=(const Staque &); // overloaded assignment operator
    ~Staque(); // destructor
    void push(myType); // function to insert new element to the list
    void display(ostream&); // function to output the elements of the list
    void pop(int, int); // function to delete even and/or odd numbers from the list
    void pop(int = 1); // function that deletes last element(s) from the list based on their insert order
};

ostream& operator<< (ostream&, Staque&); // overloaded output operator

#endif