
#include "TH1F.h"

#include "RooFit.h"
#include "RooRealVar.h"
#include "RooArgList.h"
#include "RooWorkspace.h"

#include "RooStats/HistFactory/ParamHistFunc.h"

using namespace RooFit;


void UnitTest() {

  RooWorkspace w("w");

  RooRealVar x("x","x",0,-2,2);
  x.setBins(4);

  RooArgList Params = ParamHistFunc::createParamSet(w, "gamma", x );
  std::cout << "Params: " << Params << std::endl;

  ParamHistFunc HistFunc("HistFunc","HistFunc", x, Params);


  w.var("gamma_bin_0")->setVal(0);
  w.var("gamma_bin_1")->setVal(1);
  w.var("gamma_bin_2")->setVal(2);
  w.var("gamma_bin_3")->setVal(3);


  for(unsigned int i = 0; i < 10; ++i) {

    double x_pos = -2 + (4.0/10.0)*i;
    x.setVal( x_pos );

    //std::cout << "Setting x: " << x_pos << std::endl;
    std::cout << "HistFunc(x=" << x_pos << ")"
	      << " = " << HistFunc.getVal()
	      << " (Bin = " << HistFunc.getCurrentBin() << ")"
	      << std::endl;
  }



  w.import( HistFunc, RecycleConflictNodes() );


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
