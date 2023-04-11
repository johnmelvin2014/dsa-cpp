#pragma once

#include <memory>

template <typename T>
class ArrayList {
  public:
    static constexpr int INITIAL_CAPACITY{10};

  private:
    unsigned int size{};
    unsigned int current_capacity{INITIAL_CAPACITY};
    std::unique_ptr<T> backing_array{};

  public:
    ArrayList();
    ~ArrayList();
    ArrayList(const ArrayList &other);

    void add_at_index(unsigned int index, T data);
    void add_at_front(T data);
    void add_to_back(T data);

    T &remove_at_index(unsigned int index);
    T &remove_from_front();
    T &remove_from_back();

    T &get(unsigned int index);
    bool is_empty();
    void clear();

    unsigned int get_size();
    std::unique_ptr<T> get_backing_array();

  private:
    void copy_to_expanded_backing_array();
};