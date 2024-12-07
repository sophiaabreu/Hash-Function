#include <iostream> // For input and output operations
#include <string>   // For handling the string class
#include <sstream>  // For converting numbers to string streams
#include <iomanip>  // For formatting hexadecimal output

// Define a class to encapsulate hashing functionality
class CustomHasher {
private:
    int multiplier; // Private member variable to store the multiplier used in the hash calculation

public:
    // Constructor to initialize the multiplier with a default value
    // This ensures we always have a meaningful starting value
    CustomHasher(int initMultiplier = 37) : multiplier(initMultiplier) {}

    // Method to compute a hash for a given string
    std::string computeHash(const std::string &input) {
        unsigned long hashResult = 0; // Variable to store the calculated hash value, initialized to zero

        // Iterate over each character in the input string
        for (char character : input) {
            // Update the hash value using the ASCII value of the character and the multiplier
            // Multiplication increases the weight of each character in the hash
            // Modulus ensures the hash stays within a specific range, avoiding overflow
            hashResult = (hashResult + (multiplier * static_cast<int>(character))) % 0xFFFFFFF;
        }

        // Convert the numeric hash value into a hexadecimal string representation
        // Create a stringstream to handle the conversion
        std::stringstream hexStream;
        hexStream << std::hex            // Convert the number to a hexadecimal format
                  << std::setw(7)        // Ensure the output is at least 7 characters wide
                  << std::setfill('0')   // Fill any empty space with zeros for uniform length
                  << hashResult;         // Add the final hash value to the stream

        return hexStream.str(); // Return the formatted hexadecimal string
    }
};

int main() {
    // Create an instance of the hasher class
    // This will use the default multiplier value of 37
    CustomHasher myHasher;

    // Declare a variable to hold the user's input string
    std::string inputText;

    // Prompt the user to enter a string to hash
    // This message is displayed in the console
    std::cout << "Enter text to generate a hash: ";
    std::getline(std::cin, inputText); // Read the entire input line, including spaces

    // Call the computeHash method of the CustomHasher class to generate the hash
    std::string hashOutput = myHasher.computeHash(inputText);

    // Display the original input text to the user
    std::cout << "Input Text: " << inputText << std::endl;

    // Display the generated hash value to the user
    std::cout << "Hashed Output: " << hashOutput << std::endl;

    return 0; // Indicate successful program termination
}
