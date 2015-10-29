# SDL CMake Template

I've grown tired of creating the same scaffolding every time I start a new idea
or project that needs SDL.

## Setup

You can clone, fork, or just download this directory and delete the `.git`
directory. Your call really.

```bash
git clone git@github.com:warmwaffles/sdl-cmake-template.git
pushd ./sdl-cmake-template
rm -rf .git
popd
```

## Usage

```bash
mkdir build
cd build
cmake ..
make
```

## Organization

You can really organize your project however, but this project assumes that you
have code underneath the `./src` directory.

