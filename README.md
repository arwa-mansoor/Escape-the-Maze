# 🧩 Escape the Maze Game

An exciting Escape the Maze game where players navigate through a maze filled with obstacles and aim to reach the destination. Built in C, this game is designed for players of all skill levels, with multiple difficulty levels to choose from.

---

## 🛠️ **Technologies Used** 💻

This project uses several technologies to provide a seamless and engaging user experience. Below are the key technologies used to build the Escape the Maze game:

- **C Programming Language** 🖥️  
  This project uses several technologies to provide a seamless and engaging user experience. Below are the key technologies used to build the Escape the Maze game:

- **Standard C Libraries** 📚  
  - `stdio.h`: Used for input and output operations, displaying the game grid and taking user input.
  - `stdlib.h`: Used for input and output operations, displaying the game grid and taking user input.
  - `time.h`: Used for seeding the random number generator.

- **Windows API** 🖥️  
  `windows.h`: Used to clear the screen between moves, improving the user interface experience.

---

## 🔧 Features
- **Multiple Difficulty Levels**: Choose from Easy, Medium, and Hard difficulty, each with unique maze sizes and obstacle counts. 
- **Maze Navigation**: Use 'W', 'A', 'S', 'D' keys to navigate the maze. 
- **Obstacles**: Avoid obstacles scattered throughout the maze that block your path. 
- **Exit**: Reach the end of the maze to win, or choose to quit anytime.

---

## ⚙️ How to Play
1. **Start the Game**: When the game starts, choose a difficulty level (Easy, Medium, Hard).
2. **Navigate the maze**: Use the following keys to move:
  - `W` : Move Up
  - `S` : Move Down
  - `A` : Move Left
  - `D` : Move Right
  - `Q` : Quit
4. **Avoid Obstacles:**: Be careful not to hit obstacles as you move around the maze.
5. **Reach the End:**: Your goal is to reach the destination (marked with 'H') to win the game.

---

## 📸 **Screenshots** 📷

Here are some screenshots showcasing different stages of Escape the Maze game:

 - 1. **Category Selection**  
   This screenshot shows the main menu where you can select the difficulty level (Easy, Medium, Hard) to start the game.

    ![image](https://github.com/user-attachments/assets/65e99faf-a8f6-4c6d-b432-6cbc5485d255) 

 - 2. **Gameplay**  
   Once you start the game, the maze appears on the screen, and you can move the player `P` to avoid obstacles `X` and reach the exit `H`.

    ![image](https://github.com/user-attachments/assets/5fb53cd7-044d-4095-83da-9d8013bd6c85)

---

## 🚀 How to Run
### Requirements:
- **C Compiler** (e.g., GCC)
  
### Steps:
- 1. **Download the Files**: Make sure you have the source code.
    
- 2. **Compile the Code**:
   ```bash
   gcc EscapeTheMaze.c -o maze_game
   
- 3. **Run the Game**:
   ````bash
   ./maze_game

- 4. **Follow the Prompts**: Choose the difficulty level and start navigating the maze.

---

## 🧩 **Future Enhancements** 🔮

The current version of the Escape the Maze game includes the core gameplay and various difficulty levels. In the future, we plan to enhance the game with the following features:

 1. **Custom Maze Generator** 🔄
   - Allow players to generate custom mazes with different shapes and sizes.
   
   **Implementation:** Add an option for players to choose maze size and layout before starting the game.

- 2. **Timer for Gameplay** ⏱️
   - Add a timer to challenge players to complete the maze in the shortest time possible.

   **Implementation:** Display a countdown timer during gameplay and track the player's time to finish the maze.

- 3. **Sound Effects** 🎶
   - Add sound effects for movement, hitting obstacles, and winning/losing the game.

   **Implementation:**  Integrate audio files and use an appropriate library (e.g., SDL_mixer) to play sounds.

- 4. **Graphical User Interface (GUI)** 💻
   - Transition from a text-based game to a GUI for a more interactive experience.

   **Implementation:** Use a graphics library like SFML or SDL to create a visual representation of the maze and player movement.

- 5. **Multiplayer Mode** 👫
   - Introduce a two-player mode where two players can race through the maze to reach the exit.

   **Implementation:**  Each player controls their own character, and the first to reach the exit wins.

- 6. **Maze Themes** 🌈
   - Add different themes for the maze (e.g., dark mode, festive mode) for variety.

   **Implementation:** Allow players to select a theme before starting the game, altering the appearance of the maze and obstacles.

- 7. **High Score Tracking** 🏆
   - Track the fastest times for each difficulty level and display a leaderboard.

   **Implementation:** Store and display the fastest completion times in a file or database.

---

## 💬 Feedback

Your feedback is important to us! If you have any suggestions or encounter any issues, please feel free to open an issue in the GitHub repository or reach out to us directly.

Thank you for playing and good luck escaping the maze! 🎉

