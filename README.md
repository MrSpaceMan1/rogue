# Rogue - game

This repo aims to create a truly Rogue-like game using 32blit sdk.

# Developing

To start developing, clone the repository along with the submodules:

```
git clone --recurse-submodules git@github.com:MrSpaceMan1/rogue.git
```

Next, install dependencies. For Debian/Ubuntu use:

```
sudo apt install git gcc g++ gcc-arm-none-eabi cmake make \
python3 python3-pip python3-setuptools python3-venv \
libsdl2-dev libsdl2-image-dev libsdl2-net-dev unzip
```

Create and activate python virtual environment to install python dependencies:

```
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

To build the project:

```
cd rogue
mkdir build
cd build
cmake ..
make
```

These steps are largely based on [quick start guide](https://chilichip.eu/docs/game-sdk/quickstart/linux-quickstart/) for VGC Zero
