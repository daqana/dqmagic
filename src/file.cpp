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

#if !defined(R_SIZE_T)
# include <cstddef>
# define R_SIZE_T std::size_t
#endif

//' @title Get file types
//' @description Get file types based on the file's content.
//' @param files  Vector of file names including full or relative paths
//' @param mime_type  Logical indicating whether the MIME type should be returned
//' @param mime_encoding  Logical indicating whether the MIME encoding should be returned
//' @param magicfiles  Vector with file names to be used as magic file; the first
//'   usable file is selected
//' @return Vector of textual file type descriptions or MIME types/encodings
//' @export
// [[Rcpp::export]]
Rcpp::CharacterVector file_type(Rcpp::CharacterVector files,
                                bool mime_type = false,
                                bool mime_encoding = false,
                                Rcpp::Nullable<Rcpp::CharacterVector> magicfiles = R_NilValue) {
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

  R_SIZE_T len = files.length();
  Rcpp::CharacterVector res(len);
  for (R_SIZE_T i = 0; i < len; ++i) {
    res.at(i) = magic_file(magic, files.at(i));
  }
  magic_close(magic);
  return res;
}
