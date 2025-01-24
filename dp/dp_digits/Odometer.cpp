/* problem link: https://usaco.org/index.php?page=viewproblem2&cpid=435&lang=en
 * solution by: Raghad Islam
 * date: 21-1-2025 
 */

#include <bits/stdc++.h>
using namespace std;

void fileIO(void)
{

#ifndef ONLINE_JUDGE

    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);

#endif

}

void fastIO(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

}

typedef long long ll;
#define int ll
#define tests int t; cin >> t; int o = -1; while(++o < t)
ll dp[19][50][2][2];
string num;

ll solve_dp(int idx, int cnt, bool can, bool leading_z, int targ, int dup) {
	if (idx == num.size()) {
		if (!leading_z) { return 0; }
		if (dup != -1) {
			if (cnt == 20) return 1;
			return 0;
		}

		if (cnt >= 20) return 1;
		return 0;
	}
	int&ret = dp[idx][cnt][can][leading_z];
	if (ret != -1) return ret;

	ll ans = 0;
	for (int i = 0; i <= 9; i++) {
		int digit_diff = num[idx] - '0';
		if (!can && i > digit_diff) { break; }
		bool is_under = can;
		if (i < digit_diff) { is_under = true; }

		bool is_started = leading_z || i != 0;

		if (is_started && dup != -1 && i != targ && i != dup) { continue; }

		int new_k = cnt;
		if (is_started) {
			if (targ == i) {
				new_k = cnt + 1;
			} else {
				new_k = cnt - 1;
			}
		}
		ans += solve_dp(idx + 1, new_k, is_under, is_started, targ, dup);
	}
	return ret = ans;
}


void solve() {
	int x, y; cin >> x >> y;
	num = to_string(y);
	int ans1 = 0;
	for (int i = 0; i <= 9; i++) {
		memset(dp,-1,sizeof(dp));
		ans1 += solve_dp(0, 20, false, false, i, -1);
	}
	int dup = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			memset(dp,-1,sizeof(dp));
			dup += solve_dp(0, 20, false, false, i, j);
		}
	}
	ans1 -= (dup/2);



	num = to_string(x-1);
	int ans2 = 0;
	for (int i = 0; i <= 9; i++) {
		memset(dp,-1,sizeof(dp));
		ans2 += solve_dp(0, 20, false, false, i, -1);
	}
	dup = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			memset(dp,-1,sizeof(dp));
			dup += solve_dp(0, 20, false, false, i, j);
		}
	}
	ans2 -= (dup/2);
	cout << ans1-ans2 << endl;
}

signed main(){
    fileIO();
    fastIO();
   // tests
    solve();
    return 0;
}
