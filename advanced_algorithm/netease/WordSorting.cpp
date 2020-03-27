bool cmp(const pair<string, string> & p1, const pair<string, string> & p2) {
  return p1.second < p2.second;
}
class Solution {
public:
    /**
     * @param alphabet: the new alphabet
     * @param words: the original string array
     * @return: the string array after sorting
     */
    vector<string> wordSort(string &alphabet, vector<string> &words) {
        // Write your code here
        vector<string> res;
        long long rank[26];
        int alpha_size = alphabet.length();
        for (long long iter = 0; iter < alpha_size; ++ iter) {
          char ch = alphabet[iter];   
          rank[ch - 'a' ] = iter; 
        }
        
        vector<pair<string, string > > vec;
        for (string word: words) {
          string weight;
          for (char ch: word) {
            weight.push_back(rank[ch - 'a'] + 'a');
          }
          vec.push_back(make_pair(word, weight));
        }
        
        sort(vec.begin(), vec.end(), cmp);
        for (pair<string, string> p: vec) {
          res.push_back(p.first);    
        }
        return res;
    }
};
