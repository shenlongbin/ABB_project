// Shen Longbin
// File Version: 0.0.1 (2013/06/06)

#ifndef GRASPPLANNER_H
#define GRASPPLANNER_H

#include "ObjBox3.h"
#include <string>
#include <vector>

template <typename Real>
class CGraspPlanner
{
public:
	// constructor and destructor
	CGraspPlanner(); // uninitialized
	~CGraspPlanner();
	CGraspPlanner (const std::vector< Wm5::ObjBox3<Real> >& vec_obj, std::string& obj_name);
	CGraspPlanner (const CGraspPlanner<Real>& gsp_plnr);
	CGraspPlanner& operator= (const CGraspPlanner<Real>& gsp_plnr);

	std::vector< Wm5::ObjBox3<Real> > m_vec_obj;
	std::string m_obj_name2grasp;
};

//#include "GraspPlanner.cpp"

typedef CGraspPlanner<float> CGraspPlannerf;
typedef CGraspPlanner<double> CGraspPlannerd;
#endif