/*
You have 'n'(n <= 10^5) boxes of chocolate. Each box contains a[i] (a[i] <= 10000) chocolates. You need to distribute these boxes among 'm' students such that the maximum number of chocolates allocated to a student is minimum.

a. One box will be allocated to exactly one student.
b. All the boxes should be allocated.
c. Each student has to be allocated at least one box.
d. Allotment should be in contiguous order, for instance, a student cannot be allocated box 1 and box 3, skipping box 2.

==> Calculate and return that minimum possible number.
==> Assume that it is always possible to distribute the chocolates.

---> The first line of input will contain the value of n, the number of boxes.
---> The second line of input will contain the n numbers denoting the number of chocolates in each box.
---> The third line will contain the m, number of students.

INPUT:
4
12 34 67 90
2

OUTPUT:
113

*/ 

#include <iostream>
using namespace std;
#include <vector>

bool CanDistChoco(vector<int> &v, int mid, int student){
    // int n = v.size();
    int studentRequired = 1;
    int currentSum = 0;
    for(int i=0;i<v.size();i++){
        if(v[i] > mid){
            return false;
        }
        if(currentSum + v[i] > mid){
            studentRequired++;
            currentSum = v[i];
            if(studentRequired > student) return false;
        } else{
            currentSum += v[i];
        }
    }
    return true;
} 
int DistChoco(vector<int> &v, int low, int high,int student){
    // int n = v.size();
    // int low = v[0];
    // int high = 0;
    for(int i=0;i<v.size();i++){
        high += v[i];
    }
    int ans = -1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(CanDistChoco(v,mid,student)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
}
int main(){

    int n;
    cout<<"Enter the No. of boxex: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    int student;
    cout<<"No. of Students: ";
    cin>>student;

    cout<<"Distribution of chocolate in students are: "<<DistChoco(v,v[0],0,student)<<endl;

    return 0;
}