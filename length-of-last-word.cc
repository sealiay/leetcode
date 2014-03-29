class Solution {
public:
    int lengthOfLastWord(const char *s) {
        const char *t = s + strlen(s);
        while ( t != s && *(t - 1) == ' ' ) --t;
        int l = 0;
        while ( t != s && *(t - 1) != ' ' ) { 
            ++l;
            --t;
        }
        return l;
    }
};
