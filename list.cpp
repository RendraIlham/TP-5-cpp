#include "list.h"

#include <iostream>
using namespace std;

void searchElement_103032430018(List &L, infotype x) {
    address current;
    int position;

    current = L.first;
    position = 1;

    while (current != nullptr && current -> info != x) {
        position++;
        current = current -> next;
    }

    if (current != nullptr) {
        cout << "Alamat dari current adalah" << &current << "di posisi ke " << position;
    } else {
        cout << "elemen tersebut tidak ada dalam list";
    }
}

void selectionSort_103032430018(List &L) {
    address p, Min, temp;
    infotype x;

    p = L.first;

    while (p != nullptr) {
        Min = p;
        temp = p;

        while (temp != nullptr) {
            if ((temp -> info) < Min -> info) {
                Min = temp;
            }
            temp = temp -> next;
        }
        x = p -> info;
        p -> info = Min -> info;
        Min -> info = x;

        p = p -> next;
    }
}

void insertSorted_103032430018(List &L, address p) {
    address q, prev;
    bool found;

    q = L.first;
    found = false;
    prev = nullptr;

    while (q != nullptr && found == false) {
        if (q -> info < p -> info) {
            prev = q;
            q = q -> next;
        } else {
            found = true;
        }
    }

    if (prev == nullptr) {
        p -> next = L.first;
        L.first = p;
    } else {
        p -> next = q;
        prev -> next = p;
    }
}
