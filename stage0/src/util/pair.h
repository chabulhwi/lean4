/*
Copyright (c) 2013 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#pragma once
#include <utility>
#include <lean/serializer.h>

namespace lean {
template<typename T1, typename T2>
using pair = typename std::pair<T1, T2>;

/** \brief Alias for make_pair */
template<typename T1, typename T2>
inline pair<T1, T2> mk_pair(T1 const & v1, T2 const & v2) {
    return std::make_pair(v1, v2);
}

template<typename T1, typename T2>
inline serializer & operator<<(serializer & s, pair<T1, T2> const & p) {
    s << p.first << p.second; return s;
}

template<typename T1, typename T2>
inline deserializer & operator>>(deserializer & d, pair<T1, T2> & p) {
    d >> p.first >> p.second; return d;
}
}
