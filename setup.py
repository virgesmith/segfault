from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, ParallelCompile


ext_modules = [
    Pybind11Extension(
        "example",
        sources=["module.cpp"],
        depends=["setup.py"],
        # extra_compile_args=["-fsanitize=address"],
        cxx_std=20,
    ),
]

ParallelCompile().install()

setup(
    name="segfault",
    ext_modules=ext_modules,
)
