#include<vector>

//returns the index of first element found and takes linear time
template <typename T, typename F>
T linear_search(T begin, T end, F element){
    auto it = begin;
    while(it!=end){
        if(*it == element){
            break;
        }
        it++;
    }
    return it;
}

//returns all the indexes of given element and takes linear time
template <typename T, typename F>
std::vector<int> linear_search_all(T begin, T end, F element){
    auto it=begin;
    std::vector<int> indexes_list;
    while(it!=end){
        if(*it == element){
            indexes_list.push_back(it-begin);
        }
        it++;
    }
    return indexes_list;
}