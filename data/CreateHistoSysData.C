

{


  TFile* file_data = new TFile( "data/example_HistoSys_data.root", "RECREATE" );

  TH1F* data = new TH1F( "data", "data", 2, 0, 2 );

  // Fill data as 10, 15
  for( unsigned int i=0; i < 10; ++i) data->Fill( .5 );
  for( unsigned int i=0; i < 15; ++i) data->Fill( 1.5 );
  data->Write();

  //
  // Signal
  //

  TFile* file_signal = new TFile( "data/example_HistoSys_signal.root", "RECREATE" );
  TH1F* signal = new TH1F("signal", "signal", 2, 0, 2 );
  // Fill as 4, 8
  signal->SetBinContent( 1, 4 );
  signal->SetBinContent( 2, 8 );
  signal->Write();

  TH1F* signal_up = new TH1F("signal_up", "signal up", 2, 0, 2 );
  // Fill as 5, 10
  signal_up->SetBinContent( 1, 5 );
  signal_up->SetBinContent( 2, 10 );
  signal_up->Write();

  TH1F* signal_down = new TH1F("signal_down", "signal down", 2, 0, 2 );
  // Fill as 3, 6
  signal_down->SetBinContent( 1, 3 );
  signal_down->SetBinContent( 2, 6 );
  signal_down->Write();

  file_signal->Close();

  //
  // Background
  //

  TFile* file_background1 = new TFile( "data/example_HistoSys_background1.root", "RECREATE" );
  TH1F* background1 = new TH1F("background1", "background1", 2, 0, 2 );
  // Fill as 6, 7
  background1->SetBinContent( 1, 6 );
  background1->SetBinContent( 2, 7 );
  background1->Write();

  TH1F* background1_up = new TH1F("background1_up", "background1 up", 2, 0, 2 );
  // Fill as 7, 8
  background1_up->SetBinContent( 1, 7 );
  background1_up->SetBinContent( 2, 8 );
  background1_up->Write();

  TH1F* background1_down = new TH1F("background1_down", "background1 down", 2, 0, 2 );
  // Fill as 5, 5
  background1_down->SetBinContent( 1, 5 );
  background1_down->SetBinContent( 2, 5 );
  background1_down->Write();

  file_background1->Close();


}
