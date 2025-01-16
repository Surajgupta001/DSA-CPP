#include <iostream>
using namespace std;
#include <vector>

int firstOccurrence(vector<int> &v, int low, int high, int target){
    int ans = -1;
    while (low <= high){
        int mid = low + (high - low) / 2;

        if (v[mid] == target){
            ans = mid;
            high = mid - 1;
        }
        else if (v[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> v(n);
    for (int i=0; i<n;i++){
        cin>>v[i];
    }

    int target;
    cout<<"Enter the value of target: ";
    cin>>target;

    cout<<"first index/occurrences of this 'target' is: "<<firstOccurrence(v, 0, v.size() - 1, target);

    return 0;
}