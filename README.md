<!-- README.md is generated from README.Rmd. Please edit that file -->
dqmagic
=======

[![Travis-CI Build Status](https://travis-ci.org/RInstitute/dqmagic.svg?branch=master)](https://travis-ci.org/RInstitute/dqmagic)

The goal of dqmagic is to provide an R interface to the libmagic library for determining the type of a file based on its content.

Example
-------

This is a basic example which shows you how to determine the type of a file:

``` r
library(dqmagic)
file_type("DESCRIPTION")
#> [1] "ASCII text"
file_type("src/file.cpp")
#> [1] "C source, ASCII text"
```
