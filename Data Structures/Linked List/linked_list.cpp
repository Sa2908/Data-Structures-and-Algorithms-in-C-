#include<iostream>
using namespace std;

// Class for the Nodes of the linked list
class Node {
    public:
        int data;
        Node * next;
};

// C++ implementation of Linked Lists
class LinkedList {
private:
    Node * tail, * head;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert at the end 
    void push_back(int value) {
        Node * node = new Node();
        node->data = value;
        node->next = NULL;
        if(head == NULL)        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }
    }
    
    // Display the Linked List
    void display() {
        Node * node = new Node();
        node = head;
        while (node!=NULL) {
            cout<<node->data<<endl;
            node = node->next;
        }
    }

    // Insert at the start
    void insert_at_start(int value) {
        Node * node = new Node();
        node->data = value;
        node->next = head;
        head = node;
    }
    
    // Insert at a given index in the Linked List
    void insert_at_index(int value, int index) {
        Node * pre, * cur;
        Node * node = new Node();

        node->data = value;
        cur = head;

        for (int i = 0; i < index; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = node;
        node->next = cur;
    }

    // Delete the first node
    void delete_first() {
        Node * node = new Node();
        node = head;
        head = head->next;
        delete node;
    }

    // Delete the last node
    void pop_back() {
        Node * current = new Node();
        Node * previous = new Node();

        current = head;

        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }

        tail = previous;
        previous->next = NULL;
        delete current;
    }

    // Delete node at a given index
    void delete_at_index(int index) {
        Node * current = new Node();
        Node * previous = new Node();

        current = head;
        
        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
    } 
};

int main(){

    // Uncomment the below code and use the features of the LinkedList Class 

    LinkedList ll;
    // ll.push_back(5);
    // ll.push_back(6);
    // ll.push_back(7);
    // ll.push_back(8);
    // ll.push_back(9);
    // ll.display();

    // ll.insert_at_start(20);
    // cout<<endl;
    // ll.display();


    // ll.insert_at_index(45, 3);
    // cout<<endl;
    // ll.display();

    // ll.delete_first();
    // cout<<endl;
    // ll.display();

    // ll.pop_back();
    // cout<<endl;
    // ll.display();

    // ll.delete_at_index(2);
    // cout<<endl;
    // ll.display();
    return 0;
}