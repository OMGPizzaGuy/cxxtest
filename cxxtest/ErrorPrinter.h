/*
-------------------------------------------------------------------------
 CxxTest: A lightweight C++ unit testing library.
 Copyright (c) 2008 Sandia Corporation.
 This software is distributed under the LGPL License v3
 For more information, see the COPYING file in the top CxxTest directory.
 Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
 the U.S. Government retains certain rights in this software.
-------------------------------------------------------------------------
*/

#ifndef __cxxtest__ErrorPrinter_h__
#define __cxxtest__ErrorPrinter_h__

//
// The ErrorPrinter is a simple TestListener that
// just prints "OK" if everything goes well, otherwise
// reports the error in the format of compiler messages.
// The ErrorPrinter uses std::cout
//

#include <cxxtest/Flags.h>

#ifndef _CXXTEST_HAVE_STD
#   define _CXXTEST_HAVE_STD
#endif // _CXXTEST_HAVE_STD

#include <cxxtest/ErrorFormatter.h>
#include <cxxtest/StdValueTraits.h>

#ifdef _CXXTEST_OLD_STD
#   include <iostream.h>
#else // !_CXXTEST_OLD_STD
#   include <iostream>
#endif // _CXXTEST_OLD_STD

namespace CxxTest
{
class ErrorPrinter : public ErrorFormatter
{
public:
    ErrorPrinter(CXXTEST_STD(ostream) &o = CXXTEST_STD(cout), const char *preLine = ":", const char *postLine = "",
                 const char *errorString = "Error",
                 const char *warningString = "Warning") :
        ErrorFormatter(new StdOStreamAdapter(o), preLine, postLine, errorString, warningString) {}

};
}

#endif // __cxxtest__ErrorPrinter_h__
