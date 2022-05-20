#include <iostream>
#include <iterator>
#include <vector>

class Integer {
   public:
    struct iterator {
       public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = int*;
        using reference = int&;

        iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() { return *m_ptr; }
        pointer operator->() { return m_ptr; }

        iterator& operator++() {
            m_ptr++;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const iterator& a, const iterator& b) { return a.m_ptr == b.m_ptr; }
        friend bool operator!=(const iterator& a, const iterator& b) { return a.m_ptr != b.m_ptr; }

       private:
        pointer m_ptr;
    };

    iterator begin() { return &m_data[0]; }
    iterator end() { return &m_data[500]; }

   private:
    int m_data[500];
};

int main() {
    Integer::iterator it;
    return 0;
}

// if container size is not fixed then take help of size of conatiner