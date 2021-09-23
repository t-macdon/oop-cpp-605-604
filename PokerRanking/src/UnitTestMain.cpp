/**
 * @file UnitTestMain.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Unit testing main file
 * @version 0.1
 * @date 2021-09-23
 */

#if defined(RUN_UNIT_TESTS) && RUN_UNIT_TESTS
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#else
#define DOCTEST_CONFIG_IMPLEMENT
#endif
#include "doctest.h"