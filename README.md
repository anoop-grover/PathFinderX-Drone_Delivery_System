# 🚁 PathFinderX – Drone Delivery System

> **"Combining Algorithms with Imagination to Solve Real-World Problems."**

---

## 🌟 Project Overview
PathFinderX - Drone Delivery System is a real-world inspired major project built for the **Data Structures & Algorithms** course. It simulates a drone delivery system over a grid-based city map using **Breadth-First Search (BFS)** to find the shortest path between multiple delivery stops, while avoiding obstacles and staying within a battery limit.

Whether you're planning a smart city delivery network or just mastering DSA, this project fuses logic, design, and interactivity.

---

## 🚀 Features
- 📍 Grid-based city layout (customizable size)
- 🚫 Obstacle detection & avoidance
- 🛫 Source and 🛬 Destination points
- 📦 Multiple delivery stops
- 🧠 Shortest path finding using **BFS**
- 🔋 Battery constraint handling
- 📊 Visual grid output (`S`, `D`, `P`, `*`, `X`)
- 🌐 HTML-based animated visualizer (for demos)

---

## 📁 Folder Structure
```
PathFinderX-Drone_Delivery_System/
│
├── code/
│   ├── PathFinderX.cpp             # C++ source code (core DSA logic)
│   └── pathfinderx_visual.html    # Optional visual demo (HTML animation)
│
├── report/                        # Final report (DOC/PDF)
│
├── ppt/                           # Project presentation slides
│
└── README.md                      # This file!
```

---

## 💻 How to Run the Code
**C++ Console Simulation:**
1. Open terminal in `code/` folder
2. Compile: `g++ PathFinderX.cpp -o drone`
3. Run: `./drone`
4. Follow on-screen prompts (grid size, source, delivery points, etc.)

**HTML Animation Demo:**
1. Open `pathfinderx_visual.html` in any browser
2. Watch the path animate over the grid

> 💡 *Note: Update the HTML `path[]` with actual coordinates from your C++ output for a custom animation.*

---

## 📚 Algorithms & Data Structures Used
- 🔁 **Breadth-First Search (BFS)** – for shortest path
- 🧮 **2D Arrays** – grid modeling
- 🧺 **Queue** – BFS traversal
- 🧩 **Vector of Pairs** – for storing path & delivery points

---

## 🔮 Future Enhancements
- 🚀 Switch to A* or Dijkstra for weighted pathfinding
- 🛰️ Add real-time map layers (e.g. weather zones)
- ⚡ Optimize energy usage per step
- 📡 Connect to real-world map APIs

---

## 🧑‍💻 Developed By
**[Anoop Grover]**  
B.Tech CSE – [Lovely Professional University]  
🗓️ Summer Training Project, July 2025

---

## ⭐ GitHub Tags
`#cpp` `#bfs` `#graph-algorithms` `#drone-routing` `#dsa-project` `#html-visualizer`
