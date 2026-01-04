#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front;
    int rear;
    int arr[5];
    int itemCount;

public:
    CircularQueue() {
        itemCount = 0;   
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % 5 == front);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        } 
        else if (isEmpty()) {
            front = rear = 0;
        } 
        else {
            rear = (rear + 1) % 5;
        }
        arr[rear] = val;
        itemCount++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        int x = arr[front];
        arr[front] = 0;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % 5;
        }

        itemCount--;
        return x;
    }

    int count() {
        return itemCount;
    }

    void display() {
        cout << "Queue elements: ";
        if (isEmpty()) {
            cout << "Queue is Empty";
        } else {
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % 5;
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q1;
    int option, value;

    do {
        cout << "\n1.Enqueue  2.Dequeue  3.isEmpty  4.isFull  5.Count  6.Display  0.Exit\n";
        cin >> option;

        switch (option) {
        case 1:
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            cout << "Dequeued: " << q1.dequeue() << endl;
            break;
        case 3:
            cout << (q1.isEmpty() ? "Empty\n" : "Not Empty\n");
            break;
        case 4:
            cout << (q1.isFull() ? "Full\n" : "Not Full\n");
            break;
        case 5:
            cout << "Count: " << q1.count() << endl;
            break;
        case 6:
            q1.display();
            break;
        }
    } while (option != 0);

    return 0;
}
