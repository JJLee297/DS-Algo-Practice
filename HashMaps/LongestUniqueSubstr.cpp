/*
Using window-sliding, the program returns the length of the longest substring of unique characters from an input string. 
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int size = s.size();
        int start = 0;
        unordered_map<char, int> LastIndex;
        for (int end = 0; end < size; end++) {
            auto it = LastIndex.find(s[end]);
            if (it == LastIndex.end()) {
                LastIndex[s[end]] = end;
                res = max(end - start + 1, res);
            }
            else if (it->second >= start) {
                start = it->second + 1;
                it->second = end;
            }
            else {
                it->second = end;
                res = max(end - start + 1, res);
            }
            cout << "Window: " << s.substr(start, end - start + 1) << endl;
        }
        return res;
    }
};


int main() {
    Solution A;
    cout << A.lengthOfLongestSubstring("CAPABLE") << endl;
}
