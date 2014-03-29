class Solution {
public:
    static int g(char c) {
        switch (c) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
        }
    }

    int romanToInt(string s) {
        int v = 0;
        for (size_t i = 0; i < s.size() - 1; ++i) {
            int a = g(s[i]), b = g(s[i+1]);
            if ( a < b ) v -= a;
            else v += a;
        }
        v += g(s.back());
        return v;
    }
};
