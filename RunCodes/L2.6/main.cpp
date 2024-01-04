#include <iostream>
#include <string>
#include <vector>

bool compare(std::string word1, std::string word2){
    for(std::size_t i = 0; i < word1.length(); i++){
        if(i == word2.length()) return true; 
        if(tolower(word1[i]) > tolower(word2[i])) return true;
        else{
            if(tolower(word1[i]) == tolower(word2[i])) continue;
            return false;
        }
    }
    return false;
}

void bubbleSort(std::vector<std::string>&vec, size_t i){
    bool swapped;
    for(std::size_t j = 0; j < i - 1; j++){
        if(compare(vec[j], vec[j+1]) == true){
            swap(vec[j] , vec[j+1]);
            swapped = true;
        }
    }
    if(swapped == false) return;
    else bubbleSort(vec, (i-1));
}

int main(){
    std::vector<std::string>words;
    std::string name;
    while(std::cin >> name){
        words.push_back(name);
    }
    bubbleSort(words,words.size());
    for(std::string toPrint : words){
        std::cout << toPrint << '\n';
    }
}