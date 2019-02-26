void printcor(Double_t x){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(72);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.035);
    std::string str = std::to_string(x);
    l.DrawLatex(0.15,0.91,("correlation factor = " + str).c_str());
}

void testread(){

	TFile *ntfile = new TFile("JetTree_mc_424.root","READ");
	//TFile *ntfile = new TFile("nomatching.root","READ");
	TTree *data = (TTree*)ntfile->Get("btagana/ttree");
 
	float eff[10] = {};
	float pass[10] = {};
	float fail[10] = {};
	float ueff[10] = {};
	float TagVarCSV_trackJetPt[50] = {};
	int TagVarCSV_FirstTrack[50] = {};
	float TagVarCSVTrk_trackPtRel[1000] = {};
	float jetNTracks, TagVarCSV_jetNSecondaryVertices, TagVarCSV_trackSip3dValAboveCharm,TagVarCSV_trackSip2dValAboveCharm,TagVarCSV_trackSip3dSigAboveCharm,TagVarCSV_trackSip2dSigAboveCharm;

	UInt_t OnNStoredVertices,NStoredVertices;

	float TagVarCSV_jetNSelectedTracks[50] = {};
	float trackSumJetDeltaR, vertexCategory, trackSumJetETRatio, jetNTracksEtaRel, OnjetNTracksEtaRel;

	UInt_t n_jetNSelectedTracks_;
	int nJet;
	
	float trackEtaRel[100] = {};
	float TagVarCSVTrk_trackDeltaR[100] = {};
	float TagVarCSVTrk_trackPtRatio[100] = {};
	float TagVarCSVTrk_trackSip3dSig[100] = {};
	float TagVarCSVTrk_trackSip2dSig[100] = {};
	float TagVarCSVTrk_trackDecayLenVal[100] = {};
	float TagVarCSVTrk_trackJetDistVal[100] = {};

	float TagVarCSV_vertexMass[10] = {}; 
	float TagVarCSV_vertexNTracks[10] = {};
	float TagVarCSV_vertexJetDeltaR[10] = {};
	float TagVarCSV_vertexEnergyRatio[10] = {};
	float TagVarCSV_flightDistance2dVal[10] = {};
	float TagVarCSV_flightDistance3dVal[10] = {};
	float TagVarCSV_flightDistance2dSig[10] = {};
	float TagVarCSV_flightDistance3dSig[10] = {};

	data->SetBranchAddress("nJet",&nJet);
	data->SetBranchAddress("TagVarCSV_trackJetPt",&TagVarCSV_trackJetPt);
	data->SetBranchAddress("TagVarCSV_jetNTracks",&TagVarCSV_jetNSelectedTracks);
	data->SetBranchAddress("TagVarCSV_trackPtRel",&TagVarCSVTrk_trackPtRel);
	data->SetBranchAddress("Jet_nFirstTrkTagVarCSV",&TagVarCSV_FirstTrack);
/*
	data->SetBranchAddress("TagVarCSV_vertexMass",&TagVarCSV_vertexMass);
	data->SetBranchAddress("TagVarCSV_vertexNTracks",&TagVarCSV_vertexNTracks);
	data->SetBranchAddress("TagVarCSV_vertexJetDeltaR",&TagVarCSV_vertexJetDeltaR);
	data->SetBranchAddress("TagVarCSV_vertexEnergyRatio",&TagVarCSV_vertexEnergyRatio);
	data->SetBranchAddress("TagVarCSV_flightDistance2dVal",&TagVarCSV_flightDistance2dVal);
	data->SetBranchAddress("TagVarCSV_flightDistance3dVal",&TagVarCSV_flightDistance3dVal);
	data->SetBranchAddress("TagVarCSV_flightDistance2dSig",&TagVarCSV_flightDistance2dSig);
	data->SetBranchAddress("TagVarCSV_flightDistance3dSig",&TagVarCSV_flightDistance3dSig);	
	data->SetBranchAddress("DeepCSVProbb",&DeepCSVProbb);
	data->SetBranchAddress("DeepCSVProbbb",&DeepCSVProbbb);
	data->SetBranchAddress("n_TagVarCSV_jetNSelectedTracks",&n_jetNSelectedTracks_);
	data->SetBranchAddress("DeepCSVProbc",&DeepCSVProbc);
	data->SetBranchAddress("DeepCSVProbudsg",&DeepCSVProbudsg);
	data->SetBranchAddress("CSVProbb",&CSVProbb);
	data->SetBranchAddress("trackJetPt",&trackJetPt);
	data->SetBranchAddress("jetNTracks",&jetNTracks);
	data->SetBranchAddress("n_StoredVertices",&NStoredVertices);
	data->SetBranchAddress("TagVarCSV_jetNSecondaryVertices",&TagVarCSV_jetNSecondaryVertices);
	data->SetBranchAddress("TagVarCSV_jetNSelectedTracks",&TagVarCSV_jetNSelectedTracks);
	data->SetBranchAddress("TagVarCSV_trackSip3dValAboveCharm",&TagVarCSV_trackSip3dValAboveCharm);
	data->SetBranchAddress("TagVarCSV_trackSip2dValAboveCharm",&TagVarCSV_trackSip2dValAboveCharm);
	data->SetBranchAddress("TagVarCSV_trackSip3dSigAboveCharm",&TagVarCSV_trackSip3dSigAboveCharm);
	data->SetBranchAddress("TagVarCSV_trackSip2dSigAboveCharm",&TagVarCSV_trackSip2dSigAboveCharm);
	data->SetBranchAddress("TagVarCSV_vertexCategory",&vertexCategory);
	data->SetBranchAddress("TagVarCSV_trackSumJetEtRatio",&trackSumJetETRatio);
	data->SetBranchAddress("TagVarCSV_jetNTracksEtaRel",&jetNTracksEtaRel);
	data->SetBranchAddress("TagVarCSV_trackSumJetDeltaR",&trackSumJetDeltaR);
	data->SetBranchAddress("TagVarCSV_trackEtaRel",&trackEtaRel);
	data->SetBranchAddress("TagVarCSVTrk_trackDeltaR",&TagVarCSVTrk_trackDeltaR);
	data->SetBranchAddress("TagVarCSVTrk_trackPtRatio",&TagVarCSVTrk_trackPtRatio);
	data->SetBranchAddress("TagVarCSVTrk_trackSip3dSig",&TagVarCSVTrk_trackSip3dSig);
	data->SetBranchAddress("TagVarCSVTrk_trackSip2dSig",&TagVarCSVTrk_trackSip2dSig);
	data->SetBranchAddress("TagVarCSVTrk_trackDecayLenVal",&TagVarCSVTrk_trackDecayLenVal);
	data->SetBranchAddress("TagVarCSVTrk_trackJetDistVal",&TagVarCSVTrk_trackJetDistVal);

*/


	Int_t nentries = data->GetEntries();
	int trackcount = 0;
	float alltracks = 0;
	for (Int_t i=0;i<2;i++) {
		data->GetEntry(i);
		cout << "Entry = " << i << endl;
		cout << "NJets = " << nJet << endl;
		int tracksseen = 0;
		for(Int_t n = 0; n<nJet; n++){
			cout << "Jet PT track based = " << TagVarCSV_trackJetPt[n] << endl;
			cout << "nr of tracks = " << TagVarCSV_jetNSelectedTracks[n] << endl; 
			trackcount = TagVarCSV_jetNSelectedTracks[n];
			cout << "Blob = " << TagVarCSV_FirstTrack[n] << endl;
			for(int z = TagVarCSV_FirstTrack[n]; z<TagVarCSV_FirstTrack[n]; z++){
				cout << TagVarCSVTrk_trackPtRel[z] << endl;
			}
			tracksseen += trackcount;
		}
	}
}
