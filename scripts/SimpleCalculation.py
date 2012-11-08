#!/usr/bin/env python


#import ROOT


def main():

    try:
        import ROOT
    except:
        print "It seems that pyROOT isn't properly configured"
        return


    """
    Create a HistFactory measurement from python (!!!!!)
    """

    InputFile =  "./data/example.root"

    # Create the measurement
    meas = ROOT.RooStats.HistFactory.Measurement("myMeasurement", "my Measurement")
    meas.SetOutputFilePrefix( "myMeasurementResults/myMeasurement" )
    meas.SetPOI( "SignalStrength" )


    meas.SetLumi( 1.0 )
    meas.SetLumiRelErr( 0.10 )
    meas.SetExportOnly( False )

    # Create a channel
    chan = ROOT.RooStats.HistFactory.Channel( "channel1" )
    chan.SetData( "data", InputFile )

    # Create the signal sample
    signal = ROOT.RooStats.HistFactory.Sample( "signal", "signal", InputFile )
    signal.AddOverallSys( "SignalUncertainty",    0.95, 1.05 )
    signal.AddNormFactor( "SignalStrength", 1, 0, 3 )
    chan.AddSample( signal )


    # Create the background sample
    background1 = ROOT.RooStats.HistFactory.Sample( "background1", "background1", InputFile )
    background1.AddOverallSys( "BackgroundUncertainty", 0.90, 1.10  )
    chan.AddSample( background1 )

    background2 = ROOT.RooStats.HistFactory.Sample( "background2", "background2", InputFile )
    background2.AddOverallSys( "BackgroundUncertainty", 0.90, 1.10  )
    chan.AddSample( background2 )



    # Add this channel to the measurement
    meas.AddChannel( chan )

    # Print Some Information
    meas.CollectHistograms()
    meas.PrintTree()
    meas.PrintXML( "xmlFromPy" )
    meas.PrintXML( "xmlFromPy", meas.GetOutputFilePrefix() )

    ROOT.RooStats.HistFactory.MakeModelAndMeasurementFast( meas )

    pass


if __name__ == "__main__":
    main()
