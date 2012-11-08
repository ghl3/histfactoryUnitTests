#!/usr/bin/env python


import ROOT
import os
import subprocess

def main():

    #ROOT.gROOT.ProcessLine(".L StandardProfileLikelihoodDemo.C+")
    #subprocess.call('root.exe -b "gROOT.LoadMacro(\"StandardProfileLikelihoodDemo.C+\")"', shell=True)
    #os.system( 'root.exe -b -q ".L StandardProfileLikelihoodDemo.C"')

    #os.system(
    #os.system(".q")
    #ROOT.gDebug = 7;

    ROOT.gSystem.Load("libCint.so")
    ROOT.gSystem.Load("libRint.so")
    ROOT.gROOT.LoadMacro("$ROOTSYS/tutorials/roostats/StandardProfileLikelihoodDemo.C+")
    ROOT.StandardProfileLikelihoodDemo()

    #ROOT.gInterpreter.GenerateDictionary("Test","Test.C");

    #ROOT.gROOT.LoadMacro("Test.C+")
    #ROOT.Test()

    pass

if __name__ == "__main__":
    main()
