#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>

struct Node {
    int value;
    int count;
    Node* next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void addNode(int value, int count);
    void removeNode(int value);
    void printList();
    void createListFromVector(std::vector<int>& vec);
    int sumNodes();

private:
    Node* head;
};

#endif
