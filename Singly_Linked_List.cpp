#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int data;
    Node* next;

    Node() {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = NULL;
    }

    // 1. Check if node exists
    Node* nodeExists(int k) {
        Node* ptr = head;
        while (ptr != NULL) {
            if (ptr->key == k)
                return ptr;
            ptr = ptr->next;
        }
        return NULL;
    }

    // 2. Append Node
    void appendNode(Node* n) {
        if (nodeExists(n->key) != NULL) {
            cout << "Node already exists with key " << n->key << endl;
            return;
        }

        if (head == NULL) {
            head = n;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = n;
        }
        cout << "Node appended successfully" << endl;
    }

    // 3. Prepend Node
    void prependNode(Node* n) {
        if (nodeExists(n->key) != NULL) {
            cout << "Node already exists with key " << n->key << endl;
            return;
        }

        n->next = head;
        head = n;
        cout << "Node prepended successfully" << endl;
    }

    // 4. Insert Node After
    void insertNodeAfter(int k, Node* n) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL) {
            cout << "No node exists with key " << k << endl;
            return;
        }

        if (nodeExists(n->key) != NULL) {
            cout << "Node already exists with key " << n->key << endl;
            return;
        }

        n->next = ptr->next;
        ptr->next = n;
        cout << "Node inserted successfully" << endl;
    }

    // 5. Delete Node By Key
    void deleteNodeByKey(int k) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->key == k) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted successfully" << endl;
            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr != NULL) {
            if (curr->key == k) {
                prev->next = curr->next;
                delete curr;
                cout << "Node deleted successfully" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Node not found" << endl;
    }

    // 6. Update Node
    void updateNodeByKey(int k, int d) {
        Node* ptr = nodeExists(k);
        if (ptr != NULL) {
            ptr->data = d;
            cout << "Node updated successfully" << endl;
        } else {
            cout << "Node not found" << endl;
        }
    }

    // 7. Print List
    void printList() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        cout << "Singly Linked List: ";
        while (temp != NULL) {
            cout << "(" << temp->key << "," << temp->data << ") -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList s;
    int option, key, data, k;

    do {
        cout << "\nChoose operation:\n";
        cout << "1. Append Node\n";
        cout << "2. Prepend Node\n";
        cout << "3. Insert Node After\n";
        cout << "4. Delete Node\n";
        cout << "5. Update Node\n";
        cout << "6. Print List\n";
        cout << "0. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter key and data: ";
            cin >> key >> data;
            s.appendNode(new Node(key, data));
            break;

        case 2:
            cout << "Enter key and data: ";
            cin >> key >> data;
            s.prependNode(new Node(key, data));
            break;

        case 3:
            cout << "Enter key after which to insert: ";
            cin >> k;
            cout << "Enter new key and data: ";
            cin >> key >> data;
            s.insertNodeAfter(k, new Node(key, data));
            break;

        case 4:
            cout << "Enter key to delete: ";
            cin >> key;
            s.deleteNodeByKey(key);
            break;

        case 5:
            cout << "Enter key and new data: ";
            cin >> key >> data;
            s.updateNodeByKey(key, data);
            break;

        case 6:
            s.printList();
            break;

        case 0:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid option" << endl;
        }
    } while (option != 0);

    return 0;
}
