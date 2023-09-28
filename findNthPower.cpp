#include <bits/stdc++.h>
using namespace std;
class test
{
private:
    int comparePow(int mid,int root, int num){
        long long ans=1;
        while(root>0){
            ans= ans*mid;
            root--;
            if(ans>num) return 2;
        }
        if(ans== num) return 1;
        if(ans<num) return 0;
    }
public:
    int NthRoot(int root, int num)
    {
        int low = 1, high = num - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int ans= comparePow(mid, root, num);
            if (ans== 1)
                return mid;
            else if (ans== 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
int main()
{
    test tst;

    return 0;
}