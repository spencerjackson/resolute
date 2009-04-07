/* File: testrunner.cpp
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

#include<cppunit/extensions/TestFactoryRegistry.h>
#include<cppunit/ui/text/TestRunner.h>

int main( int argc, char **argv) {
  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
  if (argc > 1) {
    CppUnit::Test* allTests = registry.makeTest();
    CppUnit::TestSuite* selectedTests = new CppUnit::TestSuite;
    for(int i = 1; i<argc; i++) {
      selectedTests->addTest(allTests->findTest(argv[i]));
    }
    runner.addTest(selectedTests);
  }
  else {
    runner.addTest(registry.makeTest());
  }
  runner.run();
  return 0;
}
