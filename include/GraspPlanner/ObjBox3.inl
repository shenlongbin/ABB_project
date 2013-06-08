// Geometric Tools, LLC
// Shen Longbin
// File Version: 0.0.1 (2013/06/06)

//----------------------------------------------------------------------------
template <typename Real>
ObjBox3<Real>::ObjBox3 ()
{
}
//----------------------------------------------------------------------------
template <typename Real>
ObjBox3<Real>::~ObjBox3 ()
{
}
//----------------------------------------------------------------------------
template <typename Real>
ObjBox3<Real>::ObjBox3 (const ObjInfo<Real>& obj_info)
	:
	m_obj_name(obj_info.ObjName),
	m_gsp_width(obj_info.Gsp_width)
{
	Vector3<Real> center(obj_info.center[0], obj_info.center[1], obj_info.center[2]);
	Vector3<Real> gsp_dir(obj_info.Gsp_direction[0], obj_info.Gsp_direction[1], obj_info.Gsp_direction[2]);
	Vector3<Real> point0(obj_info.CornerPoints[0], obj_info.CornerPoints[0+8], obj_info.CornerPoints[0+16]);
	Vector3<Real> point1(obj_info.CornerPoints[1], obj_info.CornerPoints[1+8], obj_info.CornerPoints[1+16]);
	Vector3<Real> point3(obj_info.CornerPoints[3], obj_info.CornerPoints[3+8], obj_info.CornerPoints[3+16]);
	Vector3<Real> point4(obj_info.CornerPoints[4], obj_info.CornerPoints[4+8], obj_info.CornerPoints[4+16]);
	Vector3<Real> axis0 = point1 - point0;
	Real extent0 = axis0.Length()/Real(2.0);
	axis0.Normalize( Real(1.0) );
	Vector3<Real> axis1 = point3 - point0;
	Real extent1 = axis1.Length()/Real(2.0);
	axis1.Normalize( Real(1.0) );
	Vector3<Real> axis2 = point4 - point0;
	Real extent2 = axis2.Length()/Real(2.0);
	axis2.Normalize( Real(1.0) );
	m_gsp_dir = gsp_dir;
	m_box3 = Box3<Real>(center, axis0, axis1, axis2, extent0, extent1, extent2);
}

//----------------------------------------------------------------------------
template <typename Real>
ObjBox3<Real>::ObjBox3 (const std::string& obj_name, const Box3<Real>& box3, const Vector3<Real>& gsp_dir,
						const Real gsp_width)
    :
    m_obj_name(obj_name),
	m_box3(box3),
	m_gsp_dir(gsp_dir),
	m_gsp_width(gsp_width)
{
    
}

//----------------------------------------------------------------------------
template <typename Real>
ObjBox3<Real>::ObjBox3 (const ObjBox3& obj_box3)
{
	m_obj_name = obj_box3.m_obj_name;
	m_box3 = obj_box3.m_box3;
	m_gsp_dir = obj_box3.m_gsp_dir;
	m_gsp_width = obj_box3.m_gsp_width;	
}
//----------------------------------------------------------------------------
template <typename Real>
ObjBox3<Real>& ObjBox3<Real>::operator= (const ObjBox3& obj_box3)
{
	m_obj_name = obj_box3.m_obj_name;
	m_box3 = obj_box3.m_box3;
	m_gsp_dir = obj_box3.m_gsp_dir;
	m_gsp_width = obj_box3.m_gsp_width;
	return *this;
}
