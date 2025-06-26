# 🏓 Pong Masters

A classic two-player Pong-style game built in C++ using the [raylib](https://www.raylib.com/) library.  
Includes features like score tracking, increasing ball speed, a welcome menu, and game-over screen with a winner announcement.

---

## 🎮 Features

- 🔥 Classic Pong mechanics
- 🎯 Set your own win point limit before playing
- 🚀 Ball speeds up after each paddle hit
- 🌑 Smooth blackout animation before game starts
- 🏁 Game Over screen with WINNER message
- 🎮 Local 2-player controls
- ❌ Exit or 🔁 Restart from the end screen

---

## 🎮 Controls

| Player        | Key Up | Key Down |
|---------------|--------|----------|
| Player 1 (Left) | `W`    | `S`      |
| Player 2 (Right)| `↑`    | `↓`      |

---

## 🧩 Requirements

### ✅ Required:
- [raylib](https://www.raylib.com/) C++ library
- g++ / clang++ compiler
- (Linux) Install via `sudo apt install libraylib-dev`

---

## 🛠️ Build Instructions

### 🔧 Linux / macOS

```bash
make           # Compile the game
make run       # Run the game
make clean     # Clean build files
