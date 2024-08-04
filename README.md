# segfault

So far unsuccessful ttempt to create a minimal reproducible example of a segfault [here](https://github.com/virgesmith/neworder/pull/87). Only occurs on Windows builds.

```sh
pip install pybind11 setuptools
python setup.py install
python test.py
```

NB Compiling in linux with address sanitiser enabled and running:

```sh
LD_PRELOAD=$(gcc --print-file-name=libasan.so) pytest -s test.py
```

detects:

```txt
test.py ==77651==AddressSanitizer CHECK failed: ../../../../src/libsanitizer/asan/asan_interceptors.cpp:335 "((__interception::real___cxa_throw)) != (0)" (0x0, 0x0)
    #0 0x707481ebd9a8 in AsanCheckFailed ../../../../src/libsanitizer/asan/asan_rtl.cpp:74
    #1 0x707481ede32e in __sanitizer::CheckFailed(char const*, int, char const*, unsigned long long, unsigned long long) ../../../../src/libsanitizer/sanitizer_common/sanitizer_termination.cpp:78
    #2 0x707481e395a4 in __interceptor___cxa_throw ../../../../src/libsanitizer/asan/asan_interceptors.cpp:335
    #3 0x70747dbbd823 in test_sqrt(double) [clone .cold] (/home/az/dev/segfault/.venv3.12-segfault/lib/python3.12/site-packages/segfault-0.0.0-py3.12-linux-x86_64.egg/example.cpython-312-x86_64-linux-gnu.so+0x9823)
```

but Win tests do not segfault. Perhaps a red herring?


