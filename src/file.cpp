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
// along with RcppArrayFire.  If not, see <http://www.gnu.org/licenses/>.

#include <Rcpp.h>
#include <magic.h>
using namespace Rcpp;

//' @title Get file type
//' @description Get file type.
//' @param file  Name of the file including full or relative path
//' @return Textual description of file type
//' @export
// [[Rcpp::export]]
String file_type(String file) {
  struct magic_set *magic = magic_open(MAGIC_NONE);
  if (magic == NULL) {
    Rcpp::stop("Unable to initialise magic.");
  }
  magic_load(magic, NULL);
  if (magic == NULL) {
    Rcpp::stop("Unable to load magic.");
  }
  String res = magic_file(magic, file.get_cstring());
  magic_close(magic);
  return res;
}

