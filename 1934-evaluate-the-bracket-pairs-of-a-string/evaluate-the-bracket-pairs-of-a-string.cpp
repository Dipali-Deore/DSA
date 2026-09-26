class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;
        
        // Store knowledge in hash map
        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }
        
        string ans;
        int i = 0;
        
        while (i < s.length()) {
            
            // Normal character
            if (s[i] != '(') {
                ans += s[i];
                i++;
            }
            
            // Bracket pair
            else {
                int j = i + 1;
                
                // Find closing bracket
                while (s[j] != ')') {
                    j++;
                }
                
                // Extract key
                string key = s.substr(i + 1, j - i - 1);
                
                // Check if key exists
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } 
                else {
                    ans += "?";
                }
                
                // Move after ')'
                i = j + 1;
            }
        }
        
        return ans;
    }
};