#!/bin/bash

# Write a simple test program to find out PIDs of ALL ancestor (i.e.,
# parent, grandparent) processes of the current process or a given process
# specified by a PID. A parent process\'s PID of a given process pid can be
# found in /proc/\$pid/status

declare -i pid
declare -ia pid_list=()

if [[ "$1" == +([0-9]) ]]; then
    pid="$1"
else
    pid="$$"
fi
pid_list+=( "$pid" )

while [ -f "/proc/$pid/status" ]; do
    pid="$(
        awk '/PPid/ { print $2 }' "/proc/$pid/status"
    )"
    [ "$pid" != '' ] && pid_list+=( "$pid" )
done

echo 'Process chain'
declare -i len="((${#pid_list[@]} - 1))"
for (( i="$len"; i >= 0; i--)); do
    for (( idx="$len"-"$i" ; idx>0 ; idx-- )) ; do printf '\t'; done
    [ "$i" -eq 0 ] && echo -n 'current PID: '
    echo "${pid_list[$i]}"
done

