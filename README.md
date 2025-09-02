
conan remote add emilcode-conan https://emilcodedev.jfrog.io/artifactory/api/conan/emilcode-conan

### Cross compilation
# install the dependencies with two profiles, fmt will be built for the raspberry profile

conan profile detect --name=profile_build_detected

conan install . --build missing --profile:build=profile_build_detected --profile:host=./profiles/profile_host_ubuntu24 
(For now you will need your jfrog remote username and password/token in the installation step to access the embedded-lib package)

# activate the build environment so that we use the selected CMake version for building

source build/Release/generators/conanbuild.sh

# build our application for the Raspberry Pi

cmake --preset=conan-release

cmake --build --preset=conan-release

# check that we built the correct architecture

file ./build/Release/src/embeddedapp


### Create documentation
cd doc
doxygen Doxyfile
sphinx-build ./source ./build