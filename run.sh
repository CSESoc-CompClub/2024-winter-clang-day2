#!/bin/bash

# Get tmp file name
out_file=$(mktemp -q "./out.XXXXXX")

# Compile main.c
gcc src/main.c src/game.c -o "$out_file"

# Run
"./$out_file"

# Remove
rm -rf "$out_file"

