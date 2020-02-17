#pragma once
#include <iostream>

class Image
{
public:
	Image(int nWidth, int nHeight) :m_nWidth(nWidth), m_nHeight(nHeight) {}

	void Scale(double fltScale){
		if (0 < fltScale) {
			m_nHeight = (int)(m_nHeight * fltScale);
			m_nWidth = (int)(m_nWidth * fltScale);
		}
	}

	void Show()
	{
		std::cout << "Image info: " << m_nWidth << " * " << m_nHeight << std::endl;
	}

private:
	int m_nWidth;
	int m_nHeight;
};

