#include <chrono>
#include <cstdio>
#include <thread>

int main(int argc, char** argv) {
  const char* mode = argc > 1 ? argv[1] : "preview";
  std::printf("deepfake bridge mode=%s target_latency_ms=100\n", mode);
  for (int i = 0; i < 3; ++i) {
    auto t0 = std::chrono::steady_clock::now();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    auto ms = std::chrono::duration<double, std::milli>(
        std::chrono::steady_clock::now() - t0).count();
    std::printf("frame %d latency_ms=%.1f\n", i, ms);
  }
  return 0;
}
