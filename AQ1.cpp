#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(NULL) {}
};

Node* head = NULL;

void show() {
    Node* cur = head;
    while (cur) {
        cout << cur->data;
        if (cur->next) cout << "->";
        cur = cur->next;
    }
    cout << "\n";
}

void insertbeg(int x) {
    Node* n = new Node(x);
    n->next = head;
    head = n;
}

void insertend(int x) {
    Node* n = new Node(x);
    if (!head) {
        head = n;
        return;
    }
    Node* cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = n;
}

bool insertbefore(int t, int x) {
    if (!head) return false;
    if (head->data == t) {
        insertbeg(x);
        return true;
    }
    Node* cur = head;
    while (cur->next && cur->next->data != t) {
        cur = cur->next;
    }
    if (!cur->next) return false;
    Node* n = new Node(x);
    n->next = cur->next;
    cur->next = n;
    return true;
}

bool insertafter(int t, int x) {
    Node* cur = head;
    while (cur && cur->data != t) {
        cur = cur->next;
    }
    if (!cur) return false;
    Node* n = new Node(x);
    n->next = cur->next;
    cur->next = n;
    return true;
}

bool delbeg() {
    if (!head) return false;
    Node* t = head;
    head = head->next;
    delete t;
    return true;
}

bool delend() {
    if (!head) return false;
    if (!head->next) {
        delete head;
        head = NULL;
        return true;
    }
    Node* cur = head;
    while (cur->next->next) {
        cur = cur->next;
    }
    delete cur->next;
    cur->next = NULL;
    return true;
}

bool delval(int x) {
    if (!head) return false;
    if (head->data == x) return delbeg();
    Node* cur = head;
    while (cur->next && cur->next->data != x) {
        cur = cur->next;
    }
    if (!cur->next) return false;
    Node* t = cur->next;
    cur->next = cur->next->next;
    delete t;
    return true;
}

int searchval(int x) {
    Node* cur = head;
    int pos = 1;
    while (cur) {
        if (cur->data == x) return pos;
        cur = cur->next;
        pos++;
    }
    return -1;
}

int main() {
    while (1) {
        cout << "\n1.insert beg\n";
        cout << "2.insert end\n";
        cout << "3.insert before\n";
        cout << "4.insert after\n";
        cout << "5.del beg\n";
        cout << "6.del end\n";
        cout << "7.del val\n";
        cout << "8.search\n";
        cout << "9.show\n";
        cout << "0.exit\n";
        int c;
        cin >> c;
        if (c == 0) break;
        int x, t;
        switch (c) {
            case 1:
                cin >> x;
                insertbeg(x);
                break;
            case 2:
                cin >> x;
                insertend(x);
                break;
            case 3:
                cin >> x >> t;
                if (!insertbefore(t, x)) cout << "not found\n";
                break;
            case 4:
                cin >> x >> t;
                if (!insertafter(t, x)) cout << "not found\n";
                break;
            case 5:
                if (!delbeg()) cout << "empty\n";
                break;
            case 6:
                if (!delend()) cout << "empty\n";
                break;
            case 7:
                cin >> x;
                if (!delval(x)) cout << "not found\n";
                break;
            case 8:
                cin >> x;
                t = searchval(x);
                if (t == -1) cout << "not found\n";
                else cout << "pos " << t << "\n";
                break;
            case 9:
                show();
                break;
        }
    }
}
