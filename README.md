
# Tetris Game

## Description
This project is a classic Tetris game implemented in C++ using the **Raylib** library. The game consists of four main files: `grid.cpp`, `game.cpp`, `block.cpp`, and the entry point `tetris.cpp`.

## Features
- Simple and intuitive Tetris gameplay
- Clear grid, block, and game logic separation for easy understanding and extension

## Installation

### 1. Install Raylib for C++
To get started with the Raylib library for C++ on your system, follow these steps:

#### For Windows:
1. Download the Raylib binaries from the [Raylib official website](https://www.raylib.com/).
2. Set up Raylib in your development environment:
   - **MinGW**:
     - Extract Raylib files.
     - Add the path to `raylib/include` and `raylib/lib` in your MinGW settings.
   - **Visual Studio**:
     - Open your project settings.
     - Add `raylib/include` to the include directories and `raylib.lib` to the linker dependencies.

#### For Linux:
1. Install dependencies:  
   ```bash
   sudo apt install libasound2-dev libglfw3-dev
   ```
2. Clone and build Raylib:
   ```bash
   git clone https://github.com/raysan5/raylib.git
   cd raylib/src
   make PLATFORM=PLATFORM_DESKTOP
   sudo make install
   ```

#### For MacOS:
1. Install Raylib using Homebrew:
   ```bash
   brew install raylib
   ```

### 2. Compile the Game
Once Raylib is installed, you can compile the main file (`tetris.cpp`) along with the other source files using a simple compile command. Here's an example for Linux:

```bash
g++ -o tetris tetris.cpp game.cpp grid.cpp block.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

For Windows, ensure your Raylib environment is set up, and use a similar compile command with the appropriate linker flags.

## Usage
Once compiled, you can run the game with the following command:

```bash
./tetris
```

## File Structure
- `grid.cpp`: Handles the grid system of the Tetris game.
- `game.cpp`: Manages the game logic and flow.
- `block.cpp`: Controls the movement and appearance of the Tetris blocks.
- `tetris.cpp`: The main entry point of the game.

## Contributing
As of now, I am the sole contributor to this project. Contributions are not currently open.
