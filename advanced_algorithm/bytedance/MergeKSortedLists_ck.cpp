/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  // new_node's next is nullptr
  void append(ListNode * dummy, ListNode *& head,  ListNode *& tail, ListNode * new_node) {
    if (head == nullptr && tail == nullptr) {
      dummy->next = head = tail = new_node;  
      return; 
    }
    
    tail->next = new_node; 
    tail = new_node;
    return; 
  }
  
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int, ListNode*>, 
                   vector<pair<int, ListNode*> >,
                   greater<pair<int, ListNode*> > > min_q; 
    
    ListNode * head = nullptr, * tail = nullptr, * dummy = new ListNode(0, head);
    for (ListNode * iter: lists) {
      if (iter != nullptr) {
        min_q.push(make_pair(iter->val, iter));  
      }
    }
    
    while(!min_q.empty()) {
      pair<int, ListNode *> top = min_q.top(); 
      int val = top.first;
      ListNode* iter = top.second;
      min_q.pop();
      
      ListNode* next = iter->next;
      iter->next = nullptr;
      append(dummy, head, tail, iter);
      
      if (next != nullptr) {
        min_q.push(make_pair(next->val, next));
      }
    }
    return dummy->next;
  }
};
