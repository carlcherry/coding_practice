/*
 * ccutilities.cpp
 *
 *  Created on: 2013-01-22
 *      Author: carl
 */
#include <iostream>
#include <vector>

namespace cc
{

void printArray(std::string message, int *inputArray, int start, int end)
{
    if (message.length() > 0)
        std::cout << message << std::endl;
    for (int index = start; index <= end; index++)
    {
        std::cout << inputArray[index] << " ";
    }
    std::cout << std::endl;
}

static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z', '0', '1', '2', '3',
        '4', '5', '6', '7', '8', '9', '+', '/'};

std::string base64_encode(const unsigned char* input, int length)
{
    std::vector<char>  result;
    int i = 0;
    for (i = 0; i < (length - 2); i = i + 3)
    {
        // We know we have 3 bytes to work with in this loop
        // Break the 3 bytes into 4 6-bit values
        int index = (input[i] & 0xFC) >> 2;
        result.push_back(encoding_table[index]);
        index = ((input[i] & 0x03) << 4) + ((input[i+1] & 0xF0) >> 4);
        result.push_back(encoding_table[index]);
        index = ((input[i+1] & 0x0F) << 2) + ((input[i+2] & 0xC0) >> 6);
        result.push_back(encoding_table[index]);
        index = input[i+2] & 0x3F;
        result.push_back(encoding_table[index]);
    }

    // Now deal with the last 1 or 2 characters
    int remaining = length - i;
    if (remaining > 0)
    {
        // Set up the buffer for the last 3 bytes
        char buffer[3] = { 0, 0, 0 };
        buffer[0] = input[i];
        if (remaining == 2)
        {
            buffer[1] = input[i+1];
        }

        // Convert the last 3 bytes
        // 1. Always take the first 12 bits
        int index = (buffer[0] & 0xFC) >> 2;
        result.push_back(encoding_table[index]);
        index = ((buffer[0] & 0x03) << 4) + ((buffer[1] & 0xF0) >> 4);
        result.push_back(encoding_table[index]);

        // If there were 2 bytes remaining then add in the next 6 bits and pad with a single '='
        if (remaining == 2) {
            index = ((buffer[1] & 0x0F) << 2) + ((buffer[2] & 0xC0) >> 6);
            result.push_back(encoding_table[index]);
            result.push_back('=');
        }
        else {
            // There was only a single character left over so pad with '=='
            result.push_back('=');
            result.push_back('=');
        }
    }
    return std::string(result.begin(), result.end());
}

void test_base64()
{
    const char * input = "any carnal pleasur";
    std::string result = base64_encode((const unsigned char*)input, strlen(input));
    if (result != "YW55IGNhcm5hbCBwbGVhc3Vy")
    {
        std::cout << "base64_encode failed for \"" << input << "\"" << std::endl;
    }

    const char *input2 = "any carnal pleasure.";
    result = base64_encode((const unsigned char*)input2, strlen(input2));
    if (result != "YW55IGNhcm5hbCBwbGVhc3VyZS4=")
    {
        std::cout << "base64_encode failed for \"" << input2 << "\" , result: " << result << std::endl;
    }

    const char *input3 = "any carnal pleasure";
    result = base64_encode((const unsigned char*)input3, strlen(input3));
    if (result != "YW55IGNhcm5hbCBwbGVhc3VyZQ==")
    {
        std::cout << "base64_encode failed for \"" << input3 << "\" , result: " << result << std::endl;
    }
}

} // end namespace cc




