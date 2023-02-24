#include<bits/stdc++.h>
using namespace std;

float calculatePercentile(int totalStudent,vector<int>& marks,int yourScore){
    float x = 0;
    
    //finding students who scored less marks than my marks
    for(auto i:marks){
        if(i < yourScore) x++;
    }
    //percentile calculation
    float percentile = (x / totalStudent) * 100;
    return percentile;
}

int main(){
    int totalStudents = 7;
    vector<int> marks = {800, 300, 950, 760, 680, 490, 640};
    int yourScore = 760;

    float percentileScore = calculatePercentile(totalStudents,marks,yourScore);
    cout<<percentileScore<<endl; 
    return 0;
}

