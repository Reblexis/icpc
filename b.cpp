#include <bits/stdc++.h>
using namespace std;

#define un long long

constexpr un K = 1001;

void solve();


int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    un T; cin >> T;
    while(T--) solve();
}

bool isPrime(un x){

    if (x <= 1) return false;

    for (un i = 2; i < min(K, x-1); i++){
        if (x % i == 0) return false;
    }

    return true;

}

void solve(){
    un a, b;

    cin >> a >> b;

    if (abs(a-b) != 2) {
        cout << "N" << endl;
        return;
    }

    if (not isPrime(a)){
        cout << "N" << endl;
        return;
    }

    if (not isPrime(b)){
        cout << "N" << endl;
        return;
    }

    cout << "Y" << endl;

}