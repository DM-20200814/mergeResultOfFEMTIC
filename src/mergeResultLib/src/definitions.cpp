#include <mergeResultLib/mergeResult.h>

const double MU0     = 4.0 * M_PI * 1.0e-7;
const double RAD2DEG = 180.0 / M_PI;
const double DEG2RAD = M_PI / 180.0;
const double FACTOR  = 1.0;

const std::string m_componentIndex[6]   = {"xx", "xy", "yx", "yy", "zx", "zy"};
const std::string m_componentIndexPT[4] = {"11", "12", "21", "22"};
const std::string m_componentIndexXY[2] = {"x", "y"};

int         m_stationTypeCur(-1);
bool        m_readTrueErrorFile(false);
std::string m_trueErrorFileName;
bool        m_outputCSV(false);
bool        m_isImpedanceTensorConvertedToAppResAndPhase(false);
int         m_typeOfDistortion(NO_DISTORTION);

std::vector<std::pair<int, MTData>>                          m_MTDataListAll;
std::vector<std::pair<int, VTFData>>                         m_VTFDataListAll;
std::vector<std::pair<int, HTFData>>                         m_HTFDataListAll;
std::vector<std::pair<int, PTData>>                          m_PTDataListAll;
std::vector<std::pair<int, NMTData>>                         m_NMTDataListAll;
std::vector<std::pair<int, MTData>>                          m_NMT2DataListAll;
std::vector<std::pair<int, ApparentResistivityAndPhaseData>> m_AppResAndPhsDataListAll;
std::vector<std::pair<int, ApparentResistivityAndPhaseData>> m_NMT2AppResAndPhsDataListAll;
std::vector<std::pair<int, MTTrueError>>                     m_MTTrueErrorListAll;
std::vector<std::pair<int, VTFTrueError>>                    m_VTFTrueErrorListAll;
std::vector<std::pair<int, HTFTrueError>>                    m_HTFTrueErrorListAll;
std::vector<std::pair<int, PTTrueError>>                     m_PTTrueErrorListAll;
std::vector<std::pair<int, NMTTrueError>>                    m_NMTTrueErrorListAll;
std::vector<std::pair<int, MTTrueError>>                     m_NMT2TrueErrorListAll;
std::vector<std::pair<int, MTTrueError>>                     m_AppResAndPhsTrueErrorListAll;
std::vector<std::pair<int, MTTrueError>>                     m_NMT2AppResAndPhsTrueErrorListAll;
std::map<int, StationType>                                   m_SiteIDToSiteType;
std::map<int, DistortionMatrix>                              m_distortionMatrixList;
std::map<int, std::string>                                   m_SiteIDToSiteName;