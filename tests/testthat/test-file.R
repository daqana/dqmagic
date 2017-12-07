context("file")

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
  expect_equal(file_type("sample/foo.xlsx"), "Microsoft OOXML")
})
