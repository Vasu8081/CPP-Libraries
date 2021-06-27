template <typename T>

void insertion_sort(T begin, T end){
	for(auto it = begin+1; it!=end;it++){
		auto temp = *it;
		auto itj = it-1;
		while(itj!=(begin-1) && temp<*(itj)){
			*(itj+1) = *itj;
			itj--;
		}
		*(itj+1)=temp;
	}
}
