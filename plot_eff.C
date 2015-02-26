#include <TCanvas.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
#include <TAxis.h>
void plot_eff(string particle_name){
   gStyle -> SetPadTickX(1);
   gStyle -> SetPadTickY(1);
   gStyle -> SetTitleX(0.5);
   gStyle -> SetTitleAlign(23);
   gStyle -> SetNdivisions(505);

   string par_nm;
   //char infile_nm_exp[100];
   //char infile_nm_fp[100];
   string infile_nm_exp;
   string infile_nm_fp;
   //strncpy(par_nm, particle_name, 100);
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
   ifstream infile_exp(infile_nm_exp.c_str()); 
   ifstream infile_fp(infile_nm_fp.c_str()); 
   float efficiency_exp[9][10] = {0,};
   float efficiency_exp_ori[9][10] = {0,};
   float efficiency_fp[9][10] = {0,};
   float efficiency_fp_ori[9][10] = {0,};
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
        efficiency_exp_ori[centbin][ptbin-1] = eff_exp;
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
        efficiency_fp_ori[centbin][ptbin-1] = eff_exp;
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
   sprintf(fig_nm, "plot_exp_vs_fp_%s.eps", par_nm.c_str());
   c1 -> SaveAs(fig_nm);

//===========Fit the Function to the Plots===================================

   TCanvas* c2 = new TCanvas("c2", "c2", 800, 600);  
   c2 -> SetLogy();
   TMultiGraph* mg1 = new TMultiGraph(); 
   char mg1_title[100];
   if(par_nm == "Lambda"){
       mg1 -> SetTitle("#Lambda Efficiency in AuAu 200GeV");
   }
   else{
       mg1 -> SetTitle("#bar{#Lambda} Efficiency in AuAu 200GeV");
   }

   TF1* erf = new TF1("erf", "[0]*TMath::Erf(x-[1])+[2]", 0.5, 3.0);   
   double par[9][3];
   for(int i = 0; i < 9; i++){
       TGraph* gr_exp = new TGraph(10, ptx, efficiency_exp[i]);
       TGraph* gr_exp_ori = new TGraph(10, ptx, efficiency_exp_ori[i]);
       gr_exp -> SetMarkerSize(1.45);
       gr_exp -> SetMarkerColor(2);
       gr_exp -> SetMarkerStyle(29);
       mg1 -> Add(gr_exp);
       gr_exp_ori -> Fit(erf, "R0");
       erf -> GetParameters(par[i]); 
       std::cout<<"[0]="<<par[i][0]<<" [1]="<<par[i][1]<<" [2]="<<par[i][2]<<std::endl;
   }
   mg1 -> Draw("ap");
   mg1 -> GetXaxis() -> SetTitle("Pt(GeV/c)");
   mg1 -> GetYaxis() -> SetTitle("Efficiency");
   mg1 -> GetYaxis() -> SetRangeUser(pow(10, -11), 1000);
   gPad -> Update();

   char eff_fit_output[100];
   sprintf(eff_fit_output, "eff_fit_par_%s.dat", particle_name.c_str());
   ofstream eff_fit(eff_fit_output);
   for(int i = 0; i < 9; i++){
       TF1* erf_temp = new TF1("erf_temp", "[0]*TMath::Erf(x-[1])+[2]", 0.5, 3.0);
       erf_temp -> SetParameter(0, pow(10, -i)*par[i][0]); 
       erf_temp -> SetParameter(1, par[i][1]); 
       erf_temp -> SetParameter(2, pow(10, -i)*par[i][2]); 
       erf_temp -> SetLineColor(1);
       erf_temp -> SetLineStyle(2);
       erf_temp -> Draw("sames");
       eff_fit << par[i][0] << " " << par[i][1] << " " << par[i][2] <<std::endl;
   }
   eff_fit.close();
   gPad -> Update();
   
   TLegend* leg1 = new TLegend(0.45, 0.75, 0.7, 0.87);
   TGraph* graph_temp_1 = (TGraph*)mg1 -> GetListOfGraphs() -> At(2);
   TF1* erf_temp = new TF1("erf_temp", "[0]*TMath::Erf(x-[1])+[2]", 0.5, 3.0);
   erf_temp -> SetLineColor(1);
   erf_temp -> SetLineStyle(2);

   leg1 -> AddEntry(graph_temp_1, "Efficiency", "p");
   leg1 -> AddEntry(erf_temp, "Error Function", "l");
   leg1 -> SetBorderSize(0);
   leg1 -> Draw("same");

   char fit_fig_nm[100];
   sprintf(fit_fig_nm, "%s_fit_plot.eps", particle_name.c_str()); 
   c2 -> SaveAs(fit_fig_nm);
}
