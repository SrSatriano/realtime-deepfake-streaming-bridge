# Real-Time Deepfake Streaming Bridge

Pipeline GPU: webcam → face swap/avatar → câmera virtual (<100ms) para OBS.

## Stack

- C++, CUDA, OpenCV, WebRTC

## Pipeline

```
Webcam ──► CUDA preprocess ──► Model inference ──► Blend ──► Virtual cam
   │              │                    │
   └──────────────┴────────────────────┘
              < 100ms target
```

## VRAM

| Resolução | VRAM estimada |
|-----------|---------------|
| 720p | ~2 GB |
| 1080p | ~4 GB |

Estratégias: batch=1, FP16, TensorRT engine — [docs/VRAM.md](docs/VRAM.md)

## Build

```bash
cmake -B build -DUSE_CUDA=ON
cmake --build build
./build/deepfake_bridge --virtual-cam obs
```

## Estrutura

| Pasta | Função |
|-------|--------|
| `src/capture/` | OpenCV |
| `src/inference/` | ONNX/TRT |
| `src/output/` | Virtual camera |
