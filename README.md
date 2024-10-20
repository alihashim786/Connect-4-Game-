# Connect 4 - Two Player Game

A simple implementation of the two-player game **Connect 4**, where players take turns dropping tokens into a board of customizable size. The game continues until one player wins by connecting four tokens in a row or the board is completely filled.


## Game Overview
Connect 4 is a two-player connection game where players take turns dropping tokens into a vertical board with a set width and height. The first player to form a horizontal, vertical, or diagonal line of four consecutive tokens wins the game.

This version allows players to:
- Set the width and height of the board.
- Use tokens represented by `+` for Player 1 and `x` for Player 2.
- Fill empty slots with `_` to indicate a blank space.

The game ends when either one player wins by connecting four tokens, or the board gets filled without any player winning.

## Features
- **Customizable board size**: Players can adjust the width and height of the Connect 4 board.
- **Turn-based gameplay**: Players alternate turns, dropping their respective tokens (`+` or `x`) into the board.
- **Victory conditions**: The game detects wins when a player connects four tokens in a row (horizontally, vertically, or diagonally).
- **Board visualization**: The game board is represented using characters: 
  - `+` for Player 1
  - `x` for Player 2
  - `_` for blank spaces

## How to Play
1. **Set the board size**: Before starting the game, players choose the width and height of the board.
2. **Take turns**: Player 1 (`+`) and Player 2 (`x`) take turns to drop their token into one of the columns.
3. **Winning conditions**: The game checks for four consecutive tokens either horizontally, vertically, or diagonally. If no player has won when the board is full, the game ends in a draw.

## Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/connect4.git
    ```
2. Navigate to the project directory:
    ```bash
    cd connect4
    ```
3. Compile the source code (example for C or C++):
    ```bash
    gcc connect4.c -o connect4
    ```
4. Run the game:
    ```bash
    ./connect4
    ```

## Usage
To implement the game logic, there is a function that accepts a 2D pointer to a char array representing the board. The function handles gameplay mechanics such as player turns and checks for winning conditions.

You can start the game by setting up the board size and then taking turns to drop your tokens.

## Further Information
To learn more about the game mechanics and rules, visit the official Wikipedia page for [Connect 4](https://en.wikipedia.org/wiki/Connect_Four).

---

Enjoy the game and feel free to contribute to this project by submitting issues or pull requests!

## <img src="https://img.icons8.com/ios/50/000000/email-open.png" width="20"/> Contact:
If you have any queries, feel free to email me at [muhammadalihashim514@gmail.com](mailto:muhammadalihashim514@gmail.com) or [i220554@nu.edu.pk](mailto:i220554@nu.edu.pk).

Feel free to connect with me on [LinkedIn](https://www.linkedin.com/in/muhammad-ali-hashim-5115882b4) to stay in touch and network.

