#include <MutantStack.hpp>
#include <list>

int main()
{
	std::cout << "_______________SUBJECT_MAIN_______________" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "_______________MY_TESTS_______________" << std::endl;

	// Test case: Create an empty MutantStack
    MutantStack<int> mstack1;
    std::cout << "Size of mstack1: " << mstack1.size() << std::endl;

    // Test case: Push some elements into the MutantStack
    mstack1.push(1);
    mstack1.push(2);
    mstack1.push(3);
    std::cout << "Top element of mstack1: " << mstack1.top() << std::endl;

    // Test case: Pop an element from the MutantStack
    mstack1.pop();
    std::cout << "Size of mstack1 after popping: " << mstack1.size() << std::endl;

    // Test case: Use iterators to print elements of the MutantStack
    MutantStack<int>::iterator it1 = mstack1.begin();
    MutantStack<int>::iterator ite1 = mstack1.end();
    std::cout << "Elements of mstack1: ";
    while (it1 != ite1) {
        std::cout << *it1 << " ";
        ++it1;
    }
    std::cout << std::endl;

	MutantStack<int> mstack2;
	for (int i = 0; i < 10000; i++) {
		mstack2.push(i);
	}

    // Test case: Copy constructor
    MutantStack<int> mstack3 = mstack1;
    std::cout << "Top element of mstack3: " << mstack3.top() << std::endl;

    // Test case: Assignment operator
    MutantStack<int> mstack4;
    mstack4 = mstack2;
    std::cout << "Top element of mstack4: " << mstack4.top() << std::endl;

    // Test case: Clear the MutantStack
    std::cout << "Size of mstack4 before clearing: " << mstack4.size() << std::endl;
    mstack4.clear();
    std::cout << "Size of mstack4 after clearing: " << mstack4.size() << std::endl;

	std::cout << "_______________LIST_TEST_______________" << std::endl;
    MutantStack<int> A;
    A.push(5);
    A.push(17);
    A.push(3);
    A.push(5);
    A.push(737);
    A.push(0);
    MutantStack<int>::iterator p = A.begin();
    MutantStack<int>::iterator pe = A.end();
    while (p != pe) {
        std::cout << *p << std::endl;
        ++p;
    }
	std::cout << "---SEPARATOR---" << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);
    std::list<int>::iterator lit = l.begin();
    std::list<int>::iterator lite = l.end();
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }
	return 0;

}
