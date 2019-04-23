#include <string>
#include <vector>

class RomanNumeral
{
public:
	RomanNumeral(int);
	~RomanNumeral();
private:
	int intRomanValue;
	// Converts users number and prints the Roman Numeral equivalent
	std::string intValtoRoman(int);

public:
	std::string toString();
};
