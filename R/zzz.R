.onLoad <- function(libname = find.package("dqmagic"), pkgname = "dqmagic") {
  if (.Platform$OS.type == "windows")
    Sys.setenv(MAGIC = system.file("extdata", "magic.mgc", package = "dqmagic"))
}
