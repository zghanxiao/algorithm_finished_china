class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    vector<int> stack;
    int index = -1;
    
    Stack() {
      stack.resize(1000);
    }
    
    void push(int x) {
      // write your code here
      stack[++index] = x;
    }

    /*
     * @return: nothing
     */
    void pop() {
      // write your code here
      if (!isEmpty()) {
        index --;
      }
    }

    /*
     * @return: An integer
     */
    int top() {
      // write your code here
      if (isEmpty()) {
        return -1;
      } 
      return stack[index];
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
      // write your code here
      return index == -1;
    }
};
