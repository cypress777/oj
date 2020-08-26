class Solution {
public:
    int gcd (int a, int b) {
        int m = max(abs(a), abs(b));
        int n = min(abs(a), abs(b));

        while (n != 0) {
            int tmp = m % n;
            m = n;
            n = tmp;
        }

        return m;
    }

    int maxPoints(vector<vector<int>>& points) {
        int res = 0;

        for (int i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> cnt;
            int same_point = 0;
            // cout << "----- " << i << endl;
            for (int j = i; j < points.size(); j++) {
                // cout << "--- " << j << endl;
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int sign = ((dx >= 0 && dy >= 0) || (dx <= 0 && dy <= 0)) ? 1 : -1;

                dx = sign * abs(dx);
                dy = abs(dy);

                if (dx != 0 && dy != 0) {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;
                } else if (dx != 0) {
                    dx = 1;
                } else if (dy != 0) {
                    dy = 1;
                } else {
                    same_point++;
                }

                pair<int, int> k(dx, dy);
                if (cnt.find(k) == cnt.end()) cnt[k] = 1;
                else cnt[k]++;

                // cout << k.first << " " << k.second << " " << cnt[k] << endl;
            }

            for (const auto &it : cnt) {
                if (it.first.first == 0 && it.first.second == 0) {
                    res = max(res, it.second);
                } else {
                    res = max(res, it.second + same_point);
                }
            }
        }

        return res;
    }
};
