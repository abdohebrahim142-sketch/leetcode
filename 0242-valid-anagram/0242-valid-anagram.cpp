class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() !=t.size()) return false;
        unordered_map<char, int> mp1,mp2;
        for(int c : s)
        {
            mp1[c]++;
        }
        for(int i : t)
        {
            mp2[i]++;
        }
        return mp1==mp2;
    }
};