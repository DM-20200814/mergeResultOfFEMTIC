#include <mergeResultLib/mergeResult.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "You must specify iteration number and process number !!" << std::endl;
        exit(1);
    }
    readResult(atoi(argv[1]), atoi(argv[2]));
    for (int i = 3; i < argc; ++i) {
        // strcmp : compare two strings char by char following the distionary order
        // return 0 if they are same
        // return > 0 if the first string is larger than the second one
        // return < 0 if the first string is smaller than the second one
        if (strcmp(argv[i], "-name") == 0) {
            // read relation between site name and site ID
            readRelationSiteIDBetweenSiteName(argv[i + 1]);
        } else if (strcmp(argv[i], "-err") == 0) {
            m_trueErrorFileName = argv[i + 1];
            m_readTrueErrorFile = true;
        } else if (strcmp(argv[i], "-csv") == 0) {
            m_outputCSV = true;
        } else if (strcmp(argv[i], "-undist") == 0) {
            readControlData("control.dat");
            readDistortionMatrix(atoi(argv[1]));
        } else if (strcmp(argv[i], "-appphs") == 0) {
            std::cout << "Impedance tensors are converted to apparent resistivity and phase."
                      << std::endl;
            m_isImpedanceTensorConvertedToAppResAndPhase = true;
        }
    }
    calcTrueRMS(m_readTrueErrorFile, m_trueErrorFileName);
    writeResult();
    return 0;
}