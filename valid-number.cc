class Solution {
public:
    bool isNumber(const char *s) {
        const char *b = s;
        while ( isspace(*b) ) ++b;
        const char *e = b + strlen(b);
        while ( e != b && isspace(*(e-1)) ) --e;
        
        const char *i = find(b, e, 'E');
        if ( i == e ) i = find(b, e, 'e');
        return is_sfloat(b, i) && (i == e || is_sint(i+1, e));
    }
    
    bool is_sint(const char *b, const char *e) {
        if ( b == e ) return false;
        if ( *b == '+' || *b == '-' ) return is_uint(b+1, e);
        return is_uint(b, e);
    }
    
    bool is_uint(const char *b, const char *e) {
        if ( b == e ) return false;
        return all_digit(b, e);
    }
    
     bool is_sfloat(const char *b, const char *e) {
        if ( b == e ) return false;
        if ( *b == '+' || *b == '-' ) return is_ufloat(b+1, e);
        return is_ufloat(b, e);
    }    
    
    bool is_ufloat(const char *b, const char *e) {
        if ( b == e ) return false;
        const char *i = find(b, e, '.');
        if ( i == e ) return is_sint(b, e);
        return e - b > 1 && all_digit(b, i) && all_digit(i+1, e);
    }
    
    bool all_digit(const char *b, const char *e) {
        while ( b != e && isdigit(*b) ) ++b;
        return b == e;
    }
    
};
