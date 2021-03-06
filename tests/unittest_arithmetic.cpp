#include "unittest_main.h"
#include <cmath>

using namespace std;
using namespace minerva;

TEST(Arithmetic, CpuAdd) {
  auto& ms = MinervaSystem::Instance();
  ms.current_device_id_ = cpu_device;
  Scale size{2, 3, 4, 5, 6};

  auto a = NArray::Randn(size, 0, 5);
  auto b = NArray::Randn(size, 0, 5);
  auto c = a + b;
  auto a_ptr = a.Get();
  auto b_ptr = b.Get();
  auto c_ptr = c.Get();
  for (int i = 0; i < size.Prod(); ++i) {
    EXPECT_FLOAT_EQ(c_ptr.get()[i], a_ptr.get()[i] + b_ptr.get()[i]);
  }
}

TEST(Arithmetic, GpuAdd) {
  auto& ms = MinervaSystem::Instance();
  ms.current_device_id_ = cpu_device;
  Scale size{2, 3, 4, 5, 6};

  auto a = NArray::Randn(size, 0, 5);
  auto b = NArray::Randn(size, 0, 5);
  ms.current_device_id_ = gpu_device;
  auto c = a + b;
  auto a_ptr = a.Get();
  auto b_ptr = b.Get();
  auto c_ptr = c.Get();
  for (int i = 0; i < size.Prod(); ++i) {
    EXPECT_FLOAT_EQ(c_ptr.get()[i], a_ptr.get()[i] + b_ptr.get()[i]);
  }
}

TEST(Arithmetic, CpuSub) {
  auto& ms = MinervaSystem::Instance();
  ms.current_device_id_ = cpu_device;
  Scale size{2, 3, 4, 5, 6};

  auto a = NArray::Randn(size, 0, 5);
  auto b = NArray::Randn(size, 0, 5);
  auto c = a - b;
  auto a_ptr = a.Get();
  auto b_ptr = b.Get();
  auto c_ptr = c.Get();
  for (int i = 0; i < size.Prod(); ++i) {
    EXPECT_FLOAT_EQ(c_ptr.get()[i], a_ptr.get()[i] - b_ptr.get()[i]);
  }
}

TEST(Arithmetic, GpuSub) {
  auto& ms = MinervaSystem::Instance();
  ms.current_device_id_ = cpu_device;
  Scale size{2, 3, 4, 5, 6};

  auto a = NArray::Randn(size, 0, 5);
  auto b = NArray::Randn(size, 0, 5);
  ms.current_device_id_ = gpu_device;
  auto c = a - b;
  auto a_ptr = a.Get();
  auto b_ptr = b.Get();
  auto c_ptr = c.Get();
  for (int i = 0; i < size.Prod(); ++i) {
    EXPECT_FLOAT_EQ(c_ptr.get()[i], a_ptr.get()[i] - b_ptr.get()[i]);
  }
}

TEST(Arithmetic, CpuMult) {
  auto& ms = MinervaSystem::Instance();
  ms.current_device_id_ = cpu_device;
  Scale size{2, 3, 4, 5, 6};

  auto a = NArray::Randn(size, 0, 5);
  auto b = NArray::Randn(size, 0, 5);
  auto c = Elewise::Mult(a, b);
  auto a_ptr = a.Get();
  auto b_ptr = b.Get();
  auto c_ptr = c.Get();
  for (int i = 0; i < size.Prod(); ++i) {
    EXPECT_FLOAT_EQ(c_ptr.get()[i], a_ptr.get()[i] * b_ptr.get()[i]);
  }
}

TEST(Arithmetic, GpuMult) {
  auto& ms = MinervaSystem::Instance();
  ms.current_device_id_ = cpu_device;
  Scale size{2, 3, 4, 5, 6};

  auto a = NArray::Randn(size, 0, 5);
  auto b = NArray::Randn(size, 0, 5);
  ms.current_device_id_ = gpu_device;
  auto c = Elewise::Mult(a, b);
  auto a_ptr = a.Get();
  auto b_ptr = b.Get();
  auto c_ptr = c.Get();
  for (int i = 0; i < size.Prod(); ++i) {
    EXPECT_FLOAT_EQ(c_ptr.get()[i], a_ptr.get()[i] * b_ptr.get()[i]);
  }
}

TEST(Arithmetic, CpuDiv) {
  auto& ms = MinervaSystem::Instance();
  ms.current_device_id_ = cpu_device;
  Scale size{2, 3, 4, 5, 6};

  auto a = NArray::Randn(size, 0, 5);
  auto b = NArray::Randn(size, 0, 5);
  auto c = a / b;
  auto a_ptr = a.Get();
  auto b_ptr = b.Get();
  auto c_ptr = c.Get();
  for (int i = 0; i < size.Prod(); ++i) {
    EXPECT_FLOAT_EQ(c_ptr.get()[i], a_ptr.get()[i] / b_ptr.get()[i]);
  }
}

TEST(Arithmetic, GpuDiv) {
  auto& ms = MinervaSystem::Instance();
  ms.current_device_id_ = cpu_device;
  Scale size{2, 3, 4, 5, 6};

  auto a = NArray::Randn(size, 0, 5);
  auto b = NArray::Randn(size, 0, 5);
  ms.current_device_id_ = gpu_device;
  auto c = a / b;
  auto a_ptr = a.Get();
  auto b_ptr = b.Get();
  auto c_ptr = c.Get();
  for (int i = 0; i < size.Prod(); ++i) {
    EXPECT_FLOAT_EQ(c_ptr.get()[i], a_ptr.get()[i] / b_ptr.get()[i]);
  }
}

