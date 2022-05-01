# LinuxGameJam2022

This is my repository for the [Linux Game Jam 2022](https://itch.io/jam/linux-game-jam-2022).


## Installation Instructions (Linux)

Open a terminal and run the following commands:

```bash
git clone git@github.com:bluesentinelsec/LinuxGameJam2022.git
cd LinuxGameJam2022
sudo ./install_dependencies.sh # install SDL2, SDL_Image, and SDL_Mixer
./liberty_space_battle
```

## Build from source

1. **You need a C compiler and GNU Make.**

These can easily be installed with most package managers, for example:

```bash
# Debian / Ubuntu
sudo apt install build-essential
```

2. **Install SDL2 development libraries.**

```bash
# Debian / Ubuntu
apt install libsdl2{,-image,-mixer,-ttf,-gfx}-dev
```

```bash
# Fedora
 yum install SDL2{,_image,_mixer}-devel
```

```bash
# MacOS
 brew install sdl2{,_image,_mixer} pkg-config
```

3. **Build source with Make**

```bash
git clone git@github.com:bluesentinelsec/LinuxGameJam2022.git
cd LinuxGameJam2022
make
# ./liberty_space_battle
```

## This software respects your liberty

- No microtransactions
- No data collection
- No advertisements
- No DRM

- You may use this software however you wish
- You may read and change the source code
- You may share your changes with anyone


## This project was created with free software

1. Programming: VS Codium, Vim, Make, gcc, clang
2. Artwork: Gimp
3. Sound: SFXR