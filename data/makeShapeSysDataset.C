

{
  
  TFile* file = new TFile("standardShapeSys.root", "RECREATE");
    
  TH1F* signal = new TH1F("signal", "signal", 2,0,2);
  signal->SetBinContent(1, 20);
  signal->SetBinContent(2, 10);

  // Background 1
  TH1F* background1 = new TH1F("background1", "background1", 2,0,2);
  background1->SetBinContent(1, 100);
  background1->SetBinContent(2, 0);

  // Background 1 Error
  TH1F* bkg1ShapeError = new TH1F("bkg1ShapeError", "bkg1ShapeError", 2,0,2);
  bkg1ShapeError->SetBinContent(1, .10);  // 10%
  bkg1ShapeError->SetBinContent(2, .15);  // 15%


  // Background 2
  TH1F* background2 = new TH1F("background2", "background2", 2,0,2);
  background2->SetBinContent(1, 0);
  background2->SetBinContent(2, 100);

  // Background 2 Error
  TH1F* bkg2ShapeError = new TH1F("bkg2ShapeError", "bkg2ShapeError", 2,0,2);
  bkg2ShapeError->SetBinContent(1, .05);  // 5%
  bkg2ShapeError->SetBinContent(2, .20);  // 20%


  TH1F* data = new TH1F("data", "data", 2,0,2);
  data->SetBinContent(1, 122);
  data->SetBinContent(2, 112);

  file.Write();
  file.Close();


}
