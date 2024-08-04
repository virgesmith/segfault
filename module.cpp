#include <pybind11/pybind11.h>

namespace py = pybind11;

#include <string>
#include <cmath>

using namespace std::string_literals;

double test_sqrt(double x)
{
  if (x < 0.0)
    throw py::value_error(("x can't be negative: "s + std::to_string(x)).c_str());
  return sqrt(x);
}

PYBIND11_MODULE(example, m)
{
  m.def("sqrt", &test_sqrt, "A function that adds two numbers");

  py::register_exception_translator(
    [](std::exception_ptr p) {
      try {
        py::print("rethrowing...");
        if (p) std::rethrow_exception(p);
      } catch (void* p) {
      }
    }
  );
}


// g++ -g -O3 -Wall -shared -std=c++20 -fPIC $(python3 -m pybind11 --includes) -fsanitize=address module.cpp -o so.so
// g++ g++ -g -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) module.cpp -o so.so

// LD_PRELOAD=$(gcc --print-file-name=libasan.so) python test.py