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

#include <config.h>
#include <Rcpp.h>
#include <magic.h>
#include <file/file.h>

// I don't want to depend on BH to get boost::split()
std::vector<std::string> split(const std::string& s, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  while (std::getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

//' @title Get libmagic version
//' @description Get version of the libmagic library as integer: MAJOR * 100 + MINOR.
//' @return Integer representing the version number
//' @export
// [[Rcpp::export]]
int magicVersion() {
  return magic_version();
}

//' @title Get default magic
//' @description Get path for the default magic file.
//' @return Path of thedefault magic file
//' @export
// [[Rcpp::export]]
Rcpp::CharacterVector magicPathDefault() {
  std::string paths = magic_getpath(NULL, FILE_LOAD);
  return Rcpp::wrap(split(paths, ':'));
}
