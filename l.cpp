#include <bits/stdc++.h>
using namespace std;

#define un long long

void solve();

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    un T; cin >> T; while(T--) solve();
}

un get_side(un x, un y, un a, un b){

    un val = x*b - y*a;

    if (val == 0) return 0;
    if (val < 0) return -1;
    if (val > 0) return 1;
}


void solve() {

    un x0, x1, x2, x3;
    un y0, y1, y2, y3;

    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    un x_line = x2 - x3;
    un y_line = y2 - y3;

    un x_l = x0 - x3;
    un y_l = y0 - y3;

    un x_r = x1 - x3;
    un y_r = y1 - y3;


    un s = 0;
    s += get_side(x_line, y_line, x_l, y_l);
    s += get_side(x_line, y_line, x_r, y_l);
    s += get_side(x_line, y_line, x_l, y_r);
    s += get_side(x_line, y_line, x_r, y_r);

    if (abs(s) == 4) {
        cout << "OK" << endl;
    }
    else{
        cout << "STOP" << endl;
    }

}