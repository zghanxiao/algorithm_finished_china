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
    ListNode* reverseKGroup1(ListNode* head, int k) {
      if (k == 1) {
        return head;
      }
      int l_len= 0;
      ListNode * curr = head; 
      for (;curr != nullptr; curr = curr->next) {
        l_len ++;
      } 
        
      curr = head;
      ListNode * pre = nullptr; 
      ListNode * pre_tail = nullptr, * curr_tail = nullptr;
      ListNode * new_head = nullptr;
      int cnt = 0;
      while(curr != nullptr) {
        ListNode * post = curr->next;   
        cnt ++;
        if (cnt % k == 1) {
          pre_tail = curr_tail;
          curr_tail = curr; 
          if (l_len - cnt + 1 < k) {
            pre_tail->next = curr;  
            break;
          }
          curr->next = nullptr;
        } else {
          curr->next = pre;
        }
        
        if (cnt % k == 0) {
          if (pre_tail != nullptr) {
            pre_tail->next = curr;
          } else {
            new_head = curr;
          } 
        }
        
        pre = curr;
        curr = post;
      }
      return new_head;
    }
  
    void reverse(ListNode * & head, ListNode * &tail) {
      ListNode * pre = nullptr, * curr = head;
      while(curr != nullptr) {
        ListNode * post = curr->next;  
        curr->next = pre;
        pre = curr;
        curr = post;
      }
      tail = head; 
      head = pre;
      return;
    }
  
    void append(ListNode * & head, ListNode * & tail, ListNode * n_head, ListNode * n_tail) {
      if (head == nullptr && tail == nullptr) {
        head = n_head;
        tail = n_tail;
        return;
      }
      
      if (!(n_head == nullptr && n_tail == nullptr)) {
        tail->next = n_head;  
        tail = n_tail;
        return;
      } else {
        return;
      }
    }
  
    ListNode* reverseKGroup(ListNode* head, int k) {
      if (k == 1) {
        return head;
      }
      
      ListNode * iter = head;
      ListNode * pre = nullptr;
      ListNode * tail = nullptr;
      ListNode * new_head = nullptr, * new_tail = nullptr;
      
      int cnt = 0;
      while(true) {
        cnt ++;
        if (cnt % k == 1) {
          if (cnt > k) {
            pre->next = nullptr;
            reverse(tail, pre);  
            append(new_head, new_tail, tail, pre); 
          }
          tail = iter;
        }
        if (iter == nullptr) {
          break;
        }
        pre = iter;
        iter = iter->next;  
      }
      if (cnt % k != 1) {
        append(new_head, new_tail, tail, pre);  
      }
      return new_head;
    }
};
