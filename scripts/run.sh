#!/usr/bin/env bash
set -euo pipefail

# Simple helper to configure, build and run the bookstore demo
ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="$ROOT_DIR/build"

echo "Building project (CMake) in: $BUILD_DIR"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"
cmake ..
cmake --build . -- -j$(nproc || 1)

EXE="$BUILD_DIR/bookstore"
if [ -x "$EXE" ]; then
  echo "Running: $EXE"
  "$EXE"
else
  echo "Executable not found: $EXE" >&2
  exit 1
fi
