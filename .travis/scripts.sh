#!/bin/bash

qmake CONFIG+=release PREFIX=/usr

make -j$(nproc)