# Maze Generator and pathfinding (C++ & Raylib)

This project is a simple and interactive maze generator and pathfinding visualizer written in C++ using the raylib graphics library. Simple demonstration of concepts of graph traversal and visualization in a grid-based environment.

## Features

- Maze generation using **Depth-First Search (DFS)** backtracking algorithm  
- Pathfinding using **Breadth-First Search (BFS)**
- Fully interactive: click to select the start and end points  
- Real-time visualization of traversal and final path  

---

## Algorithms Used

### Maze Generation
- Uses a randomized **DFS (backtracking)** to create a maze

### Pathfinding
- Implements **BFS** to find the **shortest path**
- Shows visited cells and highlights the final path
  
---

## Controls

- **Left Click** to choose the starting cell for maze generation
- After generation:
  - **Left Click** to select the **start point** for BFS
  - **Left Click again** to select the **end point**
  - BFS runs automatically and visualizes the search and path

---


### Requirements:
- C++20 or newer
- [Raylib](https://www.raylib.com/) installed and linked


---

