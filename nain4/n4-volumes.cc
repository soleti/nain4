#include "n4-volumes.hh"

#include "nain4.hh"
#include <G4LogicalVolume.hh>
#include <G4Sphere.hh>
#include <G4VGraphicsScene.hh>


namespace nain4 {

G4Sphere* sphere::solid() const {
  return new G4Sphere(name, r_min_, r_max_, phi_start_, phi_delta_, theta_start_, theta_delta_);
}

G4LogicalVolume* sphere::logical(G4Material* material) const {
  return volume<G4Sphere>(name, material, r_min_, r_max_, phi_start_, phi_delta_, theta_start_, theta_delta_);
}

} // namespace nain4
