//--------------------------------------------------------------------------
// MIT License
//
// Copyright (c) 2021 Yoshiya Usui
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//--------------------------------------------------------------------------
#pragma once
#ifndef DBLDEF_MERGE_RESULT
#define DBLDEF_MERGE_RESULT
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>

enum StationType {
    MT = 0,
    VTF,
    PT,
    HTF,
    NMT,
    NMT2,
    APP_RES_AND_PHS,
    NMT2_APP_RES_AND_PHS,
    ADDITINAL_OUTPUT_POINT
};

enum ImpedanceTensorComponentIndex {
    XX = 0,
    XY,
    YX,
    YY,
};

struct ImpedanceTensor {
    std::complex<double> Z[4];
};

struct VerticalMagneticTransferFunction {
    std::complex<double> TZ[2];
};

struct HorizontalMagneticTransferFunction {
    std::complex<double> T[4];
};

struct PhaseTensor {
    double Phi[4];
};

struct NMTResponseFunction  // NMT: Non-orthogonal Magnetic Transfer function
                            // ？？？？？？？
{
    std::complex<double> Y[2];
};

struct ApparentResistivityAndPhase {
    double apparentResistivity[4];
    double phase[4];
};

struct DistortionMatrix {
    double C[4];
};

struct MTData {
    double          freq;
    ImpedanceTensor Cal;
    ImpedanceTensor Res;
    ImpedanceTensor Obs;
    ImpedanceTensor Err;
};

struct VTFData  // VTF: Vertical Magnetic Transfer function
{
    double                           freq;
    VerticalMagneticTransferFunction Cal;
    VerticalMagneticTransferFunction Res;
    VerticalMagneticTransferFunction Obs;
    VerticalMagneticTransferFunction Err;
};

struct HTFData  // HTF: Horizontal Magnetic Transfer function
{
    double                             freq;
    HorizontalMagneticTransferFunction Cal;
    HorizontalMagneticTransferFunction Res;
    HorizontalMagneticTransferFunction Obs;
    HorizontalMagneticTransferFunction Err;
};

struct PTData  // PT: Phase Tensor
{
    double      freq;
    PhaseTensor Cal;
    PhaseTensor Res;
    PhaseTensor Obs;
    PhaseTensor Err;
};

struct NMTData  // NMT: Non-orthogonal Magnetic Transfer function ？？？？？？？
{
    double              freq;
    NMTResponseFunction Cal;
    NMTResponseFunction Res;
    NMTResponseFunction Obs;
    NMTResponseFunction Err;
};

struct ApparentResistivityAndPhaseData {
    double                      freq;
    ApparentResistivityAndPhase Cal;
    ApparentResistivityAndPhase Res;
    ApparentResistivityAndPhase Obs;
    ApparentResistivityAndPhase Err;
};

struct MTTrueError  // MT: Magnetotelluric
{
    double                    freq;
    std::pair<double, double> error[4];
};

struct VTFTrueError {
    double                    freq;
    std::pair<double, double> error[2];
};

struct HTFTrueError {
    double                    freq;
    std::pair<double, double> error[4];
};

struct PTTrueError {
    double freq;
    double error[4];
};

struct NMTTrueError  //
{
    double                    freq;
    std::pair<double, double> error[2];
};

struct NumDataAndSumResidual {
    int    numData;
    double sumResidual;
};

// Type of galvanic distortion
enum TypeOfDistortion {
    NO_DISTORTION = 0,
    ESTIMATE_DISTORTION_MATRIX_DIFFERENCE,
    ESTIMATE_GAINS_AND_ROTATIONS,
    ESTIMATE_GAINS_ONLY,
};

extern const double                         MU0;
extern const double                         RAD2DEG;
extern const double                         DEG2RAD;
extern const double                         FACTOR;
extern const std::string                    m_componentIndex[6];
extern const std::string                    m_componentIndexPT[4];
extern const std::string                    m_componentIndexXY[2];
extern int                                  m_stationTypeCur;
extern bool                                 m_readTrueErrorFile;
extern std::string                          m_trueErrorFileName;
extern bool                                 m_outputCSV;
extern bool                                 m_isImpedanceTensorConvertedToAppResAndPhase;
extern int                                  m_typeOfDistortion;
extern std::vector<std::pair<int, MTData>>  m_MTDataListAll;
extern std::vector<std::pair<int, VTFData>> m_VTFDataListAll;
extern std::vector<std::pair<int, HTFData>> m_HTFDataListAll;
extern std::vector<std::pair<int, PTData>>  m_PTDataListAll;
extern std::vector<std::pair<int, NMTData>> m_NMTDataListAll;
extern std::vector<std::pair<int, MTData>>  m_NMT2DataListAll;
extern std::vector<std::pair<int, ApparentResistivityAndPhaseData>> m_AppResAndPhsDataListAll;
extern std::vector<std::pair<int, ApparentResistivityAndPhaseData>> m_NMT2AppResAndPhsDataListAll;
extern std::vector<std::pair<int, MTTrueError>>                     m_MTTrueErrorListAll;
extern std::vector<std::pair<int, VTFTrueError>>                    m_VTFTrueErrorListAll;
extern std::vector<std::pair<int, HTFTrueError>>                    m_HTFTrueErrorListAll;
extern std::vector<std::pair<int, PTTrueError>>                     m_PTTrueErrorListAll;
extern std::vector<std::pair<int, NMTTrueError>>                    m_NMTTrueErrorListAll;
extern std::vector<std::pair<int, MTTrueError>>                     m_NMT2TrueErrorListAll;
extern std::vector<std::pair<int, MTTrueError>>                     m_AppResAndPhsTrueErrorListAll;
extern std::vector<std::pair<int, MTTrueError>> m_NMT2AppResAndPhsTrueErrorListAll;
extern std::map<int, StationType>               m_SiteIDToSiteType;
extern std::map<int, DistortionMatrix>          m_distortionMatrixList;
extern std::map<int, std::string>               m_SiteIDToSiteName;

