#include<iostream>
#include<fstream>
#include<vector>


int return_mult(int i, std::string line, bool* do_ptr){
    if(line.substr(i,4) == "do()"){
        *do_ptr = true;
    }
    if(line.substr(i,7) == "don't()"){
        std::cout << "weee" << std::endl;
        *do_ptr = false;
    }
    
    if(*do_ptr==false){
        return 0;
    }

    if(line.substr(i,4) == "mul("){
        std::cout << line.substr(i,12) << std::endl;
        int last_index = -1;
        for(int j = i+4; j < i+12; j++){
            if(line[j] == ')'){
                std::cout << "i fulfiil the ) condition" << std::endl;
                last_index = j;
                break;
            }
        }
        if(last_index==-1){
            return 0;
        }
        std::string pattern = line.substr(i+4,last_index-i-4);
        int pos = pattern.find(",");
        if(pos==-1){
            return 0;
        }
        
        int space = pattern.find(char(32));
        if(space!=-1){
            return 0;
        }

        int left_nr = std::stoi(pattern.substr(0,pos));
        int right_nr = std::stoi(pattern.substr(pos+1, size(pattern)-1 - pos));
        if(!left_nr or !right_nr){
            return 0;
        }

        
        std::cout << "got here" << std::endl;
        return left_nr*right_nr;


    }
    return 0;
}



int main(){
    std::string filename = "input.txt";
    std::ifstream inFile;
    inFile.open(filename);

    if(!inFile){
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    
    int total_sum = 0;
    std::string line;
    bool todo = true;
    bool * do_ptr = &todo;
    while(getline(inFile, line)){
        for(int i = 0; i < size(line); i++){
            int mul = return_mult(i, line, do_ptr);
            std::cout << todo << std::endl;
            total_sum+=mul;
        }
    }

    inFile.close();

    std::cout << total_sum << std::endl;


    return 0;
}
