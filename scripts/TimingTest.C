
#include <sstream>

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

#include "TMath.h"

#include "RooStats/HistFactory/Measurement.h"
#include "RooStats/HistFactory/MakeModelAndMeasurementsFast.h"

#include "RooAbsPdf.h"
#include "RooAbsData.h"
#include "RooWorkspace.h"

using namespace RooStats;
using namespace HistFactory;


/*

  Create a HistFactory model with
  many channels for the purpose
  of timing the fit

*/

TH1* CreateGaussian( std::string name, int bins, int mean, int width, int height ) {

  TH1F* hist = new TH1F(name.c_str(), name.c_str(), bins, 0, bins);

  // Fill the Hist
  for(int i = 0; i < bins; ++i) {
    double bin_center = i + .5;
    double val = TMath::Gaus(bin_center, mean, width)*height;
    hist->SetBinContent(i+1, val);
  }

  return hist;

}


void TimingTest() {

  // Remove a LOT of ROOT crap
  TH1::AddDirectory(kFALSE);

  // Create the measurement
  Measurement meas("meas", "meas");

  meas.SetOutputFilePrefix( "./results/LongTest" );
  meas.SetPOI( "SigXsecOverSM" );

  meas.SetLumi( 1.0 );
  meas.SetLumiRelErr( 0.10 );
  meas.SetExportOnly( true );


  // Loop and create the various channels
  // for this model

  int num_channels = 20;
  int initial_bins = 10;
  int num_histo_sys = 35;

  for( int i = 0; i < num_channels; ++i) {
    
    std::stringstream channel_stream;
    channel_stream << i;
    std::string channel_str = channel_stream.str();

    // Create a channel
    Channel chan( "channel_" + channel_str );

    // Create the bins
    int bins = initial_bins; // + i;

    // Create the data
    double data_height = 5.0 + ((double)i)*5.0/num_channels;
    chan.SetData( CreateGaussian("data", bins, initial_bins-3, 2, data_height) );
    //chan.SetStatErrorConfig( 0.05, "Poisson" );
    
    // Create the signal sample
    Sample signal("signal");
    double signal_height = 3.0 + ((double)i)*5.0/num_channels;
    signal.SetHisto( CreateGaussian("signal", bins, initial_bins-2, 1, signal_height) );
    signal.AddOverallSys( "syst1",  0.95, 1.05 );
    signal.AddNormFactor( "SigXsecOverSM", 1, 0, 3 );
    chan.AddSample( signal );
    
    Sample background1("background1");
    double bkg1_height = 2.0 + ((double)i)*5.0/num_channels;
    background1.SetHisto( CreateGaussian("signal", bins, initial_bins-4, 1, bkg1_height) );
    //background1.ActivateStatError( "background1_statUncert", InputFile );
    background1.AddOverallSys( "syst2", 0.95, 1.05  );

    for(unsigned int j = 0; j < num_histo_sys; j++) {
      std::stringstream histo_sys_stream;
      histo_sys_stream << j;

      HistoSys histo_syst("histo_sys_" + histo_sys_stream.str());
      double uncertainty = (double)j / 10.0 + .4;
      histo_syst.SetHistoLow( CreateGaussian("bkg1_histo_sys_" + histo_sys_stream.str() + " _low", bins, initial_bins-1 - uncertainty, 1, bkg1_height - uncertainty) );
      histo_syst.SetHistoHigh( CreateGaussian("bkg1_histo_sys_" + histo_sys_stream.str() + "_high", bins, initial_bins-1 + uncertainty, 1, bkg1_height + uncertainty) );
      background1.AddHistoSys(histo_syst);
    }


    chan.AddSample( background1 );



    Sample background2("background2");
    double bkg2_height = 1.0 + ((double)i)*5.0/num_channels;
    background2.SetHisto( CreateGaussian("signal", bins, initial_bins-1, 1, bkg2_height) );
    //background2.ActivateStatError( "background2_statUncert", InputFile );
    background2.AddOverallSys( "syst1", 0.98, 1.01  );
    background2.AddOverallSys( "syst3", 0.70, 1.15  );

    for(unsigned int j = 0; j < num_histo_sys; j++) {
      std::stringstream histo_sys_stream;
      histo_sys_stream << j;

      HistoSys histo_syst("histo_sys_" + histo_sys_stream.str());
      double uncertainty = (double)j / 10.0 + .2;
      histo_syst.SetHistoLow( CreateGaussian("bkg2_histo_sys_" + histo_sys_stream.str() + " _low", bins, initial_bins-1 - uncertainty, 1, bkg2_height - uncertainty) );
      histo_syst.SetHistoHigh( CreateGaussian("bkg2_histo_sys_" + histo_sys_stream.str() + "_high", bins, initial_bins-1 + uncertainty, 1, bkg2_height + uncertainty) );
      background2.AddHistoSys(histo_syst);
    }

    chan.AddSample( background2 );



    // Done with this channel
    // Add it to the measurement:
    meas.AddChannel( chan );
    
  }

  std::cout << "About to MakeModelAndMeasurementFast" << std::endl;
  
  // Now, do the measurement
  RooWorkspace* wspace = MakeModelAndMeasurementFast( meas );

  RooAbsPdf* pdf = wspace->pdf("simPdf");
  RooAbsData* data = wspace->data("obsData");


  struct timeval start, end;


  gettimeofday(&start, NULL);
  pdf->fitTo(*data);
  // usleep(2000);
  gettimeofday(&end, NULL);

  // Print the time
  long mtime, seconds, useconds;
  seconds  = end.tv_sec  - start.tv_sec;
  useconds = end.tv_usec - start.tv_usec;
  mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
  std::cout << "Time to fit: " << mtime << " (ms)" << std::endl;

  std::cout << "Successfully MakeModelAndMeasurementFast" << std::endl;

  return;

}
