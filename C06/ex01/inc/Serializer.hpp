#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <string>
#include <stdint.h>
#include <stddef.h>

typedef struct Data {
	std::string s1;
	int n;
	std::string s2;
} Data;

class Serializer {
	public:
		Serializer();
		~Serializer();
		Serializer(Serializer& other);
		Serializer& operator=(Serializer& other);

		static uintptr_t serialize(Data* ptr); // It takes a pointer and converts it to the unsigned integer type uintptr_t

		static Data* deserialize(uintptr_t raw); // It takes an unsigned integer type uintptr_t and converts it to a pointer

};

#endif
