// Copyright © 2017 Thomas Nagler and Thibault Vatter
//
// This file is part of the vinecopulib library and licensed under the terms of
// the MIT license. For a copy, see the LICENSE file in the root directory of
// vinecopulib or https://vinecopulib.github.io/vinecopulib/.

#pragma once

#include <functional>
#include <vinecopulib/misc/tools_eigen.hpp>

namespace vinecopulib {

namespace tools_integration {

    double integrate_zero_to_one(std::function<double(double)> f);
    Eigen::Matrix<double, Eigen::Dynamic, 2> legendre_rule(size_t N = 25);

}

}
