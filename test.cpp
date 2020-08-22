#include <string.h>
#include <stdio.h>

class String {
public:
    String(const char* str) { init(str); }

    String(const String& other) { init(other._p); }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] _p;
            init(other._p);
        }
        return *this;
    }

    String& operator=(const char* str) {
        delete[] _p;
        init(str);
        return *this;
    }

    ~String() { delete[] _p; }

    size_t length() const { return _length; }

    operator const char*() const { return _p; }

private:
    size_t _length;
    char* _p;

private:
    void init(const char* str) {
        _length = strlen(str);
        _p = new char[_length];
        strcpy(_p, str);
    }
};

int main() {
    String str = "string";
    printf("%s\n", (const char*)str);

    {
        String other = str;
        printf("%s, %d\n", (const char*)other, other.length());
    }

    str = "uifweuif";
    printf("%s, %d\n", (const char*)str, str.length());
}