#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int data;
    Node* next;
    Node* previous;

    Node() {
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
        previous = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    DoublyLinkedList(Node* n) {
        head = n;
    }

    // 1. Check if node exists using key value
    Node* nodeExists(int k) {
        Node* ptr = head;

        while (ptr != NULL) {
            if (ptr->key == k) {
                return ptr;
            }
            ptr = ptr->next;
        }
        return NULL;
    }

    // 2. Append a node to the list
    void appendNode(Node* n) {
        if (nodeExists(n->key) != NULL) {
            cout << "Node already exists with key value: " << n->key << endl;
        } else {
            if (head == NULL) {
                head = n;
                cout << "Node appended as head node" << endl;
            } else {
                Node* ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
                cout << "Node appended" << endl;
            }
        }
    }

    // 3. Prepend Node - Attach a node at the start
    void prependNode(Node* n) {
        if (nodeExists(n->key) != NULL) {
            cout << "Node already exists with key value: " << n->key << endl;
        } else {
            if (head == NULL) {
                head = n;
                cout << "Node prepended as head node" << endl;
            } else {
                head->previous = n;
                n->next = head;
                head = n;
                cout << "Node prepended" << endl;
            }
        }
    }

    // 4. Insert a Node after a particular node
    void insertNodeAfter(int k, Node* n) {
        Node* ptr = nodeExists(k);

        if (ptr == NULL) {
            cout << "No node exists with key value: " << k << endl;
        } else {
            if (nodeExists(n->key) != NULL) {
                cout << "Node already exists with key value: " << n->key << endl;
            } else {
                Node* nextNode = ptr->next;

                // inserting at end
                if (nextNode == NULL) {
                    ptr->next = n;
                    n->previous = ptr;
                    cout << "Node inserted at the end" << endl;
                }
                // inserting in between
                else {
                    n->next = nextNode;
                    nextNode->previous = n;
                    n->previous = ptr;
                    ptr->next = n;
                    cout << "Node inserted in between" << endl;
                }
            }
        }
    }

    // 5. Delete node by unique key (De-Link, not delete memory)

void deleteNodeByKey(int k)
{
    Node* ptr = nodeExists(k);

    if (ptr == NULL)
    {
        cout << "No node exists with key value: " << k << endl;
    }
    else
    {
        // If node is head
        if (ptr == head)
        {
            head = head->next;
            if (head != NULL)
            {
                head->previous = NULL;
            }
            cout << "Node unlinked (was head)" << endl;
        }
        // If node is in between or at end
        else
        {
            Node* prevNode = ptr->previous;
            Node* nextNode = ptr->next;

            if (nextNode != NULL)
            {
                nextNode->previous = prevNode;
            }

            prevNode->next = nextNode;
            cout << "Node unlinked" << endl;
        }

        // De-linking only (no delete)
        ptr->next = NULL;
        ptr->previous = NULL;
    }
}

// 6. Update node by unique key

void updateNodeByKey(int k, int d)
{
    Node* ptr = nodeExists(k);

    if (ptr == NULL)
    {
        cout << "No node exists with key value: " << k << endl;
    }
    else
    {
        ptr->data = d;
        cout << "Node data updated successfully" << endl;
    }
}

// 7. Print / Display the list

void printList()
{
    if (head == NULL)
    {
        cout << "Doubly Linked List is empty" << endl;
    }
    else
    {
        Node* temp = head;
        cout << "Doubly Linked List values are:" << endl;

        while (temp != NULL)
        {
            cout << "(" << temp->key << ", " << temp->data << ") <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}


};

int main()
{
    DoublyLinkedList obj;
    int option;
    int key, data, k;

    do
    {
        cout << "\n===== DOUBLY LINKED LIST MENU =====\n";
        cout << "1. Append Node\n";
        cout << "2. Prepend Node\n";
        cout << "3. Insert Node After Key\n";
        cout << "4. Delete Node By Key\n";
        cout << "5. Update Node By Key\n";
        cout << "6. Print List\n";
        cout << "7. Clear Screen\n";
        cout << "0. Exit\n";
        cout << "==================================\n";
        cout << "Enter your option: ";
        cin >> option;

        Node* n = new Node();

        switch (option)
        {
        case 1:
            cout << "Enter key and data to APPEND: ";
            cin >> key >> data;
            n->key = key;
            n->data = data;
            obj.appendNode(n);
            break;

        case 2:
            cout << "Enter key and data to PREPEND: ";
            cin >> key >> data;
            n->key = key;
            n->data = data;
            obj.prependNode(n);
            break;

        case 3:
            cout << "Enter key AFTER which to insert: ";
            cin >> k;
            cout << "Enter new node key and data: ";
            cin >> key >> data;
            n->key = key;
            n->data = data;
            obj.insertNodeAfter(k, n);
            break;

        case 4:
            cout << "Enter key of node to DELETE: ";
            cin >> key;
            obj.deleteNodeByKey(key);
            break;

        case 5:
            cout << "Enter key of node to UPDATE: ";
            cin >> key;
            cout << "Enter new data: ";
            cin >> data;
            obj.updateNodeByKey(key, data);
            break;

        case 6:
            obj.printList();
            break;

        case 7:
            system("cls");   // for Windows
            // system("clear"); // use this for Linux / Mac
            break;

        case 0:
            cout << "Exiting program... Goodbye!" << endl;
            break;

        default:
            cout << "Invalid option! Try again." << endl;
        }

    } while (option != 0);

    return 0;
}
