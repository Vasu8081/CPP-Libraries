//returns iterator to index of element if present else iterator the next smallest element to that number
template <typename R, typename T>
R binary_search_f(R begin, R end, T element){
    R middle;
    int dist = end-begin;
    int mid = dist/2;
    while(dist >0 && mid>0){
        dist = end-begin;
        mid = dist/2;
        middle = begin+mid;
        if(*middle == element){
            return middle;
        }
        else if(*middle > element){
            end = middle;
        }
        else{
            begin = middle;
        }
    }
    return middle;
}