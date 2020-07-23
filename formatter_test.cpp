/*
 * @Author: Hata
 * @Date: 2020-07-13 00:20:46
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-14 20:05:51
 * @FilePath: \LeetCode\formatter_test.cpp
 * @Description:
 */
#include "tools.h"
/***********************/

#include <bits/stdc++.h>

struct A {
    inline virtual std::string toString() { return "is A"; }
};

struct B : public A {};

struct C : public A {
    inline virtual std::string toString() override { return "is C"; }
};

struct D : public B {
    inline virtual std::string toString() override { return "is D"; }
};

template <typename T>
struct TemplateClassToString {
    inline std::string to_string() { return std::string{typeid(T).name()}; }
};

template <>
struct TemplateClassToString<int> {
    inline std::string to_string() && { return "int &&"; }
    inline std::string to_string() & { return "int &"; }
};

int main() {
    using namespace lctools;
    // STL组件
    std::cout << "STL组件: " << std::endl;
    using GodList =
        std::variant<std::deque<int>, std::list<int>, std::vector<int>, std::initializer_list<int>,
                     std::forward_list<int>, std::array<int, 4>, std::bitset<4>>;
    auto dict =
        std::unordered_map<std::string, GodList>{{"0000", std::deque<int>{0, 0, 0, 0}},
                                                 {"0001", std::bitset<4>{"0001"}},
                                                 {"0010", std::array{0, 0, 1, 0}},
                                                 {"0100", std::forward_list<int>{0, 1, 0, 0}},
                                                 {"0101", std::vector<int>{0, 1, 0, 1}},
                                                 {"0110", std::list<int>{0, 1, 1, 0}},
                                                 {"0111", std::initializer_list<int>{0, 1, 1, 1}}};
    auto json = std::make_pair(
        "KEY",
        std::make_pair(
            "KEY[0]",
            std::make_pair("KEY[1]", std::make_tuple("VALUE[0]", "VALUE[1]",
                                                     std::make_pair("VALUE[2].KEY[2]",
                                                                    std::array{1, 2, 3, 4, 5})))));
    std::cout << Formatter::ToStringLines(dict, json) << std::endl;

    // 编译期多态
    std::cout << "\n编译期多态: " << std::endl;
    TemplateClassToString<std::string> tcts_string;
    std::cout << Formatter::ToString(TemplateClassToString<float*>{}, TemplateClassToString<int>{},
                                     tcts_string)
              << std::endl;

    // 运行期多态
    std::cout << "\n运行期多态: " << std::endl;
    std::unique_ptr<A> pb = std::make_unique<B>(), pc = std::make_unique<C>(),
                       pd = std::make_unique<D>();
    std::cout << Formatter::ToString(*pb, *pc, *pd.get()) << std::endl;

    // C风格组件
    std::cout << "\nC风格组件: " << std::endl;
    const char* c_str = "c_str";
    int64_t c_array[]{532, 413, 7568, 9, '2', 0B1010111, 001746, 7346712LL};
    std::cout << Formatter::ToString(c_str, u8"UTF-8字符串字面量", c_array) << std::endl;
}