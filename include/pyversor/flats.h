// Copyright (c) 2015, Lars Tingelstad
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of pyversor nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include <pybind11/pybind11.h>

#include <pyversor/multivectors.h>

namespace pyversor {

namespace py = pybind11;

namespace cga {

struct flats {
  template <typename flat_t, bool dual, typename module_t = py::module>
  static void add_location(module_t &m) {
    using vsr::cga::Flat;
    using vsr::cga::Round;
    m.def("location", [](const flat_t &a) {
      return Flat::location(a, Round::null(ega::vector_t{0.0, 0.0, 0.0}), dual);
    });
    m.def("location", [](const flat_t &a, const point_t &b) {
      return Flat::location(a, Round::null(b), dual);
    });
  }

  template <typename flat_t, typename module_t = py::module>
  static void add_direction(module_t &m) {
    using vsr::cga::Flat;
    m.def("direction", [](const flat_t &a) { return Flat::direction(a); });
  }
};

// void add_line(py::module &m) {
//   auto t = add_conformal_multivector<line_t>(m, "Line");
//   t.def(py::init<double, double, double, double, double, double>());
//   flat::add_location<line_t, false>(t);
//   flat::add_direction<line_t>(t);
// }

void def_flats(py::module &m);
void def_flat_point(py::module &m);
void def_dual_line(py::module &m);
void def_line(py::module &m);
void def_plane(py::module &m);
void def_dual_plane(py::module &m);

} // namespace cga

} // namespace pyversor