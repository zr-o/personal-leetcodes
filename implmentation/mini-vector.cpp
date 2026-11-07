#include <cstddef>
#include <memory>

template <typename T> class MiniVector {
public:
  using size_type = std::size_t;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;

private:
  std::allocator<T> allocator_;
  value_type *data_ = nullptr;
  size_type capacity_{0uz};
  size_type size_{0uz};

public:
  MiniVector() = default;
  MiniVector(std::size_t count, const T &value)
      : data_(allocator_.allocate(count)), capacity_(count) {
    try {
      for (std::size_t i; i < capacity_; ++i) {
        std::construct_at(data_ + i, value);
        ++size_;
      }
    } catch (...) {
      for (std::size_t i; i < size_; ++i) {
        std::destroy_at(data_ + i);
      }
      allocator_.deallocate(data_, capacity_);
      throw;
    }
  }
};
