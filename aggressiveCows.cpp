// coordinates of the each stall given in arr place k cows in those stalls such that distance between each cow is max
#include <bits/stdc++.h>
using namespace std;
class test
{
private:
    int placingPossible(vector<int> a, int mid, int k)
    {
        int n = a.size(), last = 0;
        k--;
        for (int i = 1; i < n; i++)
        {
            if (k == 0)
                break;
            int dist = a[i] - a[last];
            if (dist >= mid)
            {
                last = i;
                k--;
            }
            else
                continue;
        }
        if (k > 0)
            return 0;
        return 1;
    }

public:
    int aggressiveCows(vector<int> &a, int k)
    {
        sort(a.begin(), a.end());
        int n = a.size();
        if (k == 2)
            return a[n - 1] - a[0];
        int low = 1, high = a[n - 1] - a[0];
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int placed = placingPossible(a, mid, k);
            if (placed)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return high;
    }
};
int main()
{
    test tst;
    vector<int> stalls = {87, 93, 51, 81, 68, 99, 59};
    int k = 4;
    int ans = tst.aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}