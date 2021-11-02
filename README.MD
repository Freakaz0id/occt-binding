# Install VS Code #
Download VS Code for Ubuntu (.deb): https://code.visualstudio.com/download

Install
```
cd ~/Downloads
sudo dpkg -i code_1.61.2-1634656828_amd64.deb
```

# Install Prerequisites #

```
sudo apt-get install git
sudo apt-get install cmake
sudo apt-get install libpython3.8-dev
```

# Install OpenCASCADE #
https://realglitch.com/2020/04/how-to-install-opencascade-7-4-on-ubuntu-18-04-lts/

Install dependencies
```
sudo apt-get install software-properties-common
sudo apt-get install libtool autoconf automake gfortran gdebi
sudo apt-get install gcc-multilib libxi-dev libxmu-dev libxmu-headers
sudo apt-get install libx11-dev mesa-common-dev libglu1-mesa-dev
sudo apt-get install libfontconfig1-dev
sudo apt-get install libfreetype6 libfreetype6-dev
sudo apt-get install tcl tcl-dev tk tk-dev
```

Download **opencascade-7.5.0.tar.gz**, then unpack and build it with **ccmake**

```
cd ~/Downloads
tar xf opencascade-7.5.0.tar.gz
mkdir occt
cd occt
ccmake ../Downloads/opencascade-7.5.0
```

**Copy occt/ to ./externals/occt**

# Setup Module #
Clone pybind to externals

```
mkdir externals
cd externals
git clone https://github.com/pybind/pybind11.git
```

Create source file ./src/**module.cpp**
```cpp
#include <pybind11/pybind11.h>

namespace py = pybind11;

float some_fn(float arg1, float arg2) {
    return arg1 + arg2;
}

// The module name 'spark' must match the module definition in CMakeLists.txt
PYBIND11_MODULE(spark, handle) {
    handle.doc() = "This is a doc";
    handle.def("some_fn", &some_fn);
}
```

Create ./**CMakeLists.txt**

```c#
cmake_minimum_required(VERSION 3.16)

project(pybind_example)

set(EXTERNALS "${PROJECT_SOURCE_DIR}/externals")
set(MODULE_SOURCE "${PROJECT_SOURCE_DIR}/src")
add_subdirectory("${EXTERNALS}/pybind11")

# make sure 'spark' matches the module name
pybind11_add_module("spark" "${MODULE_SOURCE}/module.cpp")
```

# Build #

Make build directory and generate build files
```
mkdir build
cd build
cmake ..
```

Build the files
```
make
```

Test the module in python
```
python3

>>> import spark
>>> spark.some_fn(1,4)
5
```