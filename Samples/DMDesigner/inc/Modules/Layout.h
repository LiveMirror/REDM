// ----------------------------------------------------------------
// Copyright (c)  
// All rights reserved.
// 
// File name:	Layout.h
// File mark:   
// File summary:������DMLayoutImpl
// Author:		guoyouhuang
// Edition:     1.0
// Create date: 2016-7-8
// ----------------------------------------------------------------
#pragma once
namespace DMAttr
{
	/// <summary>
	///		<see cref="DM::Layout"/>��xml���Զ���
	/// </summary>
	class PosLayoutAttr
	{
	public:
		/// -------------------------------------------------
		///  @brief ָ��λ��,��õ�Ϊָ���ĸ�����,ʾ����
		///  @remark ʾ��1:pos="10,11,101,102",�ĸ���ֱ��������:10,��:11,��:101,��:102
		///  @remark ʾ��2:pos="10,11,-12,-13",�ĸ���ֱ��������:10,��:11,��:�������ұ�����12,��:�������±�����13--->'-'�����崰�ڵļ������෴����ϵ
		///  @remark ʾ��3:pos="10,11,@100,@101",�ĸ���ֱ��������:10,��:11,��:100,��:101--->'@'�����崰�ڵ�size��ֻ�ں�����ֵ����Ч
		///  @remark ʾ��4:pos="10,11,|-1,|2",�ĸ���ֱ��������:10,��:11,��:���������ĵ�����1(-1),�£����������ĵ�����2-->'|':�ο�����������
		///  @remark ʾ��5:pos="[10,[11,@100,@101",�ĸ���ֱ��������:��ǰһ���ֵܴ����Լ����ı�����(10)����:��ǰһ���ֵܴ����Լ����ı�����(10)����:100,��:101--->'['�ο�ǰһ���ֵܴ������Լ����ıߣ�û���ֵܴ��ھͲο������ڵĿ��ò��ֿռ䣩
		///  @remark ʾ��6:pos="0,1,]-10,@100",�ĸ���ֱ��������:0����:1����:����һ���ֵܴ�������10(-10),��:100--->']'�ο���һ���ֵܴ������Լ����ıߣ�û���ֵܴ��ھͲο������ڵĿ��ò��ֿռ䣩
		///  @remark -->'{'�ο���һ���ֵܴ������Լ����ıߣ���ʾ��5���ͣ�-->'}'�ο���һ���ֵܴ������Լ�Զ�ı�,��ʾ��6����
		///  @remark ʾ��7:pos="%10,%20,%30,%40",�ĸ���ֱ��������:�����ڲ��ֿռ��%10���ϣ������ڲ��ֿռ��%20���ң������ڲ��ֿռ��%30���£������ڲ��ֿռ��%40--->'%'�����ڸ����ڵİٷֱȶ�������
		static wchar_t* POS_pos;	

		/// -------------------------------------------------
		///  @brief ָ��λ��,��pos����С����ʱ�����posʹ��,ʾ��:
		///  @remark ʾ��1:pos="%10,%11" possize="100,101",pos��¼�����Ͻ�����,��possize��¼�˿�100����101
		///  @remark ʾ��2:pos="%10,%20" possize="-1,-1"��pos��Ϊ��,ͬʱpossize��СΪ-1��-1,��-1)��ʾ�������ݲ��֣�ʹ��DV_GetDesiredSize��possizeǰһֵΪ���򣬺�һֵΪ��ֱ
		///  @remark ʾ��3:pos="%10,%20" possize="-1,100"��pos��Ϊ��,ͬʱpossize��СΪ-1��100,��-1)��ʾ�������ݲ���,�߶�100,ʹ��DV_GetDesiredSize��possizeǰһֵΪ���򣬺�һֵΪ��ֱ
		///  @remark ʾ��4:pos="" possize="-1,-1",posΪ��,possize��СΪ-1��-1������������
		///  @remark ʾ��4:pos="" possize="x,x",posΪ��,x��ȫΪ-1��-1��ʹ���Զ�����,ǰ-1��ʾ�������򸸴��ڣ���-1��ʾ�������򸸴���
		static wchar_t* SIZE_possize;                                                        
	};
	DMAttrValueInit(PosLayoutAttr,POS_pos)DMAttrValueInit(PosLayoutAttr,SIZE_possize)
}

namespace DM
{
#define POSFLAG_NULL           L""			 // ��������,���ű�ʾ����(��)Ϊ�ο�
#define POSFLAG_REFCENTER      L'|'          // �ο�����������
#define POSFLAG_PERCENT        L'%'          // �����ڸ����ڵİٷֱȶ�������
#define POSFLAG_REFPREV_NEAR   L'['          // �ο�ǰһ���ֵܴ������Լ����ı�
#define POSFLAG_REFNEXT_NEAR   L']'          // �ο���һ���ֵܴ������Լ����ı�
#define POSFLAG_REFPREV_FAR    L'{'          // �ο�ǰһ���ֵܴ������Լ�Զ�ı�
#define POSFLAG_REFNEXT_FAR    L'}'          // �ο���һ���ֵܴ������Լ�Զ�ı�
#define POSFLAG_DEFSIZE        L'@'          // ��pos�����ж��崰�ڵ�size��ֻ���ڶ���x2,y2ʱ��Ч

