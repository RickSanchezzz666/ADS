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

    bool __isListEmpty() {
        if (__count <= -1) { return true; }
        else { return false; };
    }

    bool __isListFull() {
        if (__count == SIZE - 1) { return true; }
        else { return false; }
    }

public:
    DoublyLinkedList() : __count(-1) { __head  = new Node; }

    ~DoublyLinkedList() {
        Node* temp = __head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
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

    void insertInBetweenNodes(int newData, int nodePos) {
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

            Node* node = __head;
            for (int i = 0; i < __count; i++) {
                node = node->next;
            }

            node->next = newNode;
            newNode->prev = node;

            ++__count;
        }
    }

    void deleteAtTheBeginning() {
        if (__isListEmpty()) {
            std::cout << "The List is Empty!\n";
            return;
        }
        else {
            Node* head = __head;
            if (head->next == nullptr) {
                delete head;
                __head = nullptr;
            }
            else {
                Node* node = head->next;
                delete head;
                node->prev = nullptr;
                __head = node;
            }
            --__count;
        }
    }

    void deleteByPosition(int nodePos) {
        if (__isListEmpty()) {
            std::cout << "The List is Empty!\n";
            return;
        }
        else {
            if (nodePos < 0 || nodePos > __count) {
                std::cout << "This position is invalid!\n";
                return;
            }

            Node* node = __head;
            if (nodePos == 0) {
                delete node;
                __head = nullptr;
            }
            else {
                for (int i = 1; i < nodePos; i++) {
                    node = node->next;
                }
                if (node == nullptr) {
                    std::cout << "This position is invalid!\n";
                    return;
                }
                Node* prev = node->prev;
                Node* next = node->next;
                delete node;
                prev->next = next;
                next->prev = prev;
            }
            --__count;
        }
    }

    void deleteAtTheEnd() {
        if (__isListEmpty()) {
            std::cout << "The List is Empty!\n";
            return;
        }
        else {
            Node* node = __head;
            if (node->next == nullptr) {
                delete node;
                __head = nullptr;
            }
            else {
                for (int i = 0; i < __count; i++) {
                    node = node->next;
                }
                node->prev->next = nullptr;
                delete node;
            }
            --__count;
        }
    }

    bool searchNode(int value) {
        Node* node = __head;
        for (int i = 0; i < __count; i++) {
            if (node->next != nullptr) {
                if (node->data = value) {
                    return true;
                }
                node = node->next;
            }
            else {
                std::cout << "The Node was not found!\n";
                return false;
            }
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

    list.insertInBetweenNodes(13, 1);

    list.insertAtTheEnd(666);

    list.insertAtTheEnd(15);

    list.deleteAtTheBeginning();

    list.deleteByPosition(2);

    list.deleteAtTheEnd();

    list.displayList();

    bool node = list.searchNode(666);

    std::cout << "Node by value was found: " << (node ? "True" : "False");
}