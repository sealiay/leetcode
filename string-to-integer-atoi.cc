class Solution {
public:
    int atoi(const char *str) {
        if ( !str ) return 0;
        int s = 0;
        long long w = 0;
        while ( isspace(*str) ) ++str;
        if ( *str == '-' ) {
            s = 1;
            ++str;
        } else if ( *str == '+' ) ++str;
        while ( *str == '0' ) ++str;
        int n = 0;
        while ( n++ < 11 && isdigit(*str) ) {
            w = w * 10 + *str++ - '0';
        }
        if ( w > INT_MAX ) return s ? INT_MIN : INT_MAX;
        return s ? -w : w;
    }
};
