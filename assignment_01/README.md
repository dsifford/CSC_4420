1. **(10 pts)** Write a simple shell script to move (rename) all \*.PDF
   files under the current directory (if any) to \*.pdf, e.g.,\
   move _test.PDF_ to _test.pdf_\
   move _hello.PDF.PDF_ to _hello.PDF.pdf_\
   move ._hello.PDF.PDF_ to _.hello.PDF.pdf_\
   and report each action, otherwise just report there are no \*.PDF
   files.

2. **(20 pts)** Write a simple single thread **CSC4420 shell** , i.e.,
   no concurrent commands, to support at least the following built-in
   commands:

* **prompt:** can set to any string you input, in addition to the
  current history event number, i.e, %h as in csh;
* **url:** list the course web site
* **hour:** list class times
* **room:** list classroom location
* **desp:** list the description of this course
* **text:** list the textbook
* **ref:** list the reference books
* **prof:** list the professor\'s name
* **pol:** professor's office location
* **poh:** professor's office hours
* **pma:** professor's email address
* **ta:** list the TA's name
* **tol:** TA's office location
* **toh:** TA's office hours
* **tma:** TA's email address
* **history:** list history of events up to the number you set
* **help:** list all the available commands
* **exit or quit:** exit CSC4420 shell

