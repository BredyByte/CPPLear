#include "Span.hpp"

int main()
{
    Span a(5);
    a.addNumber(6);
    a.addNumber(3);
    a.addNumber(17);
    a.addNumber(9);
    a.addNumber(11);
    std::cout << a.shortestSpan() << std::endl;
    std::cout << a.longestSpan() << std::endl;
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    a.fillRange(numbers.begin(), numbers.end());
    std::cout << a.shortestSpan() << std::endl;
    std::cout << a.longestSpan() << std::endl;
    return 0;
}
