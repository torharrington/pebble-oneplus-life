#!/bin/bash
pebble clean
pebble wipe
pebble build
mv build/*.pbw ./
rm -rf build

