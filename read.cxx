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



void printcor(Double_t x){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(72);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.035);
    std::string str = std::to_string(x);
    l.DrawLatex(0.15,0.91,("correlation factor = " + str).c_str());
}

using namespace std;

int read(){
  	TFile *ntfile = new TFile("DeepNTuple_1p1MJets_changedDeepCSVVtxDef.root","READ");
	//TFile *ntfile = new TFile("DeepNTuple_RunE_0p23.root","READ");
  	//TFile *ntfile = new TFile("ntuple.root","READ");
      	TTree *data = (TTree*)ntfile->Get("Ntupler/tree");
	//TTree *data2 = (TTree*)ntfile2->Get("Ntupler/tree");
	//TTree *data = (TTree*)ntfile->Get("deepntuplizer/tree");'
  	TH2F *h_DeepCSVCSVcompOnline = new TH2F("h_DeepCSVCSVcompOnline", "h_DeepCSVCSVcompOnline", 100, 0, 1.0,100,0,1.0);
  	TH2F *h_DeepCSVCSVcompOffline = new TH2F("h_DeepCSVCSVcompOffline", "h_DeepCSVCSVcompOffline", 100, 0, 1.0,100,0,1.0);
  	TH2F *h_DeepCSVprobbOffvsOn = new TH2F("h_DeepCSVprobbOffvsOn", "h_DeepCSVprobbOffvsOn", 100, 0, 1.0,100,0,1.0);
  	TH2F *h_DeepCSVprobbNewOffvsOn = new TH2F("h_DeepCSVprobbNewOffvsOn", "h_DeepCSVprobbNewOffvsOn", 100, 0, 1.0,100,0,1.0);
  	TH2F *h_DifferentInput = new TH2F("h_DifferentInput", "h_DifferentInput", 100, 0, 1.0,100,0,1.0);
  	TH2F *h_DeepCSVprobcOffvsOn = new TH2F("h_DeepCSVprobcOffvsOn", "h_DeepCSVprobcOffvsOn", 100, 0, 1.0,100,0,1.0);
  	TH2F *h_DeepCSVprobudsgOffvsOn = new TH2F("h_DeepCSVprobudsgOffvsOn", "h_DeepCSVprobudsgOffvsOn", 100, 0, 1.0,100,0,1.0);
  	TH2F *h_MisVertexDeepCSVOffvsOn = new TH2F("h_MisVertexDeepCSVOffvsOn", "h_MisVertexDeepCSVOffvsOn", 100, 0, 1,100,0,1);
  	TH2F *h_MisVertexCSVOffvsOn = new TH2F("h_MisVertexCSVOffvsOn", "h_MisVertexCSVOffvsOn", 100, 0, 1,100,0,1);
 	TH2F *h_MisTrackDeepCSVOffvsOn = new TH2F("h_MisTrackDeepCSVOffvsOn", "h_MisTrackDeepCSVOffvsOn", 100, 0, 1,100,0,1);
 	TH2F *h_MisTrackEtaRelDeepCSVOffvsOn = new TH2F("h_MisTrackEtaRelDeepCSVOffvsOn", "h_MisTrackEtaRelDeepCSVOffvsOn", 100, 0, 1,100,0,1);
  	TH2F *h_CSVprobbOffvsOn = new TH2F("h_CSVprobbOffvsOn", "h_CSVprobbOffvsOn", 120, 0, 1.2,120,0,1.2);
  	TH2F *h_trackJetPtOffvsOn = new TH2F("h_trackJetPtOffvsOn", "trackJetPtOffvsOn", 100, 0, 300,100,0,300);
  	TH2F *h_jetNSelectedTracksOffvsOn = new TH2F("h_jetNSelectedTracksOffvsOn", "h_jetNSelectedTracksOffvsOn", 20, -0.5, 19.5,20,-0.5,19.5);
  	TH2F *h_jetNSecondaryVerticesOffvsOn = new TH2F("h_jetNSecondaryVerticesOffvsOn", "h_jetNSecondaryVerticesOffvsOn", 5, -0.5, 4.5,5,-0.5,4.5);
	TH2F *h_trackSip3dValAboveCharmOffvsOn = new TH2F("h_trackSip3dValAboveCharmOffvsOn", "h_trackSip3dValAboveCharmOffvsOn", 100, -2.05, 2.05,100,-2.05,2.05);
	TH2F *h_trackSip2dValAboveCharmOffvsOn = new TH2F("h_trackSip2dValAboveCharmOffvsOn", "h_trackSip2dValAboveCharmOffvsOn", 100, -2.05, 2.05,100,-2.05,2.05);
	TH2F *h_trackSip3dSigAboveCharmOffvsOn = new TH2F("h_trackSip3dSigAboveCharmOffvsOn", "h_trackSip3dSigAboveCharmOffvsOn", 100, -7.0, 7.0,100,-7.0,7.0);
	TH2F *h_trackSip2dSigAboveCharmOffvsOn = new TH2F("h_trackSip2dSigAboveCharmOffvsOn", "h_trackSip2dSigAboveCharmOffvsOn", 100, -7.0, 7.0,100,-7.0,7.0);
	TH2F *h_jetNTracksEtaRelOffvsOn = new TH2F("h_jetNTracksEtaRelOffvsOn", "h_jetNTracksEtaRelOffvsOn", 17, -0.5, 16.5,17,-0.5,16.5);
	TH2F *h_trackSumJetETRatioOffvsOn = new TH2F("h_trackSumJetETRatioOffvsOn", "h_trackSumJetETRatioOffvsOn", 100, 0, 1.2,100,0,1.2);
	TH2F *h_vertexCategoryOffvsOn = new TH2F("h_vertexCategoryOffvsOn", "h_vertexCategoryOffvsOn", 3, -0.5, 2.5,3,-0.5,2.5);
	TH2F *h_trackSumJetDeltaROffvsOn = new TH2F("h_trackSumJetDeltaROffvsOn", "h_trackSumJetDeltaROffvsOn", 100, 0, 0.3,100,0,0.3);
//cout << "Number " << n << "Value =" <<	TagVarCSVTrk_trackPtRel[n] << " " << TagVarCSVTrk_trackDeltaR[n] << " " << TagVarCSVTrk_trackSip3dSig[n] << " " << TagVarCSVTrk_trackSip2dSig[n] << " " << TagVarCSVTrk_trackDecayLenVal[n] << " " << TagVarCSVTrk_trackJetDistVal[n] << endl;
	TH1F *h_DeepCSVprobb= new TH1F("DeepCSVprobb","DeepCSVprobb", 100,0,1);
	TH1F *h_OnDeepCSVprobb= new TH1F("OnDeepCSVprobb","OnDeepCSVprobb", 100,0,1);
	TH1F *h_DeepCSVprobc= new TH1F("DeepCSVprobc","DeepCSVprobc", 100,0,1);
	TH1F *h_OnDeepCSVprobc= new TH1F("OnDeepCSVprobc","OnDeepCSVprobc", 100,0,1);
	TH1F *h_OnDeepCSVprobbTest= new TH1F("OnDeepCSVprobbTest","OnDeepCSVprobbTest", 100,0,1);
	TH1F *h_DeepCSVprobbTest= new TH1F("DeepCSVprobbTest","DeepCSVprobbTest", 100,0,1);
	TH1F *h_pass= new TH1F("h_pass","h_pass", 25,0,1);
	h_pass->Sumw2();
	TH1F *h_all= new TH1F("h_all","h_all", 25,0,1);
	h_all->Sumw2();
	TH1F *h_eff= new TH1F("h_eff","h_eff", 25,0,1);
	h_eff->Sumw2();	

	TH1F *h_pass2= new TH1F("h_pass2","h_pass2", 25,0,1);
	h_pass2->Sumw2();
	TH1F *h_all2= new TH1F("h_all2","h_all2", 25,0,1);
	h_all2->Sumw2();
	TH1F *h_eff2= new TH1F("h_eff2","h_eff2", 25,0,1);
	h_eff2->Sumw2();
	TH1F *h_DeepCSVprobudsg= new TH1F("DeepCSVprobudsg","DeepCSVprobudsg", 100,0,1);
	TH1F *h_OnDeepCSVprobudsg= new TH1F("OnDeepCSVprobudsg","OnDeepCSVprobudsg", 100,0,1);
	TH1F *h_CSVprobb= new TH1F("CSVprobb","CSVprobb", 100,0,1);
	TH1F *h_OnCSVprobb= new TH1F("OnCSVprobb","OnCSVprobb", 100,0,1);

	TH1F *h_trackEtaRel= new TH1F("trackEtaRel","trackEtaRel", 100,0,10);
	TH1F *h_trackPtRel= new TH1F("trackPtRel","trackPtRel", 100,0,10);
	TH1F *h_trackDeltaR= new TH1F("trackDeltaR","trackDeltaR", 100,0,0.5);
	TH1F *h_trackSip3dSig= new TH1F("trackSip3dSig","trackSip3dSig", 100,-7,7);
	TH1F *h_trackSip2dSig= new TH1F("trackSip2dSig","trackSip2dSig", 100,-7,7);
	TH1F *h_trackJetDistVal= new TH1F("trackJetDistVal","trackJetDistVal", 100,-0.1,0);
	TH1F *h_trackDecayLenVal= new TH1F("trackDecayLenVal","trackDecayLenVal", 100,0,2.5);

	TH1F *h_OntrackEtaRel= new TH1F("OntrackEtaRel","OntrackEtaRel", 100,0,10);
	TH1F *h_OntrackPtRel= new TH1F("OntrackPtRel","OntrackPtRel", 100,0,10);
	TH1F *h_OntrackDeltaR= new TH1F("OntrackDeltaR","OntrackDeltaR", 100,0,0.5);
	TH1F *h_OntrackSip3dSig= new TH1F("OntrackSip3dSig","OntrackSip3dSig", 100,-7,7);
	TH1F *h_OntrackSip2dSig= new TH1F("OntrackSip2dSig","OntrackSip2dSig", 100,-7,7);
	TH1F *h_OntrackJetDistVal= new TH1F("OntrackJetDistVal","OntrackJetDistVal", 100,-0.1,0);
	TH1F *h_OntrackDecayLenVal= new TH1F("OntrackDecayLenVal","OntrackDecayLenVal", 100,0,2.5);
	float OnDeepCSVProbb; //!
	float DeepCSVProbb; //!
	float DeepCSVProbbb; //!
	float OnDeepCSVProbc; //!                     
	float DeepCSVProbc; //!
	float OnCSVProbb; //!                                                                                                                       
	float CSVProbb; //!
	float OnDeepCSVProbudsg; //!
	float DeepCSVProbudsg; //!
	TH1F *h_vertexMass= new TH1F("vertexMass","vertexMass", 100,0,20);
	TH1F *h_vertexNTracks= new TH1F("vertexNTracks","vertexNTracks", 16,0.5,16.5);
	TH1F *h_vertexEnergyRatio= new TH1F("vertexEnergyRatio","vertexEnergyRatio", 100,0,1.2);
	TH1F *h_vertexJetDeltaR= new TH1F("vertexJetDeltaR","vertexJetDeltaR", 100,0,0.4);
	TH1F *h_flightDistance2dVal= new TH1F("flightDistance2dVal","flightDistance2dVal", 20,0,2.5);
	TH1F *h_flightDistance3dVal= new TH1F("flightDistance3dVal","flightDistance3dVal", 20,0,2.5);
	TH1F *h_flightDistance2dSig= new TH1F("flightDistance2dSig","flightDistance2dSig", 20,0,20);
	TH1F *h_flightDistance3dSig= new TH1F("flightDistance3dSig","flightDistance3dSig", 20,0,20);

	TH1F *h_OnvertexMass= new TH1F("OnvertexMass","OnvertexMass", 100,0,20);
	TH1F *h_OnvertexNTracks= new TH1F("OnvertexNTracks","OnvertexNTracks", 16,0.5,16.5);
	TH1F *h_OnvertexEnergyRatio= new TH1F("OnvertexEnergyRatio","OnvertexEnergyRatio",100, 0,1.2);
	TH1F *h_OnvertexJetDeltaR= new TH1F("OnvertexJetDeltaR","OnvertexJetDeltaR", 100, 0,0.4);
	TH1F *h_OnflightDistance2dVal= new TH1F("OnflightDistance2dVal","OnflightDistance2dVal", 20,0,2.5);
	TH1F *h_OnflightDistance3dVal= new TH1F("OnflightDistance3dVal","OnflightDistance3dVal", 20,0,2.5);
	TH1F *h_OnflightDistance2dSig= new TH1F("OnflightDistance2dSig","OnflightDistance2dSig", 20,0,20);
	TH1F *h_OnflightDistance3dSig= new TH1F("OnflightDistance3dSig","OnflightDistance3dSig", 20,0,20);


	TH2F *h_vertexMassOffVsOn= new TH2F("vertexMassOffVsOn","vertexMassOffVsOn", 12,0,20,12,0,20);
	TH2F *h_vertexNTracksOffVsOn= new TH2F("vertexNTracksOffVsOn","vertexNTracksOffVsOn", 16,0.5,16.5,16,0.5,16.5);
	TH2F *h_vertexJetDeltaROffVsOn= new TH2F("vertexJetDeltaROffVsOn","vertexJetDeltaROffVsOn", 12,0,0.4,12,0,0.4);
	TH2F *h_vertexEnergyRatioOffVsOn= new TH2F("vertexEnergyRatioOffVsOn","vertexEnergyRatioOffVsOn", 12,0,1.2,12,0,1.2);

	TH2F *h_flightDistance2dValOffVsOn= new TH2F("flightDistance2dValOffVsOn","flightDistance2dValOffVsOn", 12,0,2.5,12,0,2.5);	
	TH2F *h_flightDistance3dValOffVsOn= new TH2F("flightDistance3dValOffVsOn","flightDistance3dValOffVsOn", 12,0,2.5,12,0,2.5);
	TH2F *h_flightDistance2dSigOffVsOn= new TH2F("flightDistance2dSigOffVsOn","flightDistance2dSigOffVsOn", 12,0,20,12,0,20);
	TH2F *h_flightDistance3dSigOffVsOn= new TH2F("flightDistance3dSigOffVsOn","flightDistance3dSigOffVsOn", 12,0,20,12,0,20);

	float eff[10] = {};
	float pass[10] = {};
	float fail[10] = {};
	float ueff[10] = {};
	float trackJetPt, jetNTracks, TagVarCSV_jetNSecondaryVertices, TagVarCSV_trackSip3dValAboveCharm,TagVarCSV_trackSip2dValAboveCharm,TagVarCSV_trackSip3dSigAboveCharm,TagVarCSV_trackSip2dSigAboveCharm;
	float OnNewDeepCSVProbb = 0;
	float OnNStoredVerticesf,NStoredVerticesf;
	UInt_t OnNStoredVertices = 0;
	UInt_t NStoredVertices = 0;
	int Compare = 1;
	float TagVarCSV_jetNSelectedTracks;
	float trackSumJetDeltaR, vertexCategory, trackSumJetETRatio, jetNTracksEtaRel, OnjetNTracksEtaRel;

	float OntrackSumJetDeltaR, OnvertexCategory, OntrackSumJetETRatio;

	UInt_t n_jetNSelectedTracks_;
	UInt_t Onn_jetNSelectedTracks_;
	float OntrackJetPt, OnjetNTracks, OnTagVarCSV_jetNSecondaryVertices,OnTagVarCSV_jetNSelectedTracks, OnTagVarCSV_trackSip3dValAboveCharm,OnTagVarCSV_trackSip2dValAboveCharm,OnTagVarCSV_trackSip3dSigAboveCharm,OnTagVarCSV_trackSip2dSigAboveCharm;
	
	float OntrackEtaRel[100] = {};
	float trackEtaRel[100] = {};
	float TagVarCSVTrk_trackPtRel[100] = {};
	float TagVarCSVTrk_trackDeltaR[100] = {};
	float TagVarCSVTrk_trackPtRatio[100] = {};
	float TagVarCSVTrk_trackSip3dSig[100] = {};
	float TagVarCSVTrk_trackSip2dSig[100] = {};
	float TagVarCSVTrk_trackDecayLenVal[100] = {};
	float TagVarCSVTrk_trackJetDistVal[100] = {};
	
	float OnTagVarCSVTrk_trackPtRel[100] = {};
	float OnTagVarCSVTrk_trackDeltaR[100] = {};
	float OnTagVarCSVTrk_trackPtRatio[100] = {};
	float OnTagVarCSVTrk_trackSip3dSig[100] = {};
	float OnTagVarCSVTrk_trackSip2dSig[100] = {};
	float OnTagVarCSVTrk_trackDecayLenVal[100] = {};
	float OnTagVarCSVTrk_trackJetDistVal[100] = {};

	float TagVarCSV_vertexMass[10] = {}; 
	float TagVarCSV_vertexNTracks[10] = {};
	float TagVarCSV_vertexJetDeltaR[10] = {};
	float TagVarCSV_vertexEnergyRatio[10] = {};
	float TagVarCSV_flightDistance2dVal[10] = {};
	float TagVarCSV_flightDistance3dVal[10] = {};
	float TagVarCSV_flightDistance2dSig[10] = {};
	float TagVarCSV_flightDistance3dSig[10] = {};

	float OnTagVarCSV_vertexMass[10] = {}; 
	float OnTagVarCSV_vertexNTracks[10] = {};
	float OnTagVarCSV_vertexJetDeltaR[10] = {};
	float OnTagVarCSV_vertexEnergyRatio[10] = {};
	float OnTagVarCSV_flightDistance2dVal[10] = {};
	float OnTagVarCSV_flightDistance3dVal[10] = {};
	float OnTagVarCSV_flightDistance2dSig[10] = {};
	float OnTagVarCSV_flightDistance3dSig[10] = {};

	data->SetBranchAddress("TagVarCSV_vertexMass",&TagVarCSV_vertexMass);
	data->SetBranchAddress("TagVarCSV_vertexNTracks",&TagVarCSV_vertexNTracks);
	data->SetBranchAddress("TagVarCSV_vertexJetDeltaR",&TagVarCSV_vertexJetDeltaR);
	data->SetBranchAddress("TagVarCSV_vertexEnergyRatio",&TagVarCSV_vertexEnergyRatio);
	data->SetBranchAddress("TagVarCSV_flightDistance2dVal",&TagVarCSV_flightDistance2dVal);
	data->SetBranchAddress("TagVarCSV_flightDistance3dVal",&TagVarCSV_flightDistance3dVal);
	data->SetBranchAddress("TagVarCSV_flightDistance2dSig",&TagVarCSV_flightDistance2dSig);
	data->SetBranchAddress("TagVarCSV_flightDistance3dSig",&TagVarCSV_flightDistance3dSig);

	data->SetBranchAddress("OnTagVarCSV_vertexMass",&OnTagVarCSV_vertexMass);
	data->SetBranchAddress("OnTagVarCSV_vertexNTracks",&OnTagVarCSV_vertexNTracks);
	data->SetBranchAddress("OnTagVarCSV_vertexJetDeltaR",&OnTagVarCSV_vertexJetDeltaR);
	data->SetBranchAddress("OnTagVarCSV_flightDistance2dVal",&OnTagVarCSV_flightDistance2dVal);
	data->SetBranchAddress("OnTagVarCSV_vertexEnergyRatio",&OnTagVarCSV_vertexEnergyRatio);
	data->SetBranchAddress("OnTagVarCSV_flightDistance3dVal",&OnTagVarCSV_flightDistance3dVal);
	data->SetBranchAddress("OnTagVarCSV_flightDistance2dSig",&OnTagVarCSV_flightDistance2dSig);
	data->SetBranchAddress("OnTagVarCSV_flightDistance3dSig",&OnTagVarCSV_flightDistance3dSig);

	//	data->SetBranchAddress("OnNewDeepCSVProbb",&OnNewDeepCSVProbb);
	data->SetBranchAddress("DeepCSVProbb",&DeepCSVProbb);
	data->SetBranchAddress("DeepCSVProbbb",&DeepCSVProbbb);
	data->SetBranchAddress("n_TagVarCSV_jetNSelectedTracks",&n_jetNSelectedTracks_);
	data->SetBranchAddress("Onn_TagVarCSV_jetNSelectedTracks",&Onn_jetNSelectedTracks_);
	data->SetBranchAddress("DeepCSVProbc",&DeepCSVProbc);
	data->SetBranchAddress("DeepCSVProbudsg",&DeepCSVProbudsg);
	data->SetBranchAddress("CSVProbb",&CSVProbb);
	data->SetBranchAddress("trackJetPt",&trackJetPt);
	data->SetBranchAddress("jetNTracks",&jetNTracks);

	data->SetBranchAddress("n_StoredVertices",&NStoredVertices);
	data->SetBranchAddress("Onn_StoredVertices",&OnNStoredVertices);
	data->SetBranchAddress("NStoredVertices",&NStoredVerticesf);
	data->SetBranchAddress("OnNStoredVertices",&OnNStoredVerticesf);
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
	data->SetBranchAddress("TagVarCSVTrk_trackPtRel",&TagVarCSVTrk_trackPtRel);


	data->SetBranchAddress("OnTagVarCSVTrk_trackDeltaR",&OnTagVarCSVTrk_trackDeltaR);
	data->SetBranchAddress("OnTagVarCSVTrk_trackPtRatio",&OnTagVarCSVTrk_trackPtRatio);
	data->SetBranchAddress("OnTagVarCSVTrk_trackSip3dSig",&OnTagVarCSVTrk_trackSip3dSig);
	data->SetBranchAddress("OnTagVarCSVTrk_trackSip2dSig",&OnTagVarCSVTrk_trackSip2dSig);
	data->SetBranchAddress("OnTagVarCSVTrk_trackDecayLenVal",&OnTagVarCSVTrk_trackDecayLenVal);
	data->SetBranchAddress("OnTagVarCSVTrk_trackJetDistVal",&OnTagVarCSVTrk_trackJetDistVal);
	data->SetBranchAddress("OnTagVarCSVTrk_trackPtRel",&OnTagVarCSVTrk_trackPtRel);
	data->SetBranchAddress("OnDeepCSVProbb",&OnDeepCSVProbb);
	data->SetBranchAddress("OnDeepCSVProbc",&OnDeepCSVProbc);
	data->SetBranchAddress("OnDeepCSVProbudsg",&OnDeepCSVProbudsg);
	data->SetBranchAddress("OnCSVProbb",&OnCSVProbb);
	data->SetBranchAddress("OntrackJetPt",&OntrackJetPt);
	data->SetBranchAddress("OnjetNTracks",&OnjetNTracks);

	data->SetBranchAddress("OnTagVarCSV_jetNSecondaryVertices",&OnTagVarCSV_jetNSecondaryVertices);

	data->SetBranchAddress("OnTagVarCSV_jetNSelectedTracks",&OnTagVarCSV_jetNSelectedTracks);
	data->SetBranchAddress("OnTagVarCSV_trackSip3dValAboveCharm",&OnTagVarCSV_trackSip3dValAboveCharm);
	data->SetBranchAddress("OnTagVarCSV_trackSip2dValAboveCharm",&OnTagVarCSV_trackSip2dValAboveCharm);
	data->SetBranchAddress("OnTagVarCSV_trackSip3dSigAboveCharm",&OnTagVarCSV_trackSip3dSigAboveCharm);
	data->SetBranchAddress("OnTagVarCSV_trackSip2dSigAboveCharm",&OnTagVarCSV_trackSip2dSigAboveCharm);
	data->SetBranchAddress("OnTagVarCSV_vertexCategory",&OnvertexCategory);
	data->SetBranchAddress("OnTagVarCSV_trackSumJetEtRatio",&OntrackSumJetETRatio);
	data->SetBranchAddress("OnTagVarCSV_trackEtaRel",&OntrackEtaRel);
	data->SetBranchAddress("OnTagVarCSV_trackSumJetDeltaR",&OntrackSumJetDeltaR);
	data->SetBranchAddress("OnTagVarCSV_jetNTracksEtaRel",&OnjetNTracksEtaRel);
	
	double bestx = 0.0;
	double besty = 0.0;
	float wp = 0.0;
	float wp1[10] = {};
	float null[10] = {};
	double pseudovertexevent = 0;
	double allevent = 0;
	double count1 = 0;
	double count2 = 0;
	Int_t nentries = data->GetEntries();
	//cout << nentries << endl;
	//Int_t nentries = 1000000;
/*
	float DeepCSVProbb2,DeepCSVProbbb2,OnDeepCSVProbc2,OnDeepCSVProbudsg2,OnDeepCSVProbb2;
	data2->SetBranchAddress("DeepCSVProbb",&DeepCSVProbb2);
	data2->SetBranchAddress("DeepCSVProbbb",&DeepCSVProbbb2);
	data2->SetBranchAddress("OnDeepCSVProbc",&OnDeepCSVProbc2);
	data2->SetBranchAddress("OnDeepCSVProbudsg",&OnDeepCSVProbudsg2);

	for (Int_t i=0;i<nentries;i++) {
		data2->GetEntry(i);
		DeepCSVProbb2 = DeepCSVProbb2+DeepCSVProbbb2;
		OnDeepCSVProbb2 = 1-OnDeepCSVProbudsg2-OnDeepCSVProbc2;
		if(OnDeepCSVProbb2 > 1.1){OnDeepCSVProbb2 = -1;}
		if(OnDeepCSVProbb2 > 0.6){
			h_pass2->Fill(DeepCSVProbb2);
		}
		h_all2->Fill(DeepCSVProbb2);
	}
*/
	for (Int_t i=0;i<nentries;i++) {
		data->GetEntry(i);
		float lal = n_jetNSelectedTracks_;
		DeepCSVProbb = DeepCSVProbb + DeepCSVProbbb;
		//if(vertexCategory != 1){continue;}
		//if(OnvertexCategory != 1){continue;}

		//if(!(OnTagVarCSV_jetNSecondaryVertices < TagVarCSV_jetNSecondaryVertices)){continue;}
		OnDeepCSVProbb = 1-OnDeepCSVProbc-OnDeepCSVProbudsg;
		if(OnDeepCSVProbb > 1.1){OnDeepCSVProbb = -1;}
		allevent++;
		h_trackJetPtOffvsOn->Fill(trackJetPt,OntrackJetPt);
		h_DeepCSVprobbOffvsOn->Fill(DeepCSVProbb,OnDeepCSVProbb);
		//h_DeepCSVprobbNewOffvsOn->Fill(OnDeepCSVProbb,OnNewDeepCSVProbb);
		h_DeepCSVprobcOffvsOn->Fill(DeepCSVProbc,OnDeepCSVProbc);
		h_DeepCSVCSVcompOnline->Fill(OnDeepCSVProbb,OnCSVProbb);
		h_DeepCSVCSVcompOffline->Fill(DeepCSVProbb,CSVProbb);
		h_DeepCSVprobudsgOffvsOn->Fill(DeepCSVProbudsg,OnDeepCSVProbudsg);
		h_DeepCSVprobb->Fill(DeepCSVProbb);
		h_OnDeepCSVprobb->Fill(OnDeepCSVProbb);
		h_DeepCSVprobc->Fill(DeepCSVProbc);
		h_OnDeepCSVprobc->Fill(OnDeepCSVProbc);
		h_DeepCSVprobudsg->Fill(DeepCSVProbudsg);
		h_OnDeepCSVprobudsg->Fill(OnDeepCSVProbudsg);
//0.8484
		if(OnCSVProbb > 0.7){
			h_pass2->Fill(CSVProbb);
		}
		h_all2->Fill(CSVProbb);
//0.6324
		if(OnDeepCSVProbb > 0.6){
			h_pass->Fill(DeepCSVProbb);
		}
		h_all->Fill(DeepCSVProbb);	
		h_CSVprobb->Fill(CSVProbb);
		h_OnCSVprobb->Fill(OnCSVProbb);
		h_CSVprobbOffvsOn->Fill(CSVProbb,OnCSVProbb);
		h_jetNSelectedTracksOffvsOn->Fill(TagVarCSV_jetNSelectedTracks,OnTagVarCSV_jetNSelectedTracks);
		h_jetNSecondaryVerticesOffvsOn->Fill(TagVarCSV_jetNSecondaryVertices,OnTagVarCSV_jetNSecondaryVertices);
		h_trackSip3dValAboveCharmOffvsOn->Fill(TagVarCSV_trackSip3dValAboveCharm,OnTagVarCSV_trackSip3dValAboveCharm);
		h_trackSip2dValAboveCharmOffvsOn->Fill(TagVarCSV_trackSip2dValAboveCharm,OnTagVarCSV_trackSip2dValAboveCharm);
		h_trackSip2dSigAboveCharmOffvsOn->Fill(TagVarCSV_trackSip2dSigAboveCharm,OnTagVarCSV_trackSip2dSigAboveCharm);
		h_trackSip3dSigAboveCharmOffvsOn->Fill(TagVarCSV_trackSip3dSigAboveCharm,OnTagVarCSV_trackSip3dSigAboveCharm);
		h_trackSumJetDeltaROffvsOn->Fill(trackSumJetDeltaR,OntrackSumJetDeltaR);
		h_vertexCategoryOffvsOn->Fill(vertexCategory,OnvertexCategory);
		h_trackSumJetETRatioOffvsOn->Fill(trackSumJetETRatio,OntrackSumJetETRatio);
		h_jetNTracksEtaRelOffvsOn->Fill(jetNTracksEtaRel,OnjetNTracksEtaRel);
		if( TagVarCSV_jetNSecondaryVertices != OnTagVarCSV_jetNSecondaryVertices){
			//h_MisVertexDeepCSVOffvsOn->Fill(DeepCSVProbb,OnDeepCSVProbb);
			//h_MisVertexCSVOffvsOn->Fill(CSVProbb,OnCSVProbb);
		}
		if( TagVarCSV_jetNSecondaryVertices > OnTagVarCSV_jetNSecondaryVertices){
			h_MisVertexDeepCSVOffvsOn->Fill(DeepCSVProbb,OnDeepCSVProbb);
			h_MisVertexCSVOffvsOn->Fill(CSVProbb,OnCSVProbb);
		}
		if( OnTagVarCSV_jetNSelectedTracks != TagVarCSV_jetNSelectedTracks){
			h_MisTrackDeepCSVOffvsOn->Fill(DeepCSVProbb,OnDeepCSVProbb);
		}
		if( jetNTracksEtaRel != OnjetNTracksEtaRel){
			h_MisTrackEtaRelDeepCSVOffvsOn->Fill(DeepCSVProbb,OnDeepCSVProbb);
		}
		for(int n = 0; n < jetNTracksEtaRel; n++){
			h_trackEtaRel->Fill(trackEtaRel[n]);
		}
		for(int n = 0; n < OnjetNTracksEtaRel; n++){
			h_OntrackEtaRel->Fill(OntrackEtaRel[n]);
		}
		for(int n = 0; n < n_jetNSelectedTracks_; n++){
			//cout << "Number " << n << "Value =" <<	TagVarCSVTrk_trackPtRel[n] << " " << TagVarCSVTrk_trackDeltaR[n] << " " << TagVarCSVTrk_trackSip3dSig[n] << " " << TagVarCSVTrk_trackSip2dSig[n] << " " << TagVarCSVTrk_trackDecayLenVal[n] << " " << TagVarCSVTrk_trackJetDistVal[n] << endl;
			h_trackPtRel->Fill(TagVarCSVTrk_trackPtRel[n]);
			h_trackDeltaR->Fill(TagVarCSVTrk_trackDeltaR[n]);
			h_trackSip3dSig->Fill(TagVarCSVTrk_trackSip3dSig[n]);
			h_trackSip2dSig->Fill(TagVarCSVTrk_trackSip2dSig[n]);
			h_trackDecayLenVal->Fill(TagVarCSVTrk_trackDecayLenVal[n]);
			h_trackJetDistVal->Fill(TagVarCSVTrk_trackJetDistVal[n]);		
		}
		for(int n = 0; n < Onn_jetNSelectedTracks_; n++){
			//cout << "Number " << n << "Value =" <<	TagVarCSVTrk_trackPtRel[n] << " " << TagVarCSVTrk_trackDeltaR[n] << " " << TagVarCSVTrk_trackSip3dSig[n] << " " << TagVarCSVTrk_trackSip2dSig[n] << " " << TagVarCSVTrk_trackDecayLenVal[n] << " " << TagVarCSVTrk_trackJetDistVal[n] << endl;
			h_OntrackPtRel->Fill(OnTagVarCSVTrk_trackPtRel[n]);
			h_OntrackDeltaR->Fill(OnTagVarCSVTrk_trackDeltaR[n]);
			h_OntrackSip3dSig->Fill(OnTagVarCSVTrk_trackSip3dSig[n]);
			h_OntrackSip2dSig->Fill(OnTagVarCSVTrk_trackSip2dSig[n]);
			h_OntrackDecayLenVal->Fill(OnTagVarCSVTrk_trackDecayLenVal[n]);
			h_OntrackJetDistVal->Fill(OnTagVarCSVTrk_trackJetDistVal[n]);		
		}
		for(int n = 0; n < OnNStoredVertices; n++){
		  if(NStoredVertices == 0){continue;}
		  if(OnTagVarCSV_flightDistance2dSig[n] < 3.0){
			h_OnDeepCSVprobbTest->Fill(OnDeepCSVProbb);
		  }
		  h_OnvertexMass->Fill(OnTagVarCSV_vertexMass[n]);
		  h_OnvertexNTracks->Fill(OnTagVarCSV_vertexNTracks[n]);
		  h_OnvertexEnergyRatio->Fill(OnTagVarCSV_vertexEnergyRatio[n]);
		  h_OnvertexJetDeltaR->Fill(OnTagVarCSV_vertexJetDeltaR[n]);
		  h_OnflightDistance2dVal->Fill(OnTagVarCSV_flightDistance2dVal[n]);
		  h_OnflightDistance3dVal->Fill(OnTagVarCSV_flightDistance3dVal[n]);
		  h_OnflightDistance2dSig->Fill(OnTagVarCSV_flightDistance2dSig[n]);
		  h_OnflightDistance3dSig->Fill(OnTagVarCSV_flightDistance3dSig[n]);
		}
		for(int n = 0; n < NStoredVertices; n++){
		  if(TagVarCSV_flightDistance2dSig[n] < 3.0){
			h_DeepCSVprobbTest->Fill(DeepCSVProbb);
		  }
		  h_vertexMass->Fill(TagVarCSV_vertexMass[n]);
		  h_vertexNTracks->Fill(TagVarCSV_vertexNTracks[n]);
		  h_vertexEnergyRatio->Fill(TagVarCSV_vertexEnergyRatio[n]);
		  h_vertexJetDeltaR->Fill(TagVarCSV_vertexJetDeltaR[n]);
		  h_flightDistance2dVal->Fill(TagVarCSV_flightDistance2dVal[n]);
		  h_flightDistance3dVal->Fill(TagVarCSV_flightDistance3dVal[n]);
		  h_flightDistance2dSig->Fill(TagVarCSV_flightDistance2dSig[n]);
		  h_flightDistance3dSig->Fill(TagVarCSV_flightDistance3dSig[n]);
		}
		if( (NStoredVertices == 1) && (OnNStoredVertices == 1) ){
			h_vertexMassOffVsOn->Fill(TagVarCSV_vertexMass[0],OnTagVarCSV_vertexMass[0]);
			h_vertexNTracksOffVsOn->Fill(TagVarCSV_vertexNTracks[0],OnTagVarCSV_vertexNTracks[0]);
			h_vertexJetDeltaROffVsOn->Fill(TagVarCSV_vertexJetDeltaR[0],OnTagVarCSV_vertexJetDeltaR[0]);
			h_vertexEnergyRatioOffVsOn->Fill(TagVarCSV_vertexEnergyRatio[0],OnTagVarCSV_vertexEnergyRatio[0]);
			h_flightDistance2dValOffVsOn->Fill(TagVarCSV_flightDistance2dVal[0],OnTagVarCSV_flightDistance2dVal[0]);
			h_flightDistance3dValOffVsOn->Fill(TagVarCSV_flightDistance3dVal[0],OnTagVarCSV_flightDistance3dVal[0]);
			h_flightDistance2dSigOffVsOn->Fill(TagVarCSV_flightDistance2dSig[0],OnTagVarCSV_flightDistance2dSig[0]);
			h_flightDistance3dSigOffVsOn->Fill(TagVarCSV_flightDistance3dSig[0],OnTagVarCSV_flightDistance3dSig[0]);
		}
	}
gStyle->SetOptStat(0);
	TCanvas *cd = new TCanvas("cd", "trackJetPtOffvsOn",50,50,1000,800);
	h_trackJetPtOffvsOn->Draw("colz");
	h_trackJetPtOffvsOn->GetXaxis()->SetTitle("Offline");
	h_trackJetPtOffvsOn->GetYaxis()->SetTitle("Online");
	printcor(h_trackJetPtOffvsOn->GetCorrelationFactor());
	cd->SetLogz();	
	cd->Update();
	TCanvas *cd1 = new TCanvas("cd1", "DeepCSVOffvsOn b",50,50,1000,800);
	h_DeepCSVprobbOffvsOn->Draw("colz");
	h_DeepCSVprobbOffvsOn->SetTitle("Offline vs Online DeepCSV discriminator");
	h_DeepCSVprobbOffvsOn->GetXaxis()->SetTitle("Offline DeepCSV discriminator");
	h_DeepCSVprobbOffvsOn->GetYaxis()->SetTitle("Online DeepCSV discriminator");
	//h_DeepCSVprobbOffvsOn->GetZaxis()->SetRangeUser(1,700);
	printcor(h_DeepCSVprobbOffvsOn->GetCorrelationFactor());
	cd1->SetLogz();
	cd1->Update();
	/*
	TCanvas *dc1 = new TCanvas("dc1", "new DeepCSVOffvsOn b",50,50,1000,800);
	h_DeepCSVprobbNewOffvsOn->Draw("colz");
	h_DeepCSVprobbNewOffvsOn->SetTitle("Legacy vs Candidate Method");
	h_DeepCSVprobbNewOffvsOn->GetXaxis()->SetTitle("Candidate Method");
	h_DeepCSVprobbNewOffvsOn->GetYaxis()->SetTitle("Legcay Method");
	printcor(h_DeepCSVprobbNewOffvsOn->GetCorrelationFactor());
	dc1->SetLogz();
	dc1->Update();
	*/
	TCanvas *d1 = new TCanvas("d1", "DeepCSVOffvsOn c",50,50,1000,800);
	h_DeepCSVprobcOffvsOn->Draw("colz");
	h_DeepCSVprobcOffvsOn->GetXaxis()->SetTitle("Offline");
	h_DeepCSVprobcOffvsOn->GetYaxis()->SetTitle("Online");
	printcor(h_DeepCSVprobcOffvsOn->GetCorrelationFactor());
	d1->SetLogz();
	d1->Update();
	TCanvas *d2 = new TCanvas("d2", "DeepCSVOffvsOn udsg",50,50,1000,800);
	h_DeepCSVprobudsgOffvsOn->Draw("colz");
	h_DeepCSVprobudsgOffvsOn->GetXaxis()->SetTitle("Offline");
	h_DeepCSVprobudsgOffvsOn->GetYaxis()->SetTitle("Online");
	printcor(h_DeepCSVprobudsgOffvsOn->GetCorrelationFactor());
	d2->SetLogz();
	d2->Update();
	TCanvas *cd2 = new TCanvas("cd2", "CSVOffvsOn",50,50,1000,800);
	h_CSVprobbOffvsOn->Draw("colz");
	h_CSVprobbOffvsOn->GetXaxis()->SetTitle("Offline");
	h_CSVprobbOffvsOn->GetYaxis()->SetTitle("Online");
	printcor(h_CSVprobbOffvsOn->GetCorrelationFactor());
	cd2->SetLogz();
	cd2->Update();
	TCanvas *cd3 = new TCanvas("cd3", "jetNSelectedTracksOffvsOn",50,50,1000,800);
	h_jetNSelectedTracksOffvsOn->Draw("colz");
	h_jetNSelectedTracksOffvsOn->GetXaxis()->SetTitle("Offline");
	h_jetNSelectedTracksOffvsOn->GetYaxis()->SetTitle("Online");
	cd3->SetLogz();
	cd3->Update();
	TCanvas *cd4 = new TCanvas("cd4", "jetNSecondaryVerticesOffvsOn",50,50,1000,800);
	h_jetNSecondaryVerticesOffvsOn->Draw("colz");
	h_jetNSecondaryVerticesOffvsOn->GetXaxis()->SetTitle("Offline");
	h_jetNSecondaryVerticesOffvsOn->GetYaxis()->SetTitle("Online");
	cd4->SetLogz();
	cd4->Update();
	TCanvas *cd5 = new TCanvas("cd5", "MisVertexDeepCSVOffvsOn",50,50,1000,800);
	h_MisVertexDeepCSVOffvsOn->Draw("colz");
	h_MisVertexDeepCSVOffvsOn->GetXaxis()->SetTitle("Offline");
	h_MisVertexDeepCSVOffvsOn->GetYaxis()->SetTitle("Online");
	cout << "Deep CSV with different vertex categories = " << h_MisVertexDeepCSVOffvsOn->GetCorrelationFactor() << endl;
	cd5->SetLogz();	
	cd5->Update();
	TCanvas *cd50 = new TCanvas("cd50", "MisVertexCSVOffvsOn",50,50,1000,800);
	h_MisVertexCSVOffvsOn->Draw("colz");
	h_MisVertexCSVOffvsOn->GetXaxis()->SetTitle("Offline");
	h_MisVertexCSVOffvsOn->GetYaxis()->SetTitle("Online");
	cout << "CSV with different vertex categories = " << h_MisVertexCSVOffvsOn->GetCorrelationFactor() << endl;
	cd50->SetLogz();	
	cd50->Update();
	TCanvas *cd6 = new TCanvas("cd6", "MisTrackDeepCSVOffvsOn",50,50,1000,800);
	h_MisTrackDeepCSVOffvsOn->Draw("colz");
	h_MisTrackDeepCSVOffvsOn->GetXaxis()->SetTitle("Offline");
	h_MisTrackDeepCSVOffvsOn->GetYaxis()->SetTitle("Online");
	//cout << h_MisTrackDeepCSVOffvsOn->GetCorrelationFactor() << endl;
	cd6->SetLogz();
	cd6->Update();
	TCanvas *cd60 = new TCanvas("cd60", "MisTrackEtaRelDeepCSVOffvsOn",50,50,1000,800);
	h_MisTrackEtaRelDeepCSVOffvsOn->Draw("colz");
	h_MisTrackEtaRelDeepCSVOffvsOn->GetXaxis()->SetTitle("Offline");
	h_MisTrackEtaRelDeepCSVOffvsOn->GetYaxis()->SetTitle("Online");
	cout << "Mis Eta Rel Corr =" << h_MisTrackEtaRelDeepCSVOffvsOn->GetCorrelationFactor() << endl;
	cd60->SetLogz();
	cd60->Update();						
	TCanvas *cd7 = new TCanvas("cd7", "trackSip3dValAboveCharmOffvsOn",50,50,1000,800);
	h_trackSip3dValAboveCharmOffvsOn->Draw("colz");
	h_trackSip3dValAboveCharmOffvsOn->GetXaxis()->SetTitle("Offline");
	h_trackSip3dValAboveCharmOffvsOn->GetYaxis()->SetTitle("Online");
	cd7->SetLogz();
	cd7->Update();			
	TCanvas *cd8 = new TCanvas("cd8", "trackSip2dValAboveCharmOffvsOn",50,50,1000,800);
	h_trackSip2dValAboveCharmOffvsOn->Draw("colz");
	h_trackSip2dValAboveCharmOffvsOn->GetXaxis()->SetTitle("Offline");
	h_trackSip2dValAboveCharmOffvsOn->GetYaxis()->SetTitle("Online");
	cd8->SetLogz();
	cd8->Update();
	TCanvas *cd9 = new TCanvas("cd9", "trackSip3dSigAboveCharmOffvsOn",50,50,1000,800);
	h_trackSip3dSigAboveCharmOffvsOn->Draw("colz");
	h_trackSip3dSigAboveCharmOffvsOn->GetXaxis()->SetTitle("Offline");
	h_trackSip3dSigAboveCharmOffvsOn->GetYaxis()->SetTitle("Online");
	cd9->SetLogz();
	cd9->Update();
	TCanvas *cd10 = new TCanvas("cd10", "trackSip2dSigAboveCharmOffvsOn",50,50,1000,800);
	h_trackSip2dSigAboveCharmOffvsOn->Draw("colz");
	h_trackSip2dSigAboveCharmOffvsOn->GetXaxis()->SetTitle("Offline");
	h_trackSip2dSigAboveCharmOffvsOn->GetYaxis()->SetTitle("Online");
	cd10->SetLogz();
	cd10->Update();
	TCanvas *cd11 = new TCanvas("cd11", "trackSumJetDeltaROffvsOn",50,50,1000,800);
	h_trackSumJetDeltaROffvsOn->Draw("colz");
	h_trackSumJetDeltaROffvsOn->SetTitle("Pseudoangular Distance between Jet Axis and Track Fourvector Sum");
	h_trackSumJetDeltaROffvsOn->GetXaxis()->SetTitle("Offline trackSumJetDeltaR");
	h_trackSumJetDeltaROffvsOn->GetYaxis()->SetTitle("Online trackSumJetDeltaR");
	printcor(h_trackSumJetDeltaROffvsOn->GetCorrelationFactor());
	cd11->SetLogz();
	cd11->Update();
	TCanvas *cd12 = new TCanvas("cd12", "vertexCategoryOffvsOn",50,50,1000,800);
	h_vertexCategoryOffvsOn->Draw("colz");
	h_vertexCategoryOffvsOn->GetXaxis()->SetTitle("Offline");
	h_vertexCategoryOffvsOn->GetYaxis()->SetTitle("Online");
	cd12->SetLogz();
	cd12->Update();

/*
	TCanvas *cd120 = new TCanvas("cd120", "vertexMass",50,50,1000,800);
	h_vertexMassOffVsOn->Draw("colz");
	h_vertexMassOffVsOn->GetXaxis()->SetTitle("Offline");
	h_vertexMassOffVsOn->GetYaxis()->SetTitle("Online");
	cd120->Update();
	TCanvas *cd121 = new TCanvas("cd121", "vertexNTracks",50,50,1000,800);
	h_vertexNTracksOffVsOn->Draw("colz");
	h_vertexNTracksOffVsOn->GetXaxis()->SetTitle("Offline");
	h_vertexNTracksOffVsOn->GetYaxis()->SetTitle("Online");
	cd121->Update();
	TCanvas *cd122 = new TCanvas("cd122", "vertexEnergyRatio",50,50,1000,800);
	h_vertexEnergyRatioOffVsOn->Draw("colz");
	h_vertexEnergyRatioOffVsOn->GetXaxis()->SetTitle("Offline");
	h_vertexEnergyRatioOffVsOn->GetYaxis()->SetTitle("Online");
	cd122->Update();

*/

	TCanvas *cd13 = new TCanvas("cd13", "trackSumJetETRatioOffvsOn",50,50,1000,800);
	h_trackSumJetETRatioOffvsOn->Draw("colz");
	h_trackSumJetETRatioOffvsOn->GetXaxis()->SetTitle("Offline");
	h_trackSumJetETRatioOffvsOn->GetYaxis()->SetTitle("Online");
	printcor(h_trackSumJetETRatioOffvsOn->GetCorrelationFactor());
	cd13->Update();
	gStyle->SetMarkerSize(1);
	gStyle->SetMarkerStyle(20);
	TCanvas *cd14 = new TCanvas("cd14", "trackEtaRelOffvsOn",50,50,1000,800);
	h_jetNTracksEtaRelOffvsOn->Draw("colz");
	h_jetNTracksEtaRelOffvsOn->GetXaxis()->SetTitle("Offline");
	h_jetNTracksEtaRelOffvsOn->GetYaxis()->SetTitle("Online");
	cd14->Update();
	TCanvas *cd15 = new TCanvas("cd15", "trackPtRelOffvsOn",50,50,1000,800);
	float scale1 = h_trackPtRel->Integral(1,100);
	h_trackPtRel->Rebin();
	h_trackPtRel->Draw("hist");
	h_trackPtRel->Scale(1/scale1);
	h_trackPtRel->SetFillColor(2);
	float scale2 = h_OntrackPtRel->Integral(1,100);
	h_OntrackPtRel->Rebin();
	h_OntrackPtRel->Draw("E0 same");
	h_OntrackPtRel->Scale(1/scale2);	
	h_OntrackPtRel->SetMarkerStyle(20);
	h_trackPtRel->SetTitle("Track Transverse Momentum, relative to the jet axis");
	h_trackPtRel->GetYaxis()->SetTitle("Normalized Event Count");
	h_trackPtRel->GetXaxis()->SetTitle("trackPtRel [GeV]");
   	auto legend = new TLegend(0.9,0.7,0.48,0.9);
   	legend->AddEntry(h_trackPtRel,"Offline");
   	legend->AddEntry(h_OntrackPtRel,"Online");
	legend->Draw();
	cd15->SetLogy();
	cd15->Update();
	TCanvas *cd16 = new TCanvas("cd16", "trackDeltaROffvsOn",50,50,1000,800);
	float scale3 = h_trackDeltaR->Integral(1,100);
	h_trackDeltaR->Rebin();
	h_trackDeltaR->Draw("hist");
	h_trackDeltaR->SetFillColor(2);
	h_trackDeltaR->Scale(1/scale3);
	float scale4 = h_OntrackDeltaR->Integral(1,100);
	h_OntrackDeltaR->Rebin();
	h_OntrackDeltaR->Draw("E0 same");
	h_OntrackDeltaR->SetMarkerStyle(20);
	h_OntrackDeltaR->Scale(1/scale4);
	legend->Draw();
	cd16->SetLogy();
	cd16->Update();
	TCanvas *cd17 = new TCanvas("cd17", "trackDecayLenValOffvsOn",50,50,1000,800);
	float scale5 = h_trackDecayLenVal->Integral(1,100);
	h_trackDecayLenVal->Draw("hist");
	h_trackDecayLenVal->Rebin(2);
	h_trackDecayLenVal->Scale(1/scale5);
	h_trackDecayLenVal->SetFillColor(2);
	float scale6 = h_OntrackDecayLenVal->Integral(1,100);
	h_OntrackDecayLenVal->Rebin(2);	
	h_OntrackDecayLenVal->Draw("E0 same");
	h_OntrackDecayLenVal->Scale(1/scale6);
	h_OntrackDecayLenVal->SetMarkerStyle(20);
	legend->Draw();
	cd17->SetLogy();
	cd17->Update();
	TCanvas *cd18 = new TCanvas("cd18", "trackJetDistValOffvsOn",50,50,1000,800);
	float scale7 = h_trackJetDistVal->Integral(1,100);
	h_trackJetDistVal->Rebin(2);	
	h_trackJetDistVal->Draw("hist");
	h_trackJetDistVal->SetFillColor(2);
	h_trackJetDistVal->Scale(1/scale7);
	float scale8 = h_OntrackJetDistVal->Integral(1,100);
	h_OntrackJetDistVal->Rebin(2);	
	h_OntrackJetDistVal->Draw("E0 same");
	h_OntrackJetDistVal->SetMarkerStyle(20);
	h_OntrackJetDistVal->Scale(1/scale8);
	legend->Draw();
	cd18->SetLogy();
	cd18->Update();
	TCanvas *cd19 = new TCanvas("cd19", "vertexMassOffvsOn",50,50,1000,800);
	float scale9 = h_vertexMass->Integral(1,100);
	h_vertexMass->Rebin(5);	
	h_vertexMass->Draw("hist");
	h_vertexMass->SetFillColor(2);
	h_vertexMass->Scale(1/scale9);
	float scale10 = h_OnvertexMass->Integral(1,100);
	h_OnvertexMass->Rebin(5);	
	h_OnvertexMass->Draw("E0 same");
	h_OnvertexMass->SetMarkerStyle(20);
	h_OnvertexMass->Scale(1/scale10);
	legend->Draw();
	cd19->SetLogy();
	cd19->Update();
	TCanvas *cd20 = new TCanvas("cd20", "vertexNTracksOffvsOn",50,50,1000,800);
	scale9 = h_vertexNTracks->Integral(1,16);
	scale10 = h_OnvertexNTracks->Integral(1,16);
	h_vertexNTracks->SetTitle("Number of Vertex Tracks offline and online");
	h_vertexNTracks->Draw("hist");
	h_vertexNTracks->SetFillColor(2);
	//h_vertexNTracks->Scale(1/scale9);
	h_OnvertexNTracks->Draw("E0 same");
	h_OnvertexNTracks->SetMarkerStyle(20);
	//h_OnvertexNTracks->Scale(1/scale10);
	h_vertexNTracks->GetYaxis()->SetTitle("Normalized Event Count");
	h_vertexNTracks->GetXaxis()->SetTitle("Number of Vertex Tracks");
	legend->Draw();
	cd20->SetLogy();
	cd20->Update();
	TCanvas *cd21 = new TCanvas("cd21", "vertexEnergyRatioOffvsOn",50,50,1000,800);
	scale9 = h_vertexEnergyRatio->Integral(1,100);
	scale10 = h_OnvertexEnergyRatio->Integral(1,100);
	h_vertexEnergyRatio->Rebin(5);	
	h_vertexEnergyRatio->Draw("hist");
	h_vertexEnergyRatio->SetFillColor(2);
	h_vertexEnergyRatio->Scale(1/scale9);
	h_OnvertexEnergyRatio->Rebin(5);	
	h_OnvertexEnergyRatio->Draw("E0 same");
	h_OnvertexEnergyRatio->SetMarkerStyle(20);
	h_OnvertexEnergyRatio->Scale(1/scale10);
	legend->Draw();
	cd21->SetLogy();
	cd21->Update();
	TCanvas *cd22 = new TCanvas("cd22", "vertexJetDeltaROffvsOn",50,50,1000,800);
	scale9 = h_vertexJetDeltaR->Integral(1,100);
	scale10 = h_OnvertexJetDeltaR->Integral(1,100);
	h_vertexJetDeltaR->Rebin(5);	
	h_vertexJetDeltaR->Draw("hist");
	h_vertexJetDeltaR->SetFillColor(2);
	h_vertexJetDeltaR->Scale(1/scale9);
	h_OnvertexJetDeltaR->Rebin(5);	
	h_OnvertexJetDeltaR->Draw("E0 same");
	h_OnvertexJetDeltaR->SetMarkerStyle(20);
	h_OnvertexJetDeltaR->Scale(1/scale10);
   	auto legend1 = new TLegend(0.9,0.7,0.48,0.9);
   	legend1->AddEntry(h_vertexJetDeltaR,"Offline");
   	legend1->AddEntry(h_OnvertexJetDeltaR,"Online");
	legend1->Draw();
	cd22->SetLogy();
	cd22->Update();
	TCanvas *cd23 = new TCanvas("cd23", "flightDistance2dValOffvsOn",50,50,1000,800);
	scale9 = h_flightDistance2dVal->Integral(1,20);
	//h_flightDistance2dVal->Rebin(5);	
	h_flightDistance2dVal->Draw("hist");
	h_flightDistance2dVal->SetFillColor(2);
	h_flightDistance2dVal->Scale(1/scale9);
	scale10 = h_OnflightDistance2dVal->Integral(1,20);
	//h_OnflightDistance2dVal->Rebin(5);	
	h_OnflightDistance2dVal->Draw("E0 same");
	h_OnflightDistance2dVal->SetMarkerStyle(20);
	h_OnflightDistance2dVal->Scale(1/scale10);
	legend1->Draw();
	cd23->SetLogy();
	cd23->Update();
	TCanvas *cd24 = new TCanvas("cd24", "flightDistance3dValOffvsOn",50,50,1000,800);
	//h_flightDistance3dVal->Rebin(5);	
	h_flightDistance3dVal->Draw("hist");
	h_flightDistance3dVal->SetFillColor(2);
	//h_flightDistance3dVal->Scale(1/scale9);
	//h_OnflightDistance3dVal->Rebin(5);	
	h_OnflightDistance3dVal->Draw("E0 same");
	h_OnflightDistance3dVal->SetMarkerStyle(20);
	//h_OnflightDistance3dVal->Scale(1/scale10);
	legend1->Draw();
	cd24->SetLogy();
	cd24->Update();
	TCanvas *cd25 = new TCanvas("cd25", "flightDistance3dSigOffvsOn",50,50,1000,800);
	scale9 = h_flightDistance3dSig->Integral(1,200);
	//h_flightDistance3dSig->Rebin(5);	
	h_flightDistance3dSig->Draw("hist");
	h_flightDistance3dSig->SetFillColor(2);
	h_flightDistance3dSig->Scale(1/scale9);
	//h_OnflightDistance3dSig->Rebin(5);	
	scale10 = h_OnflightDistance3dSig->Integral(1,200);
	h_OnflightDistance3dSig->Draw("E0 same");
	h_OnflightDistance3dSig->SetMarkerStyle(20);
	h_OnflightDistance3dSig->Scale(1/scale10);
	legend1->Draw();
	cd25->SetLogy();
	cd25->Update();
	TCanvas *cd26 = new TCanvas("cd26", "flightDistance2dSigOffvsOn",50,50,1000,800);
	scale9 = h_flightDistance2dSig->Integral(1,20);
	h_flightDistance2dSig->Draw("hist");
	h_flightDistance2dSig->SetFillColor(2);
	h_flightDistance2dSig->Scale(1/scale9);
	//h_OnflightDistance2dSig->Rebin(5);
	scale10 = h_OnflightDistance2dSig->Integral(1,20);	
	h_OnflightDistance2dSig->Draw("E0 same");
	h_OnflightDistance2dSig->SetMarkerStyle(20);
	h_OnflightDistance2dSig->Scale(1/scale10);
	legend1->Draw();
	cd26->SetLogy();
	cd26->Update();
	TCanvas *cd27 = new TCanvas("cd27", "DeepCSVprobb",50,50,1000,800);
	h_DeepCSVprobb->Rebin(5);	
	h_DeepCSVprobb->Draw("hist");
	h_DeepCSVprobb->SetFillColor(2);
	float scale11 = h_DeepCSVprobb->Integral(1,20);
	h_DeepCSVprobb->Scale(1/scale11);
	h_OnDeepCSVprobb->Rebin(5);
	float scale12 = h_OnDeepCSVprobb->Integral(1,20);	
	h_OnDeepCSVprobb->Draw("E0 same");
	h_OnDeepCSVprobb->SetMarkerStyle(20);
	h_OnDeepCSVprobb->Scale(1/scale12);
	legend1->Draw();
	cd27->SetLogy();
	cd27->Update();
	TCanvas *cd28 = new TCanvas("cd28", "CSVprobb",50,50,1000,800);
	h_CSVprobb->Rebin(5);	
	h_CSVprobb->Draw("hist");
	h_CSVprobb->SetFillColor(2);
	h_CSVprobb->Scale(1/scale11);
	h_OnCSVprobb->Rebin(5);	
	h_OnCSVprobb->Draw("E0 same");
	h_OnCSVprobb->SetMarkerStyle(20);
	h_OnCSVprobb->Scale(1/scale12);
	legend1->Draw();
	cd28->SetLogy();
	cd28->Update();
	TCanvas *cd29 = new TCanvas("cd29", "DeepCSVprobc",50,50,1000,800);
	h_DeepCSVprobc->Rebin(5);	
	h_DeepCSVprobc->Draw("hist");
	h_DeepCSVprobc->SetFillColor(2);
	h_DeepCSVprobc->Scale(1/scale11);
	h_OnDeepCSVprobc->Rebin(5);
	h_OnDeepCSVprobc->Draw("E0 same");
	h_OnDeepCSVprobc->SetMarkerStyle(20);
	h_OnDeepCSVprobc->Scale(1/scale12);
	legend1->Draw();
	cd29->SetLogy();
	cd29->Update();
	TCanvas *ce28 = new TCanvas("ce28", "DeepCSVprobudsg",50,50,1000,800);
	h_DeepCSVprobudsg->Rebin(5);	
	h_DeepCSVprobudsg->Draw("hist");
	h_DeepCSVprobudsg->SetFillColor(2);
	h_DeepCSVprobudsg->Scale(1/scale11);
	h_OnDeepCSVprobudsg->Rebin(5);
	h_OnDeepCSVprobudsg->Draw("E0 same");
	h_OnDeepCSVprobudsg->SetMarkerStyle(20);
	h_OnDeepCSVprobudsg->Scale(1/scale12);
	legend1->Draw();
	ce28->SetLogy();
	ce28->Update();
	TCanvas *ce1 = new TCanvas("ce1", "trackSip3dSig",50,50,1000,800);
	h_trackSip3dSig->Rebin(5);	
	h_trackSip3dSig->Draw("hist");
	h_trackSip3dSig->SetFillColor(2);
	h_trackSip3dSig->Scale(1/scale3);
	h_OntrackSip3dSig->Rebin(5);
	h_OntrackSip3dSig->Draw("E0 same");
	h_OntrackSip3dSig->SetMarkerStyle(20);
	h_OntrackSip3dSig->Scale(1/scale4);
	legend1->Draw();
	ce1->SetLogy();
	ce1->Update();
	TCanvas *ce2 = new TCanvas("ce2", "trackSip2dSig",50,50,1000,800);
	h_trackSip2dSig->Rebin(5);	
	h_trackSip2dSig->Draw("hist");
	h_trackSip2dSig->SetFillColor(2);
	h_trackSip2dSig->Scale(1/scale3);
	h_OntrackSip2dSig->Rebin(5);
	h_OntrackSip2dSig->Draw("E0 same");
	h_OntrackSip2dSig->SetMarkerStyle(20);
	h_OntrackSip2dSig->Scale(1/scale4);
	legend1->Draw();
	ce2->SetLogy();
	ce2->Update();
	TCanvas *ce3 = new TCanvas("ce3", "trackEtaRel",50,50,1000,800);
	float EtaScale = h_trackEtaRel->Integral(1,100);
	h_trackEtaRel->Rebin(5);
	h_trackEtaRel->Draw("hist");
	h_trackEtaRel->SetFillColor(2);
	h_trackEtaRel->Scale(1/EtaScale);
	float OnEtaScale = h_OntrackEtaRel->Integral(1,100);
	h_OntrackEtaRel->Rebin(5);
	h_OntrackEtaRel->Draw("E0 same");
	h_OntrackEtaRel->SetMarkerStyle(20);
	h_OntrackEtaRel->Scale(1/OnEtaScale);
	legend1->Draw();
	ce3->SetLogy();
	ce3->Update();

	TCanvas *cblah = new TCanvas("cblah", "cblah",50,50,1000,800);
	h_eff->Divide(h_pass,h_all,1,1);
	h_eff->SetNameTitle("DeepCSV Turn on Curve", "DeepCSV Turn on Curve");
	h_eff->GetXaxis()->SetTitle("Offline DeepCSV discriminator ");
	h_eff->GetYaxis()->SetTitle("Efficiency");
	h_eff->SetMarkerStyle(20);
	h_eff->SetMarkerColor(2);		
	h_eff->Draw();
    	TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    	l.SetNDC();
    	l.SetTextFont(72);
    	l.SetTextColor(kBlack);
    	l.SetTextSize(0.035);
    	//l.DrawLatex(0.15,0.81,"Online DeepCSV discriminator WP = 0.6324");
	l.DrawLatex(0.15,0.81,"Online DeepCSV discriminator WP = 0.6");
	cblah->Update();	


	TCanvas *cblah2 = new TCanvas("cblah2", "cblah2",50,50,1000,800);
	h_eff2->Divide(h_pass2,h_all2,1,1);
	h_eff2->SetNameTitle("CSV Turn on Curve", "CSV Turn on Curve");
	h_eff2->GetXaxis()->SetTitle("Offline CSV discriminator");
	h_eff2->GetYaxis()->SetTitle("Efficiency");
	h_eff2->SetMarkerStyle(20);
	h_eff2->SetMarkerColor(2);		
	h_eff2->Draw();
    	TLatex l1; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    	l1.SetNDC();
    	l1.SetTextFont(72);
    	l1.SetTextColor(kBlack);
    	l1.SetTextSize(0.035);
    	//l1.DrawLatex(0.15,0.81,"Online CSV discriminator WP = 0.8484");
	l1.DrawLatex(0.15,0.81,"Online CSV discriminator WP = 0.7");
	cblah2->Update();	


	TCanvas *bob2 = new TCanvas("bob2", "DeepCSV vs CSV online",50,50,1000,800);
	h_DeepCSVCSVcompOnline->Draw("colz");
	h_DeepCSVCSVcompOnline->GetXaxis()->SetTitle("online DeepCSV");
	h_DeepCSVCSVcompOnline->GetYaxis()->SetTitle("online CSV");
	printcor(h_DeepCSVCSVcompOnline->GetCorrelationFactor());
	bob2->SetLogz();
	bob2->Update();


	TCanvas *bab3 = new TCanvas("bab3", "DeepCSV low flight dist",50,50,1000,800);
	float kappo1 = h_OnDeepCSVprobbTest->Integral(1,100);
	h_OnDeepCSVprobbTest->Scale(1/kappo1);
	h_OnDeepCSVprobbTest->SetMarkerStyle(20);
	h_OnDeepCSVprobbTest->SetMarkerColor(2);
	h_OnDeepCSVprobbTest->Draw();
	float kappo = h_DeepCSVprobbTest->Integral(1,100);
	h_DeepCSVprobbTest->Scale(1/kappo);
	h_DeepCSVprobbTest->SetMarkerStyle(20);
	h_DeepCSVprobbTest->SetMarkerColor(4);
	h_DeepCSVprobbTest->Draw("same E0");
	
	bab3->Update();

	TCanvas *bob3 = new TCanvas("bob3", "DeepCSV vs CSV offline",50,50,1000,800);
	h_DeepCSVCSVcompOffline->Draw("colz");
	h_DeepCSVCSVcompOffline->GetXaxis()->SetTitle("offline DeepCSV");
	h_DeepCSVCSVcompOffline->GetYaxis()->SetTitle("offline CSV");
	printcor(h_DeepCSVCSVcompOffline->GetCorrelationFactor());
	bob3->SetLogz();
	bob3->Update();

	return 1;
}	
