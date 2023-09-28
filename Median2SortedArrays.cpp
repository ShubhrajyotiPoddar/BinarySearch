#include <bits/stdc++.h>
using namespace std;
class test
{
private:
public:
    int medianBrute(vector<int> arr1, vector<int> arr2)
    {
        int i = 0, j = 0;
        vector<int> median;
        while (i < arr1.size() && j < arr2.size())
        {
            if (arr1[i] < arr2[j])
            {
                median.push_back(arr1[i]);
                i++;
            }
            else
            {
                median.push_back(arr2[j]);
                j++;
            }
        }
        if (i < arr1.size())
        {
            while (i < arr1.size())
            {
                median.push_back(arr1[i]);
                i++;
            }
        }
        if (j < arr2.size())
        {
            while (j < arr2.size())
            {
                median.push_back(arr2[j]);
                j++;
            }
        }
        if ((median.size()) % 2 == 0)
        {
            int center = median.size() / 2;
            return (median[center] + median[center - 1]) / 2;
        }
        else
        {
            int center = median.size() / 2;
            return median[center];
        }
    }
    double medianBetter(vector<int> arr1, vector<int> arr2)
    {
        int totLen = arr1.size() + arr2.size();
        int reqInd = totLen / 2 - 1, reqInd2 = reqInd + 1, k = -1, i = 0, j = 0, val1 = 0, val2 = 0;
        while (i < arr1.size() && j < arr2.size())
        {
            if (arr1[i] < arr2[j])
            {
                k++;
                i++;
                if (k == reqInd)
                    val1 = arr1[i - 1];
                if (k == reqInd2)
                {
                    val2 = arr1[i - 1];
                    break;
                }
            }
            else
            {
                k++;
                j++;
                if (k == reqInd)
                    val1 = arr2[j - 1];
                if (k == reqInd2)
                {
                    val2 = arr2[j - 1];
                    break;
                }
            }
        }
        if (i < arr1.size() && k < reqInd2)
        {
            while (i < arr1.size())
            {
                k++;
                i++;
                if (k == reqInd)
                    val1 = arr1[i - 1];
                if (k == reqInd2)
                {
                    val2 = arr1[i - 1];
                    break;
                }
            }
        }
        if (j < arr2.size() && k < reqInd2)
        {
            while (j < arr2.size())
            {
                k++;
                j++;
                if (k == reqInd)
                    val1 = arr2[j - 1];
                if (k == reqInd2)
                {
                    val2 = arr2[j - 1];
                    break;
                }
            }
        }
        if (totLen % 2 == 0)
            return ((double)val1 + (double)val2) / 2;
        else
            return double(val2);
    }
    double median(vector<int> a, vector<int> b){
        int n1=a.size(), n2= b.size();
        if(n1>n2) return median(b, a);
        int n= n1+n2;
        int reqELE= (n1+n2+1)/2; //for odd total no of digits
        int low= 0, high= n1;
        while (low<=high)
        {
            int mid= (low+high)/2;
            int mid2= reqELE-mid;
            int l1= INT_MIN, l2= INT_MIN, r1= INT_MAX, r2=INT_MAX;
            if(mid<n1) r1= a[mid];
            if(mid2<n2) r2= b[mid2];
            if(mid-1>=0) l1= a[mid-1];
            if(mid2-1>=0) l2= b[mid2-1];
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0) return ((double)(max(l1, l2)+min(r1, r2)))/2.0;
                else return double(max(l1,l2));
            }else if(l1>r2) high= mid-1;
            else low=mid+1;
        }
        return 0;
    }    
};
int main()
{
    test tst;
    vector<int> a = {1, 3, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    vector<int> a1 = {1, 2, 3, 4};
    vector<int> b1 = {5, 6, 7, 8, 9, 10};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << tst.median(a1, b1) << '\n';
    return 0;
}