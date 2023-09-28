// arr: no of pages of each book(ele) m: no of students books to be allocated
// for each student only contigious books to be allocated and all student must get 1 book
// distribute books such that max pages allocated to any student is minimum
// determining low and high
#include <bits/stdc++.h>
using namespace std;
class test
{
private:
int allStudentsAllocated(vector<int> arr, int mid){
    int studentsGot=1, pagesGot= 0;
    for(auto it: arr){
        if(pagesGot+ it<= mid) pagesGot+= it;
        else{
            pagesGot= it;
            studentsGot++;
        }
    }
    return studentsGot;
}
public:
    int findPages(vector<int> &arr, int n, int m)
    {
        int high=0, low=0;
        for(auto it: arr){
            if(it> low) low= it;
            high+=it;
        }
        if(m> n) return -1;
        while (low<= high)
        {
            int mid= (low+high)/2;
            int allocatedS= allStudentsAllocated(arr, mid);
            if(allocatedS<= m) high= mid-1;
            // else if(allocatedS< m) high= mid-1;
            else low= mid+1;
        }
        return low;
    }
};
int main()
{
    test tst;
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = tst.findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}