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
    
    int total_dist = 0;
    for (int i = 0; i < std::size(left); i++){
        int dist = std::abs(left[i] - right[i]);
        total_dist += dist;
    }
    std::cout << total_dist << std::endl;
    
}
