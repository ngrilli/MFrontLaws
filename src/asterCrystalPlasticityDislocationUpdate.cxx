/*!
* \file   src/asterCrystalPlasticityDislocationUpdate.cxx
* \brief  This file implements the aster interface for the CrystalPlasticityDislocationUpdate behaviour law
* \author Nicolò Grilli
* \date   17 / 08 / 2023
*/

#include<iostream>
#include<stdexcept>
#include"TFEL/Material/OutOfBoundsPolicy.hxx"
#include"TFEL/Material/CrystalPlasticityDislocationUpdate.hxx"
#include"MFront/Aster/AsterStressFreeExpansionHandler.hxx"

#include"MFront/Aster/AsterInterface.hxx"

#include"MFront/Aster/asterCrystalPlasticityDislocationUpdate.hxx"

static tfel::material::OutOfBoundsPolicy&
astercrystalplasticitydislocationupdate_getOutOfBoundsPolicy(){
using namespace tfel::material;
static OutOfBoundsPolicy policy = None;
return policy;
}

extern "C"{

MFRONT_SHAREDOBJ const char* 
astercrystalplasticitydislocationupdate_build_id = "";

MFRONT_SHAREDOBJ const char* 
astercrystalplasticitydislocationupdate_mfront_ept = "astercrystalplasticitydislocationupdate";

MFRONT_SHAREDOBJ const char* 
astercrystalplasticitydislocationupdate_tfel_version = "3.4.0";

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_mfront_mkt = 1u;

MFRONT_SHAREDOBJ const char *
astercrystalplasticitydislocationupdate_mfront_interface = "Aster";

MFRONT_SHAREDOBJ const char *
astercrystalplasticitydislocationupdate_src = "CrystalPlasticityDislocationUpdate.mfront";

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_nModellingHypotheses = 1u;

MFRONT_SHAREDOBJ const char * 
astercrystalplasticitydislocationupdate_ModellingHypotheses[1u] = {"Tridimensional"};

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_nMainVariables = 1;
MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_nGradients = 1;

MFRONT_SHAREDOBJ int astercrystalplasticitydislocationupdate_GradientsTypes[1] = {3};
MFRONT_SHAREDOBJ const char * astercrystalplasticitydislocationupdate_Gradients[1] = {"DeformationGradient"};
MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_nThermodynamicForces = 1;

MFRONT_SHAREDOBJ int astercrystalplasticitydislocationupdate_ThermodynamicForcesTypes[1] = {1};
MFRONT_SHAREDOBJ const char * astercrystalplasticitydislocationupdate_ThermodynamicForces[1] = {"Stress"};
MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_nTangentOperatorBlocks = 0;

MFRONT_SHAREDOBJ const char * const * astercrystalplasticitydislocationupdate_TangentOperatorBlocks = nullptr;

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_BehaviourType = 2u;

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_BehaviourKinematic = 3u;

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_SymmetryType = 1u;

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_ElasticSymmetryType = 1u;

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_savesTangentOperator = 0;
MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_FiniteStrainFormulation = 1u;
MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_Tridimensional_UsableInPurelyImplicitResolution = 1;

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_Tridimensional_nMaterialProperties = 0u;

MFRONT_SHAREDOBJ const char * const *astercrystalplasticitydislocationupdate_Tridimensional_MaterialProperties = nullptr;

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_Tridimensional_nInternalStateVariables = 37;
MFRONT_SHAREDOBJ const char * astercrystalplasticitydislocationupdate_Tridimensional_InternalStateVariables[37] = {"PlasticSlip[0]",
"PlasticSlip[1]","PlasticSlip[2]","PlasticSlip[3]","PlasticSlip[4]","PlasticSlip[5]",
"PlasticSlip[6]","PlasticSlip[7]","PlasticSlip[8]","PlasticSlip[9]","PlasticSlip[10]",
"PlasticSlip[11]","ElasticPartOfTheDeformationGradient","EquivalentViscoplasticSlip[0]","EquivalentViscoplasticSlip[1]","EquivalentViscoplasticSlip[2]",
"EquivalentViscoplasticSlip[3]","EquivalentViscoplasticSlip[4]","EquivalentViscoplasticSlip[5]","EquivalentViscoplasticSlip[6]","EquivalentViscoplasticSlip[7]",
"EquivalentViscoplasticSlip[8]","EquivalentViscoplasticSlip[9]","EquivalentViscoplasticSlip[10]","EquivalentViscoplasticSlip[11]","delta_rho_ssd[0]",
"delta_rho_ssd[1]","delta_rho_ssd[2]","delta_rho_ssd[3]","delta_rho_ssd[4]","delta_rho_ssd[5]",
"delta_rho_ssd[6]","delta_rho_ssd[7]","delta_rho_ssd[8]","delta_rho_ssd[9]","delta_rho_ssd[10]",
"delta_rho_ssd[11]"};
MFRONT_SHAREDOBJ int astercrystalplasticitydislocationupdate_Tridimensional_InternalStateVariablesTypes [] = {0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_Tridimensional_nExternalStateVariables = 0;
MFRONT_SHAREDOBJ const char * const * astercrystalplasticitydislocationupdate_Tridimensional_ExternalStateVariables = nullptr;

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_Tridimensional_nParameters = 29;
MFRONT_SHAREDOBJ const char * astercrystalplasticitydislocationupdate_Tridimensional_Parameters[29] = {"epsilon",
"theta","YoungModulus1","YoungModulus2","YoungModulus3","PoissonRatio12",
"PoissonRatio23","PoissonRatio13","ShearModulus12","ShearModulus23","ShearModulus13",
"ao","xm","creep_ao","creep_xm","burgers_vector_mag",
"shear_modulus","alpha_0","r","tau_c_0","k_0",
"y_c","h","h_D","init_rho_ssd","minimal_time_step_scaling_factor",
"maximal_time_step_scaling_factor","numerical_jacobian_epsilon","iterMax"};
MFRONT_SHAREDOBJ int astercrystalplasticitydislocationupdate_Tridimensional_ParametersTypes [] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2};

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_epsilon_ParameterDefaultValue = 1e-14;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_theta_ParameterDefaultValue = 1;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_YoungModulus1_ParameterDefaultValue = 93812.45;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_YoungModulus2_ParameterDefaultValue = 93812.45;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_YoungModulus3_ParameterDefaultValue = 93812.45;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_PoissonRatio12_ParameterDefaultValue = 0.40228;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_PoissonRatio23_ParameterDefaultValue = 0.40228;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_PoissonRatio13_ParameterDefaultValue = 0.40228;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_ShearModulus12_ParameterDefaultValue = 126200;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_ShearModulus23_ParameterDefaultValue = 126200;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_ShearModulus13_ParameterDefaultValue = 126200;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_ao_ParameterDefaultValue = 0.001;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_xm_ParameterDefaultValue = 0.1;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_creep_ao_ParameterDefaultValue = 0;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_creep_xm_ParameterDefaultValue = 0.1;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_burgers_vector_mag_ParameterDefaultValue = 0.000256;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_shear_modulus_ParameterDefaultValue = 126200;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_alpha_0_ParameterDefaultValue = 0.3;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_r_ParameterDefaultValue = 1.4;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_tau_c_0_ParameterDefaultValue = 0.112;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_k_0_ParameterDefaultValue = 1.13;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_y_c_ParameterDefaultValue = 0.0013;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_h_ParameterDefaultValue = 0;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_h_D_ParameterDefaultValue = 0;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_init_rho_ssd_ParameterDefaultValue = 4.921;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_minimal_time_step_scaling_factor_ParameterDefaultValue = 0.1;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_maximal_time_step_scaling_factor_ParameterDefaultValue = 1.7976931348623e+308;

MFRONT_SHAREDOBJ double astercrystalplasticitydislocationupdate_Tridimensional_numerical_jacobian_epsilon_ParameterDefaultValue = 1e-15;

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_Tridimensional_iterMax_ParameterDefaultValue  = 100;

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_Tridimensional_requiresStiffnessTensor = 0;
MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_Tridimensional_requiresThermalExpansionCoefficientTensor = 0;
MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_Tridimensional_ComputesInternalEnergy = 0;

MFRONT_SHAREDOBJ unsigned short astercrystalplasticitydislocationupdate_Tridimensional_ComputesDissipatedEnergy = 0;

MFRONT_SHAREDOBJ int
astercrystalplasticitydislocationupdate_Tridimensional_setParameter(const char *const key,const double value){
using tfel::material::CrystalPlasticityDislocationUpdateTridimensionalParametersInitializer;
auto& i = CrystalPlasticityDislocationUpdateTridimensionalParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ int
astercrystalplasticitydislocationupdate_Tridimensional_setUnsignedShortParameter(const char *const key,const unsigned short value){
using tfel::material::CrystalPlasticityDislocationUpdateTridimensionalParametersInitializer;
auto& i = CrystalPlasticityDislocationUpdateTridimensionalParametersInitializer::get();
try{
i.set(key,value);
} catch(std::runtime_error& e){
std::cerr << e.what() << std::endl;
return 0;
}
return 1;
}

MFRONT_SHAREDOBJ void
astercrystalplasticitydislocationupdate_setOutOfBoundsPolicy(const int p){
if(p==0){
astercrystalplasticitydislocationupdate_getOutOfBoundsPolicy() = tfel::material::None;
} else if(p==1){
astercrystalplasticitydislocationupdate_getOutOfBoundsPolicy() = tfel::material::Warning;
} else if(p==2){
astercrystalplasticitydislocationupdate_getOutOfBoundsPolicy() = tfel::material::Strict;
} else {
std::cerr << "astercrystalplasticitydislocationupdate_setOutOfBoundsPolicy: invalid argument\n";
}
}

char *astercrystalplasticitydislocationupdate_getIntegrationErrorMessage(){
#if (defined __GNUC__) && (!defined __clang__) && (!defined __INTEL_COMPILER) && (!defined __PGI)
#if __GNUC__ * 10000+__GNUC_MINOR__ * 100 <  40800
static __thread char msg[128];
#else
static thread_local char msg[128];
#endif
#else /* (defined __GNUC__) ...*/
static thread_local char msg[128];
#endif /* (defined __GNUC__) ...*/
return msg;
} // end of astercrystalplasticitydislocationupdate_getIntegrationErrorMessage

MFRONT_SHAREDOBJ void
CrystalPlasticityDislocationUpdate(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const F0,const aster::AsterReal *const F1,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
char * msg = astercrystalplasticitydislocationupdate_getIntegrationErrorMessage();
if(aster::AsterInterface<tfel::material::CrystalPlasticityDislocationUpdate>::exe(msg,NTENS,DTIME,DROT,DDSOE,F0,F1,TEMP,DTEMP,PROPS,NPROPS,PREDEF,DPRED,STATEV,NSTATV,STRESS,NUMMOD,astercrystalplasticitydislocationupdate_getOutOfBoundsPolicy(),nullptr)!=0){
*PNEWDT = -1.;
return;
}
}

MFRONT_SHAREDOBJ void
astercrystalplasticitydislocationupdate(aster::AsterReal *const STRESS,aster::AsterReal *const STATEV,aster::AsterReal *const DDSOE,const aster::AsterReal *const F0,const aster::AsterReal *const F1,const aster::AsterReal *const DTIME,const aster::AsterReal *const TEMP,const aster::AsterReal *const DTEMP,const aster::AsterReal *const PREDEF,const aster::AsterReal *const DPRED,const aster::AsterInt  *const NTENS,const aster::AsterInt  *const NSTATV,const aster::AsterReal *const PROPS,const aster::AsterInt  *const NPROPS,const aster::AsterReal *const DROT,aster::AsterReal *const PNEWDT,const aster::AsterInt *const NUMMOD)
{
CrystalPlasticityDislocationUpdate(STRESS,STATEV,DDSOE,F0,F1,DTIME,TEMP,DTEMP,
PREDEF,DPRED,NTENS,NSTATV,PROPS,NPROPS,DROT,PNEWDT,NUMMOD);
}

} // end of extern "C"
