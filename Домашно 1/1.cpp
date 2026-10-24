#include<iostream>

void printarr(int *arr, int len){
    for (int i=0; i<len; i++)
        std::cout << *(arr+i) << " "; 
    std::cout << '\n';
}

void swap_p(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void swap_r(int &a, int &b){
    int t=a;
    a=b;
    b=t;
}

void bubble_sort(int *arr, int len){
    for (int i=0; i<len; i++){
        for (int j=0; j<len-i-1; j++){
            if (*(arr+j)>*(arr+j+1))
                std::swap(*(arr+j), *(arr+j+1));
        }
    }
}

int binary_search_i(int *arr, int key, int start, int end){
    while (start<=end){
        int mid=(start+end)/2;
        if (*(arr+mid)==key)
            return mid;
        if (*(arr+mid)>key)
            end=mid-1;
        if (*(arr+mid)<key)
            start=mid+1;
    }
    return -1;
}
int binary_search_r(int *arr, int key, int start, int end){
    if (start>end)
        return -1;
    else{
        int mid=(start+end)/2;
        if (*(arr+mid)==key)
            return mid;
        else if (*(arr+mid)>key)
            return binary_search_r(arr, key, start, mid-1);
        else 
            return binary_search_r(arr, key, mid+1, end);
    }
}

int main(){
    int n, a, b;
    std::cin >> a >> b;
    swap_p(&a, &b);
    std::cout << a << " " << b << '\n';
    swap_r(a, b);
    std::cout << a << " " << b << '\n';
    std::cin >> n;
    int arr[n], keyind, key;
    std::cin >> key;
    for (int i=0; i<n; i++)
        std::cin >> *(arr+i);
    printarr(arr, n);
    bubble_sort(arr, n);
    printarr(arr, n);
    keyind=binary_search_i(arr, key, 0, n-1);
    if (keyind!=-1)
        std::cout << "The element is at pos. " << keyind << '\n';
    else 
        std::cout << "The element is not in the array!" << '\n';
    keyind=binary_search_r(arr, key, 0, n-1);
    if (keyind!=-1)
        std::cout << "The element is at pos. " << keyind << '\n';
    else 
        std::cout << "The element is not in the array!" << '\n';

    return 0;
}