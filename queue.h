//
// Created by vitor on 9/24/23.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Queue {
private:
    Node *front;
    Node *rear;
    int count;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }
    ~Queue() {
        Node *temp;
        while (front != nullptr) {
            temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        count = 0;
    }
    void enqueue(int element) {
        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = nullptr;
        if (front == nullptr) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        count++;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "A fila esta vazia." << endl;
            exit(EXIT_FAILURE);
        }

        Node *temp = front;
        front = front->next;
        delete temp;
        count--;
    }
    void display() {
        Node *temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool isEmpty() {
        return count == 0;
    }
};


#endif //QUEUE_QUEUE_H
