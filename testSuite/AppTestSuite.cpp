#include "AppTestSuite.h"
#include "CowAsciiString_test.h"

CppUnit::Test* AppTestSuite::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("AppTestSuite");

	pSuite->addTest(CowAsciiString_test::suite());

	return pSuite;
}
