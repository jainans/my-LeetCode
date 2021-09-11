#define ll long long int
class Solution {
public:
    int calculate(string s) {
    ll total = 0;
    vector<ll> signs(2, 1);
    for (ll i=0; i<s.size(); i++) {
        char c = s[i];
        if (c >= '0') {
            ll number = 0;
            while (i < s.size()  &&  s[i] >= '0')
                number = 10 * number + s[i++] - '0';
            total += signs.back() * number;
            signs.pop_back();
            i--;
        }
        else if (c == ')')
            signs.pop_back();
        else if (c != ' ')
            signs.push_back(signs.back() * (c == '-' ? -1 : 1));
    }
    return total;
}
};