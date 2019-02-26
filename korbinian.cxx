void korbinian(){

	TFile *ntfile = new TFile("MuonEG_RunE_phase1.root","READ");
      	TTree *data = (TTree*)ntfile->Get("tree");
	int pfJets_num, offJets_num;
	TH1F *h_eff= new TH1F("h_eff","h_eff", 25,0,1);
	h_eff->Sumw2();	
	TH1F *h_pass= new TH1F("h_pass","h_pass", 25,0,1);
	h_pass->Sumw2();
	TH1F *h_all= new TH1F("h_all","h_all", 25,0,1);
	h_all->Sumw2();
	TH1F *h_eff2= new TH1F("h_eff2","h_eff2", 25,0,1);
	h_eff2->Sumw2();	
	TH1F *h_pass2= new TH1F("h_pass2","h_pass2", 25,0,1);
	h_pass2->Sumw2();
	TH1F *h_all2= new TH1F("h_all2","h_all2", 25,0,1);
	h_all2->Sumw2();
	float OffDeepCSV[10000];
	float OffDeepCSVb[10000];
	float OffDeepCSVbb[10000];
	float OnDeepCSV[10000];
	float pfJets_pt[10000];
	float pfJets_eta[10000];
	float pfJets_phi[10000];
	float offJets_eta[10000];
	float offJets_phi[10000];
	int matchOff[10000];
	int matchPF[10000];
	data->SetBranchAddress("pfJets_num",&pfJets_num);
	data->SetBranchAddress("offJets_num",&offJets_num);
	data->SetBranchAddress("pfJets_matchOff[pfJets_num]",&matchOff);
	data->SetBranchAddress("offJets_matchPF[offJets_num]",&matchPF);
	data->SetBranchAddress("pfJets_pt[pfJets_num]",&pfJets_pt);
	data->SetBranchAddress("offJets_deepcsv[offJets_num]",&OffDeepCSV);
	data->SetBranchAddress("offJets_deepcsv_b[offJets_num]",&OffDeepCSVb);
	data->SetBranchAddress("offJets_deepcsv_bb[offJets_num]",&OffDeepCSVbb);
	data->SetBranchAddress("pfJets_deepcsv[pfJets_num]",&OnDeepCSV);
	data->SetBranchAddress("pfJets_eta[pfJets_num]",&pfJets_eta);
	data->SetBranchAddress("pfJets_phi[pfJets_num]",&pfJets_phi);
	data->SetBranchAddress("offJets_eta[offJets_num]",&offJets_eta);
	data->SetBranchAddress("offJets_phi[offJets_num]",&offJets_phi);	
	cout << data->GetEntries() << endl;
	Int_t nentries = 1000000;
   	float pi = TMath::Pi();
	for (Int_t i=0;i<nentries;i++){
		std::vector<size_t> matches;
		data->GetEntry(i);
		for(int n = 0; n < pfJets_num; n++){
			if( (pfJets_pt[n] < 30.0) | (abs(pfJets_eta[n]) > 2.4) | (OnDeepCSV[n] < -5) ){
				matches.push_back(9999);
				continue;
			}			
       			double dRMin = 0.1;
       			size_t index = 9999;			
			for(int z = 0; z < offJets_num; z++){
	 			double deta = offJets_eta[z] - pfJets_eta[n];
	 			double dphi = TMath::Abs( offJets_phi[z] - pfJets_phi[n]);
				if(dphi > pi){
	   				dphi = 2*pi-dphi;
	 			}
				double dR = TMath::Sqrt(deta*deta + dphi*dphi);
	 			if(dR < dRMin){
	   				dRMin = dR;
	   				index = z;
	 			}						
			}
		       	matches.push_back(index);
		}
		for(int n = 0; n < matches.size(); n++){
			if(matches[n] == 9999){continue;}
			for(int z = n+1; z < matches.size(); z++){
				if(n == z | matches[z] == 9999){continue;}
				if(matches[n] == matches[z]){
					cout << "Jet nummer " << z << " har værdi = " << matches[z] << endl;
					cout << "Jet nummer " << n << " har værdi = " << matches[n] << endl;
				}
			}			
		}
		std::vector<float> Vectorjets;
		for(int n = 0; n < pfJets_num; n++){
			if(pfJets_pt[n] < 30.0){continue;}
			if((OnDeepCSV[n] < -5)){continue;}
			if(abs(pfJets_eta[n]) > 2.4){continue;}
			if(matches[n] == 9999){continue;}
			Vectorjets.push_back(OnDeepCSV[n]);
			//cout << i << " nr jet = " << n << " og værdi = " << OnDeepCSV[n] << endl; 
			if(OnDeepCSV[n] > 0.6){
				h_pass->Fill(OffDeepCSV[matches[n]]);
			}
			h_all->Fill(OffDeepCSV[matches[n]]);		
		}
		for(int n = 0; n < Vectorjets.size(); n++){
			if(Vectorjets[n] == 0 | Vectorjets[n] == (-20)){continue;}
			for(int z = n+1; z < Vectorjets.size(); z++){
				if(Vectorjets[z] == 0 | Vectorjets[z] == (-20) | n == z){continue;}
				if(Vectorjets[n] == Vectorjets[z]){
					cout << "Jet nummer " << z << " har værdi = " << Vectorjets[z] << endl;
					cout << "Jet nummer " << n << " har værdi = " << Vectorjets[n] << endl;
				}
			}			
		}
		for(int n = 0; n < pfJets_num; n++){
			if(matchOff[n] < 0){continue;}
			if(abs(pfJets_eta[n]) > 2.4){continue;}
			if((OnDeepCSV[n] < -5)){continue;} 
			//if(OnDeepCSV[n] < 0.000001){continue;}
			if(pfJets_pt[n] < 30.0){continue;}
			if(OnDeepCSV[n] > 0.6){
				h_pass2->Fill(OffDeepCSV[matchOff[n]]);
			}
			h_all2->Fill(OffDeepCSV[matchOff[n]]);		
		}

/*
		for(int n = 0; n < offJets_num; n++){
			if(matchPF[n] < 0){continue;}
			if(OnDeepCSV[matchPF[n]] > 0.01){continue;}
			if(pfJets_pt[matchPF[n]] < 30.0){continue;}
			if(OnDeepCSV[matchPF[n]] > 0.6){
				h_pass2->Fill(OffDeepCSV[n]);
			}
			h_all2->Fill(OffDeepCSV[n]);		
		}
*/

	}
	TCanvas *cblah = new TCanvas("cblah", "cblah",50,50,1000,800);
	h_eff->Divide(h_pass,h_all,1,1);
	h_eff->SetNameTitle("DeepCSV Turn on Curve", "DeepCSV Turn on Curve");
	h_eff->GetXaxis()->SetTitle("Offline DeepCSV discriminator ");
	h_eff->GetYaxis()->SetTitle("Efficiency");
	h_eff->SetMarkerStyle(20);
	h_eff->SetMarkerColor(2);		
	h_eff->Draw();
	h_eff2->Divide(h_pass2,h_all2,1,1);
	h_eff2->Draw("same");

}
