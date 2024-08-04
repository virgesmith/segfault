# segfault

Minimal reproducible example of a segfault seeming caused by throwing an exception from C++ back to python.

Segfault only occurs on Windows build.

NB Compiling with g++ address sanitiser results in a crash in asan


```sh
pip install pybind11 setuptools
python setup.py install
python test.py
```

