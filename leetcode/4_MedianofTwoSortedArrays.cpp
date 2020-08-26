class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a, b;
        if (!nums1.empty() && (nums2.empty() || nums1[0] > nums2[0])) {
            a = nums2;
            b = nums1;
        } else {
            a = nums1;
            b = nums2;
        }

        if (a.empty()) {
            if (b.size() % 2) {
                return b[(b.size() + 1) / 2 - 1];
            } else {
                return double(b[b.size() / 2 - 1] + b[b.size() / 2]) / 2;
            }
        }

        int sa = a.size(), sb = b.size();

        double res = 0;

        int la = 0;
        int ra = sa - 1;

        int ma = (la + ra) / 2;
        int c = (sa + sb) % 2;
        int mb = (sa + sb - c - 4 - 2 * ma) / 2;
        // cout << "start ma mb: " << ma << " " << mb << endl;

        while (la < ra) {
            // cout << "ma mb: " << ma << " " << mb << endl;
            if (mb > sb - 1 || ma + 1 <= sa - 1 && mb >= 0 && a[ma + 1] < b[mb]) {
                la = ma + 1;
            } else if (mb < -1 || mb + 1 < sb && b[mb + 1] < a[ma]) {
                ra = ma - 1;
            } else {
                break;
            }

            ma = (la + ra) / 2;
            mb = (sa + sb - c - 4 - 2 * ma) / 2;
        }

        mb = (sa + sb - c - 4 - 2 * ma) / 2;
        // cout << "fin ma mb: " << ma << " " << mb << endl;

        if ((ma + mb + 2) * 2 == sa + sb) {
            double mid1 = (mb == -1 ? a[ma] : double(max(a[ma], b[mb])));
            double mid2;
            if (mb == sb - 1) {
                mid2 = a[ma + 1];
            } else if (ma == sa - 1) {
                mid2 = b[mb + 1];
            } else {
                mid2 = min(a[ma + 1], b[mb + 1]);
            }
            res = (mid1 + mid2) / 2;
        } else {
            if (mb == sb - 1) {
                res = a[ma + 1];
            } else if (ma == sa - 1) {
                res = b[mb + 1];
            } else {
                res = min(a[ma + 1], b[mb + 1]);
            }
        }


        return res;
    }
};