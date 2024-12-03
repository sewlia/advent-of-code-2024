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

std::regex doPattern(R"(do\(\))");
std::regex dontPattern(R"(don\'t\(\))");

bool isDo = true;
bool isDont = false;

while (std::regex_search(content.cbegin() + start, content.cend(), match, pattern)){
    if (std::regex_search(content.cbegin() + start, content.cend(), doMatch, doPattern)){}
    if (std::regex_search(content.cbegin() + start, content.cend(), dontMatch, dontPattern)){}

    if (start==0 && match.position()<doMatch.position() && doMatch.position()<dontMatch.position()){
        start += match.position() + match.length();
    }
    else if (start==0 && match.position()<dontMatch.position() && dontMatch.position()<doMatch.position()){
        start += match.position() + match.length();
    }
    else if (match.position()<doMatch.position() && doMatch.position()<dontMatch.position()){
        start += match.position() + match.length();
    }
    else if (match.position()<dontMatch.position() && dontMatch.position()<doMatch.position()){
        start += match.position() + match.length();
    }
    else if (doMatch.position()<match.position() && match.position()<dontMatch.position()){
        isDont=false;
        start += match.position() + match.length();}
    else if (doMatch.position()<dontMatch.position() && dontMatch.position()<match.position()){
        isDont=true;
        start += match.position() + match.length();}
    else if (dontMatch.position()<match.position() && match.position()<doMatch.position()){
        isDont=true;
        start += match.position() + match.length();}
    else if (dontMatch.position()<doMatch.position() && doMatch.position()<match.position()){
        isDont=false;
        start += match.position() + match.length();}
    else{
        start += match.position() + match.length();
    }

    //std::cout << start;
    int num1 = std::stoi(match[1]);
    int num2 = std::stoi(match[2]);
    if (!isDont){
        Newsum += num1 * num2;
    }

}
std:: cout << "Total New sum is: " << Newsum << "\n";

return 0;

}