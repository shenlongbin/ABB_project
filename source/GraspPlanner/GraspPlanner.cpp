// Shen Longbin
// File Version: 0.0.1 (2013/06/06)
//----------------------------------------------------------------------------
#include "GraspPlanner.h"
//----------------------------------------------------------------------------
template <typename Real>
CGraspPlanner<Real>::CGraspPlanner()
{
}
//----------------------------------------------------------------------------
template <typename Real>
CGraspPlanner<Real>::~CGraspPlanner()
{
}
//----------------------------------------------------------------------------
template <typename Real>
CGraspPlanner<Real>::CGraspPlanner (const std::vector< Wm5::ObjBox3<Real> >& vec_obj, std::string& obj_name)
{
	m_vec_obj = vec_obj;
	m_obj_name2grasp = obj_name;
}
//----------------------------------------------------------------------------
template <typename Real>
CGraspPlanner<Real>::CGraspPlanner (const CGraspPlanner<Real>& gsp_plnr)
{
	m_obj_name2grasp = gsp_plnr.m_obj_name2grasp;
	m_vec_obj = gsp_plnr.m_vec_obj;
}
//----------------------------------------------------------------------------
template <typename Real>
CGraspPlanner<Real>& CGraspPlanner<Real>::operator= (const CGraspPlanner<Real>& gsp_plnr)
{
	m_obj_name2grasp = gsp_plnr.m_obj_name2grasp;
	m_vec_obj = gsp_plnr.m_vec_obj;
	return *this;
}
template class CGraspPlanner<float>;

template class CGraspPlanner<double>;
