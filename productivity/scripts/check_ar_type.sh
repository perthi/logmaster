#!/bin/bash
readelf -h $1 | grep 'Class\|File\|Machine'

