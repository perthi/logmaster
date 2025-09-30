#!/bin/bash
files=`find . -name "*.gcno*"`

echo "FILES=" $files

for file in $files; do
   # echo FILE = $file
    mv $file coverage
done

files=`find . -name "*.gcda*"`

for file in $files; do
   # echo FILE = $file
    mv $file coverage
done

# lcov --capture --directory coverage --output-file coverage.info 
lcov  --capture   --directory coverage --output-file  coverage.info  --ignore-errors inconsistent
lcov --remove coverage.info '/usr/*' 'tests/*' --output-file coverage.cleaned.info  --ignore-errors inconsistent
#lcov --remove coverage.info '/usr/*' 'tests/*' --output-file coverage.cleaned.info  --ignore-errors inconsistent
genhtml coverage.cleaned.info --output-directory coverage-report

firefox coverage-report/index.html