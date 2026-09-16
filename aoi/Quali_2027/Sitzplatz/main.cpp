#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int k, v, u, w;
        std::cin >> k >> v >> u >> w;

        if(k*v - u > w){
          std::cout << 1;
        } else{
          std::cout << 0;
        }
        std::cout << "\n";



    }
}
