################################################################################
context("magic file")

test_that("magic version is integer", {
  expect_type(magicVersion(), "integer")
})

test_that("default magic file path exists", {
  expect_type(magicPathDefault(), "character")
})

test_that("file recognized w/o magic file", {
  expect_equal(file_type("sample/foo.txt"),
               "ASCII text")
})

test_that("file recognized w/ default magic file", {
  expect_equal(file_type("sample/foo.txt", magicfiles = magicPathDefault()),
               "ASCII text")
})

test_that("file recognized w/ default magic file as explicit vector", {
  expect_equal(file_type("sample/foo.txt", magicfiles = c(magicPathDefault())),
               "ASCII text")
})

test_that("file recognized w/ non-existing and default magic file", {
  expect_equal(file_type("sample/foo.txt", magicfiles = c("does_not_exist", magicPathDefault())),
               "ASCII text")
})

test_that("file recognized w/ default magic and non-existing file", {
  expect_equal(file_type("sample/foo.txt", magicfiles = c(magicPathDefault(), "does_not_exist")),
               "ASCII text")
})

test_that("error w/ non-existing magic file", {
  expect_error(file_type("sample/foo.txt", magicfiles = c("does_not_exist")),
               "Unable to load magic file. Error message: could not find any valid magic files!")
})

