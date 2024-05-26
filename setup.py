from setuptools import Extension
from setuptools import setup

ext_modules = [
    Extension(
        "_hello", # module will be importable with `import _hello`
        ["src/hello/_hello.cpp"],
    )
]


def main():
    setup(
        name="hello-lib", # defines the package name, not the import name
        version="0.1.0",
        ext_modules=ext_modules,
    )


if __name__ == "__main__":
    main()

