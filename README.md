
<!-- README.md is generated from README.Rmd. Please edit that file -->

# dqmagic

[![Travis-CI Build
Status](https://travis-ci.org/daqana/dqmagic.svg?branch=master)](https://travis-ci.org/daqana/dqmagic)
[![Coverage
Status](https://img.shields.io/codecov/c/github/daqana/dqmagic/master.svg)](https://codecov.io/github/daqana/dqmagic?branch=master)

The dqmagic package provides an R interface for the
[libmagic](https://linux.die.net/man/3/libmagic) file type
identification library similar to the Unix
[file](https://linux.die.net/man/1/file) command. This allows for file
type identification based on a file’s content instead of it’s extension.

## Installation

In order to install and use dqmagic you will need the `libmagic` library
and headers:

  - Debian/Ubuntu: `sudo apt-get install libmagic-dev`
  - Fedora/CentOS/RHEL: `sudo yum install file-devel`
  - OSX with homebrew: `brew install libmagic`

At the moment dqmagic is not on CRAN, but you can install the current
version via [drat](https://cran.r-project.org/package=drat):

``` r
if (!requireNamespace("drat", quietly = TRUE)) install.packages("drat")
drat::addRepo("daqana")
install.packages("dqmagic")
```

## Examples

This is a basic example which shows you how to determine the type of a
file:

``` r
library(dqmagic)
file_type("DESCRIPTION")
#> [1] "ASCII text"
file_type("src/file.cpp")
#> [1] "C source, ASCII text"
```

And the same for the MIME type and encoding:

``` r
library(dqmagic)
file_type("DESCRIPTION", mime_type = TRUE, mime_encoding = TRUE)
#> [1] "text/plain; charset=us-ascii"
file_type("src/file.cpp", mime_type = TRUE, mime_encoding = TRUE)
#> [1] "text/x-c; charset=us-ascii"
```
