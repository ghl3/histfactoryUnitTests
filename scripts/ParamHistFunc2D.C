
#include "TH1F.h"
#include "TH2F.h"

#include "RooFit.h"
#include "RooRealVar.h"
#include "RooArgList.h"
#include "RooWorkspace.h"

#include "RooStats/HistFactory/ParamHistFunc.h"

using namespace RooFit;


void UnitTest2D() {

  RooWorkspace w("w");

  RooRealVar x("x","x",0,0,4);
  x.setBins(4);

  RooRealVar y("y","y",0,0,4);
  y.setBins(4);



  RooArgList Params = ParamHistFunc::createParamSet(w, "gamma", RooArgSet(x,y) );
  std::cout << "Params: " << Params << std::endl;

  ParamHistFunc HistFunc("HistFunc","HistFunc", RooArgSet(x,y), Params);


  TH2F* hist = new TH2F("Hist", "Hist", 4,0,4,  4,0,4 );
  hist->SetBinContent(1,1, 00);
  hist->SetBinContent(2,1, 10);
  hist->SetBinContent(3,1, 20);
  hist->SetBinContent(4,1, 30);
  hist->SetBinContent(1,2, 01);
  hist->SetBinContent(2,2, 11);
  hist->SetBinContent(3,2, 21);
  hist->SetBinContent(4,2, 31);
  hist->SetBinContent(1,3, 02);
  hist->SetBinContent(2,3, 12);
  hist->SetBinContent(3,3, 22);
  hist->SetBinContent(4,3, 32);
  hist->SetBinContent(1,4, 03);
  hist->SetBinContent(2,4, 13);
  hist->SetBinContent(3,4, 23);
  hist->SetBinContent(4,4, 33);

  HistFunc.setShape(hist);
  HistFunc.setConstant(true);

  /*
  w.var("gamma_bin_0_0")->setVal(00);
  w.var("gamma_bin_1_0")->setVal(10);
  w.var("gamma_bin_2_0")->setVal(20);
  w.var("gamma_bin_3_0")->setVal(30);
  w.var("gamma_bin_0_1")->setVal(01);
  w.var("gamma_bin_1_1")->setVal(11);
  w.var("gamma_bin_2_1")->setVal(21);
  w.var("gamma_bin_3_1")->setVal(31);
  w.var("gamma_bin_0_2")->setVal(2);
  w.var("gamma_bin_1_2")->setVal(12);
  w.var("gamma_bin_2_2")->setVal(22);
  w.var("gamma_bin_3_2")->setVal(32);
  w.var("gamma_bin_0_3")->setVal(3);
  w.var("gamma_bin_1_3")->setVal(13);
  w.var("gamma_bin_2_3")->setVal(23);
  w.var("gamma_bin_3_3")->setVal(33);
  */

  unsigned int steps = 5;

  for(unsigned int i = 0; i < steps; ++i) {
    for(unsigned int j = 0; j < steps; ++j) {

      double x_pos = (4.0/steps)*i;
      double y_pos = (4.0/steps)*j;
      
      x.setVal( x_pos );
      y.setVal( y_pos );
      
      //std::cout << "Setting x: " << x_pos << std::endl;
      std::cout << "HistFunc(x=" << x_pos << " y=" << y_pos << ")"
		<< " = " << HistFunc.getVal()
		<< " (Bin = " << HistFunc.getCurrentBin() << ")"
		<< std::endl;
    }
  }



  w.import( HistFunc, RecycleConflictNodes() );

  

  std::cout << std::endl << "Texting Index functions: " << std::endl;
  
  unsigned int numBins = HistFunc.numBins();
  std::cout << "Num Bins: " << numBins << std::endl;

  for( unsigned int i = 0; i < numBins; ++i ) {

    std::cout << "Index: " << i << std::endl;
    HistFunc.getParameter(i).Print();
    HistFunc.get(i)->Print("V");
  }


  return;

  ParamHistFunc* HistFuncWSpace = (ParamHistFunc*) w.function("HistFunc");
  RooRealVar* x_var = (RooRealVar*) w.var("x");

  std::cout << "Address of x-var in Workspace: "     << x_var << std::endl;
  std::cout << "Address of x-var in ParamHistFunc: " << x_var << std::endl;


  for(unsigned int i = 0; i < 10; ++i) {

    double x_pos = -2 + (4.0/10.0)*i;
    x_var->setVal( x_pos );

    //std::cout << "Setting x: " << x_pos << std::endl;
    std::cout << "HistFunc(x=" << x_pos << ")"
	      << " = " << HistFuncWSpace->getVal()
	      << " (Bin = " << HistFuncWSpace->getCurrentBin() << ")"
	      << std::endl;
  }


  return;

  


  w.var("gamma_bin_0")->setVal(1);
  w.var("gamma_bin_1")->setVal(1);
  w.var("gamma_bin_2")->setVal(1);
  w.var("gamma_bin_3")->setVal(1);


  std::cout << std::endl << std::endl;




  RooArgSet xArgs(x);



  for(unsigned int i = 0; i < 10; ++i) {

    double alpha_pos = 0 + (2.0/10.0)*i;
    w.var("gamma_bin_1")->setVal( alpha_pos );

    std::cout << "Integral (gamma1 = " << alpha_pos << "): " << HistFunc.analyticalIntegralWN(1, &xArgs, "" ) << std::endl;

  }


  std::cout << std::endl << std::endl;


  // Test the other constructors:

  TH1F* Hist = new TH1F("Hist","Hist", 4, -2, 2);
  Hist->SetBinContent(1, 2.0);
  Hist->SetBinContent(2, 2.0);
  Hist->SetBinContent(3, 2.0);
  Hist->SetBinContent(4, 3.0);

  
  ParamHistFunc HistFuncTH1F("HistFuncTH1F","HistFuncTH1F", x, Params, Hist);



  for(unsigned int i = 0; i < 10; ++i) {

    double x_pos = -2 + (4.0/10.0)*i;
    x.setVal( x_pos );

    //std::cout << "Setting x: " << x_pos << std::endl;
    std::cout << "HistFuncTH1F(x=" << x_pos << ")"
	      << " = " << HistFuncTH1F.getVal()
	      << std::endl;
  }

  std::cout << std::endl << std::endl;


  for(unsigned int i = 0; i < 10; ++i) {

    double alpha_pos = 0 + (2.0/10.0)*i;
    w.var("gamma_bin_1")->setVal( alpha_pos );

    std::cout << "Integral (gamma1 = " << alpha_pos << "): " << HistFuncTH1F.analyticalIntegralWN(1, &xArgs, "" ) << std::endl;

  }

  std::cout << std::endl << std::endl;





}
