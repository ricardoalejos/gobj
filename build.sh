#! /usr/bin/env bash

mkdir -p build
pushd build
cmake .. -DGOBJ_VERSION=$(git describe | tr "\n" "\0")
make
popd
