class Solution {
public:
    /**
     * @param names: a string array
     * @return: a string array
     */
    vector<string> nameDeduplication(vector<string> &names) {
      // write your code here
      unordered_set<string> name_set;
      vector<string> res;
      for (string name: names) {
        string lower_name;
        
        for (int iter = 0; iter < name.length(); ++ iter) {
          char ch = tolower(name[iter]);
          lower_name.push_back(ch);
        }
        
        if (name_set.find(lower_name) == name_set.end()) {
          name_set.insert(lower_name);  
          res.push_back(lower_name);
        } 
      }
      return res;
    }
};
