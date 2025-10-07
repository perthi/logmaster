#!/bin/bash
#!/bin/bash

if [ "$#" -eq 0 ]; then
  echo "You must specify an executable" >&2
  exit 1
fi

$1

files=`find . -name "*.gcno*" -o -name "*.gcda*"`

for file in $files; do
    if  grep -q "$coverage" "$file"; then
        echo  $file "File does not contain 'coverage'." > /dev/null
        cp $file coverage  > /dev/null 2>&1
    else
        cp $file coverage  > /dev/null 2>&1
    fi
done


lcov  --capture   --directory coverage --output-file  coverage.info  --ignore-errors unused,mismatch,count,inconsistent,mismatched
#lcov --remove coverage.info '/usr/*' 'tests/*' 'Test*' '*/*unit-tests*'  '*logmaster/json*' '*include*' '*utilities*' --output-file coverage.cleaned.info  --ignore-errors unused,mismatch,count,inconsistent,mismatched

lcov --remove coverage.info '/usr/*' 'tests/*' 'Test*' '*logmaster/json*' '*include*' '*utilities*' --output-file coverage.cleaned.info  --ignore-errors mismatch,count,inconsistent --ignore-errors unused


genhtml coverage.cleaned.info --output-directory coverage-report --ignore-errors unused,mismatch,count,inconsistent
rm  coverage.info coverage.cleaned.info

firefox coverage-report/index.html &
