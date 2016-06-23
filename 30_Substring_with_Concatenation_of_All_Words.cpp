class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(s.empty() || words.empty()) return ret;
        unordered_map<string, int> myMap;
        for(auto &a : words)
        {
            myMap[a]++;
        }
        int L = words[0].size();
        int M = s.size();
        int N = words.size();
        for(int i = 0; i < L; ++i)
        {
            unordered_map<string, int> tempMap;
            int left = i, iCount = 0;
            for(int j = i; j <= M - L; j += L)
            {
                string tempStr = s.substr(j, L);
                if(myMap.count(tempStr))
                {
                    tempMap[tempStr]++;
                    iCount++;
                    while(tempMap[tempStr] > myMap[tempStr])
                    {
                        tempMap[s.substr(left,L)]--;
                        iCount--;
                        left += L;
                    }
                    if(iCount == N)
                    {
                        ret.push_back(left);
                        tempMap[s.substr(left,L)]--;
                        iCount--;
                        left += L;
                    }
                }
                else
                {
                    tempMap.clear();
                    left = j+L;
                    iCount = 0;
                }
            }
        }
        return ret;
    }
};
