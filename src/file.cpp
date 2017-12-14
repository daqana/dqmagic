// -*- mode: C++ -*-
//
// file.cpp: Rcpp/libmagic glue
//
// Copyright (C) 2017 Ralf Stubner (R Institute GmbH)
//
// This file is part of dqmagic.
//
// dqmagic is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// dqmagic is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with dqmagic.  If not, see <http://www.gnu.org/licenses/>.

#include <Rcpp.h>
#include <magic.h>

//' @title Get file types
//' @description Get file types based on the file's content.
//' @param files  Vector of file names including full or relative paths
//' @param mime_type  Logical indicating whether the MIME type should be returned
//' @param mime_encoding  Logical indicating whether the MIME encoding should be returned
//' @param magicfiles  Vector with file or directory names to be used as magic file;
//'   the first usable location is selected
//' @param names  Logical indicating whether the file names should be added to the
//'   result as attribute names
//' @return Vector of textual file type descriptions or MIME types/encodings
//' @export
// [[Rcpp::export]]
Rcpp::CharacterVector file_type(Rcpp::CharacterVector files,
                                bool mime_type = false,
                                bool mime_encoding = false,
                                Rcpp::Nullable<Rcpp::CharacterVector> magicfiles = R_NilValue,
                                bool names = false) {
  int flag = MAGIC_NONE;
  if (mime_type) flag |= MAGIC_MIME_TYPE;
  if (mime_encoding) flag |= MAGIC_MIME_ENCODING;
  struct magic_set *magic = magic_open(flag);
  if (magic == NULL) {
    Rcpp::stop("Unable to initialise magic.");
  }

  int rc = -1;
  if (magicfiles.isNotNull()) {
    for (auto file : magicfiles.as()) {
      if ((rc = magic_load(magic, file)) != -1) {
        break; // found usable file
      }
    }
  } else {
    rc = magic_load(magic, NULL);
  }
  if (rc == -1) {
    Rcpp::stop("Unable to load magic file. Error message: %s", magic_error(magic));
  }

  std::vector<std::string> res;
  res.reserve(files.length());
  for (auto file : files) {
    res.emplace_back(magic_file(magic, file));
  }
  magic_close(magic);
  Rcpp::CharacterVector result = Rcpp::wrap(res);
  if (names) result.attr("names") = files;
  return result;
}
