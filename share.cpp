#include <utility>
#include <iostream>

template <class T>
class SharePtr {
    struct ShareBlock {
        int count;
        T* resource;

        template <class U>
        ShareBlock(U* ptr) : resource{static_cast<T*>(ptr)}, count{1} {}

        ~ShareBlock() { delete resource; }

        int increase() { return ++count; }
        int decrease() { return --count; }
    };

public:
    SharePtr() : _ptr{nullptr}, _block{nullptr} {}

    template <class U>
    SharePtr(U* ptr) : _block{new ShareBlock{static_cast<T*>(ptr)}} {
        _ptr = _block->resource;
    }

    template <class U>
    SharePtr(const SharePtr<U>& r) {
        _block = static_cast<ShareBlock*>(r._block);
        _block->increase();
        _ptr = _block->resource;
    }

    SharePtr(const SharePtr<T>& r) : _block{r._block}, _ptr{r._ptr} { _block->increase(); }

    template <class U>
    SharePtr(SharePtr<U>&& r) : SharePtr{} {
        std::swap(_block, r._block);
        std::swap(_ptr, r._ptr);
    }

    template <class U>
    SharePtr& operator=(SharePtr<U>&& r) {
        free();
        std::swap(_block, r._block);
        std::swap(_ptr, r._ptr);
        return *this;
    }

    SharePtr& operator=(const SharePtr& r) noexcept {
        free();
        _block = r._block;
        _ptr = _block->resource;
        _block->increase();
        return *this;
    }

    ~SharePtr() { this->free(); }

private:
    T* _ptr;
    ShareBlock* _block;

public:
    T& operator*() const noexcept { return *_ptr; }
    T* operator->() const noexcept { return _ptr; }

    template <class U>
    void reset(U* ptr) {
        this->free();
        _block = new ShareBlock{static_cast<T*>(ptr)};
        _ptr = _block->resource;
    }

    int count() const { return _block ? _block->count : 0; }

private:
    void free() {
        if (_block != nullptr && _block->decrease() == 0) {
            delete _block;
        }
        _block = nullptr;
        _ptr = nullptr;
    }
};

struct Test {
public:
    int i;
    Test(int _i) : i{_i} { std::cout << i << " Test()" << std::endl; }
    ~Test() { std::cout << i << " ~Test()" << std::endl; }
};

int main() {
    SharePtr<Test> p{new Test{2}};

    SharePtr<Test> p1{new Test{1}};
    SharePtr<Test> p2{std::move(p)};
    auto p3 = p2;

    std::cout << p1->i << ", " << p2->i << ", " << p3->i << std::endl;

    std::cout << p1.count() << ", " << p2.count() << ", " << p3.count() << std::endl;

    p1 = p3;

    std::cout << p1->i << ", " << p2->i << ", " << p3->i << std::endl;
    std::cout << p1.count() << ", " << p2.count() << ", " << p3.count() << std::endl;
}