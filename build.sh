#! /usr/bin/env bash

mkdir -p build
pushd build
cmake ..
make
popd
