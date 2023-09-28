#include <bits/stdc++.h>
using namespace std;
class test
{
private:
    int PaintingTimePerson(vector<int> arr, int mid){
        int personsTaken=1, timeTaken=0;
        for(auto it: arr){
            if(timeTaken+it<=  mid) timeTaken+= it;
            else{
                personsTaken++;
                timeTaken= it;
            }
        }
        return personsTaken;
    }
public:
    int findLargestMinDistance(vector<int> &arr, int k)
    {
        int low=0, high=0, n= arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]>low) low= arr[i];
            high+= arr[i];
        }
        while (low<= high)
        {
            int mid= (low+high)/2;
            int persons= PaintingTimePerson(arr, mid);
            if(persons<=k) high= mid-1;
            else low= mid+1;
        }
        return low;
    }
};
int main()
{
    test tst;
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = tst.findLargestMinDistance(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}