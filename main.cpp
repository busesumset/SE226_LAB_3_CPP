#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }
    void dequeue() {
        if (front == nullptr) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        count--;
    }

    int top() {
        if (front == nullptr) {
            return -1;
        }
        return front->data;
    }


    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        count++;
    }



    bool isEmpty() {
        return (front == nullptr);
    }

    int size() const {
        return count;
    }
};

int main() {

    Queue queue;

    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(12);
    queue.enqueue(16);
    queue.enqueue(19);
    queue.enqueue(20);
    queue.enqueue(24);
    queue.enqueue(30);

    std::cout << "Top : " << queue.top() << std::endl;
    std::cout << "Size: " << queue.size() << std::endl;


    if(queue.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    std::cout << std::endl;

    queue.dequeue();

    std::cout << "Size: " << queue.size() << std::endl;


    if(queue.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }
}
