#include <bits/stdc++.h>
using namespace std;

#define int long long

long double get_dist(long double x1, long double y1, long double x2, long double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void solve() {
    long double ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;

    int n;
    cin >> n;

    vector<pair<long double, long double>> bottles(n);
    long double total_sum = 0;

    vector<pair<long double, int>> diffA, diffB;

    for (int i = 0; i < n; i++) {
        cin >> bottles[i].first >> bottles[i].second;

        long double d_bin = get_dist(tx, ty, bottles[i].first, bottles[i].second);
        long double d_adil = get_dist(ax, ay, bottles[i].first, bottles[i].second);
        long double d_bera = get_dist(bx, by, bottles[i].first, bottles[i].second);

        total_sum += 2 * d_bin;

        diffA.push_back({d_adil - d_bin, i});
        diffB.push_back({d_bera - d_bin, i});
    }

    sort(diffA.begin(), diffA.end());
    sort(diffB.begin(), diffB.end());

    long double min_change = 1e18;

    min_change = min(min_change, diffA[0].first);
    min_change = min(min_change, diffB[0].first);

    if (diffA[0].second != diffB[0].second) {
        min_change = min(min_change, diffA[0].first + diffB[0].first);
    } else {
        if (n > 1) {
            long double optionA = diffA[0].first + diffB[1].first;
            long double optionB = diffA[1].first + diffB[0].first;
            min_change = min(min_change, min(optionA, optionB));
        }
    }

    cout << fixed << setprecision(12) << total_sum + min_change << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
