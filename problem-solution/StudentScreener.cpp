#include<bits/stdc++.h>
using namespace std;

string getEligibleStudents(int totalStudents,vector<string> students,vector<int>& marks,vector<string>& examResults,int totalMarks,float requiredPercentile){
    string ans = "";

    //creating max heap to store the students based on their score
    //data will be store as (student marks,index in student array)
    //so data will be stored in decreasing order of marks
    priority_queue<pair<int,int>> rank;
    for(int i=0;i<marks.size();i++){
        rank.push(make_pair(marks[i],i));
    }
    //calculating percentile
    int currRank = 1; //the rank of the first student in priority queue will be 1
    while(!rank.empty()){
        pair<int,int> temp = rank.top();
        rank.pop();
        int marksTemp = temp.first; //marks of the students
        int idx = temp.second;//original index of the student in input array
        
        float currPercentile = (float(totalStudents - currRank)/float(totalStudents))*100;

        //screening process
        if(currPercentile >= requiredPercentile && examResults[idx] == "Passed"){
            if(ans.length() == 0) ans += students[idx];
            else ans += (","+students[idx]);
        }
        currRank++;
    }
    return ans;
}

int main(){
    int totalStudents = 7;
    int totalMarks = 1000;
    float requiredPercentile = 50;
    vector<int> marks = {800, 300, 750, 760, 680, 790, 640};
    vector<string> students = { "Kartik", "Devang", "Pari", "Ketan", "Sheetal", "Darshana", "Mohan" };
    vector<string> examResults = {"Passed", "Failed", "Passed", "Failed", "Passed", "Passed", "Passed"};

    string eligibleStudents = getEligibleStudents(totalStudents, students,marks, examResults, totalMarks, requiredPercentile);
    cout<<eligibleStudents<<endl;
    return 0;
}