#include<iostream>
using namespace std;
class Queue{
	int capacity,size;
	int *a;
	int front, rear;
	public:
		Queue(int qsize){
			a = new int[qsize];
			front = 0;
			rear = -1;
			capacity = qsize;
			size=0;	
		}
		
    bool isFull() {
        return size == capacity;
    }		

    bool isEmpty() {
        return size == 0;
    }
		
	bool enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return false;
        }
        rear = (rear + 1) % capacity; // Circular increment
        a[rear] = x;
        size++;
        cout << x << " enqueued into queue\n";
        return true;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1; // Return a sentinel value to indicate an error
        }
        int x = a[front];
        front = (front + 1) % capacity; // Circular increment
        size--;
        return x;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1; // Return a sentinel value to indicate an error
        }
        cout<<"Value of front is "<<front<<endl;
        return a[front];
    }
};

// Driver program to test above functions
int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);  // Create queue with specified size

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front element is : " << q.peek() << endl;
    cout << q.dequeue() << " dequeued from queue\n";
    
    // Print front element of queue after dequeuing
    cout << "Front element is : " << q.peek() << endl;
    
    // Print all elements in queue
    cout << "Elements present in queue: ";
    while (!q.isEmpty()) {
        cout << q.peek() << " ";
        q.dequeue();
    }
    cout << endl;

    return 0;
}
