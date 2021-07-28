#include <stdexcept>
#include <iostream>
#include "globals.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "AnalysisManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"

//---------------------------------------------------------------------------

int main(int argc, char** argv)
{
//detect interactive mode (if no arguments) and define UI session
  G4UIExecutive* ui = nullptr;
  if (argc == 1) ui = new G4UIExecutive(argc,argv);

  G4RunManager* runManager = new G4RunManager;
  PhysicsList*  phys       = new PhysicsList();
  runManager->SetUserInitialization(phys);

  PrimaryGeneratorAction* pga        = new PrimaryGeneratorAction();
  AnalysisManager*        anaManager = new AnalysisManager();
  EventAction*            event      = new EventAction( anaManager, pga );
  DetectorConstruction*   detCon     = new DetectorConstruction();

  runManager->SetUserInitialization(detCon);
  runManager->SetUserAction(pga);
  runManager->SetUserAction(new SteppingAction(detCon));
  runManager->SetUserAction(event);

  //initialize visualization
  G4VisManager* visManager = nullptr;

  //get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  if (ui)  {
   //interactive mode
   visManager = new G4VisExecutive;
   visManager->Initialize();
   ui->SessionStart();
   delete ui;
  }
  else  {
   //batch mode
   G4String command = "/control/execute ";
   G4String fileName = argv[1];
   UImanager->ApplyCommand(command+fileName);
  }
  

  if(visManager) delete visManager;
  delete anaManager;
  delete runManager;

  return 0;
}

//---------------------------------------------------------------------------
