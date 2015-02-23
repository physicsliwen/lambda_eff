//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jan 1000 19:34:25 2015 by ROOT version 5.34/09
// from TTree McV0PicoDst/McV0PicoDst from StMcV0Maker
// found on file: auau200GeV_run1000_la_flat.414.la.picodst.root
//////////////////////////////////////////////////////////

#ifndef v0dst_h
#define v0dst_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class v0dst {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           runnumber;
   Int_t           evtnumber;
   Int_t           nrefmult;
   Int_t           nrefmultftpceast;
   Float_t         primvertexX;
   Float_t         primvertexY;
   Float_t         primvertexZ;
   Int_t           centBin9;
   Int_t           centBin16;
   Float_t         magn;
   Int_t           nmcv0;
   Int_t           nv0;
   Float_t         mcv0pt[1000];   //[nmcv0]
   Float_t         mcv0px[1000];   //[nmcv0]
   Float_t         mcv0py[1000];   //[nmcv0]
   Float_t         mcv0pz[1000];   //[nmcv0]
   Float_t         mcv0rapidity[1000];   //[nmcv0]
   Int_t           mcv0id[1000];   //[nmcv0]
   Float_t         mcv0x[1000];   //[nmcv0]
   Float_t         mcv0y[1000];   //[nmcv0]
   Float_t         mcv0z[1000];   //[nmcv0]
   Int_t           v0mcid[1000];   //[nv0]
   Int_t           v0mcstverid[1000];   //[nv0]
   Float_t         v0mass[1000];   //[nv0]
   Float_t         v0pt[1000];   //[nv0]
   Float_t         v0rapidity[1000];   //[nv0]
   Float_t         v0eta[1000];   //[nv0]
   Float_t         v0x[1000];   //[nv0]
   Float_t         v0y[1000];   //[nv0]
   Float_t         v0z[1000];   //[nv0]
   Float_t         v0px[1000];   //[nv0]
   Float_t         v0py[1000];   //[nv0]
   Float_t         v0pz[1000];   //[nv0]
   Float_t         v0declen[1000];   //[nv0]
   Float_t         v0dca[1000];   //[nv0]
   Float_t         v0dca2d[1000];   //[nv0]
   Int_t           dau1id[1000];   //[nv0]
   Int_t           dau2id[1000];   //[nv0]
   Float_t         dau1dca[1000];   //[nv0]
   Float_t         dau1dca2d[1000];   //[nv0]
   Int_t           dau1nhits[1000];   //[nv0]
   Float_t         dau1dedx[1000];   //[nv0]
   Float_t         dau1nsigma[1000];   //[nv0]
   Float_t         dau1pt[1000];   //[nv0]
   Float_t         dau1px[1000];   //[nv0]
   Float_t         dau1py[1000];   //[nv0]
   Float_t         dau1pz[1000];   //[nv0]
   Int_t           dau1tpc[1000];   //[nv0]
   Int_t           dau1ssd[1000];   //[nv0]
   Int_t           dau1svt[1000];   //[nv0]
   Float_t         dau2dca[1000];   //[nv0]
   Float_t         dau2dca2d[1000];   //[nv0]
   Int_t           dau2nhits[1000];   //[nv0]
   Float_t         dau2dedx[1000];   //[nv0]
   Float_t         dau2nsigma[1000];   //[nv0]
   Float_t         dau2pt[1000];   //[nv0]
   Float_t         dau2px[1000];   //[nv0]
   Float_t         dau2py[1000];   //[nv0]
   Float_t         dau2pz[1000];   //[nv0]
   Int_t           dau2tpc[1000];   //[nv0]
   Int_t           dau2ssd[1000];   //[nv0]
   Int_t           dau2svt[1000];   //[nv0]
   Float_t         dca1to2[1000];   //[nv0]

   // List of branches
   TBranch        *b_runnumber;   //!
   TBranch        *b_evtnumber;   //!
   TBranch        *b_nrefmult;   //!
   TBranch        *b_nrefmultftpceast;   //!
   TBranch        *b_primvertexX;   //!
   TBranch        *b_primvertexY;   //!
   TBranch        *b_primvertexZ;   //!
   TBranch        *b_centBin9;   //!
   TBranch        *b_centBin16;   //!
   TBranch        *b_magn;   //!
   TBranch        *b_nmcv0;   //!
   TBranch        *b_nv0;   //!
   TBranch        *b_mcv0pt;   //!
   TBranch        *b_mcv0px;   //!
   TBranch        *b_mcv0py;   //!
   TBranch        *b_mcv0pz;   //!
   TBranch        *b_mcv0rapidity;   //!
   TBranch        *b_mcv0id;   //!
   TBranch        *b_mcv0x;   //!
   TBranch        *b_mcv0y;   //!
   TBranch        *b_mcv0z;   //!
   TBranch        *b_v0mcid;   //!
   TBranch        *b_v0mcstverid;   //!
   TBranch        *b_v0mass;   //!
   TBranch        *b_v0pt;   //!
   TBranch        *b_v0rapidity;   //!
   TBranch        *b_v0eta;   //!
   TBranch        *b_v0x;   //!
   TBranch        *b_v0y;   //!
   TBranch        *b_v0z;   //!
   TBranch        *b_v0px;   //!
   TBranch        *b_v0py;   //!
   TBranch        *b_v0pz;   //!
   TBranch        *b_v0declen;   //!
   TBranch        *b_v0dca;   //!
   TBranch        *b_v0dca2d;   //!
   TBranch        *b_dau1id;   //!
   TBranch        *b_dau2id;   //!
   TBranch        *b_dau1dca;   //!
   TBranch        *b_dau1dca2d;   //!
   TBranch        *b_dau1nhits;   //!
   TBranch        *b_dau1dedx;   //!
   TBranch        *b_dau1nsigma;   //!
   TBranch        *b_dau1pt;   //!
   TBranch        *b_dau1px;   //!
   TBranch        *b_dau1py;   //!
   TBranch        *b_dau1pz;   //!
   TBranch        *b_dau1tpc;   //!
   TBranch        *b_dau1ssd;   //!
   TBranch        *b_dau1svt;   //!
   TBranch        *b_dau2dca;   //!
   TBranch        *b_dau2dca2d;   //!
   TBranch        *b_dau2nhits;   //!
   TBranch        *b_dau2dedx;   //!
   TBranch        *b_dau2nsigma;   //!
   TBranch        *b_dau2pt;   //!
   TBranch        *b_dau2px;   //!
   TBranch        *b_dau2py;   //!
   TBranch        *b_dau2pz;   //!
   TBranch        *b_dau2tpc;   //!
   TBranch        *b_dau2ssd;   //!
   TBranch        *b_dau2svt;   //!
   TBranch        *b_dca1to2;   //!

   v0dst(TTree *tree=0);
   virtual ~v0dst();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef v0dst_cxx
