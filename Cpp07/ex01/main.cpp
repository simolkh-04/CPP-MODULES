#include "iter.hpp"

template <typename T>
void print(T &n)
{
    std::cout << n << std::endl;
}

int main()
{
    int arr[] = {10, 20, 30};
    size_t len = 3;
    iter(arr, len, print<int>);
}