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
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(7);
    numbers.push_back(8);
    numbers.push_back(9);
    numbers.push_back(10);
    numbers.push_back(11);
    numbers.push_back(12);
    numbers.push_back(13);
    numbers.push_back(14);
    numbers.push_back(15);
    numbers.push_back(16);
    numbers.push_back(17);
    numbers.push_back(18);
    numbers.push_back(19);
    numbers.push_back(20);
    a.fillRange(numbers.begin(), numbers.end());
    std::cout << a.shortestSpan() << std::endl;
    std::cout << a.longestSpan() << std::endl;
    return 0;
}
