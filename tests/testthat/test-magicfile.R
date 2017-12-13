################################################################################
context("magic file")

test_that("file recognized w/o magic file", {
  expect_equal(file_type("sample/foo.txt"),
               "ASCII text")
})

test_that("file recognized w/ default magic file", {
  expect_equal(file_type("sample/foo.txt", magicfiles = "/usr/share/misc/magic.mgc"),
               "ASCII text")
})

test_that("file recognized w/ default magic file as explicit vector", {
  expect_equal(file_type("sample/foo.txt", magicfiles = c("/usr/share/misc/magic.mgc")),
               "ASCII text")
})

test_that("file recognized w/ non-existing and default magic file", {
  expect_equal(file_type("sample/foo.txt", magicfiles = c("does_not_exist", "/usr/share/misc/magic.mgc")),
               "ASCII text")
})

test_that("file recognized w/ default magic and non-existing file", {
  expect_equal(file_type("sample/foo.txt", magicfiles = c("/usr/share/misc/magic.mgc", "does_not_exist")),
               "ASCII text")
})

test_that("error w/ non-existing magic file", {
  expect_error(file_type("sample/foo.txt", magicfiles = c("does_not_exist")),
               "Unable to load magic file. Error message: could not find any valid magic files!")
})

