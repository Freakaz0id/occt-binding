cmake_minimum_required(VERSION 3.16)

project(pybind_example)

set(EXTERNALS "${PROJECT_SOURCE_DIR}/externals")
set(MODULE_SOURCE "${PROJECT_SOURCE_DIR}/src")
add_subdirectory("${EXTERNALS}/pybind11")

#find_package(OpenCASCADE CONFIG REQUIRED)

pybind11_add_module("spark" "${MODULE_SOURCE}/module.cpp")

set(OCCT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/externals/occt/include/opencascade")
message("OCCT_INCLUDE_DIR: ${OCCT_INCLUDE_DIR}")

set(OCCT_LIB_DIR "${PROJECT_SOURCE_DIR}/externals/occt/lin64/gcc/lib")
message("OCCT_LIB_DIR: ${OCCT_LIB_DIR}")

target_include_directories(
    "spark" 
    PRIVATE ${OCCT_INCLUDE_DIR}
)

target_link_directories(
    "spark" 
    PRIVATE ${OCCT_LIB_DIR}
)

set(LIBS
    libTKMesh.so.7
    libTKOpenGl.so.7.5.0
    libTKBO.so.7.5.0
    libTKTObj.so.7
    libTKXmlL.so.7.5.0
    libTKV3d.so.7.5.0
    libTKStdL.so.7.5.0
    libTKBin.so.7.5.0
    libTKLCAF.so.7
    libTKBinL.so.7.5.0
    libTKService.so.7
    libTKCAF.so.7
    libTKSTEP.so.7.5.0
    libTKSTEPAttr.so
    libTKCAF.so.7.5.0
    libTKCDF.so.7.5.0
    libTKHLR.so.7.5.0
    libTKCAF.so
    libTKXMesh.so
    libTKBool.so
    libTKFillet.so
    libTKGeomAlgo.so.7
    libTKOffset.so.7.5.0
    libTKService.so.7.5.0
    libTKernel.so.7.5.0
    libTKV3d.so.7
    libTKBO.so.7
    libTKXmlL.so
    libTKBRep.so.7
    libTKVCAF.so.7.5.0
    libTKSTEPBase.so.7
    libTKMath.so.7
    libTKShHealing.so.7
    libTKPrim.so
    libTKG3d.so.7
    libTKFeat.so.7.5.0
    libTKBinTObj.so.7
    libTKSTEP209.so
    libTKGeomBase.so.7.5.0
    libTKVCAF.so
    libTKG2d.so
    libTKCDF.so.7
    libTKLCAF.so
    libTKXMesh.so.7.5.0
    libTKMath.so.7.5.0
    libTKMath.so
    libTKMesh.so.7.5.0
    libTKFillet.so.7
    libTKG2d.so.7.5.0
    libTKService.so
    libTKBin.so.7
    libTKBRep.so
    libTKGeomAlgo.so.7.5.0
    libTKG3d.so
    libTKBRep.so.7.5.0
    libTKHLR.so
    libTKSTEP.so
    libTKTopAlgo.so.7.5.0
    libTKLCAF.so.7.5.0
    libTKSTEP209.so.7.5.0
    libTKMeshVS.so
    libTKXml.so.7.5.0
    libTKPrim.so.7
    libTKBinL.so.7
    libTKTObj.so
    libTKStdL.so.7
    libTKGeomBase.so
    libTKStd.so.7
    libTKBO.so
    libTKTObj.so.7.5.0
    libTKV3d.so
    libTKFeat.so
    libTKernel.so
    libTKPrim.so.7.5.0
    libTKSTEPBase.so
    libTKOpenGl.so.7
    libTKTopAlgo.so
    libTKCDF.so
    libTKMeshVS.so.7.5.0
    libTKStd.so
    libTKStdL.so
    libTKBin.so
    libTKXmlL.so.7
    libTKBinL.so
    libTKGeomAlgo.so
    libTKMeshVS.so.7
    libTKFillet.so.7.5.0
    libTKSTEPAttr.so.7.5.0
    libTKSTEPBase.so.7.5.0
    libTKXml.so.7
    libTKOpenGl.so
    libTKStd.so.7.5.0
    libTKOffset.so
    libTKTopAlgo.so.7
    libTKXmlTObj.so
    libTKXmlTObj.so.7.5.0
    libTKVCAF.so.7
    libTKGeomBase.so.7
    libTKXSBase.so.7
    libTKXmlTObj.so.7
    libTKBinTObj.so.7.5.0
    libTKOffset.so.7
    libTKXSBase.so
    libTKHLR.so.7
    libTKMesh.so
    libTKG2d.so.7
    libTKXSBase.so.7.5.0
    libTKBool.so.7.5.0
    libTKShHealing.so.7.5.0
    libTKSTEP209.so.7
    libTKG3d.so.7.5.0
    libTKShHealing.so
    libTKXMesh.so.7
    libTKFeat.so.7
    libTKSTEP.so.7
    libTKBool.so.7
    libTKernel.so.7
    libTKXml.so
    libTKBinTObj.so
    libTKSTEPAttr.so.7
)

target_link_libraries(
    "spark"
    PRIVATE ${LIBS}
)