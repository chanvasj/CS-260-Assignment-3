#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        T val = front->data;
        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
        return val;
    }

    T peek() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return front->data;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};

int main() {
    std::cout << "Testing..." << std::endl;
    
    // Test enqueue method
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Queue after enqueueing: ";
    while (!q.isEmpty()) {
        std::cout << q.dequeue() << " ";
    }
    std::cout << std::endl;

    // Test dequeue method
    Queue<int> q2;
    q2.enqueue(100);
    q2.enqueue(200);
    q2.enqueue(300);
    std::cout << "Dequeueing from queue: ";
    std::cout << q2.dequeue() << std::endl;

    // Test peek method
    Queue<int> q3;
    q3.enqueue(1000);
    q3.enqueue(2000);
    q3.enqueue(3000);
    std::cout << "Peeking at front element: ";
    std::cout << q3.peek() << std::endl;

    return 0;
}