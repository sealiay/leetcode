class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> ss;
        for (string & s : tokens) {
            if ( s.size() > 1 || isdigit(s.front()) ) ss.push_back(atoi(s.data()));
            else {
                int v = ss.back();
                ss.pop_back();
                switch ( s.front() ) {
                    case '+': ss.back() += v; break;
                    case '-': ss.back() -= v; break;
                    case '*': ss.back() *= v; break;
                    case '/': ss.back() /= v; break;
                }
            }
        }
        return ss.front();
    }
};