v0dst::v0dst(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("auau200GeV_run11_la_flat.414.la.picodst.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("auau200GeV_run11_la_flat.414.la.picodst.root");
      }
      f->GetObject("McV0PicoDst",tree);

   }
   Init(tree);
}

v0dst::~v0dst()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t v0dst::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t v0dst::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void v0dst::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runnumber", &runnumber, &b_runnumber);
   fChain->SetBranchAddress("evtnumber", &evtnumber, &b_evtnumber);
   fChain->SetBranchAddress("nrefmult", &nrefmult, &b_nrefmult);
   fChain->SetBranchAddress("nrefmultftpceast", &nrefmultftpceast, &b_nrefmultftpceast);
   fChain->SetBranchAddress("primvertexX", &primvertexX, &b_primvertexX);
   fChain->SetBranchAddress("primvertexY", &primvertexY, &b_primvertexY);
   fChain->SetBranchAddress("primvertexZ", &primvertexZ, &b_primvertexZ);
   fChain->SetBranchAddress("centBin9", &centBin9, &b_centBin9);
   fChain->SetBranchAddress("centBin16", &centBin16, &b_centBin16);
   fChain->SetBranchAddress("magn", &magn, &b_magn);
   fChain->SetBranchAddress("nmcv0", &nmcv0, &b_nmcv0);
   fChain->SetBranchAddress("nv0", &nv0, &b_nv0);
   fChain->SetBranchAddress("mcv0pt", mcv0pt, &b_mcv0pt);
   fChain->SetBranchAddress("mcv0px", mcv0px, &b_mcv0px);
   fChain->SetBranchAddress("mcv0py", mcv0py, &b_mcv0py);
   fChain->SetBranchAddress("mcv0pz", mcv0pz, &b_mcv0pz);
   fChain->SetBranchAddress("mcv0rapidity", mcv0rapidity, &b_mcv0rapidity);
   fChain->SetBranchAddress("mcv0id", mcv0id, &b_mcv0id);
   fChain->SetBranchAddress("mcv0x", mcv0x, &b_mcv0x);
   fChain->SetBranchAddress("mcv0y", mcv0y, &b_mcv0y);
   fChain->SetBranchAddress("mcv0z", mcv0z, &b_mcv0z);
   fChain->SetBranchAddress("v0mcid", v0mcid, &b_v0mcid);
   fChain->SetBranchAddress("v0mcstverid", v0mcstverid, &b_v0mcstverid);
   fChain->SetBranchAddress("v0mass", v0mass, &b_v0mass);
   fChain->SetBranchAddress("v0pt", v0pt, &b_v0pt);
   fChain->SetBranchAddress("v0rapidity", v0rapidity, &b_v0rapidity);
   fChain->SetBranchAddress("v0eta", v0eta, &b_v0eta);
   fChain->SetBranchAddress("v0x", v0x, &b_v0x);
   fChain->SetBranchAddress("v0y", v0y, &b_v0y);
   fChain->SetBranchAddress("v0z", v0z, &b_v0z);
   fChain->SetBranchAddress("v0px", v0px, &b_v0px);
   fChain->SetBranchAddress("v0py", v0py, &b_v0py);
   fChain->SetBranchAddress("v0pz", v0pz, &b_v0pz);
   fChain->SetBranchAddress("v0declen", v0declen, &b_v0declen);
   fChain->SetBranchAddress("v0dca", v0dca, &b_v0dca);
   fChain->SetBranchAddress("v0dca2d", v0dca2d, &b_v0dca2d);
   fChain->SetBranchAddress("dau1id", dau1id, &b_dau1id);
   fChain->SetBranchAddress("dau2id", dau2id, &b_dau2id);
   fChain->SetBranchAddress("dau1dca", dau1dca, &b_dau1dca);
   fChain->SetBranchAddress("dau1dca2d", dau1dca2d, &b_dau1dca2d);
   fChain->SetBranchAddress("dau1nhits", dau1nhits, &b_dau1nhits);
   fChain->SetBranchAddress("dau1dedx", dau1dedx, &b_dau1dedx);
   fChain->SetBranchAddress("dau1nsigma", dau1nsigma, &b_dau1nsigma);
   fChain->SetBranchAddress("dau1pt", dau1pt, &b_dau1pt);
   fChain->SetBranchAddress("dau1px", dau1px, &b_dau1px);
   fChain->SetBranchAddress("dau1py", dau1py, &b_dau1py);
   fChain->SetBranchAddress("dau1pz", dau1pz, &b_dau1pz);
   fChain->SetBranchAddress("dau1tpc", dau1tpc, &b_dau1tpc);
   fChain->SetBranchAddress("dau1ssd", dau1ssd, &b_dau1ssd);
   fChain->SetBranchAddress("dau1svt", dau1svt, &b_dau1svt);
   fChain->SetBranchAddress("dau2dca", dau2dca, &b_dau2dca);
   fChain->SetBranchAddress("dau2dca2d", dau2dca2d, &b_dau2dca2d);
   fChain->SetBranchAddress("dau2nhits", dau2nhits, &b_dau2nhits);
   fChain->SetBranchAddress("dau2dedx", dau2dedx, &b_dau2dedx);
   fChain->SetBranchAddress("dau2nsigma", dau2nsigma, &b_dau2nsigma);
   fChain->SetBranchAddress("dau2pt", dau2pt, &b_dau2pt);
   fChain->SetBranchAddress("dau2px", dau2px, &b_dau2px);
   fChain->SetBranchAddress("dau2py", dau2py, &b_dau2py);
   fChain->SetBranchAddress("dau2pz", dau2pz, &b_dau2pz);
   fChain->SetBranchAddress("dau2tpc", dau2tpc, &b_dau2tpc);
   fChain->SetBranchAddress("dau2ssd", dau2ssd, &b_dau2ssd);
   fChain->SetBranchAddress("dau2svt", dau2svt, &b_dau2svt);
   fChain->SetBranchAddress("dca1to2", dca1to2, &b_dca1to2);
   Notify();
}

Bool_t v0dst::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void v0dst::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t v0dst::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef v0dst_cxx
