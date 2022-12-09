#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <unordered_map>
#include <typeinfo>
#include <unistd.h>

// Rock paper scissors score map
// Paper beats rock 2 beats 1
// Scissor beats paper 3 beats 2
// Rock beats scissors 1 beats 3
std::unordered_map<char, int> rps{
    {'A',1}, //Rock 
    {'B',2}, //Paper
    {'C',3}, //Scissor
    {'X',1}, //Rock
    {'Y',2}, //Paper
    {'Z',3}, //Scissor
};

// 
std::unordered_map<char, int> alpha{
    {'a',1},
    {'b',2},
    {'c',3},
    {'d',4},
    {'e',5},
    {'f',6},
    {'g',7},
    {'h',8},
    {'i',9},
    {'j',10},
    {'k',11},
    {'l',12},
    {'m',13},
    {'n',14},
    {'o',15},
    {'p',16},
    {'q',17},
    {'r',18},
    {'s',19},
    {'t',20},
    {'u',21},
    {'v',22},
    {'w',23},
    {'x',24},
    {'y',25},
    {'z',26},
};

int rucksack(std::string& l1, std::string& l2){
    int result = 0;
    for(auto x : l1){
        for(auto y : l2){
            if(x==y){
                if(isupper(x)){
                    
                    return result = alpha.find(tolower(x))->second + 26;
                }
                else
                    return result = alpha.find(x)->second;
            }
        }
    }
    return 0;
}

void advent3(){
    std::ifstream myfile; myfile.open("input3.txt");
    std::string line;
    int rucksacks = 0;

    if(myfile.is_open()){
        while(std::getline(myfile,line)){
            int endLine = line.length()-1;
            std::string line1 = line.substr(0,line.length()/2);
            std::string line2 = line.substr(endLine/2+1, endLine);
            std::sort(line1.begin(), line1.end());
            std::sort(line2.begin(),line2.end()); 
            rucksacks += rucksack(line1,line2); 
        }
        std::cout << rucksacks << std::endl;
    }
}

void advent2(){
    std::ifstream myfile; myfile.open("input2.txt");
    std::string line;
    int score = 0;
    if(myfile.is_open()){
        while(std::getline(myfile, line)){ 
            if((rps.find(line[0])->second == 1 && rps.find(line[2])->second == 2)||
                (rps.find(line[0])->second == 2 && rps.find(line[2])->second ==3)||
                (rps.find(line[0])->second == 3 && rps.find(line[2])->second ==1)){               
                    score += 6;
                }
            if(rps.find(line[0])->second == rps.find(line[2])->second){
                    score += 3; 
            }
            score += rps.find(line[2])->second;            

        }
    }
    std::cout << "Final Score: " << score << std::endl;
}

void advent1(){
    int result = 0;
    int buffer = 0;
    std::ifstream myfile; myfile.open("input.txt");
    std::string line;
    if(myfile.is_open()){
        while(std::getline(myfile,line)){
            std::cout << line << std::endl;
            if(line != ""){
                int x = std::stoi(line);

                buffer += x;
            }
            else
            {
                if(buffer > result)
                {
                    result = buffer;
                }
                buffer = 0;
            }
            
        }

    }
    
   std::cout << "Result: " << result << std::endl;
};

int main(int argc, char** argv)
{
    //advent1();
    //advent2();
    advent3();
}