#include "Serializer.hpp"

int main() {
	Data* data = new Data();

	data->s1 = "Hello";
	data->s2 = "World";
	data->n = 42;

	uintptr_t serial = Serializer::serialize(data);

	std::cout << "serial: " << serial << std::endl;

	Data *deserial = Serializer::deserialize(serial);

	std::cout << "deserial->s1: " << deserial->s1 << std::endl;

	delete data;

	return 0;
}
