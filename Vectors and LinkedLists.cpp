#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

void insertAfter(vector<int>& vec, int firstValue, int secondValue) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == firstValue) {
            vec.insert(vec.begin() + i + 1, secondValue);
            i++;
        }
    }
}

int main() {
    vector<int> vec;
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cout << "Enter integer " << i + 1 << ": ";
        cin >> num;
        vec.push_back(num);
    }
        int firstValue, secondValue;
        cout << "Enter the first value: ";
        cin >> firstValue;
        cout << "Enter the second value: ";
        cin >> secondValue;
        insertAfter(vec, firstValue, secondValue);

        LinkedList list;
        list.createListFromVector(vec);
        cout << "The linked list is:" << endl;
        list.printList();
        cout << "The sum of all nodes is: " << list.sumNodes() << endl;

        return 0;
    }
