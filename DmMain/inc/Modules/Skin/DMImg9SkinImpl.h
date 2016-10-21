//-------------------------------------------------------
// Copyright (c) DuiMagic
// All rights reserved.
// 
// File Name: DMImg9SkinImpl.h 
// File Des: 
// File Summary: 
// Cur Version: 1.0
// Author:
// Create Data:
// History:
// 		<Author>	<Time>		<Version>	  <Des>
//      guoyou		2015-1-28	1.0			
//-------------------------------------------------------
#pragma once
#include "DMImgListSkinImpl.h"

namespace DMAttr
{
	/// <summary>
	///		<see cref="DM::DMImg9SkinImpl"/>��xml���Զ���
	/// </summary>
	class DMImg9SkinImplAttr:public DMImgListSkinImplAttr
	{
	public:
		static wchar_t* RECT_margin;                            ///< scrollΪ9�������,ָ�����Ƶ��ı߿�,margin="1,1,1,1"
	};
	DMAttrValueInit(DMImg9SkinImplAttr,RECT_margin);
}

namespace DM
{
	/// <summary>
	///		9������ͼ����ʵ�֣����ԣ�<see cref="DMAttr::DMImg9SkinImplAttr"/>
	/// </summary>
	class DMImg9SkinImpl:public DMImgListSkinImpl
	{
		DMDECLARE_CLASS_NAME(DMImg9SkinImpl,L"img9",DMREG_Skin);
	public:
		DMCode Draw(IDMCanvas *pCanvas, LPCRECT lpRectDraw, int iState,BYTE alpha=0xFF); 
		DMCode SendExpandInfo(WPARAM wp, LPARAM lp);

	public:
		DM_BEGIN_ATTRIBUTES()
			DM_RECT_ATTRIBUTE(DMAttr::DMImg9SkinImplAttr::RECT_margin ,m_rcMargin,DM_ECODE_OK)
		DM_END_ATTRIBUTES()
	protected:
		CRect								m_rcMargin;
	};

}//namespace DM