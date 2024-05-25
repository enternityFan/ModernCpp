#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <type_traits>
#include <gtest/gtest.h>

namespace TinySTL
{
    template <typename T>
    void swap(T &a, T &b)
    {
        T temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

    template <class T1, class T2>
    inline void construct(T1 *ptr1, const T2 &value)
    {
        new (ptr1) T1(value);
    }
    template <typename _Tp, typename _Alloc = std::allocator<_Tp>>
    class vector
    {
    private:
        _Tp *start_;
        _Tp *finish_;
        _Tp *end_of_storage_;

    public:
        using value_type = _Tp;
        using iterator = _Tp *;
        using const_iterator = const _Tp *;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = _Tp &;
        using const_reference = const _Tp &;
        using pointer = _Tp *;
        using const_pointer = const _Tp *;
        using allocator_type = _Alloc;

    public:
        // constructors
        vector() : start_(nullptr), finish_(nullptr), end_of_storage_(nullptr) {}
        explicit vector(size_type n);
        vector(size_type n, const value_type &val);
        template <typename _InputIterator, typename = typename std::enable_if<!std::is_integral<_InputIterator>::value>::type>
        vector(_InputIterator first, _InputIterator last);
        vector(const vector &other);
        vector(vector &&other);
        vector &operator=(const vector &other);
        vector &operator=(vector &&other);
        ~vector();

        // 比较操作
        bool operator==(const vector &other) const;
        bool operator!=(const vector &other) const;

        // 迭代器相关操作
        iterator begin() noexcept { return start_; }
        const_iterator begin() const noexcept { return start_; }
        iterator end() noexcept { return finish_; }
        const_iterator end() const noexcept { return finish_; }
        const_iterator cbegin() const noexcept { return start_; }
        const_iterator cend() const noexcept { return finish_; }
        // todo reverse相关

        // 容量相关操作
        difference_type capacity() const noexcept { return end_of_storage_ - start_; }
        difference_type max_size() const noexcept { return std::numeric_limits<difference_type>::max(); }
        difference_type size() const noexcept { return finish_ - start_; }
        bool empty() const noexcept { return start_ == finish_; }
        void reserve(size_type new_cap);
        void shrink_to_fit();

        // 元素访问相关操作
        reference operator[](const difference_type i) noexcept { return *(begin() + i); }
        const_reference operator[](const difference_type i) const noexcept { return *(begin() + i); }
        reference front() noexcept { return *begin(); }
        const_reference front() const noexcept { return *begin(); }
        reference back() noexcept { return *(end() - 1); }
        const_reference back() const noexcept { return *(end() - 1); }

        // 元素修改相关操作
        void push_back(const value_type &val);
        void pop_back();
        void clear();
        void swap(vector &other);
        void insert(iterator pos, const value_type &val);
        void insert(iterator pos, size_type n, const value_type &val);
        template <typename _InputIterator>
        void insert(iterator pos, _InputIterator first, _InputIterator last);
        iterator erase(const_iterator pos);
        iterator erase(const_iterator first, const_iterator last);
        void resize(size_type new_size);

    public:
        // friend void swap(vector<_Tp, _Alloc> &x, vector<_Tp, _Alloc> &y) noexcept;
        // friend bool operator==(const vector<_Tp, _Alloc> &x, const vector<_Tp, _Alloc> &y) noexcept;
        // friend bool operator!=(const vector<_Tp, _Alloc> &x, const vector<_Tp, _Alloc> &y) noexcept;

    private:
        // 辅助函数
        void allocateAndFill(size_type n, const value_type &val);
        void allocateAndCopy(const_iterator first, const_iterator last, const_iterator end_of_storage);
        void reallocateAndFill(iterator position, const size_type &n, const value_type &val);
        void destoryAndDeallocateAll();
        void vector_aux(const_iterator first, const_iterator last, std::true_type);
        void vector_aux(const_iterator first, const_iterator last, std::false_type);
        template <class InputIterator>
        void insert_aux(iterator position, InputIterator first, InputIterator last, std::false_type);
        template <class Integer>
        void insert_aux(iterator position, Integer n, const value_type &value, std::true_type);
    };

    // constructors
    template <typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc>::vector(size_type n)
    {
        allocateAndFill(n, value_type());
    }

    template <typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc>::vector(size_type n, const value_type &val)
    {
        allocateAndFill(n, val);
    }
    template <typename _Tp, typename _Alloc>
    template <typename _InputIterator, typename>
    vector<_Tp, _Alloc>::vector(_InputIterator first, _InputIterator last)
    {
        vector_aux(first, last, typename std::is_integral<_InputIterator>::type());
    }
    template <typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc>::vector(const vector &other)
    {
        allocateAndCopy(other.start_, other.finish_, other.end_of_storage_);
    }
    template <typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc>::vector(vector &&other)
    {
        start_ = other.start_;
        finish_ = other.finish_;
        end_of_storage_ = other.end_of_storage_;
        other.start_ = other.finish_ = other.end_of_storage_ = nullptr;
    }
    template <typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc> &vector<_Tp, _Alloc>::operator=(const vector &other)
    {
        if (this != &other)
        {
            allocateAndCopy(other.start_, other.finish_, other.end_of_storage_);
        }
        return *this;
    }
    template <typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc> &vector<_Tp, _Alloc>::operator=(vector &&other)
    {
        if (this != &other)
        {
            destoryAndDeallocateAll();
            start_ = other.start_;
            finish_ = other.finish_;
            end_of_storage_ = other.end_of_storage_;
            other.start_ = other.finish_ = other.end_of_storage_ = nullptr;
        }
        return *this;
    }

    template <typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc>::~vector()
    {
        destoryAndDeallocateAll();
    }

    // 比较操作
    template <typename _Tp, typename _Alloc>
    bool vector<_Tp, _Alloc>::operator==(const vector &other) const
    {
        if (size() != other.size())
            return false;

        return std::equal(begin(), end(), other.begin());
    }
    template <typename _Tp, typename _Alloc>
    bool vector<_Tp, _Alloc>::operator!=(const vector &other) const
    {
        return !(*this == other); // 调用重载的==操作符
    }
    // 容量相关操作
    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::reserve(size_type new_cap)
    {
        if (static_cast<difference_type>(new_cap) < capacity())
        {
            return;
        }

        _Tp *new_start = _Alloc().allocate(new_cap);
        std::uninitialized_move(start_, finish_, new_start);
        destoryAndDeallocateAll();
        start_ = new_start;
        end_of_storage_ = start_ + new_cap;
        finish_ = start_ + (finish_ - start_);
    }

    // 元素修改相关操作
    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::insert(iterator pos, const value_type &val)
    {
        std::printf("insert(iterator pos, const value_type &val)\n");
        insert_aux(pos, 1, val, std::true_type());
    }
    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::insert(iterator pos, size_type n, const value_type &val)
    {
        insert_aux(pos, n, val, typename std::is_integral<size_type>::type());
    }
    template <typename _Tp, typename _Alloc>
    template <typename _InputIterator>
    void vector<_Tp, _Alloc>::insert(iterator pos, _InputIterator first, _InputIterator last)
    {
        insert_aux(pos, first, last, typename std::is_integral<typename std::is_integral<_InputIterator>>::type());
    }

    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::push_back(const value_type &val)
    {
        insert(end(), val);
    }
    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::pop_back()
    {
        erase(end() - 1);
    }
    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::clear()
    {
        erase(begin(), end());
    }
    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::swap(vector &other)
    {
        if (this != &other)
        {
            TinySTL::swap(start_, other.start_);
            TinySTL::swap(finish_, other.finish_);
            TinySTL::swap(end_of_storage_, other.end_of_storage_);
        }
    }

    template <typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc>::iterator vector<_Tp, _Alloc>::erase(const_iterator pos)
    {

        if (pos < begin() || pos >= end())
            return end();

        iterator pos_ptr = const_cast<iterator>(pos);
        std::move(pos_ptr + 1, finish_, pos_ptr);
        --finish_;
        return pos_ptr;
    }

    template <typename _Tp, typename _Alloc>
    vector<_Tp, _Alloc>::iterator vector<_Tp, _Alloc>::erase(const_iterator first, const_iterator last)
    {
        if (first >= last || first < begin() || last > end())
            return end();

        iterator first_ptr = const_cast<iterator>(first);
        iterator last_ptr = const_cast<iterator>(last);
        std::move(last_ptr, finish_, first_ptr);
        finish_ -= last_ptr - first_ptr;
        return first_ptr;
    }

    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::resize(size_type new_size)
    {
        assert(new_size >= 0);
        if (new_size > size())
        {
            reserve(new_size);
            std::uninitialized_fill_n(finish_, new_size - size(), value_type());
            finish_ += new_size - size();
        }
        else if (new_size < size())
        {
            erase(begin() + new_size, end());
        }
    }

    // 辅助函数
    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::allocateAndFill(size_type n, const value_type &val)
    {
        start_ = finish_ = end_of_storage_ = nullptr;
        if (n > 0)
        {
            start_ = _Alloc().allocate(n);
            std::uninitialized_fill_n(start_, n, val);
            finish_ = end_of_storage_ = start_ + n;
        }
    }
    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::reallocateAndFill(iterator position, const size_type &n, const value_type &val)
    {
        size_type len = size();
        size_type new_cap = len + n;
        pointer new_start = _Alloc().allocate(new_cap);
        std::uninitialized_move(start_, position, new_start);
        std::uninitialized_fill_n(new_start + (position - start_), n, val);
        std::uninitialized_move(position, finish_, new_start + (position - start_) + n);
        destoryAndDeallocateAll();
        start_ = new_start;
        end_of_storage_ = start_ + new_cap;
        finish_ = start_ + (finish_ - start_) + n;
    }
    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::vector_aux(const_iterator first, const_iterator last, std::true_type)
    {
        size_type n = last - first;
        allocateAndFill(n, value_type());
        std::uninitialized_copy(first, last, start_);
    }
    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::vector_aux(const_iterator first, const_iterator last, std::false_type)
    {
        size_type n = std::distance(first, last);
        allocateAndFill(n, value_type());
        std::uninitialized_copy(first, last, start_);
    }
    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::allocateAndCopy(const_iterator first, const_iterator last, const_iterator end_of_storage)
    {
        start_ = finish_ = end_of_storage_ = nullptr;
        if (first != last)
        {
            start_ = _Alloc().allocate(last - first);
            finish_ = start_;
            end_of_storage_ = start_ + (last - first);
            std::uninitialized_copy(first, last, start_);
        }
    }

    template <typename _Tp, typename _Alloc>
    void vector<_Tp, _Alloc>::destoryAndDeallocateAll()
    {
        if (capacity() > 0)
        {
            std::destroy(start_, finish_);
            _Alloc().deallocate(start_, capacity());
            start_ = finish_ = end_of_storage_ = nullptr;
        }
    }
    template <typename _Tp, typename _Alloc>
    template <class InputIterator>
    void vector<_Tp, _Alloc>::insert_aux(iterator position, InputIterator first, InputIterator last, std::false_type)
    {
        size_type n = last - first;
        if (n > 0)
        {
            size_type len = size();
            if (len + n > capacity())
                reserve(len + n);
            std::uninitialized_copy(finish_, position, finish_ + n);
            finish_ += n;
            std::uninitialized_copy(first, last, finish_);
            finish_ += n;
            std::move_backward(position, finish_ - n, finish_);
        }
    }
    template <typename _Tp, typename _Alloc>
    template <class Integer>
    void vector<_Tp, _Alloc>::insert_aux(iterator position, Integer n, const value_type &value, std::true_type)
    {
        assert(n != 0);
        difference_type locationLeft = end_of_storage_ - finish_; // the size of left storage
        difference_type locationNeed = n;
        std::cout << __func__ << "\t" << __LINE__ << std::endl;
        if (locationLeft >= locationNeed)
        {
            auto tempPtr = end() - 1;
            std::cout << __func__ << "\t" << __LINE__ << std::endl;
            for (; tempPtr - position >= 0; --tempPtr)
            { // move the [position, finish_) back
              //*(tempPtr + locationNeed) = *tempPtr;//bug
                std::cout << __func__ << "\t" << __LINE__ << std::endl;
                construct(tempPtr + locationNeed, *tempPtr);
                std::cout << __func__ << "\t" << __LINE__ << std::endl;
            }
            std::cout << __func__ << "\t" << __LINE__ << std::endl;
            std::uninitialized_copy(position, n, value); // todo coredump...
            std::cout << __func__ << "\t" << __LINE__ << std::endl;
            finish_ += locationNeed;
            std::cout << __func__ << "\t" << __LINE__ << std::endl;
        }
        else
        {
            reallocateAndFill(position, n, value);
        }
    }

}; // namespace TinySTL

using namespace TinySTL;

// 测试代码
// 测试用例
TEST(VectorCapacityTest, SizeFunctionTest)
{
    vector<int> v1(5, 10); // 使用 (size_type, const value_type&) 构造函数
    ASSERT_EQ(v1.size(), 5);

    vector<std::string> v3(3, "hello"); // 使用 (size_type, const value_type&) 构造函数
    ASSERT_EQ(v3.size(), 3);
    ASSERT_FALSE(v3.empty());

    // vector<std::string> v2{1, 2, 3, 4, 5}; // 使用 (size_type, const value_type&) 构造函数
    // ASSERT_EQ(v2.size(), 5);
}

TEST(VectorMaxsizeTest, MaxsizeFunctionTest)
{
    // ASSERT_EQ(v1.max_size(), std::numeric_limits<std::ptrdiff_t>::max());

    vector<std::string> v2;
    v2.push_back("hello");
    v2.push_back("world");
    v2.push_back("!");
    ASSERT_EQ(v2.capacity(), 3);
    v2.push_back("!");
    ASSERT_EQ(v2.capacity(), 5);
    v2.reserve(10);
    ASSERT_EQ(v2.capacity(), 10);
}

TEST(VectorPushBackTest, InsertFunctionTest)
{
    vector<int> v1;
    v1.push_back(10);
    // v1.push_back(20);
    // v1.push_back(30);
    // v1.push_back(40);
    // v1.push_back(50);
    // ASSERT_EQ(v1.size(), 5);
    // ASSERT_EQ(v1[0], 10);
    // ASSERT_EQ(v1[1], 20);
    // ASSERT_EQ(v1[2], 30);
    // ASSERT_EQ(v1[3], 40);
    // ASSERT_EQ(v1[4], 50);

    vector<std::string> v2;
    v2.push_back("hello");
    v2.push_back("world");
    v2.push_back("!");
    ASSERT_EQ(v2.size(), 3);
    ASSERT_EQ(v2[0], "hello");
    ASSERT_EQ(v2[1], "world");
    ASSERT_EQ(v2[2], "!");

    v2.insert(v2.begin(), 2, "!"); // 插入 n 个元素
    ASSERT_EQ(v2.size(), 5);
    ASSERT_EQ(v2[0], "!");
    ASSERT_EQ(v2[1], "!");
    ASSERT_EQ(v2[2], "hello");
    ASSERT_EQ(v2[3], "world");
    ASSERT_EQ(v2[4], "!");
    // todo
    //  v2.insert(v2.end(), {"a", "b", "c"}); // 插入元素
    //  ASSERT_EQ(v2.size(), 8);
    //  ASSERT_EQ(v2[5], "a");
    //  ASSERT_EQ(v2[6], "b");
    //  ASSERT_EQ(v2[7], "c");

    v2.insert(v2.begin() + 2, 2, "!"); // 插入 n 个元素
    ASSERT_EQ(v2.size(), 11);
    ASSERT_EQ(v2[0], "!");
    ASSERT_EQ(v2[1], "!");
    ASSERT_EQ(v2[2], "!");
    ASSERT_EQ(v2[3], "hello");
    ASSERT_EQ(v2[4], "world");
}
int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}