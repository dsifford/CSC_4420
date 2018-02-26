## Final Project

Design and Implementation of A Secure Amazon S3 Based File System

In this project, you will design and implement a stackable file system running
on Linux, which uses Amazon's S3 as backend storage. It needs to meet the
following requirements:

* Once mounted, a bucket in S3 appears as a local directory on your Linux
  machine.
* Any updates (creation, deletion or modification of files and subdirectories)
  in the local directory are reflected in the corresponding S3 bucket, and vice
  versa.
* All files in the file system are automatically encrypted using RC4, and
  applications can transparently operate on the files without explicit
  decryptions.

The following packages can be used with any necessary modifications in this
project:

* [FUSE](http://fuse.sourceforge.net/)
* [s3fs](https://github.com/s3fs-fuse/s3fs-fuse) ||
  ([wiki](https://github.com/s3fs-fuse/s3fs-fuse/wiki/Fuse-Over-Amazon))
* [Openssl](http://www.openssl.org/)

Here is an
[instruction set](https://github.com/s3fs-fuse/s3fs-fuse/blob/master/README.md)
on s3fs. (The most recent version of s3fs is s3fs-1.80, and the fuse-utils
package may not be needed as a separate package any more).

At the end of the project, you will do a demo to the class during the
presentation sessions, and submit a final technical report.

### The report should clearly include the following components

* The goal of this project: what is expected to accomplish in this project
* Packages and tools used in this project
* Results of this project: what has been accomplished in this project
* Your work in this project: which parts of source code are modified, added to
  accomplish specific goals
* What to improve in your project if you have more time
* The report should be written in the one of the following formats: pdf or MS
  word, about 10 pages, with normal space in 10-pt font

### What to submit

* Final report
* Whole source code package, including make file
* A readme file describing how to compile, make and install your secure s3fs,
  including configuration files

## Final Report

Here is a reference structure for the final report. You don't have to follow
exactly, but this gives you an idea of what to include in yourr report:

1. Introduction
2. Project Goals
3. System information Your system specs, such as CPU model, memory size and OS
   kernel/distribution, fuse version, s3fs version, etc
4. Tools and packages
5. Design: Some diagrams would certainly help a lot
6. Integration: What have been accomplished and what not, what went wrong, you
   think
7. Implementation details: highlight your modifications of source code here
8. Future Improvement
9. Summary: What have you learned in this project.

### Timetable

| Week # | Tasks                                                                                                                                                                                                                                                                                                      |
| ------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Week1  | Download and Install Packages                                                                                                                                                                                                                                                                              |
| Week2  | Test and Experiment Package                                                                                                                                                                                                                                                                                |
| Week3  | Understand the Source Code                                                                                                                                                                                                                                                                                 |
| Week4  | Understand s3fs source code, find out where the upload and download components are. learn how to change data content in s3fs with a simple function, e.g., exclusive or 0x0011 to each byte before upload and then after download, the resulting file should be the same as the original one before upload |
| Week5  | Understand RC4 part source code in OpenSSL, and test with rc4 commands in OpenSSL                                                                                                                                                                                                                          |
| Week6  | Implement a simple stand-alone utility to encrypt and decrypt a file using RC4; start integrating RC4 into s3fs, store encryption key locally                                                                                                                                                              |
| Week7  | Further integrate RC4 into s3fs; various tests; preparing presentation                                                                                                                                                                                                                                     |
| Week8  | Finalize secure-s3fs 0.01; report writing                                                                                                                                                                                                                                                                  |
| Week9  | Report due                                                                                                                                                                                                                                                                                                 |
