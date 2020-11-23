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

  const cl::Platform& platform = platforms[0];

  std::vector<cl::Device> devices;
  err = platform.getDevices(CL_DEVICE_TYPE_GPU, &devices);
  assert(err == 0);

  for (const auto& d : devices) {
    std::cout << "--------------------" << std::endl;
    std::cout << "name: " << d.getInfo<CL_DEVICE_NAME>() << "\n";
    std::cout << "vendor: " << d.getInfo<CL_DEVICE_VENDOR>() << "\n";
    std::cout << "extensions: " << d.getInfo<CL_DEVICE_EXTENSIONS>() << "\n";
    std::cout << "global mem size in MB: "
              << d.getInfo<CL_DEVICE_GLOBAL_MEM_SIZE>() / 1024.f / 1024.f
              << "\n";
    std::cout << "address bits: " << d.getInfo<CL_DEVICE_ADDRESS_BITS>()
              << "\n";
    std::cout << "available: " << d.getInfo<CL_DEVICE_AVAILABLE>() << "\n";
    std::cout << "compiler available: "
              << d.getInfo<CL_DEVICE_COMPILER_AVAILABLE>() << "\n";
  }
}
