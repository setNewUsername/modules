#!/bin/bash

cmake CMakeLists.txt

make

build/modules/ThreadModule/build.sh

#mv build/app_bin.bin build/build-output