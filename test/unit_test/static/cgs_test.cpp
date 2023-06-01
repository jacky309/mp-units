// The MIT License (MIT)
//
// Copyright (c) 2018 Mateusz Pusz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <mp-units/systems/cgs/cgs.h>
#include <mp-units/systems/isq/mechanics.h>
#include <mp-units/systems/isq/space_and_time.h>
#include <mp-units/systems/si/unit_symbols.h>

template<class T>
  requires mp_units::is_scalar<T>
inline constexpr bool mp_units::is_vector<T> = true;

namespace {

using namespace mp_units;
using namespace mp_units::cgs;
using namespace mp_units::cgs::unit_symbols;

// https://en.wikipedia.org/wiki/Centimetre%E2%80%93gram%E2%80%93second_system_of_units#Definitions_and_conversion_factors_of_CGS_units_in_mechanics
static_assert(isq::length(100 * cm) == isq::length(1 * si::metre));
static_assert(isq::mass(1000 * g) == isq::mass(1 * si::kilogram));
static_assert(isq::time(1 * s) == isq::time(1 * si::second));
static_assert(isq::speed(100 * (cm / s)) == isq::speed(1 * (si::metre / si::second)));
static_assert(isq::acceleration(100 * Gal) == isq::acceleration(1 * (si::metre / square(si::second))));
static_assert(isq::force(100'000 * dyn) == isq::force(1 * si::newton));
static_assert(isq::energy(10'000'000 * erg) == isq::energy(1 * si::joule));
static_assert(isq::power(10'000'000 * (erg / s)) == isq::power(1 * si::watt));
static_assert(isq::pressure(10 * Ba) == isq::pressure(1 * si::pascal));
static_assert(isq::dynamic_viscosity(10 * P) == isq::dynamic_viscosity(1 * (si::pascal * si::second)));
static_assert(isq::kinematic_viscosity(10'000 * St) == isq::kinematic_viscosity(1 * (square(si::metre) / si::second)));
static_assert(isq::wavenumber(1 * K) == isq::wavenumber(100 * (1 / si::metre)));

}  // namespace