	enum POS_TYPE// ��������
	{
		SizeX_Mask          = 0x0007UL,
		SizeX_Specify       = 0x0001UL,		// width >= 0,ǿ��ָ���˴�С
		SizeX_FitContent    = 0x0002UL,		// ������ָ��
		SizeX_FitParent     = 0x0004UL,		// width = -1 default
		SizeY_Mask          = 0x0070UL,
		SizeY_Specify       = 0x0010UL,		// height >= 0
		SizeY_FitContent    = 0x0020UL,		// ������ָ��
		SizeY_FitParent     = 0x0040UL,		// height = -1 default
	};

	enum PIT// ��������
	{
		PIT_NORMAL = 0,						// һ������
		PIT_CENTER,							// �ο����������ĵ�,��"|"��ʼ
		PIT_PERCENT,						// ָ���ڸ�����������еİٷֱ�,��"%"��ͷ
		PIT_PREV_NEAR,						// �ο�ǰһ���ֵܴ������Լ����ı�
		PIT_NEXT_NEAR,						// �ο���һ���ֵܴ������Լ����ı�
		PIT_PREV_FAR,						// �ο�ǰһ���ֵܴ������Լ�Զ�ı�
		PIT_NEXT_FAR,						// �ο���һ���ֵܴ������Լ�Զ�ı�
		PIT_OFFSET,							// �����ǰ��x1,y1��ƫ��,ֻ����x2,y2��ʹ�ã���@��ͷ
	};

	typedef struct stPOS_ITEM
	{
		stPOS_ITEM(){pit=(PIT)-1;bMinus=false;nPos=0.0;}
		PIT		pit;						// ��������
		bool	bMinus;						// true��ʾ����һ����ֵ
		float   nPos;
	}POS_ITEM;

	/// <summary>
	///		ê�㲼������ʵ�֣����ԣ�<see cref="DMAttr::PosLayoutAttr"/>
	/// </summary>
	class Layout:public IDMLayout
	{
		DMDECLARE_CLASS_NAME(Layout,L"Layout",DMREG_Layout);
	public:
		Layout();

	public:
		DMCode SetOwner(LPVOID lpWnd);
		DMCode UpdateLayout(OUT LPRECT prcContainer,OUT CRect &rcWindow);
		DMCode UpdateChildLayout();

	public:// ����
		bool ParsePostion();
		bool ParsePostionType();
		bool ParseItem(CStringW &strPos, POS_ITEM &item);
		bool ParseChildPosition(DM::CList<DUIWindow*> *pList);
		int ParseItemValue(const POS_ITEM &item,int nMin, int nMax,bool bX);//����POS_WAIT��ʾ����������ǰ��󴰿�δ��ɲ��֣�bX��ʾ������
		bool Update4(LPRECT lpRcContainer,OUT CRect &rcWindow);
		bool Update2(LPRECT lpRcContainer,OUT CRect &rcWindow);
		bool UpdateFull(LPRECT lpRcContainer,OUT CRect &rcWindow);
		bool UpdateAuto(LPRECT lpRcContainer,OUT CRect &rcWindow);
		CSize CalcSize(LPRECT pRcContainer);//  ���㴰�ڴ�С

		// ���������
		CStringW GetPit(PIT pit);
		CStringW GetItem(POS_ITEM* pItem);
		CStringW GetPosString();// ����4��pos����string,��ʧ��,���ؿ�
		bool ParseItemByRect(CRect& rect,POS_ITEM& PosLeft,POS_ITEM& PosTop,POS_ITEM& PosRight,POS_ITEM& PosBtm);
		bool ParseItemPos(POS_ITEM &item,int nMin, int nMax,bool bX,int nRet);

	public:
		DM_BEGIN_ATTRIBUTES()
			DM_CUSTOM_ATTRIBUTE(DMAttr::PosLayoutAttr::POS_pos, OnAttributePos)
			DM_CUSTOM_ATTRIBUTE(DMAttr::PosLayoutAttr::SIZE_possize, OnAttributePosSize)
		DM_END_ATTRIBUTES()
	public:
		DMCode OnAttributePos(LPCWSTR pszValue, bool bLoadXml);
		DMCode OnAttributePosSize(LPCWSTR pszValue, bool bLoadXml);
	public:
		CStringW				 m_strPosValue;			

		DUIWindow*				 m_pOwner;			   // layout������ 
		int					     m_nCount;			   // ������������

		POS_ITEM m_Left;POS_ITEM m_Top;POS_ITEM m_Right;POS_ITEM m_Bottom;

		UINT					m_uPositionType;      //  ��������
		CSize                   m_size;			      // SizeX_Mask,SizeY_Mask		
		int						m_nSepSpace;          //  �����Զ��Ű����ֱ���
	};
}//namespace DM