---
title: Fun with Files and Disks
due: 2018-04-19
---

1.  Consider the directory tree of Fig. 4-8. If `/usr/jim` is the working
    directory, what is the absolute path name for the file whose relative path
    name is `../ast/x`?

`/usr/ast/x`

2.  One way to use contiguous allocation of the disk and not suffer from holes
    is to compact the disk every time a file is removed. Since all files are
    contiguous, copying a file requires a seek and rotational delay to read the
    file, followed by the transfer at full speed. Writing the file back requires
    the same work. Assuming a seek time of 5 msec, a rotational delay of 4 msec,
    a transfer rate of 80 MB/sec, and an average file size of 8 KB, how long
    does it take to read a file into main memory and then write it back to the
    disk at a new location? Using these numbers, how long would it take to
    compact half of a 16-GB disk?

Single 8KB file

```
(5msec + 4msec) * 2 + 8msec = 26 milliseconds
```

Half of a 16GB disk

```
16GB / 2 = 8GB
8GB total / 8KB avg file size = 1_000_000 * 2 = 2_000_000 individual reads/writes
2_000_000 * (5msec + 4msec) = 18_000_000 milliseconds of read/write time
18_000_000 msec = 18_000 sec

0.08GB / 1sec = 8GB / x
0.08x = 8
x     = 8/0.08
x     = 100sec transfer time

TOTAL = 18_000 sec (mechanical) + 100 sec (transfer)
      = 18_100 sec
      = ~5 hours
```

3.  In light of the answer to the previous question, does compacting the disk
    ever make any sense?

No, this takes far too much time to do on an entire disk. The cost here far
exceeds the benefit.

4.  The beginning of a free-space bitmap looks like this after the disk
    partition is first formatted: `1000 0000 0000 0000` (the first block is used
    by the root directory). The system always searches for free blocks starting
    at the lowest-numbered block, so after writing file A, which uses six
    blocks, the bitmap looks like this: `1111 1110 0000 0000`. Show the bitmap
    after each of the following additional actions:

    | Action                                 | Bitmap State          |
    | -------------------------------------- | --------------------- |
    | File B is written, using five blocks.  | `1111 1111 1111 0000` |
    | File A is deleted.                     | `1000 0001 1111 0000` |
    | File C is written, using eight blocks. | `1111 1111 1111 1100` |
    | File B is deleted.                     | `1111 1110 0000 1100` |

5.  Write a program that reverses the bytes of a file, so that the last byte is
    now first and the first byte is now last. It must work with an arbitrarily
    long file, but try to make it reasonably efficient.

**See `./prob05`**

6.  Write a program that starts at a given directory and descends the file tree
    from that point recording the sizes of all the files it finds. When it is
    all done, it should print a histogram of the file sizes using a bin width
    specified as a parameter (e.g., with 1024, file sizes of 0 to 1023 go in one
    bin, 1024 to 2047 go in the next bin, etc.).

**See `./prob06`**

7.  In which of the four I/O software layers is each of the following done.

    1.  Computing the track, sector, and head for a disk read.

    **Device driver layer**

    2.  Writing commands to the device registers.

    **Device driver layer**

    3.  Checking to see if the user is permitted to use the device.

    **Operating system layer**

    4.  Converting binary integers to ASCII for printing.

    **User-level software layer**

8.  How much cylinder skew is needed for a 7200-RPM disk with a track-to-track
    seek time of 1 msec? The disk has 200 sectors of 512 bytes each on each
    track.

        7200RPM = 120RPS --> 1 rotation = 1000/120 msec
        (1000/120)/ 200 sectors = 1/24 msec
        24 sectors passed / 1 msec --> Cylinder skew should be 24

9.  Calculate the maximum data rate in bytes/sec for the disk described in the
    previous problem.

        200 sectors * 512 bytes/sector = 102_400 bytes/rotation
        102_400 bytes/rotation * 120 RPS = 12_288_000 bytes/sec

