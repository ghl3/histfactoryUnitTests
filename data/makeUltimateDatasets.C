

{
  
  TFile* fileA = new TFile("UltimateA.root", "RECREATE");

  TDirectory* dataDir = fileA->mkdir( "data");
  dataDir->cd();            
  
  TH2F* data = new TH2F("data", "data", 2,0,2, 2,0,2);
  data->SetBinContent(1, 1, 122);
  data->SetBinContent(2, 1, 122);
  data->SetBinContent(1, 2, 132);
  data->SetBinContent(2, 2, 132);



  TDirectory* signalDir = fileA->mkdir( "signal");
  signalDir->cd();            
  
  TH2F* signal = new TH2F("signal", "signal", 2,0,2, 2,0,2);
  signal->SetBinContent(1, 1, 10);
  signal->SetBinContent(2, 1, 10);
  signal->SetBinContent(1, 2, 20);
  signal->SetBinContent(2, 2, 20);
  
  TH2F* signal_high = new TH2F("histoSys1_high", "signal", 2,0,2, 2,0,2);
  signal_high->SetBinContent(1, 1, 15);
  signal_high->SetBinContent(2, 1, 15);
  signal_high->SetBinContent(1, 2, 25);
  signal_high->SetBinContent(2, 2, 25);

  TH2F* signal_low = new TH2F("histoSys1_low", "signal", 2,0,2, 2,0,2);
  signal_low->SetBinContent(1, 1, 05);
  signal_low->SetBinContent(2, 1, 05);
  signal_low->SetBinContent(1, 2, 15);
  signal_low->SetBinContent(2, 2, 15);


  TDirectory* background1Dir = fileA->mkdir( "background1");
  background1Dir->cd();            
  
  // Background 1
  TH2F* background1 = new TH2F("background1", "background1", 2,0,2, 2,0,2);
  background1->SetBinContent(1, 1, 100);
  background1->SetBinContent(2, 1, 100);
  background1->SetBinContent(1, 2, 10);
  background1->SetBinContent(2, 2, 10);

  TH2F* background1_high = new TH2F("histoSys1_high", "background1", 2,0,2, 2,0,2);
  background1_high->SetBinContent(1, 1, 105);
  background1_high->SetBinContent(2, 1, 105);
  background1_high->SetBinContent(1, 2, 15);
  background1_high->SetBinContent(2, 2, 15);

  TH2F* background1_low = new TH2F("histoSys1_low", "background1", 2,0,2, 2,0,2);
  background1_low->SetBinContent(1, 1, 95);
  background1_low->SetBinContent(2, 1, 95);
  background1_low->SetBinContent(1, 2, 5);
  background1_low->SetBinContent(2, 2, 5);

  // Background 1 Error
  TH2F* bkg1ShapeError = new TH2F("bkg1ShapeError", "bkg1ShapeError", 2,0,2, 2,0,2);
  bkg1ShapeError->SetBinContent(1, 1, .10);  // 10%
  bkg1ShapeError->SetBinContent(2, 1, .15);  // 15%
  bkg1ShapeError->SetBinContent(1, 2, .10);  // 10%
  bkg1ShapeError->SetBinContent(2, 2, .15);  // 15%


  TDirectory* background2Dir = fileA->mkdir( "background2");
  background2Dir->cd();            


  // Background 2
  TH2F* background2 = new TH2F("background2", "background2", 2,0,2, 2,0,2);
  background2->SetBinContent(1, 1, 10);
  background2->SetBinContent(2, 1, 10);
  background2->SetBinContent(1, 2, 100);
  background2->SetBinContent(2, 2, 100);

  // Background 2 Error
  TH2F* bkg2ShapeError = new TH2F("bkg2ShapeError", "bkg2ShapeError", 2,0,2, 2,0,2);
  bkg2ShapeError->SetBinContent(1, 1, .05);  // 5%
  bkg2ShapeError->SetBinContent(2, 1, .20);  // 20%
  bkg2ShapeError->SetBinContent(1, 2, .05);  // 5%
  bkg2ShapeError->SetBinContent(2, 2, .20);  // 20%

  gDirectory->cd();

  fileA.Write();
  fileA.Close();
  

  // File 2 has everything in the same path

  TFile* fileB = new TFile("UltimateB.root", "RECREATE");

  TH2F* data = new TH2F("data", "data", 2,0,2, 2,0,2);
  data->SetBinContent(1, 1, 122);
  data->SetBinContent(2, 1, 122);
  data->SetBinContent(1, 2, 132);
  data->SetBinContent(2, 2, 132);

    
  TH2F* signal = new TH2F("signal", "signal", 2,0,2, 2,0,2);
  signal->SetBinContent(1, 1, 10);
  signal->SetBinContent(2, 1, 10);
  signal->SetBinContent(1, 2, 20);
  signal->SetBinContent(2, 2, 20);

  // Background 1
  TH2F* background1 = new TH2F("background1", "background1", 2,0,2, 2,0,2);
  background1->SetBinContent(1, 1, 100);
  background1->SetBinContent(2, 1, 100);
  background1->SetBinContent(1, 2, 10);
  background1->SetBinContent(2, 2, 10);

  // Background 1 Error
  TH2F* background1_statUncert = new TH2F("background1_statUncert", "bkg 1 stat uncert", 2,0,2, 2,0,2);
  background1_statUncert->SetBinContent(1, 1, .5);  // 10%
  background1_statUncert->SetBinContent(2, 1, .5);  // 15%
  background1_statUncert->SetBinContent(1, 2, .5);  // 10%
  background1_statUncert->SetBinContent(2, 2, .5);  // 15%

  TH2F* bkg1ShapeError = new TH2F("bkg1ShapeError", "bkg1ShapeError", 2,0,2, 2,0,2);
  bkg1ShapeError->SetBinContent(1, 1, .10);  // 10%
  bkg1ShapeError->SetBinContent(2, 1, .15);  // 15%
  bkg1ShapeError->SetBinContent(1, 2, .10);  // 10%
  bkg1ShapeError->SetBinContent(2, 2, .15);  // 15%


  // Background 2
  TH2F* background2 = new TH2F("background2", "background2", 2,0,2, 2,0,2);
  background2->SetBinContent(1, 1, 10);
  background2->SetBinContent(2, 1, 10);
  background2->SetBinContent(1, 2, 100);
  background2->SetBinContent(2, 2, 100);

  // Background 2 Error
  TH2F* bkg2ShapeError = new TH2F("bkg2ShapeError", "bkg2ShapeError", 2,0,2, 2,0,2);
  bkg2ShapeError->SetBinContent(1, 1, .05);  // 5%
  bkg2ShapeError->SetBinContent(2, 1, .20);  // 20%
  bkg2ShapeError->SetBinContent(1, 2, .05);  // 5%
  bkg2ShapeError->SetBinContent(2, 2, .20);  // 20%


  fileB.Write();
  fileB.Close();


}
