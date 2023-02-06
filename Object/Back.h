#pragma once
#include "../Util/common.h"

class Back
{
public:
	Back();
	virtual ~Back();

	void init();		// ‰Šú‰»
	void end();			// I—¹
	void draw();		// •`‰æ

private:
	// ”wŒi”z—ñ‚ÌƒTƒCƒYæ“¾
	int m_back[kVariable::BackHeight][kVariable::BackWidth];
	// ”wŒiƒnƒ“ƒhƒ‹
	int m_handle;
	// Ø‚èæ‚é¶ã‚Ì’¸“_
	int m_verX;			// ‰¡
	int m_verY;			// c
};

