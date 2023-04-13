#pragma once

#include <memory>
#include <stdexcept>
#include <string>

template <typename T>
class ArrayList {
  public:
    static constexpr int INITIAL_CAPACITY{10};

  private:
    int size{};
    int current_capacity{INITIAL_CAPACITY};
    std::unique_ptr<T[]> backing_array{};

  public:
    ArrayList();
    ArrayList(const ArrayList& other);

    void add_at_index(int index, T data);
    void add_at_front(T data);
    void add_to_back(T data);

    T& remove_at_index(int index);
    T& remove_from_front();
    T& remove_from_back();

    T& get(int index);
    T& operator[](int index);

    bool is_empty();
    void clear();

    int get_size();
    int get_current_capacity();

  private:
    void copy_to_expanded_backing_array();
    void validateIndexInRange(int index);
};

template <typename T>
ArrayList<T>::ArrayList()
    : size{},
      current_capacity{ArrayList::INITIAL_CAPACITY},
      backing_array{std::make_unique<T[]>(ArrayList::INITIAL_CAPACITY)} {}

template <typename T>
void ArrayList<T>::add_at_index(int index, T data) {
    validateIndexInRange(index);

    bool arrayIsFull{size == current_capacity};
    if (arrayIsFull) {
        copy_to_expanded_backing_array();
    }

    for (int j{size - 1}; j >= index; --j) {
        backing_array[j + 1] = std::move(backing_array[j]);
    }
    backing_array[index] = data;
    size++;
}

template <typename T>
T& ArrayList<T>::get(int index) {
    validateIndexInRange(index);

    return backing_array[index];
}

template <typename T>
T& ArrayList<T>::operator[](int index) {
    return get(index);
}

template <typename T>
int ArrayList<T>::get_size() {
    return size;
}

template <typename T>
int ArrayList<T>::get_current_capacity() {
    return current_capacity;
}

template <typename T>
void ArrayList<T>::copy_to_expanded_backing_array() {
    const int old_capacity{current_capacity};
    std::unique_ptr<T[]> old_backing_array{std::move(backing_array)};

    current_capacity *= 2;
    backing_array = std::make_unique<T[]>(current_capacity);
    for (int i{}; i < old_capacity; ++i) {
        backing_array[i] = std::move(old_backing_array[i]);
    }
}

template <typename T>
void ArrayList<T>::validateIndexInRange(int index) {
    if (index < 0) {
        std::string error_msg{"Cannot add at index less than 0"};
        throw std::out_of_range(error_msg);
    } else if (index > size) {
        std::string error_msg{"Cannot add at index > size"};
        throw std::out_of_range(error_msg);
    }
}