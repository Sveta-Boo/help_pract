#pragma once
#include <fstream>
using namespace std;
template <class T>
class MyList
{

    class Node {
    public:
        T info;
        Node* next;
        Node() { next = NULL; }
        Node(T info, Node* next = NULL) :info(info), next(next) {}
        // Node(T info) :info(info), next(NULL) {}
        friend ostream& operator<<(ostream& os, Node*& n) {
            return os << n->info;
        }
        ~Node() {}
    };
public:
    Node* head = NULL;
    Node* tail = NULL;

    bool isEmpty() {
        return head == NULL;
    }

    void addEnd(T t) {
        Node* newNode = new Node(t);
        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void addBegin(T t) {
        Node* newNode = new Node(t);
        if (head == NULL)
            head = tail = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }
    int deleteNode(T del) {
        if (head == NULL) return -1;
        if (head->info == del) {
            Node* temp = head;
            head = head->next;
            if (head == NULL) tail = NULL;
            delete temp;
            return 0;
        }
        else {
            Node* h = NULL;
            Node* temp = NULL;
            for (h = head; h->next && !(h->next->info == del); h = h-> next);
            if (h->next == NULL) return -1;
            temp = h->next;
            h->next = temp->next;
            if (temp == tail) tail = h;
            delete temp;
            return 0;
        }
    }
     int find(T value) {
        Node* c = head;
        while (c != NULL) {
            if (c->info == value) {
                return 1;
            }
            c = c->next;
        }
        return 0;
    }
    void addSort(T t) { //вставка
        Node* newNode = new Node(t); //создаём новый узел
        if (head == NULL || t < head->info) { //вставка в начало,
            newNode->next = head;
            head = newNode;
            if (tail == NULL) tail = newNode;
            return;
        }
        Node* c = head;
        while (c->next != NULL && !(t < c->next->info)) {
            c = c->next;
        }
        newNode->next = c->next;
        c->next = newNode;
    }
    friend ostream& operator<<(ostream& os, MyList& list) {
        Node* node = list.head;

        //while (node) {
        //    os << node->info << endl;
        //    node = node->next;
        //}
        //return os;
        for (Node* node = list.head; node; node = node->next)
            os << node << "-->";
        return os;
    }

};