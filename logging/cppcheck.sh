#!/bin/bash
cppcheck L* --check-level=exhaustive  --report-type=misra-cpp-2023  --platform=unix64  --language=c++ --enable=all 2>  report.txt
