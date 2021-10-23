#ifndef UTILITY_HPP_
#define UTILITY_HPP_

namespace utility
{
	// Taken from https://stackoverflow.com/a/54336178
	static std::string AddSeparators(std::string aValue, char aThousandSep = '.')
	{
		int len = aValue.length();

		int value = ((len) && (aValue[0] == '-')) ? 2 : 1;
		int size = 3;

		while ((len - value) > size)
		{	
			aValue.insert(len - size, 1, aThousandSep);

			size += 4;
			len += 1;
		}

		return aValue;
	}

} // !namespace utility

#endif // !UTILITY_HPP_
