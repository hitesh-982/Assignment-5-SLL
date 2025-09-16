#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LL {
private:
    Node* head;

public:
    LL() : head(NULL) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    int mid() {
        if (!head) return -1;

        Node* slow = head;
        Node* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    void disp() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LL list;

    for (int i = 1; i <= 5; i++) {
        list.insert(i);
    }

    cout << "list"<<endl;
    list.disp();

    cout << "middle" << list.mid() << endl;

    return 0;
}
