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
    advent2();
}