// Shen Longbin
// File Version: 0.0.1 (2013/06/06)
//----------------------------------------------------------------------------
#ifndef OBJINFO_H
#define OBJINFO_H

#include <string>
// 所有的数据单位是： 毫米 （mm）
template <typename Real>
struct ObjInfo 
{
	std::string ObjName;   
	Real center[3];              //x y z
	Real Gsp_direction[3];   // x,y z
	Real Gsp_width;
	Real CornerPoints[24];
};

typedef ObjInfo<float>	ObjInfof;
typedef ObjInfo<double>	ObjInfod;

#endif