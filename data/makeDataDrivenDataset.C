

{
  
  TFile* file = new TFile("dataDriven.root", "RECREATE");

  TH1F* FlatHist = new TH1F("FlatHist","FlatHist", 2,0,2);
  FlatHist->SetBinContent( 1, 1.0 );
  FlatHist->SetBinContent( 2, 1.0 );
    
  TH1F* Signal = new TH1F("Signal", "Signal", 2,0,2);
  Signal->SetBinContent(1, 10);
  Signal->SetBinContent(2, 80);

  // MC Background
  TH1F* Background1 = new TH1F("Background1", "Background1", 2,0,2);
  Background1->SetBinContent(1, 20);
  Background1->SetBinContent(2, 20);

  // This is the "Data-Driven" measurement
  // that represents Background2
  // Assume the extrapolation factor is 1.0
  TH1F* ControlRegion = new TH1F("ControlRegion", "ControlRegion", 2,0,2);
  ControlRegion->SetBinContent(1, 75);
  ControlRegion->SetBinContent(2, 35);


  TH1F* StatUncert = new TH1F("StatUncert", "StatUncert", 2,0,2);
  StatUncert->SetBinContent(1, .15);  // 15% uncertainty
  StatUncert->SetBinContent(2, .15);  // 15% uncertainty


  TH1F* data = new TH1F("data", "data", 2,0,2);
  data->SetBinContent(1, 90);
  data->SetBinContent(2, 110);


  file.Write();
  file.Close();


}
