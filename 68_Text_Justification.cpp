class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int N = words.size();
        if(N == 0 || maxWidth == 0)
        {
            ret.push_back("");
            return ret;
        }
        int i = 0;
        while(i < N)
        {
            int L = words[i].size();
            int j = i + 1;
            for(; j < N && (L + 1 + words[j].size()) <= maxWidth; ++j)
            {
                L += 1 + words[j].size();
            }
            if(j < N)
            {
                string row = words[i];
                int c = j - i - 1;
                i++;
                if(c == 0)
                {
                    row.append(maxWidth-row.size(),' ');
                    ret.push_back(row);
                    continue;
                }
                int shortSpace =  (maxWidth- (L - c))/c;
                int longCount = (maxWidth- (L - c))%c;
                for(int k = 0; k < c; ++k)
                {
                    row.append(shortSpace,' ');
                    if(k < longCount) row.push_back(' ');
                    row += words[i++];
                }
                ret.push_back(row);
            }
            else
            {
                string row = words[i++];
                while(i < N)
                {
                    row.push_back(' ');
                    row += words[i++];
                }
                row.append(maxWidth-row.size(),' ');
                ret.push_back(row);
            }
        }
        return ret;
    }
};
