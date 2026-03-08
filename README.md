so_long

so_long is a small 2D game written in C using the MiniLibX graphics library.
The goal of this project is to introduce fundamental concepts of graphical programming, event handling, and game logic while reinforcing clean code practices and memory management.

This project is part of the 42 curriculum.

⸻

Project Overview

In so_long, the player controls a character that must collect all collectibles on a map and reach the exit using the shortest path possible. The game is displayed in a 2D window and is controlled using keyboard inputs.

This project helped me understand how to:
	•	Open and manage graphical windows
	•	Handle keyboard events
	•	Load and display textures and sprites
	•	Parse and validate map files
	•	Implement basic game mechanics in C
	•	Manage memory safely (no leaks, no crashes)

⸻

How the Game Works

Controls:
	•	W → Move up
	•	A → Move left
	•	S → Move down
	•	D → Move right
	•	ESC → Exit the game

⸻

Map Rules

The map must follow strict validation rules:
	•	The map must be rectangular
	•	It must be surrounded by walls
	•	It must contain:
	•	Exactly one player
	•	Exactly one exit
	•	At least one collectible
	•	The map must have a valid path allowing the player to collect all items and reach the exit
