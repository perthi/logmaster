#!/bin/bash
if [ "$#" -eq 0 ]; then
  echo "Error: At least one parameter is required." >&2
  exit 1
fi

cppcheck $1 $2 $3 $4 $5 -I include --suppress=missingIncludeSystem  --check-level=exhaustive  --report-type=misra-cpp-2023  --platform=unix64  --language=c++ --enable=all 2>  report.txt
