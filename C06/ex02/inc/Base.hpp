#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>



class Base {
	public:
		virtual ~Base() {}
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base* generate();
/*
It randomly instanciates A, B or C and returns the instance as a Base pointer.  Feel free to use anything you like for the random choice implementation.
*/

void identify(Base* p);
//It prints the actual type of the object pointed to by p: "A", "B" or "C".

void identify(Base& p);
/*
It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer inside this function is forbidden.
*/
#endif
