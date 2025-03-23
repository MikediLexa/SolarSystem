# ☀️  Solar System – Interactive 2D Universe in Modern OpenGL

Welcome to **Solar System**, a minimalistic but powerful 2D simulation of our planetary system – built from scratch in **C++** using **modern OpenGL (3.3 Core)**.

This project is my hands-on journey into computer graphics, shader programming, and interactive rendering – from raw buffers to smooth orbits.

---

## 🧠 What’s inside?

- ✅ Built with **GLFW**, **GLAD2**, and **GLM**
- ☀️ A central sun and orbiting planets
- 🎛️ Dynamic speed control & interactions
- 🧩 Clean C++ structure (Renderer, Shader, Object, etc.)
- 🔭 Designed to be extended to 3D, ImGui and beyond

---

## 🚀 Why?

I’m learning OpenGL to understand the graphics pipeline at a deep level – not just to draw pretty pixels, but to **master the art of simulation and visual tool development**.  
This repo is my playground. My lab. My launchpad.

---

## 🛠️ Build & Run

### 🔧 Prerequisites
- CMake ≥ 3.10
- A C++17 compiler
- macOS or Linux (Windows coming later)

### ⚙️ Build
```bash
mkdir build
cd build
cmake ..
make
./SolarSystem

## 📦 Dependencies

This repo includes the sources of:

- [GLFW](https://github.com/glfw/glfw)
- [GLAD2](https://gen.glad.sh/)

Both are included under `libs/` for portability and ease of build.  
You don’t need to install anything manually – just clone and build.

---

## 🧠 Key Concepts (Graphics Programming)

This project is not just code – it’s a way to understand the fundamentals of real-time graphics. Here are the most important terms explained:

| Term | Meaning |
|------|---------|
| **Shader** | A small GPU program that controls rendering |
| **Vertex Shader** | Transforms each vertex (e.g. position, rotation, scaling) |
| **Fragment Shader** | Colors each pixel (e.g. texture, lighting) |
| **Vertex** | A point in space used to build geometry |
| **VBO (Vertex Buffer Object)** | Stores vertex data on the GPU |
| **VAO (Vertex Array Object)** | Describes how vertex data is laid out |
| **Uniform** | A global shader variable set from the CPU |
| **Model/View/Projection** | Transformations for objects, camera and perspective |
| **Render Loop** | Main loop for drawing and updating the screen each frame |

This table serves as a quick reference for understanding the graphics pipeline while working on this project.


## 🌌 Universe Scale & Realism

To make the Solar System feel real while keeping it viewable, we've used **real astronomical data scaled down** to fit in OpenGL's coordinate space. The goal is to maintain **proportions** – distances and sizes – between celestial objects without visual distortion.

### 🌍 Planetary Parameters (Simplified)
| Object | Diameter (km) | Distance to Sun (km) |
|--------|----------------|----------------------|
| Sun    | 1,390,000      | 0                    |
| Earth  | 12,742         | 149,600,000          |
| Moon   | 3,474          | 149,984,400 (Sun + Earth-Moon distance) |

### 🧮 Scaling Formula
We scale all distances and sizes by a constant:
```cpp
#define SCALE 1.0f / 1e8f  // 1 OpenGL unit = 100 million kilometers