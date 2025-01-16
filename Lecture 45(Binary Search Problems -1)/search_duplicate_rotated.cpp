#include <iostream>
using namespace std;
#include <vector>

int search(vector<int> &v, int low, int high, int target){
    while (low <= high){

        int mid = low + (high - low) / 2;

        if (v[mid] == target) return mid;

        if (v[mid] == v[low] && v[mid] == v[high]){
            // It may happen in case of duplicates
            ++low;
            --high;
            continue;
        }
        if (v[low] <= v[mid]){
            if (target >= v[low] && target < v[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if (target <= v[high] && target > v[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin >> n;

    vector<int>v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }

    int target;
    cout<<"Enter a target: ";
    cin>>target;

    cout<<"Target element is present at index: "<<search(v,0,v.size()- 1,target)<<endl;

    return 0;
}