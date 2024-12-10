#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

bool check_safe(std::vector<int> level){
    if(level[0] < level[1]){    
        for(int i=0; i < size(level)-1; i++){
            if(level[i + 1] - level[i] < 1 or level[i+1] - level[i] > 3){
                return false;
            }
        }
        return true;
    }
    if(level[0] > level[1]){
        for(int i=0; i < size(level)-1; i++){
            if(level[i] - level[i + 1] < 1 or level[i] - level[i+1] > 3){
                return false;
            }
        }
        return true;  
    }
    else{
        return false;
        }
}

int main(){
    std::fstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        std::cerr << "Unable to open file";
        exit(1);
    }

    std::vector<int> row;
    std::string line, word;
    int total_safety = 0;
    while (getline(inFile, line)){
        row.clear();

        std::istringstream s(line);
        char del = char(32);
        while (getline(s, word, del)){
            row.push_back(stoi(word));
        };
        if(check_safe(row)){
            total_safety+=1;
        }
        else{
            for(int i = 0; i < size(row); i++){
                if(i == size(row)-1){
                    continue;
                }
                std::vector<int> row_cropped = {};
                row_cropped.insert(row_cropped.end(), row.begin(), row.begin() + i);
                row_cropped.insert(row_cropped.end(), row.begin() + i + 1, row.end());
                if(check_safe(row_cropped)){
                    total_safety+=1;
                }
            }
        }
    }
    inFile.close();

    std::cout << total_safety << std::endl;

}
