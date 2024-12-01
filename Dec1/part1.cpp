#include <iostream> // For input/output
#include <vector> // For using std::vector
#include <fstream> // To read file
#include <algorithm> // For sorting

using namespace std;
int main(){

int sum = 0;
int num;
string line;
vector<int> numbers;
ifstream input1 ("input.txt");

// Read the numbers and store it in single column of numbers
while (input1 >> num){
    numbers.push_back(num);
}
input1.close();

// Create a matrix of the original numbers
vector<vector<int>> pairs(numbers.size()/2, vector<int>(2, 0));
for (int i=0; i<pairs.size(); i++){
    pairs[i][0] = numbers[2*i];
    pairs[i][1] = numbers[2*i+1];
}

// Separate columns and sort them
vector<int> column1, column2;
for (int i=0; i<pairs.size(); i++){
    column1.push_back(pairs[i][0]);
    column2.push_back(pairs[i][1]);
}

sort(column1.begin(), column1.end());
sort(column2.begin(), column2.end());

// Calculate the difference and sum them
vector<int> diff(column1.size());
for (int i=0; i<column1.size(); i++){
    diff[i] = abs(column1[i]-column2[i]);
    sum += diff[i];
}

cout << "The total distance between the list is:" << sum << "\n";
return 0;
}
