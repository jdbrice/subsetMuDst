
#include <iostream>
#include "allroot.h"
#include "constants.h"

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

	cout << "const: " << Constants::nChannels << endl;
  if ( argc >= 2 ){
    
  } else {
    cout << "Please provide a config file." << endl;
    return 0;
  }

  xmlConfig config( argv[ 1 ] );
  config.report();

  



	return 0;
}
