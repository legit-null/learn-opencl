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

  cl::Context context(devices, nullptr, nullptr, nullptr, &err);
  assert(err == 0);

  std::cout << "--------------------" << std::endl;
  std::cout << "num devices: " << context.getInfo<CL_CONTEXT_NUM_DEVICES>()
            << "\n";
  std::cout << "reference count: "
            << context.getInfo<CL_CONTEXT_REFERENCE_COUNT>() << "\n";
}
