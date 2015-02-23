#wrapper to run cuts.C in ACLIC mode. (much faster)
{
   gROOT->Reset();
   gROOT->LoadMacro("v0dst.C+");
   gROOT->LoadMacro("cuts_fp_la.C+");
   cuts_fp_la(0,10000);
}

