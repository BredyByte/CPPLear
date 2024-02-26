#include <MutantStack.hpp>

int main()
{
	MutantStack<int> a;
	a.getVector();
	a.push(123);
	std::cout << a.top() << std::endl;
	a.pop();
	std::cout << a.size() << std::endl;
}
