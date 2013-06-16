#include <iostream>
#include <fstream>
#include <vector>
#include "ObjInfo.h"
#include "Wm5IntrBox3Box3.h"
#include "GraspPlanner.h"


using namespace std;
using namespace Wm5;
const unsigned int MAX_NUM_OBJ = 20;

bool GetObjInfoFromFile(vector<ObjInfod> & Obj , string &filePath)
{
  ifstream infile;
  infile.open (filePath.c_str ()); 
  ObjInfod temp;
  
  if (!infile.fail())
  {
	  string words;		// 通过输入输出流读取的信息
	  double digit;

	  string objname;	 //物体的名字
	  // unused local variables modified by slb 2013.6.3
      /*double Obj_CornerPoints[24];
	  double Obj_center[3];        
      double Obj_Gsp_direction[3]; 
	  double Obj_Gsp_width;*/

	  while(true)
	  {
		  if (!getline(infile,words))
		  {
			  break;
		  }
		  if ("name" == words)
		  {
			  if (getline(infile,words))
			  {
				  temp.ObjName = words;
			  }
		  }
		  if ("corner_points" == words)
		  {
			  for (int i = 0 ; i < 24 ; ++i)
			  {
				  infile >> digit;
				  temp.CornerPoints[i] =digit;
			  }
		  }
		  if ("Gsp_Direction" == words)
		  {
			  for (int i = 0 ; i < 3 ; ++i)
			  {
				  infile >> digit;
				  temp.Gsp_direction[i] =digit;
			  }
		  }
		  if ("Gsp_Width" == words)
		  {			
				  infile >> digit;
				  temp.Gsp_width =digit;
		  }
		  if ("Obj_Center" == words)
		  {
			  for (int i = 0 ; i < 3 ; ++i)
			  {
				  infile >> digit;
				  temp.center[i] =digit;
			  }
		  }
	 	if ("-----" == words)
	 	{
			  Obj.push_back (temp);
	 	}
	  }
	  infile.close();

	 return true;
  }
  else
  {
	  cout<<"can not open the file , invalid directory"<<endl;
	  return false;
  }
}

int main()
{
	string filePath = "../../Data/ObjectInfo.txt";
	vector<ObjInfod> vec_obj_info;
	vec_obj_info.reserve(MAX_NUM_OBJ);
	if (GetObjInfoFromFile(vec_obj_info, filePath))
	{
		cout << "successfully load the object information " << endl;
		cout << "number of objects is " << vec_obj_info.size() << endl;
	}
	// transform sxk box to slb box
	vector<ObjBox3d> vec_objbox3;
	vec_objbox3.reserve(MAX_NUM_OBJ);
	for (vector<ObjInfod>::iterator iter = vec_obj_info.begin(); iter != vec_obj_info.end(); ++iter)
	{
		ObjInfod temp_objinfo = *iter;
		ObjBox3d temp_objbox3(temp_objinfo);
		vec_objbox3.push_back(temp_objbox3);
		Vector3d vertex[8];
		temp_objbox3.m_box3.ComputeVertices(vertex);
		cout << "object name: " << temp_objbox3.m_obj_name << endl;
		//cout << "corner points" << endl;
		for (int i =0; i < 8; ++i )
		{
			//cout << vertex[i] <<endl;
		}
		//cout << "grasp dir : \n" << temp_objbox3.m_gsp_dir << endl;
		//cout << "grasp width :" << temp_objbox3.m_gsp_width << endl;
		//cout << "center :" << temp_objbox3.m_box3.Center << endl;
		cout << "------------------\n";

	}
	for (vector<ObjBox3d>::iterator iter = vec_objbox3.begin(); iter != vec_objbox3.end(); ++iter)
	{
		for (vector<ObjBox3d>::iterator j = iter + 1; j !=vec_objbox3.end(); ++j)
		{
			IntrBox3Box3d inter_boxes(*iter, *j);
			if (inter_boxes.Test())
			{
				cout<< "intersection occurs between " << iter - vec_objbox3.begin() << " and " << j - vec_objbox3.begin() << endl;
			}
		}
	}
	string obj_name("");
	CGraspPlannerd grasp_planner(vec_objbox3, obj_name);
	return 0;
}