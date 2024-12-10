#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> left;
    std::vector<int> right;

    std::string line;
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    while (getline(inFile, line)){
        std::string left_nr = line.substr(0, 5);
        std::string right_nr = line.substr(8, 13);
        left.push_back(stoi(left_nr));
        right.push_back(stoi(right_nr));
    }
    inFile.close();
    
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    std::vector<int> similarities(size(left), 0);

    for (int i = 0; i < std::size(left); i++){
        for (int j = 0; j < std::size(right); j++){
            if (left[i] == right[j]){
                similarities[i]+=1;
            }
        }
    }

    int total_sim = 0;

    for (int i = 0; i < size(left); i++){
        total_sim += left[i] * similarities[i];
    }

    std::cout << total_sim << std::endl;
    
}
