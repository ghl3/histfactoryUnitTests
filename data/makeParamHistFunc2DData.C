

#include "TFile.h"
#include "TH2F.h"


void makeDataDriven() {


  TFile* DataDriven2D = new TFile("dataDriven2D.root", "RECREATE");
  DataDriven2D->cd();

  TH2F* unit_hist = new TH2F("unit_hist", "unit_hist", 2,0,2, 2,0,2);
  unit_hist->SetBinContent(1, 1, 1.0); // 1  + 9.5  + 0.80*(9-1) 
  unit_hist->SetBinContent(1, 2, 1.0); // 1  + 10   + 0.75*(8-1)
  unit_hist->SetBinContent(2, 1, 1.0); // 10 + 10.5 + 0.30*(11-5)
  unit_hist->SetBinContent(2, 2, 1.0); // 10 + 11   + 0.20*(10-5)
  unit_hist->Write();

  TH2F* signal_data = new TH2F("signal_data", "signal_data", 2,0,2, 2,0,2);
  signal_data->SetBinContent(1, 1, 12); // 1  + 9.5  + 0.80*8 
  signal_data->SetBinContent(1, 2, 11); // 1  + 10   + 0.75*7
  signal_data->SetBinContent(2, 1, 23); // 10 + 10.5 + 0.30*6
  signal_data->SetBinContent(2, 2, 22); // 10 + 11   + 0.20*5
  signal_data->Write();

  TH2F* signal_signal = new TH2F("signal", "signal signal", 2,0,2, 2,0,2);
  signal_signal->SetBinContent(1, 1, 1);
  signal_signal->SetBinContent(1, 2, 1);
  signal_signal->SetBinContent(2, 1, 10);
  signal_signal->SetBinContent(2, 2, 10);
  signal_signal->Write();

  TH2F* signal_bkg_1 = new TH2F("bkg_1", "signal bkg 1", 2,0,2, 2,0,2);
  signal_bkg_1->SetBinContent(1, 1, 9.5);
  signal_bkg_1->SetBinContent(1, 2, 10);
  signal_bkg_1->SetBinContent(2, 1, 10.5);
  signal_bkg_1->SetBinContent(2, 2, 11);
  signal_bkg_1->Write();

  TH2F* signal_bkg2_efficiency = new TH2F("bkg2_efficiency", "signal bkg 1", 2,0,2, 2,0,2);
  signal_bkg2_efficiency->SetBinContent(1, 1, .80);
  signal_bkg2_efficiency->SetBinContent(1, 2, .75);
  signal_bkg2_efficiency->SetBinContent(2, 1, .30);
  signal_bkg2_efficiency->SetBinContent(2, 2, .20);
  signal_bkg2_efficiency->Write();

  // The Control Region

  TH2F* control_data = new TH2F("control_data", "control_data", 2,0,2, 2,0,2);
  control_data->SetBinContent(1, 1, 9);
  control_data->SetBinContent(1, 2, 8);
  control_data->SetBinContent(2, 1, 11);
  control_data->SetBinContent(2, 2, 10);
  control_data->Write();

  TH2F* control_bkg = new TH2F("control_bkg", "control_bkg", 2,0,2, 2,0,2);
  control_bkg->SetBinContent(1, 1, 1);
  control_bkg->SetBinContent(1, 2, 1);
  control_bkg->SetBinContent(2, 1, 5);
  control_bkg->SetBinContent(2, 2, 5);
  control_bkg->Write();

  DataDriven2D->Write();

}
