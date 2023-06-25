template<typename T, typename AT>
T minimum(Array<T> arr, AT comp){
    T min = a[0];
    for (size_t i = 1; i < arr.size(); i++){
        if (comp(arr[i], min)) min = arr[i];

    }
    return min;
}