#pragma once
#include <vector>
#include "Image.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void Undo() = 0;
	virtual void Redo() = 0;
	virtual void Zooming(double fltScale) = 0;
};

class ImageProcessCommand : public Command
{
public:
	ImageProcessCommand(Image* pImgTarget) 
		: m_pImgTarget(pImgTarget), m_nCurOperation(0){}

	virtual void Undo()
	{
		if (m_nCurOperation == 0)	return;
		m_pImgTarget->Scale(1.0 / vecOperateState[m_nCurOperation - 1]);
		m_nCurOperation--;
	}

	virtual void Redo()
	{
		if (m_nCurOperation >= vecOperateState.size())	return;
		m_pImgTarget->Scale(vecOperateState[m_nCurOperation]);
		m_nCurOperation++;
	}

	virtual void Zooming(double fltScale)
	{
		m_pImgTarget->Scale(fltScale);
		vecOperateState.push_back(fltScale);
		m_nCurOperation++;
	}

private:
	Image* m_pImgTarget;
	std::vector<float> vecOperateState;
	int m_nCurOperation;
};

