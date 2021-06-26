#include<vector>
#include<iostream>

template<typename F, typename K>
void merge_f(F begin, F middle, F end, K numType){
	size_t s = middle-begin+1;
	std::vector<K> leftArray(s);
	s = end-middle+1;
	std::vector<K> rightArray(s);
	K a = std::numeric_limits<K>::max();
	int i=0;
	for(auto it = begin; it!=middle; it++){
		leftArray[i] = *it;
		i++;
	}
	leftArray[i] = a;
	i=0;
	for(auto it = middle; it!=end; it++){
		rightArray[i] = *it;
		i++;
	}
	rightArray[i] = a;
	int j=0,k=0;
	for(auto it = begin; it!=end; it++){
		if(leftArray[j]>rightArray[k]){
			*it = rightArray[k];
			k++;
		}
		else{
			*it = leftArray[j];
			j++;
		}
	}
	
}

template <typename T, typename E>
void merge_sort(T begin, T end, E numType){
	int dist = end-begin;
	int mid = dist/2;
	if(dist>0 && mid>0){
		T middle = begin+mid;
		merge_sort(begin,middle,numType);
		merge_sort(middle,end,numType);
		merge_f(begin, middle, end, numType);
	}
}

