#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer
{
	public:
		Serializer();
		Serializer(Serializer &copy);

		virtual ~Serializer() = 0;

		Serializer &operator=(Serializer &copy);

		static uintptr_t serialize(Data *ptr);

		static Data* deserialize(uintptr_t raw);
};

#endif