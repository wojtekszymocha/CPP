#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <functional>

std::vector<std::pair<int,int>> compressGrayscale(const std::array<std::array<int,6>,4>& arr){
     std::vector<std::pair<int,int>> vec {};

    int counter = 0;
    for(const auto row : arr){
        counter = 1;
        for(auto it = row.begin(); it != row.end(); it++){
            auto nextIt = std::next(it,1);
            if(*it != *nextIt || it == row.end()){
                vec.emplace_back(std::make_pair(*it,counter));
                counter = 1;
            }else{
                counter++;
            }
        }
    }
    vec.shrink_to_fit(); 
    return vec;
}

int main(){
        std::array<std::array<int,6>,4> arr {{{255,255,0,255,0,255},{ 128,0,128,0,128,0},{64,64,64,64,64,64},{255,192,128,64,0,0}}};
        std::vector<std::pair<int,int>> vec = compressGrayscale(arr);

        for(const auto& el : vec){
            std::cout<< el.first << " " << el.second <<'\n';

        }
        std::cout<<'\n';

        for( auto it = arr.begin(); it != arr.end();it++){
        for(auto it_inside = it->begin();it_inside != it->end();it_inside++){
            std::cout<< *it_inside << " ";
        }
            std::cout<< '\n';
        }

    return 0;

}
