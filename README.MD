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

## CMake > 3.13 ## 
Needed for the command target 
Download newest cmake version from https://cmake.org/download/

Remove old version if present
```
sudo apt remove cmake
```

Unpack
```
cd ~/Downloads
tar -xf cmake-3.22.0-rc2.tar.gz
```

Install
```
cd cmake-3.22.0-rc2
./bootstrap
make
make install
```

Add cmake to PATH
```
export PATH=$PATH:/usr/local/share/cmake-3.22
```

# Upgrade Python to 3.8 on Debian 9 #
https://linuxize.com/post/how-to-install-python-3-8-on-debian-10/

Install the necessary packages to build Python source
```
sudo apt install build-essential zlib1g-dev libncurses5-dev libgdbm-dev libnss3-dev libssl-dev libsqlite3-dev libreadline-dev libffi-dev curl libbz2-dev
```


Download the latest source code from the Python download page with wget.

```
cd ~/Downloads
wget https://www.python.org/ftp/python/3.8.12/Python-3.8.12.tgz
```

When the download is complete, extract the tarball.
```
tar -xf Python-3.8.12.tgz
```

Navigate to the Python source directory and run the configure script.
```
cd Python-3.8.12
./configure --enable-optimizations
```

Run make to start the build process
```
make -j 4
```

Once the build is done, install the Python binaries by running the following command as a user with sudo access. **Do not use the standard make install as it will overwrite the default system python3 binary.**

```
sudo make altinstall
```

Verify the installation
```
python3.8 --version
```

You can install packages using the corresponsing pip module.
```
python3.8 -m pip install trimesh
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

Download **opencascade-7.5.0.tar.gz**, then unpack and build it with **cmake**

```
cd ~/Downloads
tar xf opencascade-7.5.0.tgz
mkdir occt
cd occt
cmake ../opencascade-7.5.0
make
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
cmake_minimum_required(VERSION 3.7)

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