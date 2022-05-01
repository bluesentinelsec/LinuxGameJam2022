#!/bin/sh

# this script installs dependencies needed to play
# Liberty Space Battle
# these dependencies include:
# SDL2, SDL_Image, and SDL_Mixer

echo "[i] This script will attempt to install dependencies needed to play Liberty Space Battle."

# macos
if [ -x "$(command -v brew)" ]; then
  brew install sdl2{,_image,_mixer}
fi

echo "[i] Finished installing dependencies."