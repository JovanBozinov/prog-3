#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
void bubble_sort(int *arr, int len){
    for (int i=0; i<len; i++){
        for (int j=0; j<len-i-1; j++){
            if (arr[j]>arr[j+1])
            std::swap(arr[j], arr[j+1]);
        }
    }
}

int main(){
    std::srand(std::time(0));
    int len;
    std::cin >> len;
    int a[len];
    for (int i=0; i<len; i++)
        a[i]=std::rand();
    auto start=std::chrono::high_resolution_clock::now();
    bubble_sort(a, len);
    auto end=std::chrono::high_resolution_clock::now();
    double time_ms=std::chrono::duration<double, std::milli>(end-start).count();
    for (int i=0; i<len; i++)
        std::cout << a[i] << " ";
    std::cout << '\n' << time_ms;

    return 0;
}