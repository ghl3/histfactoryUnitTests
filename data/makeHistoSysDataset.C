
{
  
  TFile* file = new TFile("HistoSys.root", "RECREATE");
    
  TH1F* signal = new TH1F("signal", "signal", 6,0,6);
  signal->SetBinContent(1, 10);
  signal->SetBinContent(2, 10);
  signal->SetBinContent(3, 10);
  signal->SetBinContent(4, 20);
  signal->SetBinContent(5, 20);
  signal->SetBinContent(6, 20);

  // MC background
  TH1F* background1 = new TH1F("background1", "background1", 6,0,6);
  background1->SetBinContent(1, 101);
  background1->SetBinContent(2, 102);
  background1->SetBinContent(3, 103);
  background1->SetBinContent(4, 14);
  background1->SetBinContent(5, 15);
  background1->SetBinContent(6, 16);

  // A small statistical uncertainty
  TH1F* bkg1StatUncert = new TH1F("bkg1ShapeError", "bkg1ShapeError", 6,0,6);
  bkg1StatUncert->SetBinContent(1, .05);  // 05%  uncertainty
  bkg1StatUncert->SetBinContent(2, .10);  // 10%  uncertainty
  bkg1StatUncert->SetBinContent(3, .15);  // 10%  uncertainty
  bkg1StatUncert->SetBinContent(4, .20);  // 15%  uncertainty
  bkg1StatUncert->SetBinContent(5, .25);  // 20%  uncertainty
  bkg1StatUncert->SetBinContent(6, .30);  // 20%  uncertainty


  // MC background
  TH1F* background2 = new TH1F("background2", "background2", 6,0,6);
  background2->SetBinContent(1, 0);
  background2->SetBinContent(2, 10);
  background2->SetBinContent(3, 20);
  background2->SetBinContent(4, 100);
  background2->SetBinContent(5, 110);
  background2->SetBinContent(6, 120);

  TH1F* background2_up = new TH1F("background2_up", "background2_up", 6,0,6);
  background2_up->SetBinContent(1, 5);
  background2_up->SetBinContent(2, 15);
  background2_up->SetBinContent(3, 25);
  background2_up->SetBinContent(4, 105);
  background2_up->SetBinContent(5, 115);
  background2_up->SetBinContent(6, 125);

  TH1F* background2_down = new TH1F("background2_down", "background2_down", 6,0,6);
  background2_down->SetBinContent(1, 0);
  background2_down->SetBinContent(2, 5);
  background2_down->SetBinContent(3, 15);
  background2_down->SetBinContent(4, 95);
  background2_down->SetBinContent(5, 105);
  background2_down->SetBinContent(6, 115);


  TH1F* data = new TH1F("data", "data", 6,0,6);
  data->SetBinContent(1, 110);
  data->SetBinContent(2, 120);
  data->SetBinContent(3, 131);
  data->SetBinContent(4, 135);
  data->SetBinContent(5, 145);
  data->SetBinContent(6, 154);


  TH1F* FlatHist = new TH1F("FlatHist","FlatHist", 6,0,6);
  FlatHist->SetBinContent( 1, 1.0 );
  FlatHist->SetBinContent( 2, 1.0 );
  FlatHist->SetBinContent( 3, 1.0 );
  FlatHist->SetBinContent( 4, 1.0 );
  FlatHist->SetBinContent( 5, 1.0 );
  FlatHist->SetBinContent( 6, 1.0 );


  file.Write();
  file.Close();


}
