#include "person.hpp"

namespace
{
  size_t getNextCapacity(size_t capacity)
  {
    if (capacity == 0)
    {
      return 4;
    }
    return capacity * 2;
  }

  void reservePersonArray(studilova::PersonArray &array, size_t newCapacity)
  {
    if (newCapacity <= array.capacity_)
    {
      return;
    }

    studilova::Person* newData = new studilova::Person[ newCapacity ];

    for (size_t i = 0; i < array.size_; ++i)
    {
      newData[i] = array.data_[i];
    }

    delete[] array.data_;

    array.data_ = newData;
    array.capacity_ = newCapacity;
  }
}

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
