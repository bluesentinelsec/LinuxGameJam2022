#!/bin/sh

# this script installs dependencies needed to play
# Liberty Space Battle
# these dependencies include:
# SDL2, SDL_Image, and SDL_Mixer

echo "[i] This script will attempt to install dependencies needed to play Liberty Space Battle."

if [ $(id -u) -ne 0 ]; then
  echo "[!] Please run this script with sudo."
  exit 1
fi

# fedora
if [ -x "$(command -v dnf)" ]; then
  dnf install SDL2{,_image,_mixer}
fi

# old fedora
if [ -x "$(command -v yum)" ]; then
  yum install SDL2{,_image,_mixer}
fi

# debian, ubuntu
if [ -x "$(command -v apt)" ]; then
  apt install libsdl2{,-image,-mixer}
fi

# arch linux
if [ -x "$(command -v pacman)" ]; then
  pacman -S sdl2{,_image,_mixer}
fi

# gentoo
if [ -x "$(command -v emerge)" ]; then
  emerge -av libsdl2 sdl2-{image,mixer}
fi

# macos
if [ -x "$(command -v brew)" ]; then
  brew install sdl2{,_image,_mixer}
fi

echo "[i] Finished installing dependencies."