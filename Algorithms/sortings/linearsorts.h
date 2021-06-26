template <typename T, typename F>
void counting_sort(T begin, T end, F starting_range, F ending_range){
    std::vector<F> count(ending_range-starting_range);
    std::vector<F> output(end-begin);
    for(int i=0;i<ending_range-starting_range;i++){
        count[i] = 0;
    }
    for(auto it = begin; it!=end;it++){
        count[(*it)-starting_range]=count[(*it)-starting_range]+1;
    }
    for(int i=1;i<ending_range-starting_range;i++){
        count[i] = count[i]+count[i-1];
    }
    for (int i = 0; i<end-begin; i++) {
        output[count[*(begin+i)] - 1] = *(begin+i);
        --count[*(begin+i)];
    }
    int i=0;
    for (auto it = begin; it!=end;it++){
        *it = output[i];
        i++;
    }
}

template <typename T, typename F>
void rad_count_sort(T begin, T end, F starting_range, F ending_range, F digit){
    std::vector<F> count(ending_range-starting_range);
    std::vector<F> output(end-begin);
    for(int i=0;i<ending_range-starting_range;i++){
        count[i] = 0;
    }
    for(auto it = begin; it!=end;it++){
        count[(((*it)-starting_range)/digit)%10]=count[(((*it)-starting_range)/digit)%10]+1;
    }
    for(int i=1;i<ending_range-starting_range;i++){
        count[i] = count[i]+count[i-1];
    }
    for (int i = (end-begin)-1; i>=0; i--) {
        output[count[((*(begin+i)/digit))%10] - 1] = *(begin+i);
        --count[((*(begin+i)/digit))%10];
    }
    int i=0;
    for (auto it = begin; it!=end;it++){
        *it = output[i];
        i++;
    }
}


template <typename T, typename F>
void radix_sort(T begin, T end, F digits){
    int k=1;
    for(int i=0;i<digits;i++){
        rad_count_sort(begin,end,0,10,k);
        k*=10;
    }
}