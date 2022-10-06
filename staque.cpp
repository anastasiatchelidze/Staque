#include <iostream>
#include "staque.h"

using namespace std;

Staque::Staque() {
    size = 0;
    top = back = nullptr;
}
    
bool Staque::isEmpty() {
    return size == 0;
}
    
Staque::Staque(Staque &original) {
    size = original.size;
    top = back = nullptr;
        
    if(!original.isEmpty()) {
        top = back = new Node(original.top->data, original.top->order); // copying the first node
        Node* origIt = original.top->next;
        while(origIt != nullptr) {
            back->next = new Node(origIt->data, origIt->order, nullptr, back);
            back = back->next;
            origIt = origIt->next;
        }
    }
}
    
Staque& Staque::operator=(const Staque &other) {
        
    if(this != &other) { // checking for self-assignment
        this->~Staque();
        top = back = new Node(other.top->data, other.top->order);
        Node* otherIt = other.top->next;
        while(otherIt != nullptr) {
            back->next = new Node(otherIt->data, otherIt->order, nullptr, back);
            back = back->next;
            otherIt = otherIt->next;
        }
        size = other.size;
    }
        
    return *this;
}
    
Staque::~Staque() {
    Node *temp;
    while (top != nullptr) {
        temp = top;
        top = top->next;
        delete temp;
    }
}
    
void Staque::push(myType val) {
    if (val % 2 == 0) {
        top = new Node(val, ++count, top);
        if(isEmpty()) {
            back = top;
        }else {
            top->next->prev = top;
        }
        countEven++;
    }else {
        if(!isEmpty()) {
            back = new Node(val, ++count, nullptr, back);
            back->prev->next = back;
        }else {
            top = back = new Node(val, ++count);
        }
        countOdd++;
    }
    size++;
}
    
void Staque::display(ostream& out) {
    Node* temp = top;
    for(int i = 0; i < size; i++) {
        out << temp->data << " ";
        temp = temp->next;
    }
    out << endl;
}
    
void Staque::pop(int numEven, int numOdd) {
    if (countEven >= numEven && countOdd >= numOdd) {
        for(int i = 0; i < numEven; i++) {
            if(size > 1) {
                top = top->next;
                delete top->prev;
                top->prev = nullptr; // to avoid error in case of double deletion
            }else {
                delete top;
                back = top = nullptr;
            }
            countEven--;
            size--;
        }
            
        for(int i = 0; i < numOdd; i++) {
            if(size > 1) {
                back = back->prev;
                back->next = nullptr;
                delete back->next;
            }else {
                delete back;
                top = back = nullptr;
            }
            countOdd--;
            size--;
        }
    }else {
        cout << "Can't delete. Not enough numbers for the operation." << endl;
    }
}
    
void Staque::pop(int num) {
    if (num <= size) {
        for(int i = 0; i < num; i++) {
            if(size==1) {
                if(top->data & 2 == 0) {
                    countEven--;
                }else {
                    countOdd--;
                }
                delete top;
                back = top = nullptr;
            }else { // either first or last element must be deleted based on their insert order
                if(top->order > back->order) {
                    if(top->data & 2 == 0) {
                        countEven--;
                    }else {
                        countOdd--;
                    }
                    top = top->next;
                    delete top->prev;
                    top->prev = nullptr;
                }else {
                    if(top->data & 2 == 0) {
                        countEven--;
                    }else {
                        countOdd--;
                    }
                    back = back->prev;
                    delete back->next;
                    back->next = nullptr;
                }
            }
            size--;
        }
    }else {
        cout << "Can't delete. Not enough numbers for the operation." << endl;
    }
}

ostream& operator<< (ostream& out, Staque& s) {
    s.display(out);
    return out;
}