void        readResult(const int iterationNumber, const int numPE);
void        readControlData(const std::string &fileName);
void        readTrueError(const std::string &trueErrorFileName);
void        readDistortionMatrix(const int iterationNumber);
void        readRelationSiteIDBetweenSiteName(const std::string &relationFile);
void        calcTrueRMS(const bool doesReadTrueErrorFile, const std::string &trueErrorFileName);
std::string convertSiteIDToSiteName(const int siteID);
void        writeResult();
void        writeResultMT();
void        writeResultVTF();
void        writeResultHTF();
void        writeResultPT();
void        writeResultNMT();
void        writeResultNMT2();
void        writeResultAppResAndPhs();
void        writeResultNMT2AppResAndPhs();

bool pairCompareMTData(const std::pair<int, MTData> &left, const std::pair<int, MTData> &right);
bool pairCompareVTFData(const std::pair<int, VTFData> &left, const std::pair<int, VTFData> &right);
bool pairCompareHTFData(const std::pair<int, HTFData> &left, const std::pair<int, HTFData> &right);
bool pairComparePTData(const std::pair<int, PTData> &left, const std::pair<int, PTData> &right);
bool pairCompareNMTData(const std::pair<int, NMTData> &left, const std::pair<int, NMTData> &right);
bool pairCompareAppResAndPhsData(const std::pair<int, ApparentResistivityAndPhaseData> &left,
                                 const std::pair<int, ApparentResistivityAndPhaseData> &right);
void calcUndistortedImpedanceTensor(const int siteID, const ImpedanceTensor &Z,
                                    ImpedanceTensor &ZWithoutDistortion);
void calcUndistortedApparentResistiivtyAndPhase(
    const int siteID, const double freq, const ApparentResistivityAndPhase &appResAndPhs,
    ApparentResistivityAndPhase &appResAndPhsWithoutDistortion);

int                                                      getSiteTypeFromSiteID(const int siteID);
void                                                     addNumDataAndSumResidual(const int                             siteID,
                                                                                  std::map<int, NumDataAndSumResidual> &numDataAndSumResidual,
                                                                                  const double                          residual);
std::vector<std::pair<int, MTTrueError>>::const_iterator getIteratorToMTTrueError(
    const int siteID, const double freq);
std::vector<std::pair<int, VTFTrueError>>::const_iterator getIteratorToVTFTrueError(
    const int siteID, const double freq);
std::vector<std::pair<int, HTFTrueError>>::const_iterator getIteratorToHTFTrueError(
    const int siteID, const double freq);
std::vector<std::pair<int, PTTrueError>>::const_iterator getIteratorToPTTrueError(
    const int siteID, const double freq);
std::vector<std::pair<int, NMTTrueError>>::const_iterator getIteratorToNMTTrueError(
    const int siteID, const double freq);
std::vector<std::pair<int, MTTrueError>>::const_iterator getIteratorToNMT2TrueError(
    const int siteID, const double freq);
std::vector<std::pair<int, MTTrueError>>::const_iterator getIteratorToAppResAndPhsTrueError(
    const int siteID, const double freq);
std::vector<std::pair<int, MTTrueError>>::const_iterator getIteratorToNMT2AppResAndPhsTrueError(
    const int siteID, const double freq);

void isSameError(const int siteID, const double freq, const int index, const double errReal,
                 const double errImag);
void writeToOfstream(std::ofstream &ofs, const int width, const std::string &str, const bool isCSV);
void writeToOfstream(std::ofstream &ofs, const int width, const int value, const bool isCSV);
void writeToOfstream(std::ofstream &ofs, const int width, const double value, const bool isCSV);

#endif  // READRESULT_H