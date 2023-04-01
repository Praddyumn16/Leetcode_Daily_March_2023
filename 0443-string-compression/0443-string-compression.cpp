class Solution {
public:
    int compress(vector<char>& chars) {
        
        vector<pair<char , int>> v;
        int count = 1 , prev = chars[0];
        
        for(int i = 1 ; i < chars.size() ; i++) {
            if(chars[i] != prev) {
                v.push_back(make_pair(prev , count));
                prev = chars[i];
                count = 1;
            }
            else
                count++;
        }
        v.push_back(make_pair(prev , count));
        
        chars.clear();
        
        for(auto a : v){
            chars.push_back(a.first);
            if(a.second == 1) continue;
            int temp = a.second;
            string s;
            while(temp){
                s += to_string(temp % 10);
                temp /= 10;
            }
            for(int i = s.size() - 1 ; i >= 0 ; i--)
                chars.push_back(s[i]);
        }
        
        return chars.size();
    }
};