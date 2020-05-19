class Solution {
public:
    /**
     * @param s: string
     * @return: sort string in lexicographical order
     */
    string sorting(string &s) {
        // write your code here
        int size = s.size();
        int pre = 0;
        vector<string> vec;
        for (int str_i = 1; str_i <= size; ++ str_i) {
          if ((str_i == size || s[str_i] == ',') && s[str_i - 1] != ',') {
            vec.push_back(s.substr(pre, str_i - pre)); 
          } else if (str_i != size && s[str_i] != ',' && s[str_i - 1] == ',') {
            pre = str_i;
          }
        } 
        
        sort(vec.begin(), vec.end());
        
        string res;
        for (string str: vec) {
          res += str + ',';    
        }
        
        if (res.size()) {
          res.resize(res.size() - 1);
        }
        
        return res;
    }
};
