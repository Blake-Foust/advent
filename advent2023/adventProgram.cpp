#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


void day1(std::string& line){
    static int cal_sum = 0;
    int cal_combine = 0;
    int y = 0, z = 0;

    for(char x : line){
        int y = x - '0';
        if(y > 0 && y <= 9){
            cal_combine = y * 10;
            std::cout << y << std::endl;
            break;
        }
    }

    std::cout << cal_combine << std::endl; 
    for(int i = line.length(); i >= 0; --i){
        int z = line[i] - '0';
        if(z > 0 && z <= 9){
            std::cout << z << std::endl;
            cal_combine += z;
            break;
        }
        else{
            cal_combine += y;
        }
    }
    std::cout << cal_combine << std::endl;
    cal_sum += cal_combine;
    std::cout << cal_sum << std::endl;

};


int main(){
    std::ifstream file;
    std::string line;

    file.open("../d1.txt");
    if(file.is_open()){
        std::cout << "open" << std::endl;
        while(std::getline(file, line,'\n')){
            std::cout << line << std::endl;
            day1(line);
        }
    }
    std::cout << "out" << std::endl;
    
    return 0;

}
