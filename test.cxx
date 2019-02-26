void test(){
	TChain *data = new TChain("btagana/ttree");
	data->Add("MoreNtuples/MC_pt_50to80.root");
	float TagVarCSV_jetNSecondaryVertices = 0;
	float NStoredVertices = 0;
	//data->SetBranchAddress("NStoredVertices",&NStoredVertices);
	//data->SetBranchAddress("TagVarCSV_jetNSecondaryVertices",&TagVarCSV_jetNSecondaryVertices);
	int nentries = data->GetEntries();
	int counter = 0;
	for (Int_t i=0;i<nentries;i++) {
		counter++;
	}
		
	cout << counter << endl;
}
