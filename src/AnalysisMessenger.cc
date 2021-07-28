#include "AnalysisMessenger.hh"
#include "AnalysisManager.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "globals.hh"

//---------------------------------------------------------------------------

AnalysisMessenger::AnalysisMessenger(AnalysisManager* anMana)
:fAnalysisManager(anMana)
{
  fAnalysisDir = new G4UIdirectory("/APEXMC/analysis/");
  fAnalysisDir->SetGuidance("Analysis output control");

  fOutFileCmd = new G4UIcmdWithAString("/APEXMC/analysis/setOutputFile",this);
  fOutFileCmd->SetGuidance("Set the full name and path of the output file");
  fOutFileCmd->SetParameterName("choice",true);
  fOutFileCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
} 

//---------------------------------------------------------------------------

AnalysisMessenger::~AnalysisMessenger()
{
}

//---------------------------------------------------------------------------

void AnalysisMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{
  if(command == fOutFileCmd)
    {fAnalysisManager->SetOutFileName(newValue.data());}
}

//---------------------------------------------------------------------------
