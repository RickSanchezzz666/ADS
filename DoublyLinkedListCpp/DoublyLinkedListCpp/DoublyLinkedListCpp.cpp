#include <iostream>

#define SIZE 5

struct Node {
    int data = 0;
    struct Node* next = nullptr;
    struct Node* prev = nullptr;
};

class DoublyLinkedList {
private:
    int __count = -1;
    Node* __head;

    Node* __createHead() {
        if (__count == -1) {
            Node* head = new Node;
            return head;
        }
        return nullptr;
    }
    
    bool __isListEmpty() {
        if (__count <= -1) { return true; }
        else { return false; };
    }

    bool __isListFull() {
        if (__count == SIZE - 1) { return true; }
        else { return false; }
    }

    /*Node* __getTail() {
        if (__isListEmpty() == false) {
            Node* node = __head;
            while (node->next != nullptr) {
                node = node->next;
            }
            return node;
        }        
        return nullptr;
    }*/

public:
    DoublyLinkedList() : __count(-1) { __head = __createHead(); }

    ~DoublyLinkedList() {
        
    }

    void insertAtTheBeginning(int newData) {
        if (__isListFull()) { 
            std::cout << "The List is Full!\n";
            return; 
        }
        else {
            Node* newNode = new Node;
            newNode->data = newData;
            newNode->prev = nullptr;
            newNode->next = __head;

            if (__head != nullptr) {
                __head->prev = newNode;
            }

            __head = newNode;
            
            ++__count;
        }
    }

    void insertInBeetwenNodes(int newData, int nodePos) {
        if (__isListFull()) {
            std::cout << "The List is Full!\n";
            return;
        }
        else {
            if (nodePos <= 0 || nodePos > __count) {
                std::cout << "This position is invalid!\n";
                return;
            }
            Node* newNode = new Node;
            newNode->data = newData;

            Node* node = __head;
            for (int i = 0; i < nodePos - 1; i++) {
                node = node->next;
            }
            if (node == nullptr) {
                std::cout << "This position is invalid!\n";
                delete newNode;
                return;
            }

            newNode->prev = node;
            newNode->next = node->next;

            if (node->next != nullptr) {
                node->next->prev = newNode;
            }

            node->next = newNode;

            ++__count;

        }
    }

    void insertAtTheEnd(int newData) {
        if (__isListFull()) {
            std::cout << "The List is Full!\n";
            return;
        }
        else {
            Node* newNode = new Node;
            newNode->data = newData;
            newNode->next = nullptr;

            if (__head == nullptr) {
                delete newNode;
                insertAtTheBeginning(newData);
                return;
            }

            //Node* tail = __getTail();

            Node* node = __head;
            for (int i = 0; i < __count; i++) {
                node = node->next;
            }

            node->next = newNode;
            newNode->prev = node;

            ++__count;
        }
    }


    void displayList() {
        if (__isListEmpty()) {
            std::cout << "The List is Empty!\n";
            return;
        }
        else {
            Node* node = __head;
            std::cout << "Your List is:\n" << node->data;
            node = node->next;
            for (int i = 0; i < __count; i++) {   
                std::cout << "->" << node->data;
                node = node->next;
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    
    list.insertAtTheBeginning(3);
    list.insertAtTheBeginning(16);

    list.insertInBeetwenNodes(13, 1);

    list.insertAtTheEnd(666);

    list.insertAtTheEnd(6662);

    list.displayList();
}