#include "person.hpp"

void studilova::initPersonArray(PersonArray &array)
{
  array.data_ = nullptr;
  array.size_ = 0;
  array.capacity_ = 0;
}

void studilova::destroyPersonArray(PersonArray &array)
{
  delete[] array.data_;
  array.data_ = nullptr;
  array.size_ = 0;
  array.capacity_ = 0;
}
