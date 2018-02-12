#include <boost/python.hpp>
#include <scitbx/array_family/tiny_types.h>
#include <scitbx/array_family/small.h>
#include <scitbx/array_family/versa.h>
#include <scitbx/array_family/shared.h>
#include <scitbx/array_family/ref.h>
#include <scitbx/array_family/accessors/c_grid.h>
#include <scitbx/array_family/shared.h>
#include <scitbx/array_family/flex_types.h>
#include <scitbx/array_family/boost_python/flex_wrapper.h>
#include <scitbx/array_family/accessors/c_grid.h>
#include <scitbx/vec3.h>
#include <scitbx/mat3.h>
#include <cctype>
#include <complex>
#include <cmath>

namespace fractbx {
  namespace ext {

    // discover mandelbrot set

    static size_t iterations(std::complex<double> c)
    {
      std::complex<double> z = 0;
      size_t jmax = 256;
      for (size_t j = 0; j < 256; j++) {
        z = z * z + c;
        if (std::abs(z) > 2) {
          return j;
        }
      }
      return jmax;
    }

    static scitbx::af::versa< int, scitbx::af::c_grid<2> > make_flex(size_t n)
    {
      scitbx::af::c_grid<2> grid(n, n);
      scitbx::af::versa< int, scitbx::af::c_grid<2> > result(grid, 0);
      double scale = 4.0 / (n - 1);
      int off = (n - 1) / 2;
      for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
          std::complex<double> c(scale * (i - off), scale * (j - off));
          result(j, i) = iterations(c);
        }
      }
      return result;
    }

    void init_module()
    {
      using namespace boost::python;
      def("make_flex", make_flex, (arg("size")));
    }

  }
} // namespace fractbx::ext

BOOST_PYTHON_MODULE(fractbx_ext)
{
  fractbx::ext::init_module();
}
