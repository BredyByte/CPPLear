#include <easyfind.hpp>

int main(int, char**)
{
    std::vector<int> arrV = {1, 2, 3, 4, 5};
    try {
        easyfind(arrV, 8);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
