template <typename T, typename K>
K kth_element(T begin, T end, T nthelement, K element){
    int dist = end-begin;
    while(dist>0){
        dist = end-begin;
        if(dist>1){
            T randIterator = begin+rand()%(dist-1);
            swap_f(randIterator,begin);
        }
        T breakPoint = partition_quicksort(begin,end,*begin);
        swap_f(begin,breakPoint);
        if(breakPoint == nthelement){
            return *breakPoint;
        }
        else if(nthelement-breakPoint>0){
            begin = breakPoint+1;
        }
        else{
            end = breakPoint;
        }
    }
    return *begin;
}