#include "TFile.h"
#include "TTree.h"
#include "TH2F.h"
#include "TH1F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include <iostream>
#include "TStyle.h"


using namespace std;

int turnon(){
	TFile *ntfile = new TFile("DeepNTuple_1p1MJets_changedDeepCSVVtxDef.root","READ");
	TTree *data = (TTree*)ntfile->Get("Ntupler/tree");
	TH1F *h_pass= new TH1F("h_pass","h_pass", 10,0,1);
	h_pass->Sumw2();
	TH1F *h_all= new TH1F("h_all","h_all", 10,0,1);
	h_all->Sumw2();
	TH1F *h_eff= new TH1F("h_eff","h_eff", 10,0,1);
	h_eff->Sumw2();	

	float OnDeepCSVProbb; //!
	float DeepCSVProbb; //!
	float DeepCSVProbbb; //!
	float OnDeepCSVProbc; //!                     
	float DeepCSVProbc; //!
	float OnCSVProbb; //!                                                                                                                       
	float CSVProbb; //!
	float OnDeepCSVProbudsg; //!
	float DeepCSVProbudsg; //!

	data->SetBranchAddress("DeepCSVProbb",&DeepCSVProbb);
	data->SetBranchAddress("DeepCSVProbbb",&DeepCSVProbbb);
	//data->SetBranchAddress("OnDeepCSVProbb",&OnDeepCSVProbb);
	data->SetBranchAddress("OnDeepCSVProbc",&OnDeepCSVProbc);
	data->SetBranchAddress("OnDeepCSVProbudsg",&OnDeepCSVProbudsg);



	Int_t nentries = data->GetEntries();

	for (Int_t i=0;i<nentries;i++) {
		data->GetEntry(i);
		DeepCSVProbb = DeepCSVProbb + DeepCSVProbbb;
		if(DeepCSVProbb < 0){continue;}
		OnDeepCSVProbb = 1-OnDeepCSVProbc-OnDeepCSVProbudsg;
		if(OnDeepCSVProbb > 1.1){continue;}
		if(OnDeepCSVProbb > 0.6){
			h_pass->Fill(DeepCSVProbb);
		}
		h_all->Fill(DeepCSVProbb);	
	}
	gStyle->SetOptStat(0);

	TCanvas *cblah = new TCanvas("cblah", "cblah",50,50,1000,800);
	h_eff->Divide(h_pass,h_all,1,1);
	h_eff->SetNameTitle("turn on curve", "turn on curve");
	h_eff->GetXaxis()->SetTitle("offline DeepCSV");
	h_eff->GetYaxis()->SetTitle("efficiency");		
	h_eff->Draw();
	cblah->Update();	


	return 1;
}	
