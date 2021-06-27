#include<random>

template <typename T>
void swap_f(T element1, T element2){
    auto temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

template <typename T, typename E>
T partition_quicksort(T begin, T end, E pivot){
    auto its = begin;
    auto itl = begin;
    for(auto it = begin+1; it!=end; it++){
        if(*it>pivot){
            itl++;
        }
        else{
            its++;
            swap_f(it,its);
            itl++;
        }
    }
    return its;
}

template <typename F, typename K>
void quick_sort(F begin, F end, K typeInfo){
    int dist = end-begin;
    if(dist>0){
		K pivot = *begin;
        F breakPoint = partition_quicksort(begin,end,pivot);
        swap_f(begin,breakPoint);
        quick_sort(begin,breakPoint,typeInfo);
        quick_sort(breakPoint+1,end,typeInfo);
    }
}

template <typename G, typename H>
void randomized_quick_sort(G begin, G end, H typeInfo){
    int dist = end-begin;
    if(dist>0){
        if(dist>1){
            G randIterator = begin+rand()%(dist-1);
            swap_f(randIterator,begin);
        }
		H pivot = *begin;
        G breakPoint = partition_quicksort(begin,end,pivot);
        swap_f(begin,breakPoint);
        randomized_quick_sort(begin,breakPoint,typeInfo);
        randomized_quick_sort(breakPoint+1,end,typeInfo);
    }
}
