#include <iostream>
using namespace std;

struct Node {
    int value;
    int minValue;
    Node* next;
};

class MinStack {
private:
    Node *head = nullptr;
    
    int getMinValue(int currentMinValue, int newValue) {
        if (newValue < currentMinValue)
            return newValue;
        return currentMinValue;
    }
    
public:
    MinStack() {
    }
    
    void push(int val) {
        Node *newNode = new Node{};
        if (!head) {
            newNode->minValue = val;
            newNode->value = val;
            newNode->next = nullptr;
            this->head = newNode;
            return;
        }
        newNode->value = val;
        newNode->minValue = getMinValue(head->minValue, val);
        newNode->next = head;
        this->head = newNode;
    }
    
    void pop() {
        if (!head) {
            return;
        }
        Node* pointerToDelete = head;
        head = head->next;
        delete pointerToDelete;
    }
    
    int top() {
        if (!head)
            return NAN;
        return head->value;
    }
    
    int getMin() {
        if (!head)
            return NAN;
        return head->minValue;
    }

    ~MinStack() {
        if (!head)
            return;
        Node *temp;
        while(head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
