#!/bin/bash
blue=$(tput setaf 4)
gray=$(tput setaf 7)
green=$(tput setaf 2)
teal=$(tput setaf 6)
normal=$(tput sgr0)
type="hamilton"

for routine in routines/*; do
    for benchmark in benchmark/generate.*; do
        # Using file extensions to denote instance size, since extracting extension is trivial in Linux
        instance_size=${benchmark##*.}

        # Initial log - before program completion
        tmpLogFile=$(mktemp) # tmpfile to allow for pretty colors using printf
        cat > $tmpLogFile <<EOF
$normal============================[INSTANCE SIZE $instance_size]============================$green
Running the $routine benchmark for $type.
$normal============================[Input]============================$gray
$(cat $benchmark $routine <(echo Exit))
$normal============================[Program Output]===================$teal

EOF
        printf "$(more $tmpLogFile)" # printf allows for pretty colors
        tmpFile=$(mktemp) # saving to tmp file so it can be logged in follow up log
        run_project="./main --$type"

        # Run the project and capture time and memory usage
        result=$(/usr/bin/time -f "%e|%M" $run_project < <(cat $benchmark $routine <(echo Exit)) 2> >(tee $tmpFile.stderr) >$tmpFile)

        # Extract time and memory from the result
        time=${result%|*}
        mem=${result##*|}

        # Save to .csv
        echo "$(basename $type),$instance_size,$time" >> "$(basename $routine)_benchmark_time.csv"
        echo "$(basename $type),$instance_size,$mem" >> "$(basename $routine)_benchmark_memory.csv"

        # Follow up log - after program completion
        cat > $tmpLogFile <<EOF

$(cat $tmpFile)
$normal============================[usr/bin/time]=====================$green
time = $(echo $time) seconds | memory used = $(echo $mem) KB
Saved to $(basename $routine)_benchmark_time.csv $(basename $routine)_benchmark_memory.csv

$normal
EOF
        printf "$(more $tmpLogFile)" # printf allows for pretty colors

    done
done
