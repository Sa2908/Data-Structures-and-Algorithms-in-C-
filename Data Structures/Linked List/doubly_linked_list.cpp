#include<iostream>

using namespace std;


class Node {
public:
    int data;
    Node * next;
    Node * prev;
    Node() {

    }
    Node(int x) {
        data = x;
    }
};

class DoubleLinkedList {
    Node * start;
public:
    DoubleLinkedList () {
        start = NULL;
    }

    void create_list(int value) {
        Node * node, *s;
        node = new Node(value);

        node->next = NULL;

        if (start == NULL) {
            node->prev = NULL;
            start = node;
        } else {
            s = start;
            while (s != NULL) {
                s = s->next;
            }
            s->next = node;
            node->prev = s;
        }
    }

    void add_begin (int value) {
        if (start == NULL) {
            return;
        }

        Node * node = new Node(value);

        node->prev = NULL;
        node->next = start;

        start->prev = node;
        start = node;
    }

    void add_after(int value, int index) {

        if (start == NULL) {
            return;
        }

        Node * node, *s;
        s = start;

        for (int i = 0; i < index-1; i++) {
            s = s->next;
            if (s == NULL) {
                return;
            }
        }
        
        node = new Node(value);
        if (s->next == NULL) {
            s->next = node;
            node->next = NULL;
            node->prev = s;
        } else {
            node->next = s->next;
            node->next->prev = node;
            s->next = node;
            node->prev = s;
        }
    }

    void delete_first() {
        Node * node;
        node = start;
        start = start->next;
        start->prev = NULL;
        delete node;
    }

    void delete_last() {
        Node * node;
        
        Node * q;
        q = start;
        while (q->next != NULL) {
            q = q->next;
        }
        node = q;
        delete node;

        
    }
    void display() {
        Node * q;
        if (start == NULL) {
            return;
        }

        q = start;

        while (q != NULL) {
            cout<<q->data<<endl;
            q = q->next;
        }
    }

};


int main(){

    DoubleLinkedList dll;
    
    // dll.create_list(1);
    // dll.display();
    // cout<<endl;

    // dll.add_begin(5);
    // dll.add_begin(6);
    // dll.add_begin(7);
    // dll.display();
    // cout<<endl;

    // dll.delete_last();
    // dll.display();

    return 0;
}