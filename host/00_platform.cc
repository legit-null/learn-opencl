// Author: yud.von@gmail.com (legit-null)

#ifndef CL_HPP_TARGET_OPENCL_VERSION
#define CL_HPP_TARGET_OPENCL_VERSION 120
#define CL_HPP_MINIMUM_OPENCL_VERSION 120
#endif

#include <iostream>

#include "CL/opencl.hpp"

int main(int argc, char** argv) {
  std::vector<cl::Platform> platforms;
  cl_int err = cl::Platform::get(&platforms);
  assert(err == 0);

  for (const auto& p : platforms) {
    std::cout << "--------------------" << std::endl;
    std::cout << "name: " << p.getInfo<CL_PLATFORM_NAME>() << "\n";
    std::cout << "vendor: " << p.getInfo<CL_PLATFORM_VENDOR>() << "\n";
    std::cout << "version: " << p.getInfo<CL_PLATFORM_VERSION>() << "\n";
    std::cout << "profile: " << p.getInfo<CL_PLATFORM_PROFILE>() << "\n";
    std::cout << "extensions: " << p.getInfo<CL_PLATFORM_EXTENSIONS>() << "\n";
  }
}
