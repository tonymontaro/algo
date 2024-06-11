#include <bits/stdc++.h>

using namespace std;
#define ll long long


// Example: https://atcoder.jp/contests/abc344/tasks/abc344_e (solution: https://atcoder.jp/contests/abc344/submissions/54402924)
struct LinkedListNode {
    LinkedListNode* prev = nullptr;
    LinkedListNode* next = nullptr;
    ll val = 0;
    LinkedListNode(){}
    LinkedListNode(ll v){val = v;}
};
class LinkedList {
public:
    LinkedListNode* head = nullptr;
    LinkedListNode* tail = nullptr;
    LinkedListNode* setHead(ll val) {
        auto next = head;
        head = new LinkedListNode(val);
        if (next) {
            head->next = next;
            next->prev = head;
        } else
            tail = head;
        return head;
    }
    LinkedListNode* setTail(ll val) {
        if (!head) {
            return setHead(val);
        }
        auto prev = tail;
        tail = new LinkedListNode(val);
        prev->next = tail;
        tail->prev = prev;
        return tail;
    }
    LinkedListNode* insertAfter(LinkedListNode* prev, ll val) {
        auto node = new LinkedListNode(val);
        node->next = prev->next;
        if (node->next) node->next->prev = node;
        else tail = node;
        node->prev = prev;
        prev->next = node;
        return node;
    }
    LinkedListNode* insertBefore(LinkedListNode* next, ll val) {
        auto node = new LinkedListNode(val);
        node->prev = next->prev;
        if (node->prev) node->prev->next = node;
        else head = node;
        node->next = next;
        next->prev = node;
        return node;
    }
    void removeHead(LinkedListNode* node) {
        if (node->next) {
            node->next->prev = nullptr;
            head = node->next;
            node->next = nullptr;
        } else {
            head = nullptr;
            tail = nullptr;
        }
    }
    void removeTail(LinkedListNode* node) {
        if (node->prev) {
            node->prev->next = nullptr;
            tail = node->prev;
            node->prev = nullptr;
        } else {
            head = nullptr;
            tail = nullptr;
        }
    }
    void remove(LinkedListNode* node) {
        if (!node->prev) removeHead(node);
        else if (!node->next) removeTail(node);
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = nullptr;
            node->prev = nullptr;
        }
    }
};
