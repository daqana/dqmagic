##' R interface to libmagic
##'
##' The dqmagic package provides an R interface for the
##' \href{https://linux.die.net/man/3/libmagic}{\code{libmagic}} file type
##' identification library similar to the Unix
##' \href{https://linux.die.net/man/1/file}{\code{file}} command. This allows for
##' file type identification based on a file's content instead of it's extension.
##'
##' @useDynLib dqmagic, .registration = TRUE
##' @importFrom Rcpp evalCpp
"_PACKAGE"
