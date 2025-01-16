/*
A new racing track for kids is being built in New York with 'n' starting spots. The spots are located along a straight line at positions x1, x2... xn(xi <=10^9). For each 'i', xi+1 > xí. At a time only 'm' children are allowed to enter the race. Since the race track is for kids, they may run into each other while running. To prevent this, we want to choose the starting spots such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

---> The first line of input will contain the value of n, the number of starting spots. 
---> The second line of input will contain the n numbers denoting the location of each spot. 
---> The third line will contain the value of m, number of children.
*/ 

#include <iostream>
using namespace std;
#include <vector>

bool CanPlaceStudent (vector<int> &position, int mid, int student){
    int studentsReqd = 1;
    int lastPlaces = position[0];
    for(int i=1;i<position.size();i++){
        if(position[i] - lastPlaces >= mid){
            studentsReqd++;
            lastPlaces = position[i];
            if(studentsReqd == student){
                return true;
            }
        }
    }
    return false;
}

int race (vector<int> &position, int student){

    /*
    * Time: O(nlogn(xn-x1))
    * Space: O(1)
    */ 

    int n = position.size();
    int low = 1;
    int high = position[n-1] - position[0];

    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(CanPlaceStudent(position,mid,student)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the No. of positions: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    int student;
    cout<<"No. of Students: ";
    cin>>student;
    
    int result = race(v,student);

    cout<<result<<endl;

    return 0;
}