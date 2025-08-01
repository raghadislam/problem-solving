/* problem link: https://cses.fi/problemset/task/1732/
 * solution by: Raghad Islam
 * date: 1-8-2025 
 */

#include <bits/stdc++.h>
using namespace std;

void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
#include <bits/stdc++.h>
using namespace std;

void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;
#define int ll

int add(int a, int b, int mod) {
    return (0LL + a % mod + b % mod) % mod;
}

int subtract(int a, int b, int mod) {
    return (0LL + a % mod - b % mod + mod) % mod;
}

int product(int a, int b, int mod) {
    return 1LL * (a % mod) * (b % mod) % mod;
}

int power(int a, int b, int mod) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ( 1LL * (ret % mod) * (a % mod) ) % mod;
        a = ( 1LL * (a % mod) * (a % mod) ) % mod, b >>= 1;
    }
    return ret;
}

int inverse(int b, int mod) {
    return power(b, mod - 2, mod);
}

int primes[] = { 1099999997, 1099999961, 1099999907, 1099999819, 1099999781, 1099999723, 1099999721, 1099999711,
                 1099999657, 1099999613, 1099999601, 1099999573, 1099999561, 1099999543, 1099999531, 1099999507,
                 1099999477, 1099999429, 1099999427, 1099999393, 1099999349, 1099999301, 1099999289, 1099999279,
                 1099999267, 1099999231, 1099999189, 1099999151, 1099999141, 1099999111, 1099999079, 1099999067,
                 1099999057, 1099999049, 1099999037, 1099998997, 1099998961, 1099998959, 1099998929, 1099998883,
                 1099998877, 1099998871, 1099998859, 1099998847, 1099998827, 1099998733, 1099998727, 1099998709,
                 1099998707, 1099998701, 1099998659, 1099998649, 1099998629, 1099998587, 1099998577, 1099998541,
                 1099998533, 1099998511, 1099998509, 1099998467, 1099998443, 1099998409, 1099998377, 1099998371,
                 1099998353, 1099998343, 1099998337, 1099998313, 1099998287, 1099998281, 1099998269, 1099998257,
                 1099998227, 1099998169, 1099998157, 1099998149, 1099998131, 1099998083, 1099998041, 1099998037,
                 1099998001, 1099997957, 1099997953, 1099997929, 1099997909, 1099997879, 1099997867, 1099997863,
                 1099997861, 1099997849, 1099997813, 1099997741, 1099997737, 1099997719, 1099997693, 1099997687,
                 1099997671, 1099997627, 1099997623, 1099997617, 892846183, 892846133, 892846111, 892846091,
                 892846051, 892846021, 892845983, 892845979, 892845977, 892845949, 892845931, 892845917,
                 892845893,892845871, 892845869, 892845847, 892845817, 892845799, 892845769, 892845743,
                 892845727, 892845719,892845677, 892845641, 892845619, 892845617, 892845563, 892845529,
                 892845497, 892845469, 892845461,892845449, 892845427, 892845413, 892845391, 892845383,
                 892845361, 892845329, 892845319, 892845311,892845277, 892845259, 892845223, 892845221,
                 892845209, 892845139, 892845137, 892845071, 892845067,892845061 };

struct HASH {
    int start, mod;
    vector<int> base_power, base_inverse;

    HASH(int _start, int N, int MOD, int base = 70) {
        mod = MOD, start = _start;
        base_power.assign(N, 0);
        base_inverse.assign(N, 0);
        int inv = inverse(base, mod);
        base_power[0] = base_inverse[0] = 1;
        for (int i = 1; i < N; ++i) {
            base_power[i] = product(base_power[i - 1], base, mod);
            base_inverse[i] = product(base_inverse[i - 1], inv, mod);
        }
    }

    int concate(int a, int b, int len_a) {
        return add( a, product(b, base_power[len_a], mod), mod );
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define getrand(l, r) uniform_int_distribution<long long>(l, r)(rng)

HASH H('a', 1e6, primes[getrand(0, 149)]);

struct Hash {
    int size;
    vector<int> hash, hash_mirror;

    Hash(string& s, bool make_mirror) {
        size = s.size();
        hash.assign(size, 0);
        hash[0] = product(s[0] - H.start, H.base_power[0], H.mod);
        for (int i = 1; i < size; ++i)
            hash[i] = add(hash[i - 1], product( (s[i] - H.start), H.base_power[i], H.mod ), H.mod);

        if (not make_mirror) return;

        hash_mirror.resize(size);
        reverse(s.begin(), s.end());
        hash_mirror[0] = product(s[0] - H.start, H.base_power[0], H.mod);
        for (int i = 1; i < size; ++i)
            hash_mirror[i] = add(hash_mirror[i - 1], product( (s[i] - H.start), H.base_power[i], H.mod ), H.mod);
        reverse(s.begin(), s.end());
    }

    int getHash(int l, int r) {
        int ret = hash[r];
        if (l) {
            ret = subtract(ret, hash[l - 1], H.mod);
            ret = product(ret, H.base_inverse[l], H.mod);
        }
        return ret;
    }

    int getMirrorHash(int l, int r) {
        auto [mirrorL ,mirrorR] = mirrorRange(l, r);
        return mirrorHash(mirrorL, mirrorR);
    }

    pair<int, int> mirrorRange(int l, int r) {
        int mirrorL = size - r - 1;
        int mirrorR = size - l - 1;
        return { mirrorL, mirrorR };
    }

    int mirrorHash(int l, int r) {
        int ret = hash_mirror[r];
        if (l) {
            ret = subtract(ret, hash_mirror[l - 1], H.mod);
            ret = product(ret, H.base_inverse[l], H.mod);
        }
        return ret;
    }

    bool isPalindrom(int l, int r) {
        return getHash(l, r) == getMirrorHash(l, r);
    }
};

void solve() {
    string s; cin >> s;
    Hash h(s, false);
    int l = 0, r = s.size() - 1;
    while (r > 0) {
        int H1 = h.getHash(0, l);
        int H2 = h.getHash(r, s.size() - 1);
        if (H1 == H2) {
            cout << l+1 << ' ';
        }
        l++;
        r--;
    }
}

signed main(){
    fileIO();
    fastIO();
    int t = 1; //cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
