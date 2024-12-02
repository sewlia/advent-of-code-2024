#include <iostream> // For input/output
#include <vector> // For using std::vector
#include <fstream> // To read file
#include <algorithm> // For sorting

int main(){

int num;
int reports=0;
std::vector<std::vector<int>> data;
std::ifstream input ("input.txt");

std::string line;
while (getline(input, line)){
    std::vector<int> row;
    size_t pos = 0;

    while (pos < line.size()){
        size_t next_pos;
        num = stoi(line.substr(pos), &next_pos);
        row.push_back(num);
        pos += next_pos;
    }
    data.push_back(row);
}
input.close();

// Displaying the data
std::cout << "Data from the file:\n";
for (const auto& row : data) {
    for (int num : row) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Total reports
for (const auto& row : data) {
    for (int i = 0; i < row.size()-1; i++) {
        if (row[i]>row[i+1] && row[i]-row[i+1]<=3){
            if(i==row.size()-2){
                reports++;}
            continue;}
        else {break;}
    }
    for (int i = 0; i < row.size()-1; i++) {
        if (row[i]<row[i+1] && row[i+1]-row[i]<=3){                
            if(i==row.size()-2){
                reports++;}
            continue;}
        else {break;}
    }
    }
std::cout << "Total reports:" << reports << std::endl;
    
// Listing all the edge cases : not recommended
int strike = 0;
int safe_reports = 0;
bool isIncreasing = false;
int i = 0;
for (const auto& row : data) {    
    while (i < row.size() - 1 && strike <= 1) {
        if (row[i] > row[i+1] && row[i] - row[i + 1] <= 3 && i == row.size() - 2) {
            safe_reports++;
            isIncreasing = true;
            break;
        }
        else if (i==0 && row[0] > row[1] && row[1]<row[2] && row[0]-row[2]<=3 && row[0]-row[2]>0){
            i=i+2;
            strike++;
            continue;
        }
        else if (row[i] > row[i + 1] && row[i] - row[i + 1] <= 3) {
            i++;
            continue;
        }
        else if (i == row.size() - 2 && strike == 0) {
            safe_reports++;
            isIncreasing = true;
            break;
        }
        else if (i == row.size() - 2) {
            break;
        }
        else if (row[i] > row[i + 2] && row[i] - row[i + 2] <= 3 && i == row.size() - 3 && strike == 0) {
            safe_reports++;
            isIncreasing = true;
            break;
        }
        else if (row[i] > row[i + 2] && row[i] - row[i + 2] <= 3 && strike == 0) {
            i = i + 2;
            strike++;
            continue;
        }
        else if (i>1 && row[i]==row[i+2] && row[i-1]-row[i+1]<=3){
            strike++;
            i++;
            continue;
        }
        else if (i==0){
            strike++;
            i++;
            continue;
        }
        else {
            strike++;
            i++;
            break;
        }
    }
    i = 0;
    strike = 0;
    while (i < row.size() - 1 && strike <= 1 && !isIncreasing) {
        if (row[i] < row[i+1] && row[i + 1] - row[i] <= 3 && i == row.size() - 2) {
            safe_reports++;
            break;
        }
        else if (i==0 && row[0] < row[1] && row[1]>row[2] && row[2]-row[0]<=3 && row[2]-row[0]>0){
            i=i+2;
            strike++;
            continue;
        }
        else if (row[i] < row[i + 1] && row[i + 1] - row[i] <= 3) {
            i++;
            continue;
        }
        else if (i == row.size() - 2 && strike == 0) {
            safe_reports++;
            break;
        }
        else if (i == row.size() - 2) {
            break;
        }
        else if (row[i] < row[i + 2] && row[i + 2] - row[i] <= 3 && i == row.size() - 3 && strike == 0) {
            safe_reports++;
            break;
        }
        else if (row[i] < row[i + 2] && row[i + 2] - row[i] <= 3 && strike == 0) {
            i = i + 2;
            strike++;
            continue;
        }
        else if (i==0){
            strike++;
            i++;
            continue;
        }
        else {
            strike++;
            i++;
            break;
        }
    }
    i = 0;
    strike = 0;
    isIncreasing = false;
}
std::cout << "Total safe reports" << safe_reports << std::endl;

}
    
        