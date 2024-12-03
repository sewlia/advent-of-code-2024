#include <iostream> // For input/output
#include <vector> // For using std::vector
#include <fstream> // To read file
#include <algorithm> // For sorting
#include <regex>
#include <string>

int main(){

std::ifstream input ("input.txt");
std::string line, content;

while (getline(input, line)){
    content += line;
}
input.close();

std::regex pattern(R"(mul\((\d+),(\d+)\))");
std::smatch match, doMatch, dontMatch;

std::size_t start, doStart, dontStart= 0;
int sum = 0;
int Newsum = 0;

while (std::regex_search(content.cbegin() + start, content.cend(), match, pattern)){
    int num1 = std::stoi(match[1]);
    int num2 = std::stoi(match[2]);
    sum += num1 * num2;
    start += match.position() + match.length();
}
std:: cout << "Total sum is: " << sum << "\n";

return 0;

}