#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

constexpr const char kEncodeTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void createDecodingTable(vector<char> &decodingtable)
{
    for (int i = 0; i < 64; ++i)
    {
        decodingtable[kEncodeTable[i]] = i;
    }
}

std::string base64Encode(const std::string &input)
{
    std::string encodedString = "";
    uint32_t inp_length = input.length();
    uint32_t index = 0;
    //2.
    while (index < inp_length)
    {
        uint32_t j = index;
        vector<uint32_t> sequenceOf3Chars(3);
        while (j < index + 3 and j < inp_length)
        {
            sequenceOf3Chars[j % 3] = input[j];
            j++;
        }
        uint32_t bitsToShift = 16;
        uint32_t sequenceOfBits = 0;
        for (int k = 0; k < 3; ++k)
        {
            sequenceOfBits = sequenceOfBits + (sequenceOf3Chars[k] << bitsToShift);
            bitsToShift -= 8;
        }
        bitsToShift = 18;
        for (int k = 0; k < 4; ++k)
        {
            cout << kEncodeTable[(sequenceOfBits >> bitsToShift) & 63] << " ";
            encodedString += kEncodeTable[(sequenceOfBits >> bitsToShift) & 63];
            bitsToShift -= 6;
        }
        index += 3;
    }
    int noOfEquals = (inp_length % 3 == 0) ? 0 : 3 - (inp_length % 3);
    for (int k = 1; k <= noOfEquals; ++k)
    {
        encodedString[encodedString.size() - k] = '=';
    }
    return encodedString;
}
/** 
 * @brief Calculate base64 decoded string for an input string
 * @details 1. Create a decoding table that is of size 255 where each character represented by it's ASCII value is mapped to corresponding code in Base 64 encoding e.g. 
 *             decodingTable[65] = 0, which represent A decodingTable[90] = 25 which represent Z
 *          2. Since each set of 3 letters correspond to 4 letters in Base64 i.e. each 6 bits correspond to 8 bits, and with padding the input should be a multiple of 4.
 *          3. In loop, I am trying to take 4 characters at a time, putting the Base64 value of each character in to a container
 *          4. bitsToShift initialize to 18 as I need to shift left  in multiple of 6 bits each time to get 24 bits for the 4 characters in my container
 *             i.e. Most significant character by 6*3 digits, and Least significant character by 6*0 digits
 *          5. Now, bisToShift initialized to 16, as we need to get 3 characters out of the 24 bits, thus 8 bits per character and the variable will be decremented by 8
 *             i.e. Most Significant character will be obtained by right shift by 16 digits and performing and with 255 that represent (00000000000000000000000011111111) 
 *          6. We will keep putting the character corresponding to the value we obtained in step 5 and return the string.
 **/
std::string base64Decode(const std::string &input)
{
    std::string decodedString;
    string invalid = "Invalid string";
    vector<char> decodingTable(256);
    //1.
    createDecodingTable(decodingTable);

    uint32_t inp_length = input.length();
    uint32_t index = 0;
    //2.
    while (index < inp_length)
    {
        uint32_t j = index;
        vector<uint32_t> sequenceOf4Chars;
        //3.
        while (j < index + 4)
        {
            if (input[j] != '=')
            {
                if (not isalnum(input[j]) and input[j] != '+' and input[j] != '/')
                {
                    return invalid;
                }
                sequenceOf4Chars.push_back(decodingTable[input[j++]]);
            }
            else
            {
                j++;
                sequenceOf4Chars.push_back(0);
            }
        }
        //4.
        uint32_t sequenceOf3Chars = 0;
        uint32_t bitsToShift = 18;
        for (int k = 0; k < 4; ++k)
        {

            sequenceOf3Chars += (sequenceOf4Chars[k] << bitsToShift);
            bitsToShift -= 6;
        }
        //5.
        bitsToShift = 16;
        for (int k = 0; k < 3; ++k)
        {
            decodedString += ((sequenceOf3Chars >> bitsToShift) & 255);
            bitsToShift -= 8;
        }
        index += 4;
    }
    //6.
    return decodedString;
}

int main()
{
    std::string mystr = base64Decode("SGVsbG8gV29ybGQ=");
    cout << mystr << endl;
    cout << mystr.size();
    cout << base64Encode("Hello World");
}