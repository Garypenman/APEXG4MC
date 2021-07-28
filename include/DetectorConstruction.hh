#ifndef DetectorConstruction_H
#define DetectorConstruction_H 1

#include "G4VUserDetectorConstruction.hh"
#include "G4NistManager.hh"
#include "DetectorMessenger.hh"
#include "BField_Septum_New.hh"

//---------------------------------------------------------------------------

class G4VPhysicalVolume;
class FluxSD;
class EnergyDepositSD;

//---------------------------------------------------------------------------

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  DetectorConstruction();
  ~DetectorConstruction();

  G4VPhysicalVolume* Construct();

  void UpdateGeometry();

  inline G4VPhysicalVolume* GetExpHall()    { return fExpHall;     };
  inline G4VPhysicalVolume* GetDetVol(G4int i)     { return fDetVol[i]; };
  inline G4VPhysicalVolume* GetSurfVol()    { return fSurfVol;  };
  inline FluxSD*            GetFluxSD()     { return fFluxSD;    };
  inline G4int              GetNoSD()       { return fNSD;    };

  void SetTargetLength    ( G4double l    ) { fTarLength = l;    }
  void SetBigBiteDistance ( G4double dis  ) { fBBDist    = dis;  }
  void SetBigBiteAngle    ( G4double an   ) { fBBAngle   = an;   }
  void SetBigBiteField    ( G4double Bx   ) { fBBBx      = Bx;   }
  void SetBigCalDistance  ( G4double dist ) { fBCDist    = dist; }
  void SetBigCalAngle     ( G4double ang  ) { fBCAngle   = ang;  }
  void SetHMSAngle        ( G4double a    ) { fHMSAngle  = a;    }

  private:

  G4NistManager*     fNistManager;
  DetectorMessenger* fDetMessenger;

  BField_Septum_New* fSeptumField;

  static const G4int fNSD = 2;

  G4VPhysicalVolume* fExpHall;
  G4VPhysicalVolume* fDetVol[fNSD];
  G4VPhysicalVolume* fSurfVol;

  FluxSD*            fFluxSD;
  EnergyDepositSD*   fEdepSD;

  G4double           fTarLength;
  G4double           fBBDist;
  G4double           fBBAngle;
  G4double           fBBBx;
  G4double           fBCDist;
  G4double           fBCAngle;
  G4double           fHMSAngle;

};
#endif

//---------------------------------------------------------------------------

