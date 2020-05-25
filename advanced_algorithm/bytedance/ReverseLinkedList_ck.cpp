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
    ListNode* reverseList(ListNode* head) {
      ListNode * grandpa = nullptr, *parent = head;
      while(parent != nullptr) {
        ListNode * child = parent->next;  
        parent->next = grandpa;
        grandpa = parent;
        parent = child;
      }
      return grandpa;
    }
}
