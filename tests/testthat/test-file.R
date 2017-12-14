################################################################################
context("file type")

test_that("ASCII text is recognized", {
  expect_equal(file_type("sample/foo.txt"), "ASCII text")
})

test_that("Excel file is recognized", {
  expect_equal(file_type("sample/foo.xls"), "Composite Document File V2 Document, Little Endian, Os: Windows, Version 1.0, Code page: -535, Author: Ralf Stubner, Last Saved By: Ralf Stubner, Revision Number: 1, Total Editing Time: 00:43, Create Time/Date: Thu Dec  7 14:21:42 2017, Last Saved Time/Date: Thu Dec  7 14:22:24 2017")
})

test_that("HTML file is recognized", {
  expect_equal(file_type("sample/foo.html"), "HTML document, ASCII text")
})

test_that("PDF file is recognized", {
  expect_equal(file_type("sample/foo.pdf"), "PDF document, version 1.4")
})

test_that("XLSX file is recognized", {
  skip_if_not(magicVersion() >= 530L, message = "libmagic might be to old")
  expect_equal(file_type("sample/foo.xlsx"), "Microsoft OOXML")
})

test_that("Vector of files is recognized", {
  expect_equal(file_type(c("sample/foo.txt", "sample/foo.html", "sample/foo.pdf")),
               c("ASCII text", "HTML document, ASCII text", "PDF document, version 1.4"))
})

################################################################################
context("file MIME type")

test_that("ASCII text is recognized", {
  expect_equal(file_type("sample/foo.txt", mime_type = TRUE), "text/plain")
})

test_that("Excel file is recognized", {
  skip_if_not(magicVersion() >= 530L, message = "libmagic might be to old")
  expect_equal(file_type("sample/foo.xls", mime_type = TRUE), "application/vnd.ms-excel")
})

test_that("HTML file is recognized", {
  expect_equal(file_type("sample/foo.html", mime_type = TRUE), "text/html")
})

test_that("PDF file is recognized", {
  expect_equal(file_type("sample/foo.pdf", mime_type = TRUE), "application/pdf")
})

test_that("XLSX file is recognized", {
  skip_if_not(magicVersion() >= 530L, message = "libmagic might be to old")
  expect_equal(file_type("sample/foo.xlsx", mime_type = TRUE), "application/octet-stream")
})

test_that("Vector of files is recognized", {
  expect_equal(file_type(c("sample/foo.txt", "sample/foo.html", "sample/foo.pdf"), mime_type = TRUE),
               c("text/plain", "text/html", "application/pdf"))
})

################################################################################
context("file MIME encoding")

test_that("ASCII text is recognized", {
  expect_equal(file_type("sample/foo.txt", mime_encoding = TRUE), "us-ascii")
})

test_that("Excel file is recognized", {
  skip_if_not(magicVersion() >= 530L, message = "libmagic might be to old")
  expect_equal(file_type("sample/foo.xls", mime_encoding = TRUE), "application/vnd.ms-excelbinary")
})

test_that("HTML file is recognized", {
  expect_equal(file_type("sample/foo.html", mime_encoding = TRUE), "us-ascii")
})

test_that("PDF file is recognized", {
  expect_equal(file_type("sample/foo.pdf", mime_encoding = TRUE), "binary")
})

test_that("XLSX file is recognized", {
  expect_equal(file_type("sample/foo.xlsx", mime_encoding = TRUE), "binary")
})

test_that("Vector of files is recognized", {
  expect_equal(file_type(c("sample/foo.txt", "sample/foo.html", "sample/foo.pdf"), mime_encoding = TRUE),
               c("us-ascii", "us-ascii", "binary"))
})

################################################################################
context("file MIME type and encoding")

test_that("ASCII text is recognized", {
  expect_equal(file_type("sample/foo.txt", mime_type = TRUE, mime_encoding = TRUE),
               "text/plain; charset=us-ascii")
})

test_that("Excel file is recognized", {
  skip_if_not(magicVersion() >= 530L, message = "libmagic might be to old")
  expect_equal(file_type("sample/foo.xls", mime_type = TRUE, mime_encoding = TRUE),
               "application/vnd.ms-excel; charset=binary")
})

test_that("HTML file is recognized", {
  expect_equal(file_type("sample/foo.html", mime_type = TRUE, mime_encoding = TRUE),
               "text/html; charset=us-ascii")
})

test_that("PDF file is recognized", {
  expect_equal(file_type("sample/foo.pdf", mime_type = TRUE, mime_encoding = TRUE),
               "application/pdf; charset=binary")
})

test_that("XLSX file is recognized", {
  skip_if_not(magicVersion() >= 530L, message = "libmagic might be to old")
  expect_equal(file_type("sample/foo.xlsx", mime_type = TRUE, mime_encoding = TRUE),
               "application/octet-stream; charset=binary")
})

test_that("Vector of files is recognized", {
  expect_equal(file_type(c("sample/foo.txt", "sample/foo.html", "sample/foo.pdf"), mime_type = TRUE, mime_encoding = TRUE),
               c("text/plain; charset=us-ascii", "text/html; charset=us-ascii", "application/pdf; charset=binary"))
})

################################################################################
context("names attribute")

test_that("File names are rturned in the names attribute", {
  files <- c("sample/foo.txt", "sample/foo.html", "sample/foo.pdf")
  file_types <- file_type(files, names = TRUE)
  expect_equal(files, names(file_types))
})
