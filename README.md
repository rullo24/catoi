# Custom atoi Function (catoi)
This repository contains a custom implementation of the atoi function in C, designed to safely convert a string to an integer while checking for potential integer overflows and other similar errors.

## Compilation
Compilation has been made very simple due to the inclusion of a Makefile. To compile the source code into an executable, simply run the following command:
```bash
make
```
This will create a file called "libcatoi.a" or "libcatoi.lib" depending on what O/S you are running. These files are for linking in with other projects.

## Project Inclusion
To include the catoi function in other projects, ensure that the header files and compiled static library are successfully added into the linking stage of the new executable. Examples are shown below.

*IMPORTANT NOTE*: "-lm" (math.h functionality) is also to be included in the linking stage of the new executable for catoi to work correctly
```bash
INC = -I"*parent_directory_of_libcatoi*"
LIBS = -L"*parent_directory_of_libcatoi_header_file*" -lcatoi -lm
```

## Features
Overflow Handling: Prevents integer overflow when converting large numbers that exceed the limits of int.
Error Detection: Returns error codes for invalid inputs or overflow conditions.
Cross-Platform: Works on both Linux and Windows, ensuring compatibility across platforms.