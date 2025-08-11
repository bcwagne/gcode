/*
 * Program to automatically generate gcode to engrave labels
 *
 *
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


std::string writeGcodeString(char a, double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeA(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeB(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeC(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeD(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeE(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeF(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeG(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeH(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeI(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeJ(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeK(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeL(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeM(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeN(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeO(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeP(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeQ(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeR(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeS(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeT(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeU(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeV(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeW(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeX(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeY(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeZ(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeDash(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeZero(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeOne(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeTwo(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeThree(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeFour(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeFive(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeSix(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeSeven(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeEight(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);
std::string writeNine(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight);



int main(void)
{
    int labelCount = 1;
    std::string inputString = "";

    std::string outputFilename = "";
    std::string inputFilename = "";

    int xyFeedRate = 200;
    int zFeedRate = 200;
    int zSafeHeight = 15;
    double cutHeight = 1.0;

    int stringIndex = 0;
    int fileNumber = 0;
    int charCount = 0;
    double charSpacingX = 0.0;
    double charSpacingY = 12.7;
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
        std::cout << std::endl << "Failed to open input file.\n";
        return 0;
    }


    //keep going while there are characters still in the file
    while (getline(fin, inputString))
    {
        if (labelCount % 18 == 1)
        {

            //std::cout << "Starting new file\n";
            outputFilename = inputFilename + "_output" + std::__cxx11::to_string(fileNumber) + ".gcode";
            //std::cout << "Filename " << outputFilename << std::endl;
            fout.open(outputFilename);


            if(fout.fail())
            {
                std::cout << "Failed to open output file " << outputFilename << std::endl;
                return 0;
            }

            //write the gcode settings and headers, etc
            fout << "G21\nG90\nG0 Z" << zSafeHeight << "\nG0 X0Y0\n";

        }

        fout << "\n;" << inputString << std::endl << std::endl;
        //make sure we use the correct output file number so we don't overwrite files

        labelStartX = labelPosX[labelCount % 3];

        labelStartY = labelPosY[labelCount / 3 % 6];

        charCount = inputString.length();

        //figure out the character spacing
        charSpacingX = (50.8 / charCount);

        //loop through the string and write the gcode using appropriate spacing positions
        for (stringIndex = 0; stringIndex < charCount; stringIndex++)
        {
            charPosX = labelStartX + (charSpacingX * stringIndex);
            charPosY = labelStartY;

            fout << writeGcodeString(inputString[stringIndex], charPosX, charPosY, (charSpacingX * 0.75), charSpacingY, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
        }

        //next label
        labelCount++;

        //if we reach 18 labels in a file close it and increment the filenumber to be the next one
        if(labelCount % 18 == 1)
        {
            fout.close();
            fileNumber++;

        }
    }

    //close the input and output files
    fin.close();
    fout.close();

    return 0;
}











std::string writeA(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;

    //A
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95/4 << " Y" << ypos + ysize * 1/2 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/4 * 3 << " Y" << ypos + ysize * 1/2 << "\n"
    << "G0 Z" << zSafeHeight << "\n";

    return ss.str();
}
std::string writeB(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //B
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 1.0 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.60 << " Y" << ypos + ysize * 1.0 << "\n"
    << "G1 X" << xpos + xsize * 0.85 << " Y" << ypos + ysize * 0.95 << "\n"
    << "G1 X" << xpos + xsize * 0.90 << " Y" << ypos + ysize * 0.90 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.80 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.70 << "\n"
    << "G1 X" << xpos + xsize * 0.90 << " Y" << ypos + ysize * 0.60 << "\n"
    << "G1 X" << xpos + xsize * 0.85 << " Y" << ypos + ysize * 0.55 << "\n"
    << "G1 X" << xpos + xsize * 0.60 << " Y" << ypos + ysize * 0.50 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.50 << "\n"
    << "G1 X" << xpos + xsize * 0.60 << " Y" << ypos + ysize * 0.50 << "\n"
    << "G1 X" << xpos + xsize * 0.85 << " Y" << ypos + ysize * 0.45 << "\n"
    << "G1 X" << xpos + xsize * 0.90 << " Y" << ypos + ysize * 0.40 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.30 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.20 << "\n"
    << "G1 X" << xpos + xsize * 0.90 << " Y" << ypos + ysize * 0.10 << "\n"
    << "G1 X" << xpos + xsize * 0.85 << " Y" << ypos + ysize * 0.05 << "\n"
    << "G1 X" << xpos + xsize * 0.60 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeC(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //C
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.75 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.75 << " Y" << ypos + ysize * 0.95 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.50 << " Y" << ypos + ysize * 1.0 << "\n"
    << "G1 X" << xpos + xsize * 0.25 << " Y" << ypos + ysize * 0.95 << "\n"
    << "G1 X" << xpos + xsize * 0.05 << " Y" << ypos + ysize * 0.75 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.50 << "\n"
    << "G1 X" << xpos + xsize * 0.05 << " Y" << ypos + ysize * 0.25 << "\n"
    << "G1 X" << xpos + xsize * 0.25 << " Y" << ypos + ysize * 0.05 << "\n"
    << "G1 X" << xpos + xsize * 0.50 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G1 X" << xpos + xsize * 0.75 << " Y" << ypos + ysize * 0.05 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.25 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeD(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //D
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.00 << " Y" << ypos + ysize * 0.0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.0 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.5 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G1 X" << xpos + xsize * 0.66 << " Y" << ypos + ysize * 0.05 << "\n"
    << "G1 X" << xpos + xsize * 0.80 << " Y" << ypos + ysize * 0.15 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.40 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.60 << "\n"
    << "G1 X" << xpos + xsize * 0.80 << " Y" << ypos + ysize * 0.85 << "\n"
    << "G1 X" << xpos + xsize * 0.66 << " Y" << ypos + ysize * 0.95 << "\n"
    << "G1 X" << xpos + xsize * 0.5 << " Y" << ypos + ysize * 1.0 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 1.0 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeE(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //E
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1/2 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/3 * 2 << " Y" << ypos + ysize * 1/2<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeF(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //F
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1/2 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/3 * 2 << " Y" << ypos + ysize * 1/2<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeG(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //G
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.75 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.75 << " Y" << ypos + ysize * 0.95 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.50 << " Y" << ypos + ysize * 1.0 << "\n"
    << "G1 X" << xpos + xsize * 0.25 << " Y" << ypos + ysize * 0.95 << "\n"
    << "G1 X" << xpos + xsize * 0.05 << " Y" << ypos + ysize * 0.75 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.50 << "\n"
    << "G1 X" << xpos + xsize * 0.05 << " Y" << ypos + ysize * 0.25 << "\n"
    << "G1 X" << xpos + xsize * 0.25 << " Y" << ypos + ysize * 0.05 << "\n"
    << "G1 X" << xpos + xsize * 0.50 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G1 X" << xpos + xsize * 0.75 << " Y" << ypos + ysize * 0.05 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.25 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.40 << "\n"
    << "G1 X" << xpos + xsize * 0.50 << " Y" << ypos + ysize * 0.40 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeH(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //H
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1/2<< " F" << xyFeedRate << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1/2 << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeI(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //I
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize * 0 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeJ(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //J
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.4 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.285 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.069 << " Y" << ypos + ysize * 0.143 << "\n"
    << "G1 X" << xpos + xsize * 0.204 << " Y" << ypos + ysize * 0.0478 << "\n"
    << "G1 X" << xpos + xsize * 0.408 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G1 X" << xpos + xsize * 0.542 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G1 X" << xpos + xsize * 0.750 << " Y" << ypos + ysize * 0.0478 << "\n"
    << "G1 X" << xpos + xsize * 0.881 << " Y" << ypos + ysize * 0.143 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.285 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeK(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //K
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1/2<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeL(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //L
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeM(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //M
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeN(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //N
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeO(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //O
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.475 << " Y" << ypos + ysize * 0.00 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.712 << " Y" << ypos + ysize * 0.0675 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.885 << " Y" << ypos + ysize * 0.250 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.500 << "\n"
    << "G1 X" << xpos + xsize * 0.885 << " Y" << ypos + ysize * 0.750 << "\n"
    << "G1 X" << xpos + xsize * 0.712 << " Y" << ypos + ysize * 0.933 << "\n"
    << "G1 X" << xpos + xsize * 0.475 << " Y" << ypos + ysize * 1.00 << "\n"
    << "G1 X" << xpos + xsize * 0.235 << " Y" << ypos + ysize * 0.933 << "\n"
    << "G1 X" << xpos + xsize * 0.0641 << " Y" << ypos + ysize * 0.750 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.500 << "\n"
    << "G1 X" << xpos + xsize * 0.0641 << " Y" << ypos + ysize * 0.250 << "\n"
    << "G1 X" << xpos + xsize * 0.235 << " Y" << ypos + ysize * 0.0675 << "\n"
    << "G1 X" << xpos + xsize * 0.475 << " Y" << ypos + ysize * 0.00 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeP(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //P
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 1.0 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.60 << " Y" << ypos + ysize * 1.0 << "\n"
    << "G1 X" << xpos + xsize * 0.85 << " Y" << ypos + ysize * 0.95 << "\n"
    << "G1 X" << xpos + xsize * 0.90 << " Y" << ypos + ysize * 0.90 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.80 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.70 << "\n"
    << "G1 X" << xpos + xsize * 0.90 << " Y" << ypos + ysize * 0.60 << "\n"
    << "G1 X" << xpos + xsize * 0.85 << " Y" << ypos + ysize * 0.55 << "\n"
    << "G1 X" << xpos + xsize * 0.60 << " Y" << ypos + ysize * 0.50 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.50 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeQ(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //Q

    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.475 << " Y" << ypos + ysize * 0.00 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.712 << " Y" << ypos + ysize * 0.0675 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.885 << " Y" << ypos + ysize * 0.250 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.500 << "\n"
    << "G1 X" << xpos + xsize * 0.885 << " Y" << ypos + ysize * 0.750 << "\n"
    << "G1 X" << xpos + xsize * 0.712 << " Y" << ypos + ysize * 0.933 << "\n"
    << "G1 X" << xpos + xsize * 0.475 << " Y" << ypos + ysize * 1.00 << "\n"
    << "G1 X" << xpos + xsize * 0.235 << " Y" << ypos + ysize * 0.933 << "\n"
    << "G1 X" << xpos + xsize * 0.0641 << " Y" << ypos + ysize * 0.750 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.500 << "\n"
    << "G1 X" << xpos + xsize * 0.0641 << " Y" << ypos + ysize * 0.250 << "\n"
    << "G1 X" << xpos + xsize * 0.235 << " Y" << ypos + ysize * 0.0675 << "\n"
    << "G1 X" << xpos + xsize * 0.475 << " Y" << ypos + ysize * 0.00 << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.66 << " Y" << ypos + ysize * 0.25 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeR(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //R
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 1.0 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.60 << " Y" << ypos + ysize * 1.0 << "\n"
    << "G1 X" << xpos + xsize * 0.85 << " Y" << ypos + ysize * 0.95 << "\n"
    << "G1 X" << xpos + xsize * 0.90 << " Y" << ypos + ysize * 0.90 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.80 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.70 << "\n"
    << "G1 X" << xpos + xsize * 0.90 << " Y" << ypos + ysize * 0.60 << "\n"
    << "G1 X" << xpos + xsize * 0.85 << " Y" << ypos + ysize * 0.55 << "\n"
    << "G1 X" << xpos + xsize * 0.60 << " Y" << ypos + ysize * 0.50 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.50 << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.60 << " Y" << ypos + ysize * 0.50 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeS(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //S
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0.143 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.136 << " Y" << ypos + ysize * 0.048 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.338 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G1 X" << xpos + xsize * 0.610 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G1 X" << xpos + xsize * 0.814 << " Y" << ypos + ysize * 0.048 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.143 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.286 << "\n"
    << "G1 X" << xpos + xsize * 0.881 << " Y" << ypos + ysize * 0.381 << "\n"
    << "G1 X" << xpos + xsize * 0.814 << " Y" << ypos + ysize * 0.429 << "\n"
    << "G1 X" << xpos + xsize * 0.678 << " Y" << ypos + ysize * 0.476 << "\n"
    << "G1 X" << xpos + xsize * 0.272 << " Y" << ypos + ysize * 0.571 << "\n"
    << "G1 X" << xpos + xsize * 0.136 << " Y" << ypos + ysize * 0.619 << "\n"
    << "G1 X" << xpos + xsize * 0.0671 << " Y" << ypos + ysize * 0.666 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.761 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.856 << "\n"
    << "G1 X" << xpos + xsize * 0.136 << " Y" << ypos + ysize * 0.951 << "\n"
    << "G1 X" << xpos + xsize * 0.338 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.610 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.814 << " Y" << ypos + ysize * 0.951 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.856 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeT(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //T
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize * 1 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeU(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //U
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 1.0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.285 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.069 << " Y" << ypos + ysize * 0.143 << "\n"
    << "G1 X" << xpos + xsize * 0.204 << " Y" << ypos + ysize * 0.0478 << "\n"
    << "G1 X" << xpos + xsize * 0.408 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G1 X" << xpos + xsize * 0.542 << " Y" << ypos + ysize * 0.0 << "\n"
    << "G1 X" << xpos + xsize * 0.750 << " Y" << ypos + ysize * 0.0478 << "\n"
    << "G1 X" << xpos + xsize * 0.881 << " Y" << ypos + ysize * 0.143 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.285 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeV(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //V
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeW(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //W
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/4 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/4 * 3 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeX(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //X
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeY(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //Y
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize / 2<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize / 2 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeZ(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //Z
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeDash(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //-
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95/4 << " Y" << ypos + ysize / 2 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/4 * 3 << " Y" << ypos + ysize / 2<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeZero(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //0
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.475 << " Y" << ypos + ysize * 0.00 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.712 << " Y" << ypos + ysize * 0.0675 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.885 << " Y" << ypos + ysize * 0.250 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.500 << "\n"
    << "G1 X" << xpos + xsize * 0.885 << " Y" << ypos + ysize * 0.750 << "\n"
    << "G1 X" << xpos + xsize * 0.712 << " Y" << ypos + ysize * 0.933 << "\n"
    << "G1 X" << xpos + xsize * 0.475 << " Y" << ypos + ysize * 1.00 << "\n"
    << "G1 X" << xpos + xsize * 0.235 << " Y" << ypos + ysize * 0.933 << "\n"
    << "G1 X" << xpos + xsize * 0.0641 << " Y" << ypos + ysize * 0.750 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.500 << "\n"
    << "G1 X" << xpos + xsize * 0.0641 << " Y" << ypos + ysize * 0.250 << "\n"
    << "G1 X" << xpos + xsize * 0.235 << " Y" << ypos + ysize * 0.0675 << "\n"
    << "G1 X" << xpos + xsize * 0.475 << " Y" << ypos + ysize * 0.00 << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.95/4 << " Y" << ypos + ysize / 2 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/4 * 3 << " Y" << ypos + ysize / 2<< " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeOne(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //1
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0 << " F" << xyFeedRate << "\n"
    << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.50 << "\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize * 1.0 << "\n"
    << "G1 X" << xpos + xsize * 0.95/2 << " Y" << ypos + ysize * 0 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeTwo(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //2
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.067 << " Y" << ypos + ysize * 0.761 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.067 << " Y" << ypos + ysize * 0.809 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.136 << " Y" << ypos + ysize * 0.903 << "\n"
    << "G1 X" << xpos + xsize * 0.205 << " Y" << ypos + ysize * 0.951 << "\n"
    << "G1 X" << xpos + xsize * 0.338 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.610 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.747 << " Y" << ypos + ysize * 0.951 << "\n"
    << "G1 X" << xpos + xsize * 0.814 << " Y" << ypos + ysize * 0.903 << "\n"
    << "G1 X" << xpos + xsize * 0.881 << " Y" << ypos + ysize * 0.809 << "\n"
    << "G1 X" << xpos + xsize * 0.881 << " Y" << ypos + ysize * 0.713 << "\n"
    << "G1 X" << xpos + xsize * 0.814 << " Y" << ypos + ysize * 0.619 << "\n"
    << "G1 X" << xpos + xsize * 0.678 << " Y" << ypos + ysize * 0.476 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeThree(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //3
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.190 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.067 << " Y" << ypos + ysize * 0.095 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.136 << " Y" << ypos + ysize * 0.048 << "\n"
    << "G1 X" << xpos + xsize * 0.338 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G1 X" << xpos + xsize * 0.542 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G1 X" << xpos + xsize * 0.747 << " Y" << ypos + ysize * 0.048 << "\n"
    << "G1 X" << xpos + xsize * 0.881 << " Y" << ypos + ysize * 0.143 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.286 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.381 << "\n"
    << "G1 X" << xpos + xsize * 0.881 << " Y" << ypos + ysize * 0.523 << "\n"
    << "G1 X" << xpos + xsize * 0.814 << " Y" << ypos + ysize * 0.571 << "\n"
    << "G1 X" << xpos + xsize * 0.678 << " Y" << ypos + ysize * 0.619 << "\n"
    << "G1 X" << xpos + xsize * 0.476 << " Y" << ypos + ysize * 0.619 << "\n"
    << "G1 X" << xpos + xsize * 0.881 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.136 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeFour(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //4
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.75 << " Y" << ypos + ysize * 0.0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.75 << " Y" << ypos + ysize * 1.0 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.5 << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 0.5 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeFive(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //5
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.190 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.067 << " Y" << ypos + ysize * 0.095 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.136 << " Y" << ypos + ysize * 0.047 << "\n"
    << "G1 X" << xpos + xsize * 0.338 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G1 X" << xpos + xsize * 0.543 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G1 X" << xpos + xsize * 0.747 << " Y" << ypos + ysize * 0.047 << "\n"
    << "G1 X" << xpos + xsize * 0.881 << " Y" << ypos + ysize * 0.143 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.286 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.381 << "\n"
    << "G1 X" << xpos + xsize * 0.881 << " Y" << ypos + ysize * 0.523 << "\n"
    << "G1 X" << xpos + xsize * 0.747 << " Y" << ypos + ysize * 0.619 << "\n"
    << "G1 X" << xpos + xsize * 0.543 << " Y" << ypos + ysize * 0.666 << "\n"
    << "G1 X" << xpos + xsize * 0.338 << " Y" << ypos + ysize * 0.666 << "\n"
    << "G1 X" << xpos + xsize * 0.136 << " Y" << ypos + ysize * 0.619 << "\n"
    << "G1 X" << xpos + xsize * 0.067 << " Y" << ypos + ysize * 0.571 << "\n"
    << "G1 X" << xpos + xsize * 0.136 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.814 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeSix(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //6

    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.332 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"

    << "G1 X" << xpos + xsize * 0.074 << " Y" << ypos + ysize * 0.476 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.220 << " Y" << ypos + ysize * 0.571 << "\n"
    << "G1 X" << xpos + xsize * 0.440 << " Y" << ypos + ysize * 0.619 << "\n"
    << "G1 X" << xpos + xsize * 0.512 << " Y" << ypos + ysize * 0.619 << "\n"
    << "G1 X" << xpos + xsize * 0.732 << " Y" << ypos + ysize * 0.571 << "\n"
    << "G1 X" << xpos + xsize * 0.876 << " Y" << ypos + ysize * 0.476 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.332 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.286 << "\n"
    << "G1 X" << xpos + xsize * 0.876 << " Y" << ypos + ysize * 0.143 << "\n"
    << "G1 X" << xpos + xsize * 0.732 << " Y" << ypos + ysize * 0.047 << "\n"
    << "G1 X" << xpos + xsize * 0.512 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G1 X" << xpos + xsize * 0.440 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G1 X" << xpos + xsize * 0.220 << " Y" << ypos + ysize * 0.047 << "\n"
    << "G1 X" << xpos + xsize * 0.074 << " Y" << ypos + ysize * 0.143 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.332 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.571 << "\n"
    << "G1 X" << xpos + xsize * 0.074 << " Y" << ypos + ysize * 0.809 << "\n"
    << "G1 X" << xpos + xsize * 0.220 << " Y" << ypos + ysize * 0.951 << "\n"
    << "G1 X" << xpos + xsize * 0.440 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.584 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.804 << " Y" << ypos + ysize * 0.951 << "\n"
    << "G1 X" << xpos + xsize * 0.876 << " Y" << ypos + ysize * 0.856 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeSeven(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //7
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 1.0 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.95 << " Y" << ypos + ysize * 1.0 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0 << " Y" << ypos + ysize * 0 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeEight(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //8
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.338 << " Y" << ypos + ysize * 0.000 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.609 << " Y" << ypos + ysize * 0.000 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.814 << " Y" << ypos + ysize * 0.047 << "\n"
    << "G1 X" << xpos + xsize * 0.880 << " Y" << ypos + ysize * 0.095 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.190 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.332 << "\n"
    << "G1 X" << xpos + xsize * 0.880 << " Y" << ypos + ysize * 0.429 << "\n"
    << "G1 X" << xpos + xsize * 0.747 << " Y" << ypos + ysize * 0.522 << "\n"
    << "G1 X" << xpos + xsize * 0.542 << " Y" << ypos + ysize * 0.570 << "\n"
    << "G1 X" << xpos + xsize * 0.271 << " Y" << ypos + ysize * 0.619 << "\n"
    << "G1 X" << xpos + xsize * 0.135 << " Y" << ypos + ysize * 0.666 << "\n"
    << "G1 X" << xpos + xsize * 0.067 << " Y" << ypos + ysize * 0.761 << "\n"
    << "G1 X" << xpos + xsize * 0.067 << " Y" << ypos + ysize * 0.856 << "\n"
    << "G1 X" << xpos + xsize * 0.135 << " Y" << ypos + ysize * 0.951 << "\n"
    << "G1 X" << xpos + xsize * 0.338 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.609 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.814 << " Y" << ypos + ysize * 0.951 << "\n"
    << "G1 X" << xpos + xsize * 0.880 << " Y" << ypos + ysize * 0.856 << "\n"
    << "G1 X" << xpos + xsize * 0.880 << " Y" << ypos + ysize * 0.761 << "\n"
    << "G1 X" << xpos + xsize * 0.814 << " Y" << ypos + ysize * 0.666 << "\n"
    << "G1 X" << xpos + xsize * 0.678 << " Y" << ypos + ysize * 0.619 << "\n"
    << "G1 X" << xpos + xsize * 0.407 << " Y" << ypos + ysize * 0.570 << "\n"
    << "G1 X" << xpos + xsize * 0.204 << " Y" << ypos + ysize * 0.522 << "\n"
    << "G1 X" << xpos + xsize * 0.067 << " Y" << ypos + ysize * 0.429 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.332 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.190 << "\n"
    << "G1 X" << xpos + xsize * 0.067 << " Y" << ypos + ysize * 0.095 << "\n"
    << "G1 X" << xpos + xsize * 0.135 << " Y" << ypos + ysize * 0.047 << "\n"
    << "G1 X" << xpos + xsize * 0.338 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeNine(double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    std::stringstream ss;
    //9
    ss << "G0 Z" << zSafeHeight << "\n"
    << "G0 X" << xpos + xsize * 0.072 << " Y" << ypos + ysize * 0.142 << "\n"
    << "M3 S10000\n"
    << "G1 Z" << cutHeight << " F" << zFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.146 << " Y" << ypos + ysize * 0.047 << " F" << xyFeedRate << "\n"
    << "G1 X" << xpos + xsize * 0.364 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G1 X" << xpos + xsize * 0.513 << " Y" << ypos + ysize * 0.000 << "\n"
    << "G1 X" << xpos + xsize * 0.731 << " Y" << ypos + ysize * 0.047 << "\n"
    << "G1 X" << xpos + xsize * 0.877 << " Y" << ypos + ysize * 0.190 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.429 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.666 << "\n"
    << "G1 X" << xpos + xsize * 0.877 << " Y" << ypos + ysize * 0.856 << "\n"
    << "G1 X" << xpos + xsize * 0.731 << " Y" << ypos + ysize * 0.951 << "\n"
    << "G1 X" << xpos + xsize * 0.513 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.439 << " Y" << ypos + ysize * 1.000 << "\n"
    << "G1 X" << xpos + xsize * 0.220 << " Y" << ypos + ysize * 0.951 << "\n"
    << "G1 X" << xpos + xsize * 0.072 << " Y" << ypos + ysize * 0.856 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.712 << "\n"
    << "G1 X" << xpos + xsize * 0.000 << " Y" << ypos + ysize * 0.666 << "\n"
    << "G1 X" << xpos + xsize * 0.072 << " Y" << ypos + ysize * 0.522 << "\n"
    << "G1 X" << xpos + xsize * 0.220 << " Y" << ypos + ysize * 0.429 << "\n"
    << "G1 X" << xpos + xsize * 0.439 << " Y" << ypos + ysize * 0.380 << "\n"
    << "G1 X" << xpos + xsize * 0.513 << " Y" << ypos + ysize * 0.380 << "\n"
    << "G1 X" << xpos + xsize * 0.731 << " Y" << ypos + ysize * 0.429 << "\n"
    << "G1 X" << xpos + xsize * 0.877 << " Y" << ypos + ysize * 0.522 << "\n"
    << "G1 X" << xpos + xsize * 0.950 << " Y" << ypos + ysize * 0.666 << "\n"
    << "G0 Z" << zSafeHeight << "\n";
    return ss.str();
}
std::string writeGcodeString(char a, double xpos, double ypos, double xsize, double ysize, int xyFeedRate, int zFeedRate, int zSafeHeight, double cutHeight)
{
    switch (a)
    {
        case 'A':
        {
            return writeA(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'B':
        {
            return writeB(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'C':
        {
            return writeC(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'D':
        {
            return writeD(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'E':
        {
            return writeE(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'F':
        {
            return writeF(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'G':
        {
            return writeG(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'H':
        {
            return writeH(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'I':
        {
            return writeI(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'J':
        {
            return writeJ(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'K':
        {
            return writeK(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'L':
        {
            return writeL(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'M':
        {
            return writeM(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'N':
        {
            return writeN(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'O':
        {
            return writeO(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'P':
        {
            return writeP(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'Q':
        {
            return writeQ(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'R':
        {
            return writeR(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'S':
        {
            return writeS(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'T':
        {
            return writeT(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'U':
        {
            return writeU(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'V':
        {
            return writeV(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'W':
        {
            return writeW(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'X':
        {
            return writeX(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'Y':
        {
            return writeY(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case 'Z':
        {
            return writeZ(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case '-':
        {
            return writeDash(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case '0':
        {
            return writeZero(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case '1':
        {
            return writeOne(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case '2':
        {
            return writeTwo(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case '3':
        {
            return writeThree(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case '4':
        {
            return writeFour(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case '5':
        {
            return writeFive(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case '6':
        {
            return writeSix(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case '7':
        {
            return writeSeven(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case '8':
        {
            return writeEight(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        case '9':
        {
            return writeNine(xpos, ypos, xsize, ysize, xyFeedRate, zFeedRate, zSafeHeight, cutHeight);
            break;
        }
        default:
        {
            std::stringstream ss;
            return ss.str();
            break;
        }
    }
}
