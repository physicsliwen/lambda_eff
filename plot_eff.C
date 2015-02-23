#include <TCanvas.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
#include <TAxis.h>
void plot_eff(char* particle_name){
   gStyle -> SetPadTickX(1);
   gStyle -> SetPadTickY(1);
   gStyle -> SetTitleX(0.5);
   gStyle -> SetTitleAlign(23);
   gStyle -> SetNdivisions(505);

   char par_nm[100];
   char infile_nm_exp[100];
   char infile_nm_fp[100];
   par_nm = particle_name;

   if(particle_name == "Lambda"){
       infile_nm_exp = "weight_lambda_exp.txt";
       infile_nm_fp = "weight_lambda_fp.txt";
   }
   else if(particle_name == "AntiLambda"){
       infile_nm_exp = "weight_antilambda_exp.txt";
       infile_nm_fp = "weight_antilambda_fp.txt";
   }
   else{
       std::cout<<"Critical: Wrong Particle!"<<std::endl;  
       return 0;
   }

   //ifstream infile_anti("../Ks0_Analysis/weight_ks_fp.txt"); 
   ifstream infile_exp(infile_nm_exp); 
   ifstream infile_fp(infile_nm_fp); 
   float efficiency_exp[9][10] = {0,};
   float efficiency_fp[9][10] = {0,};
   int centbin = 0;
   int ptbin = 0;
   double dumb = 0.;
   double eff_exp = 0.;
   double eff_fp = 0.;
   double efferr_exp = 0.;
   double efferr_fp = 0.;
   float ptbd[11] = {0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0,2.3,2.6};
   //Float_t ptx[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   float ptx[10] = {};
   for(int i = 0; i< 10; i++){
       ptx[i] = (ptbd[i] + ptbd[i+1])/2;
       printf("pt_x = %f\n", ptx[i]);
   }

   while(infile_exp >> centbin){
        infile_exp >> ptbin;
        infile_exp >> dumb;
        infile_exp >> dumb;
        infile_exp >> dumb;
        infile_exp >> dumb;
        infile_exp >> eff_exp;
        infile_exp >> efferr_exp;
        efficiency_exp[centbin][ptbin-1] = eff_exp*pow(10, -centbin);
        //printf("centbin %d ptbin %d efficiency is %f\n", centbin, ptbin, eff);
   } 

   while(infile_fp >> centbin){
        infile_fp >> ptbin;
        infile_fp >> dumb;
        infile_fp >> dumb;
        infile_fp >> dumb;
        infile_fp >> dumb;
        infile_fp >> eff_fp;
        infile_fp >> efferr_fp;
        efficiency_fp[centbin][ptbin-1] = eff_fp*pow(10, -centbin);
        //printf("centbin %d ptbin %d efficiency is %f\n", centbin, ptbin, eff);
   } 

   TCanvas* can = new TCanvas("c1", "c1", 800, 600);
   can -> SetLogy();
   //TH2F* h2 = new TH2F("h2", "h2", 100, 0.3, 2.7, 100, 0.);
/*
   TGraph* gr = new TGraph(10, ptx, efficiency[1]);
   gr -> SetMarkerSize(1.45);
   gr -> SetMarkerColor(2);
   gr -> SetMarkerStyle(29);
   can -> cd();
   gr -> Draw("ap");
*/

   TMultiGraph* mg = new TMultiGraph();
   for(int i = 0; i < 9; i++){
       TGraph* gr_exp = new TGraph(10, ptx, efficiency_exp[i]);
       gr_exp -> SetMarkerSize(1.45);
       gr_exp -> SetMarkerColor(2);
       gr_exp -> SetMarkerStyle(29);
       mg -> Add(gr_exp); 
   }

   for(int i = 0; i < 9; i++){
       TGraph* gr_fp = new TGraph(10, ptx, efficiency_fp[i]);
       gr_fp -> SetMarkerSize(1.45);
       gr_fp -> SetMarkerColor(1);
       gr_fp -> SetMarkerStyle(29);
       mg -> Add(gr_fp);
   }

   can -> cd();
   char plot_title[100];
   if(par_nm == "Lambda"){
       mg -> SetTitle("#Lambda Efficiency in AuAu 200GeV");
   }
   else{
       mg -> SetTitle("#bar{#Lambda} Efficiency in AuAu 200GeV");
   }

   mg->Draw("ap");
   
   mg->GetXaxis()->SetTitle("Pt(GeV/c)");
   mg->GetYaxis()->SetTitle("Efficiency");
   mg->GetYaxis()->SetRangeUser(pow(10, -11), 1000);
   gPad->Update();

   TGraph* gr_exp = (TGraph*)mg -> GetListOfGraphs() -> At(1);    //Get one of the exponentially distributed efficiency plot from multigraph list.
   TGraph* gr_fp = (TGraph*)mg -> GetListOfGraphs() -> At(12);    //Get one of the flat distributed efficiency plot from multigraph.
   TLegend* leg = new TLegend(0.45, 0.75, 0.7, 0.87);
   leg -> AddEntry(gr_exp, "exponential", "p");
   leg -> AddEntry(gr_fp, "flat", "p");
   leg -> SetBorderSize(0);
   leg -> SetFillColor(0);
   leg -> SetTextSize(0.045);
   leg -> Draw("same");

   char fig_nm[100];
   sprintf(fig_nm, "plot_exp_vs_fp_%s.eps", par_nm);
   c1 -> SaveAs(fig_nm);
}
