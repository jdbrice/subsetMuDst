
#include <iostream>
#include "allroot.h"
#include "constants.h"
#include "chainLoader.h"
#include "xmlConfig.h"

/* 
*
*	GUI Application
*
*/
/*
int main(int argc, char* argv[]) {

  TApplication* rootapp = new TApplication("example",&argc, argv);

  TRandom1* myrand = new TRandom1();
  TH1F* myhist = new TH1F("stats","",100,0,10);
  for(int i=0;i<10000;++i) {
    myhist->Fill(myrand->Gaus(5,1));
  }
  myhist->Draw();
  rootapp->Run();
  return 0;
}
*/


int main( int argc, char* argv[] ) {


  gErrorIgnoreLevel=kBreak;

  if ( argc >= 2 ){
    
  } else {
    cout << "Please provide a config file." << endl;
    return 0;
  }

  xmlConfig config( argv[ 1 ] );
  config.report();

  TChain * chain = new TChain( "MuDst" );
  chainLoader::load( chain, (char*)config.getString("input.dataDir", "./").c_str(), config.getInt( "input.maxFiles", 1000 ) );

  chain->SetBranchStatus( "*", 0 );

  vector<string> branches = config.getStringVector( "keepBranches" );
  for ( uint i = 0; i < branches.size(); i++ ){
    chain->SetBranchStatus( branches[ i ].c_str(), 1 );
    cout << "[Keeping Branch]    " << branches[ i ] << endl;
  }


  TFile *newFile = new TFile( config.getString( "output.root", "out.root" ).c_str() ,"recreate");
  TTree *newTree = chain->CloneTree();

  newFile->Write();
  delete newFile;
  delete chain;

	return 0;
}
