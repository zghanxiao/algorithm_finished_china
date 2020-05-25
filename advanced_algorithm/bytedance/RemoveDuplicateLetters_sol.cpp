class Solution {
public:
    string removeDuplicateLetters(string s) {
      stack<int> stack;
      unordered_set<char> seen;
      unordered_map<char, int> last_map;
      
      for (int i = 0; i < s.size(); ++ i) {
        char ch = s[i];
        last_map[ch] = i;
      }
      
      for (int i = 0; i < s.size(); ++ i) {
        char ch = s[i];
        if (seen.find(ch) == seen.end()) {
          while(!stack.empty()) {
            char top = stack.top(); 
            if (!(top > ch && last_map[top] > i)) {
              break;
            }
            stack.pop();  
            seen.erase(top);
          }
          stack.push(ch);
          seen.insert(ch);
        }
      } 
      
      string res;
      while(!stack.empty()) {
        res += stack.top();
        stack.pop();
      }
      reverse(res.begin(), res.end());
      return res; 
    }
};
