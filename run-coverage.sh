#!/bin/bash

files=`find . -name "*.gcno*" -o -name "*.gcda*"`

for file in $files; do
  #  echo FILE = $file
    cp $file coverage
done

#exit


lcov  --capture   --directory coverage --output-file  coverage.info  --ignore-errors inconsistent
lcov --remove coverage.info '/usr/*' 'tests/*' 'Test*' '*3rd-party*' '*logmaster/json*' --output-file coverage.cleaned.info  --ignore-errors inconsistent
genhtml coverage.cleaned.info --output-directory coverage-report
rm  coverage.info overage.cleaned.info

firefox coverage-report/index.html
