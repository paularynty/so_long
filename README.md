# Lunchtime with Dragon

## Table of Contents

* [Introduction](#introduction)
* [How it works](#how-it-works)
* [Playing the game](#playing-the-game)

## Introduction
A top-down 2D game built using only C, playable directly from the computer terminal. You play as a baby dragon, whose objective is to collect all of the fruits on the screen, before depositing them in the lunch basket.

The game has been built using C and the MLX42 library, which is an open-source alternative of the miniLibX. This was a mandatory project in the Hive Helsinki curriculum (``so_long``).

The theming and graphics could be chosen freely, so I went with a colorful, cozy vibe.
I designed the sprites for the dragon and the lunch basket, and the rest of the sprites were sourced from [itch.io](https://itch.io).

## How it works
The game follows a strict ruleset:

- The executable ``so_long`` receives one argument, which is a game map of a ``.ber`` (binary file) filetype.
- The map must be square/rectangular, i.e. all rows must be of equal length.
- The map must be closed, i.e. surrounded by walls.
- There must be at least one exit, one player, and one collectible on the map.
- The game map accepts only ``P`` (player), ``1`` (wall), ``0`` (floor), ``C`` (collectible), and ``E`` (exit) characters.
- If any of these checks fail, the game must not render, and display a descriptive error message in the terminal.

## Playing the game

### Installation
```shell
git clone git@github.com:paularynty/so_long.git
cd so_long
make
./so_long [path_to_map_file].ber
```
