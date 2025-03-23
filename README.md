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