/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once

#include <type_traits>
#include <tr2/type_traits>

namespace fakeit {
    template<typename ... Type1>
    class has_one_base {
    };

    template<typename Type1, typename Type2, typename ... types>
    class has_one_base<std::tr2::__reflection_typelist<Type1, Type2, types...>> : public std::false_type {
    };

    template<typename Type1>
    class has_one_base<std::tr2::__reflection_typelist<Type1>>
            : public has_one_base<typename std::tr2::direct_bases<Type1>::type> {
    };

    template<>
    class has_one_base<std::tr2::__reflection_typelist<>> : public std::true_type {
    };

    template<typename T>
    class is_simple_inheritance_layout : public has_one_base<typename std::tr2::direct_bases<T>::type> {
    };
}
