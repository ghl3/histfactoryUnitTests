

{
  
  TFile* file = new TFile("standardShapeSys2D.root", "RECREATE");
    
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


  TH2F* data = new TH2F("data", "data", 2,0,2, 2,0,2);
  data->SetBinContent(1, 1, 122);
  data->SetBinContent(2, 1, 122);
  data->SetBinContent(1, 2, 132);
  data->SetBinContent(2, 2, 132);

  file.Write();
  file.Close();


}
