#include "ArrayList.h"

template <typename T>
ArrayList<T>::ArrayList()
    : size{},
      current_capacity{ArrayList::INITIAL_CAPACITY},
      backing_array{std::make_unique<T>(ArrayList::INITIAL_CAPACITY)} {}