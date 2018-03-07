#!/usr/bin/env bash
set -ex

mkdir -vp build
(cd build && cmake ../ && make)
