#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>


static int cal_sum = 0;

std::unordered_map<int, std::string> js{
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
};

void day1p2(std::string& line){
    int cal_combine = 0;
    std::string pn;
    std::size_t found;
    int lpos = 100;
    int rpos = 0; 
    int i = 1;
    int j = 1;
    int lval = 0;
    int rval = 0;
    bool lbool = false;
    for(; i < 10; i++){
       found = line.find(js[i]);
       if(found != std::string::npos && found < lpos){
          lpos = found;
          lval = i;
          lbool = true;
       }
    }

    std::cout << "lval: " << lval << std::endl;
    bool rbool = false; 
    for(; j <  10; j++){
       found = line.rfind(js[j]);
       if(found != std::string::npos && found > rpos){
           rpos = found;
           rval = j;
           rbool = true;
       }
    }

    std::cout << "rval: " << rval << std::endl;

    int digit = 0;
    int digpos = 0;
    bool fdbool = false;
    for(char x : line){
        int y = x - '0';
        if(y > 0 && y <= 9){
            digit = y;
            fdbool = true;
            break;
        }
        digpos++;
    }
    
    std::cout << "Digit: " << digit << std::endl;
    int y = 0;
    int drpos = 100;
    bool ldbool = false;
    for(int i = line.length(); i >= 0; --i){
        int z = line[i] - '0';
        if((z > 0 && z <= 9)){
            y = z;
            drpos = i;
            ldbool = true;
            break;
        }
        else{
            y = digit;
        }
    }

    if(lpos > digpos){
       cal_combine = digit*10;   
    }else{
        cal_combine = lval*10;
    }

    if(!ldbool && !rbool){
        cal_combine += digit;
    }else if(ldbool && !rbool){
        cal_combine += y;
    }
    else if(lbool && !fdbool && !ldbool){
        cal_combine += lval;
    }
    else if(rpos < drpos){
        cal_combine += y;
    }else{
        cal_combine += rval; 
    }
//    std::cout << cal_combine << std::endl;
    cal_sum += cal_combine;
   

};

void day1p1(std::string& line){
    static int cal_sum = 0;
    int cal_combine = 0;
    int y = 0, z = 0;

    for(char x : line){
        int y = x - '0';
        if(y > 0 && y <= 9){
            cal_combine = y * 10;
            break;
        }
    }

    for(int i = line.length(); i >= 0; --i){
        int z = line[i] - '0';
        if(z > 0 && z <= 9){
            cal_combine += z;
            break;
        }
        else{
            cal_combine += y;
        }
    }
    cal_sum += cal_combine;
};


int main(){
    std::ifstream file;
    std::string line;

    file.open("d1.txt");
    if(file.is_open()){
        std::cout << "open" << std::endl;
        while(std::getline(file, line,'\n')){
            std::cout << line << std::endl;
            day1p2(line);
        }
    }
    std::cout << "out" << std::endl;
    std::cout << cal_sum << std::endl;

    
    return 0;
};
