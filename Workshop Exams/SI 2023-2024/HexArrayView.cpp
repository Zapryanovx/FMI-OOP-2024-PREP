#include "HexArrayView.h"

HexArrayView::HexArrayView(const HexArray& arr)
{
	begin = arr.c_str();
	end = arr.c_str() + arr.getSize();
}

HexArrayView::HexArrayView(const unsigned char* begin, const unsigned char* end)
{
	this->begin = begin;
	this->end = end;
}

size_t HexArrayView::length() const
{
	return end - begin;
}

unsigned char HexArrayView::operator[](size_t index) const
{
	return begin[index];
}

HexArrayView HexArrayView::substr(size_t from, size_t length) const
{
	return HexArrayView(begin + from, begin + from + length);
}

std::ostream& operator<<(std::ostream& os, const HexArrayView& arrView)
{
	const unsigned char* iter = strView._begin;
        while (iter != strView._end)
        {
            os << std::hex << (int)*(iter++) << " ";
        }

        return os;
}
