/*
 * @Author: Hata
 * @Date: 2020-07-11 19:40:43
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-20 17:05:53
 * @FilePath: \LeetCode\tools.h
 * @Description:
 */

#ifndef __LCTOOLS_TOOLS_
#define __LCTOOLS_TOOLS_

#include <string>
#include <tuple>
#include <type_traits>
#include <variant>

#ifndef CheckMemberType
#define CheckMemberType(Name, Type)                                               \
    template <typename __##Name##_T__>                                            \
    struct Name {                                                                 \
        template <typename, typename>                                             \
        struct Helper : public std::false_type {};                                \
                                                                                  \
        template <typename __##Name##_U__>                                        \
        struct Helper<__##Name##_U__, std::void_t<typename __##Name##_U__::Type>> \
            : public std::true_type {};                                           \
                                                                                  \
        static constexpr bool value =                                             \
            Helper<std::remove_reference_t<__##Name##_T__>, void>::value;         \
    }
#endif

#ifndef CheckMemberMethod
#define CheckMemberMethod(Name, Func)                                                            \
    template <typename __##Name##_T__, typename... __##Name##_Args__>                            \
    struct Name {                                                                                \
        template <typename, typename, typename...>                                               \
        struct Helper : public std::false_type {};                                               \
                                                                                                 \
        template <typename __##Name##_U__, typename... __##Name##_SubArgs__>                     \
        struct Helper<std::void_t<decltype(std::declval<__##Name##_U__>().Func(                  \
                          std::declval<__##Name##_Args__>()...))>,                               \
                      __##Name##_U__, __##Name##_SubArgs__...> : public std::true_type {};       \
                                                                                                 \
        static constexpr bool value = Helper<void, __##Name##_T__, __##Name##_Args__...>::value; \
    }
#endif

/*
#define CheckMemberType(Name, Member)                                                             \
    template <typename __##Name##_T__>                                                            \
    struct Name {                                                                                 \
        template <typename __##Name##_U__>                                                        \
        static constexpr std::true_type check(                                                    \
            typename std::decay_t<typename __##Name##_U__::Member>*);                             \
                                                                                                  \
        template <typename __##Name##_U__>                                                        \
        static constexpr std::false_type check(...);                                              \
                                                                                                  \
        static constexpr bool value =                                                             \
            std::is_same_v<decltype(                                                              \
                               check<typename std::remove_reference_t<__##Name##_T__>>(nullptr)), \
                           std::true_type>;                                                       \
    }

#define CheckSingleMemberMethod(Name, Ret, Func, Args)                                          \
    template <typename __##Name##_I__>                                                          \
    struct Name {                                                                               \
        template <typename __##Name##_U__, Ret(__##Name##_U__::*) Args = &__##Name##_U__::Func> \
        static constexpr std::true_type check(int);                                             \
                                                                                                \
        template <typename __##Name##_U__>                                                      \
        static constexpr std::false_type check(...);                                            \
                                                                                                \
        static constexpr bool value =                                                           \
            std::is_same_v<decltype(check<__##Name##_I__>(0)), std::true_type>;                 \
    }

#define CheckMemberMethod(Name, Func)                                                              \
    template <typename __##Name##_T__, typename __##Name##_R__, typename... __##Name##_Args__>     \
    struct Name {                                                                                  \
        using __##Name##_RRT__ = typename std::remove_reference_t<__##Name##_T__>;                 \
                                                                                                   \
        CheckSingleMemberMethod(Name##_normal, __##Name##_R__, Func, (__##Name##_Args__...));      \
        CheckSingleMemberMethod(Name##_const, __##Name##_R__, Func, (__##Name##_Args__...) const); \
        CheckSingleMemberMethod(Name##_lvalue, __##Name##_R__, Func, (__##Name##_Args__...) &);    \
        CheckSingleMemberMethod(Name##_rvalue, __##Name##_R__, Func, (__##Name##_Args__...) &&);   \
        CheckSingleMemberMethod(Name##_noexcept, __##Name##_R__, Func,                             \
                                (__##Name##_Args__...) noexcept);                                  \
                                                                                                   \
        static constexpr bool value =                                                              \
            Name##_normal<__##Name##_RRT__>::value || Name##_const<__##Name##_RRT__>::value ||     \
            Name##_lvalue<__##Name##_RRT__>::value || Name##_rvalue<__##Name##_RRT__>::value ||    \
            Name##_noexcept<__##Name##_RRT__>::value;                                              \
    }
*/

namespace lctools {

template <typename T>
struct IsIterateable {
    CheckMemberMethod(HasBegin, begin);
    CheckMemberMethod(HasEnd, end);
    static constexpr bool value = HasBegin<T>::value && HasEnd<T>::value;
};

template <typename T>
struct IsBaseContainer : public IsIterateable<T> {
    CheckMemberType(HasValueType, value_type);
    CheckMemberType(HasReference, reference);
    CheckMemberType(HasIterator, iterator);
    CheckMemberType(HasConstReference, const_reference);
    CheckMemberType(HasConstIterator, const_iterator);
    CheckMemberType(HasSizeType, size_type);

    static constexpr bool value = IsIterateable<T>::value && HasValueType<T>::value &&
                                  HasConstIterator<T>::value && HasSizeType<T>::value &&
                                  HasReference<T>::value && HasConstReference<T>::value &&
                                  HasIterator<T>::value;
};

template <typename T>
struct IsContainer : public IsBaseContainer<T> {
    CheckMemberType(HasDifferenceType, difference_type);
    static constexpr bool value = IsBaseContainer<T>::value && HasDifferenceType<T>::value &&
                                  !std::is_convertible_v<T, std::string>;
};

template <typename T>
struct IsInitializerList : public IsBaseContainer<T> {
    static constexpr bool value = IsBaseContainer<T>::value;
};

template <typename T>
struct IsBaseAssociativeContainer : public IsContainer<T> {
    CheckMemberType(HasKeyType, key_type);
    static constexpr bool value = IsContainer<T>::value && HasKeyType<T>::value;
};

template <class T>
struct IsToStringable {
    CheckMemberMethod(Has_to_string, to_string);
    CheckMemberMethod(Has_toString, toString);
    CheckMemberMethod(Has_ToString, ToString);

    static constexpr bool to_string_value = Has_to_string<T>::value;
    static constexpr bool toString_value = Has_toString<T>::value;
    static constexpr bool ToString_value = Has_ToString<T>::value;

    static constexpr bool value = to_string_value || toString_value || ToString_value;
};

template <typename T>
struct IsPair {
    CheckMemberType(HasFirstType, first_type);
    CheckMemberType(HasSecondType, second_type);
    static constexpr bool value = HasFirstType<T>::value && HasSecondType<T>::value;
};

class Formatter {
    template <class Container>
    static std::string Build(Container&& container) {
        std::string res;
        for (auto&& e : std::forward<Container>(container))
            res += ToString(std::move(e)) + list_separator;
        res.erase(res.end() - list_separator.length(), res.end());
        return res;
    }

    template <class Tuple, std::size_t N>
    struct TupleHelper {
        static constexpr std::string print(Tuple&& t) {
            return TupleHelper<Tuple, N - 1>::print(std::forward<Tuple>(t)) + ", " +
                   ToString(std::get<N - 1>(std::forward<Tuple>(t)));
        }
    };

    template <class Tuple>
    struct TupleHelper<Tuple, 1> {
        static constexpr std::string print(Tuple&& t) {
            return ToString(std::get<0>(std::forward<Tuple>(t)));
        }
    };

    template <class Tuple>
    struct TupleHelper<Tuple, 0> {
        static constexpr std::string print(Tuple&& t) { return ""; }
    };

    template <class Variant, std::size_t N>
    struct VariantHelper {
        static constexpr std::string print(Variant&& v) {
            if (N - 1 == v.index())
                return ToString(std::get<N - 1>(std::forward<Variant>(v)));
            else
                return VariantHelper<Variant, N - 1>::print(std::forward<Variant>(v));
        }
    };

    template <class Variant>
    struct VariantHelper<Variant, 1> {
        static constexpr std::string print(Variant&& v) {
            return ToString(std::get<0>(std::forward<Variant>(v)));
        }
    };

public:
    template <class T,
              typename std::enable_if_t<std::is_arithmetic_v<std::remove_reference_t<T>> &&
                                            !std::is_same_v<std::remove_reference_t<T>, char>,
                                        int> = 0>
    static std::string ToString(T&& e) {
        return std::to_string(std::forward<T>(e));
    }

    template <class T,
              typename std::enable_if_t<std::is_same_v<std::remove_reference_t<T>, char>, int> = 0>
    static std::string ToString(T&& e) {
        return std::string{std::forward<T>(e)};
    }

    template <class T, typename std::enable_if_t<std::is_convertible_v<T, std::string>, int> = 0>
    static std::string ToString(T&& e) {
        return "\"" + std::string{std::forward<T>(e)} + "\"";
    }

    template <class Pair, typename std::enable_if_t<IsPair<Pair>::value, int> = 0>
    static std::string ToString(Pair&& e) {
        return "{" + ToString(std::move(e.first)) + ": " + ToString(std::move(e.second)) + "}";
    }

    template <
        class Container,
        typename std::enable_if_t<
            IsIterateable<Container>::value && !IsBaseAssociativeContainer<Container>::value &&
                !IsToStringable<Container>::value && !std::is_convertible_v<Container, std::string>,
            int> = 0>
    static std::string ToString(Container&& container) {
        return "[" + Build(std::forward<Container>(container)) + "]";
    }

    template <class Container,
              typename std::enable_if_t<IsIterateable<Container>::value &&
                                            IsBaseAssociativeContainer<Container>::value &&
                                            !IsToStringable<Container>::value,
                                        int> = 0>
    static std::string ToString(Container&& container) {
        return "{" + Build(std::forward<Container>(container)) + "}";
    }

    template <class T, size_t N>
    static std::string ToString(T (&array)[N]) {
        if constexpr (std::is_same_v<std::remove_const_t<T>, char>)
            return ToString(std::move(array));
        else
            return "[" + Build(std::move(array)) + "]";
    }

    template <class T, typename std::enable_if_t<IsToStringable<T>::value, int> = 0>
    static std::string ToString(T&& e) {
        if constexpr (IsToStringable<T>::ToString_value) return std::forward<T>(e).ToString();
        if constexpr (IsToStringable<T>::toString_value) return std::forward<T>(e).toString();
        if constexpr (IsToStringable<T>::to_string_value) return std::forward<T>(e).to_string();
    }

    template <
        class Tuple, int N = std::tuple_size<std::remove_reference_t<Tuple>>::value,
        typename std::enable_if_t<!IsContainer<Tuple>::value && !IsPair<Tuple>::value, int> = 0>
    static std::string ToString(Tuple&& tuple) {
        return "(" + TupleHelper<Tuple, N>::print(std::forward<Tuple>(tuple)) + ")";
    }

    template <class... Args>
    static std::string ToString(std::variant<Args...>&& var) {
        return VariantHelper<std::variant<Args...>,
                             std::variant_size_v<std::variant<Args...>>>::print(std::move(var));
    }

    template <class... Args>
    static std::string ToString(std::variant<Args...>& var) {
        return VariantHelper<std::variant<Args...>,
                             std::variant_size_v<std::variant<Args...>>>::print(var);
    }

    /*
     template <
         class Variant, int N = std::variant_size<std::remove_reference_t<Variant>>::value,
         typename std::enable_if_t<!IsContainer<Variant>::value && !IsPair<Variant>::value, int> =
     0> static std::string ToString(Variant&& var) { return VariantHelper<Variant,
     N>::print(std::forward<Variant>(var));
     }
     */

    template <class Arg, class... Args>
    static std::string ToString(Arg&& arg, Args&&... args) {
        return ToString(std::forward<Arg>(arg)) + list_separator +
               ToString(std::forward<Args>(args)...);
    }

    template <class Arg, class... Args>
    static std::string ToStringLines(Arg&& arg, Args&&... args) {
        return ToString(std::forward<Arg>(arg)) + "\n" + ToStringLines(std::forward<Args>(args)...);
    }

    template <class Arg>
    static std::string ToStringLines(Arg&& arg) {
        return ToString(std::forward<Arg>(arg));
    }

    template <class S>
    static void SetListSeparator(S&& s) {
        list_separator = std::forward<S>(s);
    }

private:
    inline static std::string list_separator = ", ";
};

}  // namespace lctools

#endif