class Solution {
public:
    string countAndSay(int n) {
        string a = "1";
        string p;
        while ( --n > 0 ) {
            auto b = a.begin();
            while ( b != a.end() ) {
                char c = *b++;
                int l = 1;
                for (; b != a.end() && *b == c; ++b) ++l;
                p += (char)(l + '0');
                p += c;
            }
            swap(a, p);
            p.clear();
        }
        return move(a);
    }
};
