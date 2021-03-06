#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string rev(string st) {
    int len = st.length();
    for (int i = 0; i < len / 2; i++) {
        swap(st[i], st[len - i - 1]);
    }
    return st;
}

void comp(string x, string y) {
    if (x.length() < y.length()) swap(x, y);
    x = rev(x); y = rev(y);
    for (int i = 0; i < y.length(); i++) x[i] = x[i] + y[i] - '0';
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < x.length(); i++) {
            while (x[i] >= '2') {
                flag = true;
                x[i] -= 2;
                if (i + 1 < x.length()) x[i + 1]++;
                else x.push_back('1');
                if (i - 2 >= 0) x[i - 2]++;
                else if (i - 2 == -1) x[i - 1]++;
            }
        }
        for (int i = 0; i < x.length(); i++) {
            if (x[i] == '1' && i + 1 < x.length()) {
                if (x[i + 1] == '1') {
                    x[i]--;
                    x[i + 1]--;
                    flag = true;
                    if (i + 2 < x.length()) x[i + 2]++;
                    else x.push_back('1');
                }
            }
        }
    }
    x = rev(x);
    cout << x << endl;
}

int main() {
    int t = 0;
    string a, b;
    while (cin >> a >> b) {
        if (t > 0) cout << endl;
        comp(a, b);
        t++;
    }
    return 0;
}