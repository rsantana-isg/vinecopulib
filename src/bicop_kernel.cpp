// Copyright © 2017 Thomas Nagler and Thibault Vatter
//
// This file is part of the vinecopulib library and licensed under the terms of
// the MIT license. For a copy, see the LICENSE file in the root directory of
// vinecopulib or https://tvatter.github.io/vinecopulib/.

#include "bicop_kernel.hpp"
#include "tools_stats.hpp"

namespace vinecopulib
{
    KernelBicop::KernelBicop()
    {
        // construct default grid (equally spaced on Gaussian scale)
        int m = 30;
        VecXd grid_points(m);
        for (int i = 0; i < m; ++i)
            grid_points(i) = - 3.25 + i * (6.25 / (double) m);
        grid_points = pnorm(grid_points);

        interp_grid_ = InterpolationGrid(grid_points, MatXd::Constant(30, 30, 1.0));
    }

    VecXd KernelBicop::pdf_default(const MatXd& u)
    {
        return interp_grid_.interpolate(u);
    }
    VecXd KernelBicop::hfunc1_default(const MatXd& u)
    {
        return interp_grid_.intergrate_1d(u, 1);
    }
    VecXd KernelBicop::hfunc2_default(const MatXd& u)
    {
        return interp_grid_.intergrate_1d(u, 2);
    }
    VecXd KernelBicop::hinv1_default(const MatXd& u)
    {
        return hinv1_num(u);
    }
    VecXd KernelBicop::hinv2_default(const MatXd& u)
    {
        return hinv2_num(u);
    }

    // TODO
    double KernelBicop::parameters_to_tau(const VecXd &)
    {
        throw std::runtime_error(
                "parameters_to_tau not yet implemented for kernel estimator"
        );
    }

    double KernelBicop::calculate_npars()
    {
        return npars_;
    }

    void KernelBicop::flip()
    {
        interp_grid_.flip();
    }
}
