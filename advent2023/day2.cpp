#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <cctype>


struct cubes{
    int blue = 14;
    int green = 13;
    int red = 12;
};

void day2p1(std::string& line){
    std::cout << line << std::endl;
    std::string test = "";
    int id = 0;
    
    for(int i = 0; i < line.length(); i++){
        if(line[i] == ' '){
            test = "";
        }
        else if(line[i] == ';'){
            id++;
        }
        else
        {
            test += line[i];
            if(isdigit(*test.c_str()) && !isdigit(line[i+1].c_str())){
                std::cout << test << std::endl;
            }
        }
    }
    
};

void day2p2(std::string& line){
};



int main(){
    std::ifstream file;
    file.open("ids.txt");
    std::string line;
    if(file.is_open()){
        while(std::getline(file,line)){
            day2p1(line);
        }
    }

    return 0;
};
