#include<iostream>

using namespace std;

// Class for creating nodes of Linked List
class Node {
public:
    int data;
    Node * next;
    Node () {

    }
    Node(int x){
        data = x;
    }
};


// Code for Circular Linked List
class CircularLinkedList {
public:
    Node * last;
    CircularLinkedList () {
        last = NULL;
    }
    // Create a node at the end
    void create_node (int value) {
        Node * node = new Node(value);

        if (last == NULL) {
            last = node;
            node->next = last;
        } else {
            node->next = last->next;
            last->next = node;
            last = node;
        }
    }

    // Add at the first
    void add_first(int value) {
        if (last == NULL) {
            return ;
        }

        Node * node = new Node(value);

        node->next = last->next;
        last->next = node;
    }
    
    // Add a node at an index
    void add_after(int value, int index) {
        if (last == NULL ) {
            return ;
        }
        
        Node * node = new Node(value);
        Node * s;
        s = last->next;

        for (int i = 0; i < index-1; i++) {
            s = s->next;
            if (s == last->next) {
                return ;
            }
        }
        node->next = s->next;
        s->next = node;

        if (s == last) {
            last = node;
        }
    }

    // Delete a value from the linked list
    void delete_value(int value) {
        Node * node = new Node();
        Node *s;
        s = last->next;

        if (last->next == last && last->data == value) {
            node = last;
            last = NULL;
            delete node;
            return;
        }

        if (s->data = value) {
            node = s;
            last->next = s->next;
            delete node;
            return ;
        }

        while (s->next != last) {

            if (s->next->data == value) {
                node = s->next;
                s->next = node->next;
                delete node;
                return;
            }
            s = s->next;
        }

        if (s->next->data == value) {
            node = s->next;
            s->next = last->next;
            delete node;
            last = s;
            return ;
        }

        cout<<"Element was not found in the list"<<endl;
    }

    // Display the list
    void display() {
        Node * ptr;

        if(last == NULL) {
            cout<<"Empty List"<<endl;
            return;
        }

        ptr = last->next;

        do {
            cout<<ptr->data<<endl;
            ptr = ptr->next;
        } while (ptr != last);
    }

};

int main(){

    // Uncomment the below code to perform the operations on the LinkedList

    CircularLinkedList cll;

    // cll.create_node(5);
    // cll.display();
    // cout<<endl;

    // cll.add_first(20);
    // cll.create_node(50);
    // cll.create_node(60);
    // cll.display();
    // cout<<endl;


    // cll.add_after(9, 1);
    // cll.display();
    // cout<<endl;

    // cll.delete_value(9);
    // cll.display();
    return 0;
}