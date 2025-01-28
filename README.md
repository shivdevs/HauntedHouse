# Haunted House Simulation

## Overview

The **Haunted House Simulation** is a C++ project that delivers an immersive and interactive experience where different types of attendees (Adults, Kids, and Dogs) navigate through a haunted house maze. Each attendee type encounters unique interactions and maze elements, offering a distinct and engaging gameplay experience. The project leverages advanced object-oriented programming principles such as inheritance, polymorphism, and custom data structures, including an **Array of Linked Lists**, **Circular Linked Lists**, and **Vectors**.

---

## Features

### Attendee Types
1. **Adults**:
   - Navigate a maze filled with skeleton traps, eerie sound effects, and actors in costumes.
   - Interact with traps and record reactions during their journey.
   - Maze implemented using an **Array of Linear Linked Lists** (Adjacency List).

2. **Kids**:
   - Collect candies, explore dark corners, and face spooky props.
   - Experience a kid-friendly maze implemented with a **Circular Linked List**.

3. **Dogs**:
   - Follow trails of treats, drink water, and use guiding lights to progress through the maze.
   - Maze implemented using a **Vector-based structure**.

---

## Project Structure

### Core Files
- **`haunted_house.h`**:
  - Contains declarations for all classes, including `Attendees` (base class), `Adults`, `Kids`, `Dogs`, and supporting data structure classes (`ARR_LLL`, `CLL`, and `Vec`).

- **`haunted_house.cpp`**:
  - Main driver program that simulates the haunted house experience for Adults, Kids, and Dogs.
  - Features a menu-driven interface for selecting attendee types and testing functionality.

### Class Hierarchy
1. **Base Class**:
   - `Attendees`: Manages shared attributes and behaviors for all attendee types (e.g., name, rating, and interaction tracking).
2. **Derived Classes**:
   - `Adults`: Implements adult-specific maze elements and interactions.
   - `Kids`: Focuses on candy collection and navigating spooky props.
   - `Dogs`: Provides interactions with treats, water, and guiding lights.

### Data Structures
1. **Array of Linear Linked Lists (`ARR_LLL`)**:
   - Represents a graph structure for the adult maze.
   - Uses `AdultNode` objects for adjacency lists.

2. **Circular Linked List (`CLL`)**:
   - Represents the kids' maze.
   - Uses `KidNode` objects to create a looped maze structure.

3. **Vector (`Vec`)**:
   - Represents the dogs' maze.
   - Stores `Dogs` objects and their associated maze elements.

---

## How to Run

### Prerequisites
- A C++ compiler that supports C++11 or later (e.g., `clang++` or `g++`).
- Ensure the Command Line Tools for Xcode are installed on macOS (`xcode-select --install`).

### Compilation
Use the following command to compile the program:
```bash
clang++ -std=c++11 haunted_house.cpp arr_lll.cpp cll.cpp vec.cpp attendees.cpp adults.cpp kids.cpp dogs.cpp node.cpp -o haunted_house
```

### Running the Program
```bash
./haunted_house
```

---

## Gameplay Instructions

1. **Select an Attendee Type**:
   - Choose between Adults, Kids, or Dogs.
   - Each attendee type has a unique maze experience tailored to their characteristics.

2. **Navigate the Maze**:
   - Adults: Interact with skeletons, traps, sound effects, and actors.
   - Kids: Collect candies and avoid scary props.
   - Dogs: Follow trails of treats, drink water, and use guiding lights.

3. **Test Features**:
   - Menu options allow testing for adding nodes, retrieving data, removing elements, and displaying the maze.

4. **Record Reactions**:
   - Adults can record their reactions after encountering props.
   - Kids and Dogs provide feedback on candies and treats.

---

## Example Menu Flow

- **Main Menu**:
  - Choose attendee type (Adults, Kids, or Dogs).
  - Select actions such as navigating the maze, displaying nodes, or testing features.

- **Sample Interaction**:
  - Adults may encounter:
    ```
    A skeleton jumps out!
    Scary sounds play in the distance...
    How do you feel? <Enter reaction>
    ```

---

## Key Concepts and Techniques

1. **Object-Oriented Design**:
   - Extensive use of inheritance and polymorphism for modular design.
   - Dynamic memory management with copy constructors, assignment operators, and destructors for robust functionality.

2. **Custom Data Structures**:
   - Array of Linked Lists for Adults.
   - Circular Linked List for Kids.
   - Vector for Dogs.

3. **Interactive Simulation**:
   - Real-time interaction with maze elements for attendees.
   - Randomized elements enhance replayability and engagement.

---

## Future Improvements

- Add more attendee types with unique abilities and challenges.
- Enhance the graphical interface for a more immersive experience.
- Introduce multiplayer functionality or AI-driven attendees for dynamic gameplay.

---

## Author

**Harshiv Mistry**  
Date: October 29, 2024  

---
