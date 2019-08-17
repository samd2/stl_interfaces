// Copyright (C) 2019 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOST_STL_INTERFACES_VIEW_TESTING_HPP
#define BOOST_STL_INTERFACES_VIEW_TESTING_HPP

#include <boost/stl_interfaces/view_interface.hpp>


template<typename Iterator, typename Sentinel, bool Contiguous>
struct subrange
    : boost::stl_interfaces::
          view_interface<subrange<Iterator, Sentinel, Contiguous>, Contiguous>
{
    subrange() = default;
    constexpr subrange(Iterator it, Sentinel s) : first_(it), last_(s) {}

    constexpr auto begin() const { return first_; }
    constexpr auto end() const { return last_; }

private:
    Iterator first_;
    Sentinel last_;
};

template<bool Contiguous, typename Iterator, typename Sentinel>
auto range(Iterator i, Sentinel s)
{
    return subrange<Iterator, Sentinel, Contiguous>(i, s);
}

#endif
