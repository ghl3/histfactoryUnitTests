
{

  TFile* file = new TFile("results/example_DataDriven_combined_ParamHistFunc2D_model.root");
  RooStats::HistFactory::Measurement* meas = (RooStats::HistFactory::Measurement*) file->Get("ParamHistFunc2D");
  meas->PrintXML("xml", "xml/ParamHist2D");

}
