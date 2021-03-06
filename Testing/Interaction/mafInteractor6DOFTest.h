/*=========================================================================

 Program: MAF2
 Module: mafInteractor6DOFTest
 Authors: Stefano Perticoni
 
 Copyright (c) B3C
 All rights reserved. See Copyright.txt or
 http://www.scsitaly.com/Copyright.htm for details.

 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef __CPP_UNIT_mafInteractor6DOFTest_H__
#define __CPP_UNIT_mafInteractor6DOFTest_H__

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

class mafInteractor6DOFTest : public CPPUNIT_NS::TestFixture
{
public:

	/** CPPUNIT fixture: executed before each test */
	void setUp();

	/** CPPUNIT fixture: executed after each test */
	void tearDown();

	CPPUNIT_TEST_SUITE( mafInteractor6DOFTest );
	CPPUNIT_TEST( TestFixture );
	CPPUNIT_TEST( TestConstructorDestructor );
	CPPUNIT_TEST( TestStartStopInteraction);
	CPPUNIT_TEST( TestSetGetTrackerPoseMatrix);
	CPPUNIT_TEST( TestTrackerSnapshot);
	CPPUNIT_TEST( TestUpdateDeltaTransform);
	CPPUNIT_TEST( TestSetGetTracker);
	CPPUNIT_TEST( TestSetGetIgnoreTriggerEvents);	
	CPPUNIT_TEST( TestIgnoreTriggerEventsOnOff);
	CPPUNIT_TEST( TestSetRenderer);
	CPPUNIT_TEST( TestHideShowAvatar);
 	CPPUNIT_TEST_SUITE_END();

protected:

	void TestFixture(); 
	void TestConstructorDestructor();
	void TestStartStopInteraction();
	void TestSetGetTrackerPoseMatrix();
	void TestTrackerSnapshot();
	void TestUpdateDeltaTransform();
	void TestSetGetTracker();
	void TestSetGetIgnoreTriggerEvents();	
	void TestIgnoreTriggerEventsOnOff();
	void TestSetRenderer();
	void TestHideShowAvatar();

};

int main( int argc, char* argv[] )
{
  // Create the event manager and test controller
  CPPUNIT_NS::TestResult controller;

  // Add a listener that collects test result
  CPPUNIT_NS::TestResultCollector result;
  controller.addListener( &result );        

  // Add a listener that print dots as test run.
  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener( &progress );      

  // Add the top suite to the test runner
  CPPUNIT_NS::TestRunner runner;
  runner.addTest( mafInteractor6DOFTest::suite());
  runner.run( controller );

  // Print test in a compiler compatible format.
  CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
  outputter.write(); 

  return result.wasSuccessful() ? 0 : 1;
}

#endif
