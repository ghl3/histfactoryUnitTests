
#include "RooStats/HistFactory/Measurement.h"
#include "RooStats/HistFactory/MakeModelAndMeasurementsFast.h"

using namespace RooStats;
using namespace HistFactory;

/*

 A ROOT script demonstrating
 an example of writing a HistFactory
 model using c++ only.

 This example was written to match
 the example.xml analysis in
 $ROOTSYS/tutorials/histfactory/

 Written by George Lewis

 */

void example() {


  std::string InputFile = "./data/example.root";

  // Create the measurement
  Measurement meas("meas", "meas");

  meas.SetOutputFilePrefix( "./results/example_UsingC" );
  meas.SetPOI( "SigXsecOverSM" );
  meas.AddConstantParam("alpha_syst1");
  meas.AddConstantParam("Lumi");

  meas.SetLumi( 1.0 );
  meas.SetLumiRelErr( 0.10 );
  meas.SetExportOnly( false );
  meas.SetBinHigh( 2 );

  // Create a channel

  Channel chan( "channel1" );
  chan.SetData( "data", InputFile );
  chan.SetStatErrorConfig( 0.05, "Poisson" );

  
  // Now, create some samples


  // Create the signal sample
  Sample signal( "signal", "signal", InputFile );
  signal.AddOverallSys( "syst1",  0.95, 1.05 );
  signal.AddNormFactor( "SigXsecOverSM", 1, 0, 3 );
  chan.AddSample( signal );

  // Background 1
  Sample background1( "background1", "background1", InputFile );
  background1.ActivateStatError( "background1_statUncert", InputFile );
  background1.AddOverallSys( "syst2", 0.95, 1.05  );
  chan.AddSample( background1 );


  // Background 1
  Sample background2( "background2", "background2", InputFile );
  background2.ActivateStatError();
  background2.AddOverallSys( "syst3", 0.95, 1.05  );
  chan.AddSample( background2 );
  

  // Done with this channel
  // Add it to the measurement:
  meas.AddChannel( chan );

  // Collect the histograms from their files,
  // print some output, 
  meas.CollectHistograms();
  //meas.PrintTree();

  // One can print XML code to an
  // output directory:
  // meas.PrintXML( "xmlFromCCode", meas.GetOutputFilePrefix() );

  std::cout << "About to MakeModelAndMeasurementFast" << std::endl;
  
  // Now, do the measurement
  MakeModelAndMeasurementFast( meas );

  std::cout << "Successfully MakeModelAndMeasurementFast" << std::endl;

  return;

}
