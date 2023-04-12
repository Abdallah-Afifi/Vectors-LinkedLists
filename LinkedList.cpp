#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::addNode(int value, int count) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->count = count;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::removeNode(int value) {
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr) {
        if (current->value == value) {
            if (previous == nullptr) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void LinkedList::printList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " (count: " << current->count << ")" << std::endl;
        current = current->next;
    }
}

void LinkedList::createListFromVector(std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        int value = vec[i];
        int count = 1;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] == value) {
                count++;
                vec.erase(vec.begin() + j);
                j--;
            }
        }
        addNode(value, count);
    }
}

int LinkedList::sumNodes() {
    int sum = 0;
    Node* current = head;
    while (current != nullptr) {
        sum += (current->value * current->count);
        current = current->next;
    }
    return sum;
}
