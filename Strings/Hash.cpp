#define ii pair<long long, long long>
const long long base = 1777771;
const long long mod1 = 999727999;
const long long mod2 = 1070777777;

struct Hash {
    vector<ii> hs, pot;
    Hash(string s) {
        hs.resize(SZ(s) + 1); pot.resize(SZ(s) + 1);
        pot[0] = ii(1, 1);
        for (int i = 1; i <= SZ(s); i++) {
            hs[i].first = (hs[i - 1].first * base + s[i - 1]) % mod1;
            hs[i].second = (hs[i - 1].second * base + s[i - 1]) % mod2;
            pot[i].first = (pot[i - 1].first * base) % mod1;
            pot[i].second = (pot[i - 1].second * base) % mod2;
        }
    }

    ii get(int l, int r) {l++;r++;
        long long x1 = hs[r].first - hs[l - 1].first * pot[r - l + 1].first % mod1;
        long long y1 = hs[r].second - hs[l - 1].second * pot[r - l + 1].second % mod2;
        x1 = (x1 + mod1) % mod1;
        y1 = (y1 + mod2) % mod2;
        return ii(x1, y1);
    }
};
