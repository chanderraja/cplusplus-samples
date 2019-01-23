#include <slist.h>

SListNode* reverseList(SListNode* head) {
    if (!head) {
        return nullptr;
    }

    if (!head->next) {
        return head;
    }

    SListNode* prevNode = head;
    SListNode* nextNode = head->next;
    head->next = nullptr;
    while (nextNode) {
        SListNode* temp = nextNode->next;
        nextNode->next = prevNode;
        prevNode = nextNode;
        nextNode = temp;
    }
    return prevNode;
}
