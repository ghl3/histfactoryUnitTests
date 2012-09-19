

{
  
  TFile* file = new TFile("NumberCounting.root", "RECREATE");

  // Make the Data
  TH1F* data = new TH1F("data", "data", 1,0,1 );
  data->SetBinContent(1, 20); // 20 events in data

  // Make the Signal
  TH1F* signal = new TH1F("signal", "signal", 1,0,1 );
  signal->SetBinContent(1, 5);

  // Background 1
  TH1F* background1 = new TH1F("background1", "background1", 1,0,1 );
  background1->SetBinContent(1, 10);

  // Background 2
  TH1F* background2 = new TH1F("background2", "background2", 1,0,1 );
  background2->SetBinContent(1, 4);


  // Save the File
  gDirectory->cd();

  file.Write();
  file.Close();
  
}
