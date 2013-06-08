// Shen Longbin
// File Version: 0.0.1 (2013/06/06)

#ifndef OBJBOX3_H
#define OBJBOX3_H

#include "Wm5Box3.h"
#include <string>
#include "ObjInfo.h"

namespace Wm5
{
	template <typename Real>
	class ObjBox3
	{
	public:
		// A object box has object name, box3, grasp direction, and grasp width.

		// Construction and destruction.
		ObjBox3 ();  // uninitialized
		~ObjBox3 ();
		ObjBox3 (const ObjInfo<Real>& obj_info);
		ObjBox3 (const std::string& obj_name, const Box3<Real>& box3, const Vector3<Real>& gsp_dir,
			const Real gsp_width);
		ObjBox3 (const ObjBox3& obj_box3);
		ObjBox3& operator= (const ObjBox3& obj_box3);
		
		std::string m_obj_name;
		Box3<Real> m_box3;
		Vector3<Real> m_gsp_dir;
		Real m_gsp_width;
	};

#include "ObjBox3.inl"

	typedef ObjBox3<float> ObjBox3f;
	typedef ObjBox3<double> ObjBox3d;

}

#endif
