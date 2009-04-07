/* File: resolution_test.h
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

#ifndef RESOLUTION_TEST_H
#define RESOLUTION_TEST_H
#include "../resolution.h"
#include "../clause.h"


class ResolutionTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(ResolutionTest);
  CPPUNIT_TEST(testAppendClause);
  CPPUNIT_TEST_SUITE_END();
private:
  Clause *clause1, *clause2;
  Resolution *resolution1, *resolution2;
public:
  void setUp();
  void tearDown();
  void testAppendClause();
};

#endif //RESOLUTION_TEST_H
