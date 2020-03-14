/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    stack<NestedInteger> int_stack;
    queue<int> queue_res;
    NestedIterator(vector<NestedInteger> &nestedList) {
      // Initialize your data structure here.
      int size = nestedList.size();
      for (int iter = size - 1; iter >= 0; -- iter) {
        int_stack.push(nestedList[iter]);
      }
    }

    // @return {int} the next element in the iteration
    int next() {
      // Write your code here
      int front_val = queue_res.front();
      queue_res.pop();
      return front_val;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
      // Write your code here
      int res;
      while(!int_stack.empty()) {
        NestedInteger item = int_stack.top();
        int_stack.pop();
        if (item.isInteger()) {
          res = item.getInteger();
          queue_res.push(res);
          return true;
        } else {
          vector<NestedInteger> vec = item.getList();
          int size = vec.size();
          for (int iter = size - 1; iter >= 0 ; -- iter) {
            int_stack.push(vec[iter]);
          }
        }
      }
      return false;
    }      
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */   
