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
  apt install libsdl2-2.0-0 libsdl2-mixer-2.0-0 libsdl2-image-2.0-0
fi

# arch linux
if [ -x "$(command -v pacman)" ]; then
  pacman -S sdl2{,_image,_mixer}
fi

# gentoo
if [ -x "$(command -v emerge)" ]; then
  emerge -av libsdl2 sdl2-{image,mixer}
fi

echo "[i] Finished installing dependencies."