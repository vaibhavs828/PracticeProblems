#include <iostream>

using namespace std;

#define MAX 1000

class Stack {
    int top;
public:
    int a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }

    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow\n";
            return false;
        } else {
            a[++top] = x;
            cout << x << " pushed into stack\n";
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return 0; // or a sentinel value to indicate error
        } else {
            int x = a[top--];
            return x;
        }
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return 0; // or a sentinel value to indicate error
        } else {
            return a[top];
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

// Driver program to test above functions
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    
    // print top element of stack after popping
    cout << "Top element is : " << s.peek() << endl;
    
    // print all elements in stack
    cout <<"Elements present in stack : ";
    while(!s.isEmpty()) {
        // print top element in stack
        cout << s.peek() <<" ";
        // remove top element in stack
        s.pop();
    }

    return 0;
}
