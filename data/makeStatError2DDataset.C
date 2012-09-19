
{
  
  TFile* file = new TFile("standardStatError2D.root", "RECREATE");
    
  TH2F* signal = new TH2F("signal", "signal", 3,0,30, 2,0,2);
  signal->SetBinContent(1, 1, 10);
  signal->SetBinContent(2, 1, 10);
  signal->SetBinContent(3, 1, 10);
  signal->SetBinContent(1, 2, 20);
  signal->SetBinContent(2, 2, 20);
  signal->SetBinContent(3, 2, 20);

  // Background 1
  TH2F* background1 = new TH2F("background1", "background1", 3,0,30, 2,0,2);
  background1->SetBinContent(1, 1, 101);
  background1->SetBinContent(2, 1, 102);
  background1->SetBinContent(3, 1, 103);
  background1->SetBinContent(1, 2, 14);
  background1->SetBinContent(2, 2, 15);
  background1->SetBinContent(3, 2, 16);

  // Background 1 Error
  TH2F* bkg1StatUncert = new TH2F("bkg1StatUncert", "bkg1StatUncert", 3,0,30, 2,0,2);
  bkg1StatUncert->SetBinContent(1, 1, .05);  // 05%
  bkg1StatUncert->SetBinContent(2, 1, .10);  // 10%
  bkg1StatUncert->SetBinContent(3, 1, .15);  // 10%
  bkg1StatUncert->SetBinContent(1, 2, .20);  // 15%
  bkg1StatUncert->SetBinContent(2, 2, .25);  // 20%
  bkg1StatUncert->SetBinContent(3, 2, .30);  // 20%


  // Background 2
  TH2F* background2 = new TH2F("background2", "background2", 3,0,30, 2,0,2);
  background2->SetBinContent(1, 1, 0);
  background2->SetBinContent(2, 1, 10);
  background2->SetBinContent(3, 1, 20);
  background2->SetBinContent(1, 2, 100);
  background2->SetBinContent(2, 2, 110);
  background2->SetBinContent(3, 2, 120);


  TH2F* data = new TH2F("data", "data", 3,0,30, 2,0,2);
  data->SetBinContent(1, 1, 110);
  data->SetBinContent(2, 1, 120);
  data->SetBinContent(3, 1, 131);
  data->SetBinContent(1, 2, 135);
  data->SetBinContent(2, 2, 145);
  data->SetBinContent(3, 2, 154);

  file.Write();
  file.Close();


}
