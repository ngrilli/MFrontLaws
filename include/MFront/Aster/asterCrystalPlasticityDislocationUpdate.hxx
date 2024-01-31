/*!
* \file   include/MFront/Aster/asterCrystalPlasticityDislocationUpdate.hxx
* \brief  This file declares the aster interface for the CrystalPlasticityDislocationUpdate behaviour law
* \author Nicolò Grilli
* \date   17 / 08 / 2023
*/

#ifndef LIB_ASTER_CRYSTALPLASTICITYDISLOCATIONUPDATE_HXX
#define LIB_ASTER_CRYSTALPLASTICITYDISLOCATIONUPDATE_HXX

#include"TFEL/Config/TFELConfig.hxx"

#include"MFront/Aster/Aster.hxx"

#ifdef __cplusplus
#include"MFront/Aster/AsterTraits.hxx"
#include"MFront/Aster/AsterOrthotropicBehaviour.hxx"
#include"TFEL/Material/CrystalPlasticityDislocationUpdate.hxx"
#endif /* __cplusplus */

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif /* NOMINMAX */
#include <windows.h>
#ifdef small
#undef small
#endif /* small */
#endif /* _WIN32 */

#ifndef MFRONT_SHAREDOBJ
#define MFRONT_SHAREDOBJ TFEL_VISIBILITY_EXPORT
#endif /* MFRONT_SHAREDOBJ */

#ifdef __cplusplus

namespace aster{

template<typename Type>
struct AsterTraits<tfel::material::CrystalPlasticityDislocationUpdate<tfel::material::ModellingHypothesis::TRIDIMENSIONAL,Type,false> >
{
//! behaviour type
static constexpr AsterBehaviourType btype = aster::STANDARDFINITESTRAINBEHAVIOUR;
//! space dimension
static constexpr unsigned short N = tfel::material::ModellingHypothesisToSpaceDimension<tfel::material::ModellingHypothesis::TRIDIMENSIONAL>::value;
// tiny vector size
static constexpr unsigned short TVectorSize = N;
// symmetric tensor size
static constexpr unsigned short StensorSize = tfel::math::StensorDimeToSize<N>::value;
// tensor size
static constexpr unsigned short TensorSize  = tfel::math::TensorDimeToSize<N>::value;
// size of the driving variable array
static constexpr unsigned short GradientSize = TensorSize;
// size of the thermodynamic force variable array (STRESS)
static constexpr unsigned short ThermodynamicForceVariableSize = StensorSize;
static constexpr AsterErrorReportPolicy errorReportPolicy = ASTER_NOERRORREPORT;
static constexpr bool requiresUnAlteredStiffnessTensor = false;
static constexpr bool requiresStiffnessTensor = true;
static constexpr bool requiresThermalExpansionCoefficientTensor = false;
static constexpr AsterSymmetryType type = aster::ORTHOTROPIC;
static constexpr AsterFiniteStrainFormulation afsf = aster::SIMO_MIEHE;
static constexpr unsigned short material_properties_nb = 14;
static constexpr AsterSymmetryType etype = aster::ORTHOTROPIC;
static constexpr unsigned short elasticPropertiesOffset = AsterOrthotropicElasticPropertiesOffset<N>::value;
static constexpr unsigned short thermalExpansionPropertiesOffset = 0u;
}; // end of class AsterTraits

} // end of namespace aster

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

MFRONT_SHAREDOBJ void
astercrystalplasticitydislocationupdate_setOutOfBoundsPolicy(const int);

MFRONT_SHAREDOBJ int
astercrystalplasticitydislocationupdate_Tridimensional_setParameter(const char *const,const double);

MFRONT_SHAREDOBJ int
astercrystalplasticitydislocationupdate_Tridimensional_setUnsignedShortParameter(const char *const,const unsigned short);

MFRONT_SHAREDOBJ char *astercrystalplasticitydislocationupdate_getIntegrationErrorMessage();

MFRONT_SHAREDOBJ void
CrystalPlasticityDislocationUpdate(aster::AsterReal *const,aster::AsterReal *const,aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterInt  *const,const aster::AsterInt  *const,const aster::AsterReal *const,const aster::AsterInt  *const,const aster::AsterReal *const,aster::AsterReal *const,const aster::AsterInt  *const);

MFRONT_SHAREDOBJ void
astercrystalplasticitydislocationupdate(aster::AsterReal *const,aster::AsterReal *const,aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterReal *const,const aster::AsterInt  *const,const aster::AsterInt  *const,const aster::AsterReal *const,const aster::AsterInt  *const,const aster::AsterReal *const,aster::AsterReal *const,const aster::AsterInt  *const);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LIB_ASTER_CRYSTALPLASTICITYDISLOCATIONUPDATE_HXX */
