/* File: resolution_test.cpp
Copyright 2009 Spencer Jackson

This file is part of Resolute
is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Resolute is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Resolute.  If not, see <http://www.gnu.org/licenses/>.*/

#include <cppunit/extensions/HelperMacros.h>
#include "resolution_test.h"

void ResolutionTest::setUp() {
  resolution1 = new Resolution;
  resolution2 = new Resolution;
  clause1 = new OperativeClause("Declares", "water a fundamental human right");
  clause2 = new PreambulatoryClause("Understanding", "the severity of this issue");
}
void ResolutionTest::tearDown() {
  delete resolution1;
  delete resolution2;
  delete clause1;
  delete clause2;
}
void ResolutionTest::testAppendClause() {
  PreambulatoryClause test("Understanding", "the severity of this issue");
  CPPUNIT_ASSERT_NO_THROW(resolution1->insertClause(*clause2));
}

CPPUNIT_TEST_SUITE_REGISTRATION(ResolutionTest);
