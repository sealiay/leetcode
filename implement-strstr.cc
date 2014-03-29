class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if ( !haystack || !needle ) return nullptr;
        if ( !*needle ) return haystack;
        while ( *haystack ) {
            char *a = haystack, *b = needle;
            while ( *a && *b && *a == *b ) ++a, ++b;
            if ( !*b ) return haystack;
            if ( !*a ) return nullptr;
            ++haystack;
        }
        return nullptr;
    }
};
