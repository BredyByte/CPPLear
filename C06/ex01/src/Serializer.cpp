#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(Serializer& other) {
	*this = other;
}

Serializer& Serializer::operator=(Serializer& other) {
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
	/*
	 uintptr_t -  It's an unsigned integer type exactly the size of a pointer. Whenever you need to do something unusual with a pointer - like for example invert all bits (don't ask why) you cast it to uintptr_t and manipulate it as a usual integer number, then cast back.
	*/

	/*
	 reinterpret_cast : This is used for low-level conversions between pointer types, or between pointers and integral types. It allows you to interpret the underlying bit pattern of the data, but it doesn't perform any type checking or conversions. This cast is generally considered unsafe and should be used sparingly
	*/

	/*
	 static_cast: Used for general type conversions, including implicit conversions, and is checked at compile-time.

     dynamic_cast: Used for safe downcasting in class hierarchies, performs runtime type checking - std::bad_cast exception for ex.

     reinterpret_cast: Performs low-level conversions between pointer types or between pointers and integral types, without any type checking.

     const_cast: Used to add or remove const or volatile qualifiers from a variable.*/

	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
