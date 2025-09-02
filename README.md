## Embedded App

This repository contains an embedded application designed for cross-compilation. It leverages Conan for dependency management, CMake for building, and includes documentation generation workflows. The project is structured to support modern CI/CD practices and aims to provide a robust foundation for embedded software development.

### Connect to remote conan Artifactory 

```
conan remote add emilcode-conan https://emilcodedev.jfrog.io/artifactory/api/conan/emilcode-conan
conan remote login -p <token> emilcode-conan <username>
```

### Cross compilation
#### install the dependencies with two profiles, embedded-app will be built for the Ubuntu 24 host (host=target) profile

```
conan profile detect --name=profile_build_detected
conan install . --build missing --profile:build=profile_build_detected --profile:host=./profiles/profile_host_ubuntu24 
```

#### Activate the build environment so that we use the selected CMake version for building

```
source build/Release/generators/conanbuild.sh
```

#### Build our application

```
cmake --preset=conan-release
cmake --build --preset=conan-release
```

#### Check that we built the correct architecture

```
file ./build/Release/src/embeddedapp
```

### Create documentation

```
cd doc
doxygen Doxyfile
sphinx-build ./source ./build
```

### Outlook

- [ ] Implement github action for build
- [ ] Implement action for unit tests
- [ ] Implement action for documentation generation