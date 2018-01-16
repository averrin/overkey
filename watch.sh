#!/bin/bash
watchman-make -p '**/*.cpp' '**/*.hpp' '**/*.h' 'Makefile*' -t all
