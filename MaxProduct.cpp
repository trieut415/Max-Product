#include "MaxProduct.h"

long MaxProductClass::MaxProduct(string inputfile) {
    ifstream inputFile(inputfile);
    if (!inputFile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 0; // Handle the error accordingly
    }

    vector<vector<int> > vectorOfVectors;
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        int number;
        vector<int> numbers;

        while (iss >> number) {
            if (number != -999999) {
                numbers.push_back(number);
            }
        }

        vectorOfVectors.push_back(numbers);
    }

    inputFile.close();

    vector<int> maxNumAll;

    for (int i = 0; i < vectorOfVectors.size(); i++) {
        int maxForRow = 0;
        const vector<int>& vectorOfVectorsRow = vectorOfVectors[i];
        int rowSize = vectorOfVectorsRow.size();

        if (rowSize == 1) {
            maxForRow = vectorOfVectorsRow[0];
        } else {
            int maxProduct = 0;
            for (int j = 0; j < rowSize; j++) {
                int product = 1;
                for (int k = j; k < min(j + 3, rowSize); k++) {
                    product *= vectorOfVectorsRow[k];
                    maxProduct = max(maxProduct, product);
                }
            }
            maxForRow = maxProduct;
        }

        maxNumAll.push_back(maxForRow);

        cout << maxForRow << endl; // Display the max number for each row
    }

    int biggestNum = *max_element(maxNumAll.begin(), maxNumAll.end());

    return biggestNum;
}
