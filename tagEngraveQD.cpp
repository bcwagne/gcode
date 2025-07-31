/*
 * Program to automatically generate gcode to engrave labels
 *
 *
 * */


/*
#define LABEL00X 25.357
#define LABEL00Y 7.371
#define LABEL01X 104.486
#define LABEL01Y 7.371
#define LABEL02X 183.578
#define LABEL02Y 7.371
#define LABEL03X 25.357
#define LABEL03Y 33.829
#define LABEL04X 104.486
#define LABEL04Y 33.829
#define LABEL05X 183.578
#define LABEL05Y 33.829
#define LABEL06X 25.357
#define LABEL06Y 60.288
#define LABEL07X 104.486
#define LABEL07Y 60.288
#define LABEL08X 183.578
#define LABEL08Y 60.288
#define LABEL09X 25.357
#define LABEL09Y 86.747
#define LABEL10X 104.486
#define LABEL10Y 86.747
#define LABEL11X 183.578
#define LABEL11Y 86.747
#define LABEL12X 25.357
#define LABEL12Y 113.206
#define LABEL13X 104.486
#define LABEL13Y 113.206
#define LABEL14X 183.578
#define LABEL14Y 113.206
#define LABEL15X 25.357
#define LABEL15Y 139.664
#define LABEL16X 104.486
#define LABEL16Y 139.664
#define LABEL17X 183.578
#define LABEL17Y 139.664

#define LABELSIZEX 50.8
#define LABELSIZEY 12.7

#define CHARY 12.7

#define 12CHARSPACE 4.233
#define 11CHARSPACE 4.618
#define 10CHARSPACE 5.080
#define 9CHARSPACE 5.644
#define 8CHARSPACE 6.350
#define 7CHARSPACE 7.257
#define 6CHARSPACE 8.466
#define 5CHARSPACE 10.160

#define 12CHAR 4.021
#define 11CHAR 4.387
#define 10CHAR 4.826
#define 9CHAR 5.362
#define 8CHAR 6.033
#define 7CHAR 6.894
#define 6CHAR 8.043
#define 5CHAR 9.652

#define 12CHARMULT 1.000
#define 11CHARMULT 1.090
#define 10CHARMULT 1.200
#define 9CHARMULT 1.333
#define 8CHARMULT 1.500
#define 7CHARMULT 1.714
#define 6CHARMULT 2.000
#define 5CHARMULT 2.400

*/



#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
    bool newFile = true;
    int labelCount = 1;
    std::string inputString = "";

    std::string outputFilename = "";
    std::string inputFilename = "";

    int stringIndex = 0;
    char readChar;
    int fileNumber = 1;
    int charCount = 0;
    double charSpacing = 0.0;
    double charPosX = 0.0;
    double charPosY = 0.0;
    double labelStartX = 0.0;
    double labelStartY = 0.0;

    const double labelPosX[] = {25.357, 104.486, 183.578};
    const double labelPosY[] = {7.371, 33.829, 60.288, 86.747, 113.206, 139.664};


    //open an input file
    std::cout << "Enter input file name: ";
    std::cin >> inputFilename;
    std::ifstream fin(inputFilename);
    std::ofstream fout;

    //if failed to open then quit with an error
    if (fin.fail())
    {
        std::cout << std::endl << "Failed to open file.\n";
        return -1;
    }


    //keep going while there are characters still in the file
    while (getline(fin, inputString))
    {
        if (labelCount % 18 == 1)
        {

            std::cout << "Starting new file\n";
            outputFilename = inputFilename + "_output" + std::__cxx11::to_string(fileNumber) + ".gcode";
            std::cout << "Filename " << outputFilename << std::endl;
            fout.open(outputFilename);


            if(fout.fail())
            {
                std::cout << "failed to open output file " << outputFilename << std::endl;
            }

        }

        //make sure we use the correct output file number so we don't overwrite files

        labelStartX = labelPosX[labelCount % 3];
        labelStartY = labelPosY[labelCount % 6];

        charCount = inputString.length();

        //figure out the character spacing
        charSpacing = 50.8 / charCount;

        //loop through the string and write the gcode using appropriate spacing positions
        for (stringIndex = 0; stringIndex < charCount; stringIndex++)
        {
            charPosX = labelStartX + (charSpacing * stringIndex);
            charPosY = labelStartY;
            //std::cout << "gcode for char " << inputString[stringIndex] << std::endl;
            //fout << "Gcode for char " << inputString[stringIndex] << std::endl;
            //write gcode to file (inputString[stringIndex], charPosX, charPosY);
            writeGcodeChar(inputString[stringIndex], charPosX, charPosY);
        }

        //next label
        labelCount++;

        //if we reach 18 labels in a file close it and increment the filenumber to be the next one
        if(labelCount % 18 == 1)
        {
            fileNumber++;
            fout.close();
        }
    }

    //close the input file
    fin.close();
    fout.close();

    return 0;
}
