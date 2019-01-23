#ifndef __slist_h__
#define __slist_h__

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#endif
