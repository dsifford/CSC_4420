## Output of the fork bomb from inside Ubuntu Container

(note: there is a memory limit set so as to not crash my main computer)

```
root@7b999ce37342:/# ls
bin   dev  fork_bomb.sh  lib    media  opt   root  sbin  sys  usr
boot  etc  home          lib64  mnt    proc  run   srv   tmp  var
root@7b999ce37342:/# ./fork_bomb.sh
PID             # Parents       Mem Avail
50              0               22G
50              0               22G
50              0               22G
50              0               22G
50              0               22G
50              0               22G
50              0               22G
50              0               22G
50              0               22G
50              0               22G
50              0               22G
50              0               21G
50              0               21G
50              0               19G
50              0               16G
./fork_bomb.sh: fork: No space left on device
50              0               17G
./fork_bomb.sh: fork: No space left on device
^C
```