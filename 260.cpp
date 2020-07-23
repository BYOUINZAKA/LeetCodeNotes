/*
 * @Author: Hata
 * @Date: 2020-07-13 20:06:49
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-14 17:09:53
 * @FilePath: \LeetCode\260.cpp
 * @Description: https://leetcode-cn.com/problems/single-number-iii/
 */
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        int bits = 0, val = 0;
        for (auto&& i : nums) bits ^= i;

        int diff = bits & (-bits);
        for (auto&& i : nums)
            if (i & diff) val ^= i;

        return {val, bits ^ val};
    }
};

template <typename T, typename F>
struct HasBegin {
    template <typename, typename, typename>
    struct Helper : public std::false_type {};
    template <typename Obj, typename Func>
    struct Helper<Obj, Func, typename std::void_t<decltype(static_cast<F T::*>(&Obj::begin))>>
        : public std::true_type {};

    constexpr static bool value = Helper<T, F, void>::value;
};

template <typename T, typename F, typename... Args>
struct HasToString {
    template <typename, typename, typename>
    struct Helper : public std::false_type {};
    template <typename Obj, typename Func>
    struct Helper<
        Obj, Func,
        typename std::void_t<decltype(static_cast<F (T::*)(Args...) const>(&Obj::ToString))>>
        : public std::true_type {};

    constexpr static bool value = Helper<T, F, void>::value;
};

struct Test {
    std::string ToString() const;
    std::string ToString(int i) const&& {
        std::cout << i << std::endl;
        return std::to_string(i);
    }
};

#define CheckMemberMethod(Name, Func)                                                          \
    template <typename __##Name##_T__, typename... __##Name##_Args__>                          \
    struct Name {                                                                              \
        template <typename, typename>                                                          \
        struct Helper : public std::false_type {};                                             \
                                                                                               \
        template <typename __##Name##_U__>                                                     \
        struct Helper<__##Name##_U__,                                                          \
                      typename std::void_t<decltype(std::declval<__##Name##_U__>().Func(       \
                          std::declval<__##Name##_Args__>()...))>> : public std::true_type {}; \
                                                                                               \
        constexpr static bool value = Helper<__##Name##_T__, void>::value;                     \
    }

CheckMemberMethod(CheckToString, ToString);
CheckMemberMethod(CheckBegin, begin);

static_assert(HasBegin<std::vector<int>, std::vector<int>::iterator()>::value);

static_assert(HasToString<Test, std::string>::value);

static_assert(CheckToString<Test, int>::value);
static_assert(CheckToString<Test>::value);
static_assert(CheckBegin<std::vector<int>&&>::value);