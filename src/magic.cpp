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

//' @title Get libmagic version
//' @description Get version of the libmagic library as integer: MAJOR * 100 + MINOR.
//' @return Integer representing the version number
//' @export
// [[Rcpp::export]]
int magicVersion() {
  return magic_version();
}

//' @title Get default magic
//' @description Get paths for the default magic files and directories.
//' @return Paths of the default magic files and directories
//' @export
// [[Rcpp::export]]
std::string magicPathDefault() {
  return magic_getpath(NULL, 0 /* FILE_LOAD */);
}
