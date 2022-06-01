#include "task1.h"

int main() {
	ifstream netlist;
	netlist.open("netlist.txt");
	int num_gates=0;        
	num_gates = count_components(netlist);
	gate gate_arr[num_gates];
	fill_component_arr_general(netlist, gate_arr, num_gates);
	netlist.close();

	//Printing the gates names, types, and aspect ratios
	cout << "//====================================================//" <<"\n\t\tAt Beginning\n"<<"//====================================================//\n";
	for (auto& g : gate_arr)
	{
		//print_aspect_ratio(g);
	}	
	
	//====================================================//
	//       	First iteration				//
	//====================================================//
	vector<gate>Big_lvl_1;
	bool good_fit=1;
	bool vertical=0;
	for (auto& A : gate_arr)
	{
		if (A.merged){continue;}	//Skip merged blocks
		for (auto& B : gate_arr)
		{
			if (B.merged||A.merged||A.name==B.name){continue;}	//Skip merged blocks
			//See if A and B a good fit to be merged -- if not, change good_fit to 0
			/*ADD CODE to change good_fit*/
			if (!good_fit){continue;}
			//See if will apply vertical or horizontal or vertical composition 
			vertical = !vertical;
			/*ADD CODE to change vertical properly*/
			Big_lvl_1.push_back(shape_gen(A,B,vertical));	
		}	
	}
	//Is there unmerged blocks?
	for (auto& g : gate_arr)
	{
		if (!g.merged)
		{
			Big_lvl_1.push_back(g);
		}
		
	}
	//Printing the gates names, types, and aspect ratios
	cout << "//====================================================//" <<"\n\t\tAfter 1 Iteration\n"<<"//====================================================//\n";
	for (auto& g : Big_lvl_1)
	{
		//print_aspect_ratio(g);	
	}
	//==================================================================================
	
	//====================================================//
	//       	Second iteration			//
	//====================================================//
	vector<gate>Big_lvl_2;
	good_fit=1;
	vertical=0;
	reverse(Big_lvl_1.begin(), Big_lvl_1.end());	//Reverse the vector because the last gate that wasn't merged last iteration should be served first
	for (auto& A : Big_lvl_1)
	{
		//Start merging
		if (A.merged){continue;}	//Skip merged blocks
		for (auto& B : Big_lvl_1)
		{
			if (B.merged||A.merged||A.name==B.name){continue;}	//Skip merged blocks
			//See if A and B a good fit to be merged -- if not, change good_fit to 0
			/*ADD CODE to change good_fit*/
			if (!good_fit){continue;}
			//See if will apply vertical or horizontal or vertical composition 
			vertical = !vertical;
			/*ADD CODE to change vertical properly*/
			Big_lvl_2.push_back(shape_gen(A,B,vertical));	
		}
	}
	//Is there unmerged blocks?
	for (auto& g : Big_lvl_1)
	{
		if (!g.merged)
		{
			Big_lvl_2.push_back(g);
		}
		
	}
	cout << "//====================================================//" <<"\n\t\tAfter 2 Iterations\n"<<"//====================================================//\n";
	for (auto& g : Big_lvl_2)
	{
		//print_aspect_ratio(g);
	} 
	//==================================================================================
	cout<<endl;

	//====================================================//
	//       	Third iteration			      //
	//====================================================//
	vector<gate>Big_lvl_3;
	good_fit=1;
	vertical=0;
	reverse(Big_lvl_2.begin(), Big_lvl_2.end());	//Reverse the vector because the last gate that wasn't merged last iteration should be served first
	for (auto& A : Big_lvl_2)
	{
		//Start merging
		if (A.merged){continue;}	//Skip merged blocks
		for (auto& B : Big_lvl_2)
		{
			if (B.merged||A.merged||A.name==B.name){continue;}	//Skip merged blocks
			//See if A and B a good fit to be merged -- if not, change good_fit to 0
			/*ADD CODE to change good_fit*/
			if (!good_fit){continue;}
			//See if will apply vertical or horizontal or vertical composition 
			vertical = !vertical;
			/*ADD CODE to change vertical properly*/
			Big_lvl_3.push_back(shape_gen(A,B,vertical));	
		}
	}
	//Is there unmerged blocks?
	for (auto& g : Big_lvl_2)
	{
		if (!g.merged)
		{
			Big_lvl_3.push_back(g);
		}
		
	}
	cout << "//====================================================//" <<"\n\t\tAfter 3 Iterations\n"<<"//====================================================//\n";
	for (auto& g : Big_lvl_3)
	{
		//print_aspect_ratio(g);
	} 
	//==================================================================================
	cout<<endl;

	//====================================================//
	//       	Fourth iteration		      //
	//====================================================//
	vector<gate>Big_lvl_4;
	good_fit=1;
	vertical=0;
	reverse(Big_lvl_3.begin(), Big_lvl_3.end());	//Reverse the vector because the last gate that wasn't merged last iteration should be served first
	for (auto& A : Big_lvl_3)
	{
		//Start merging
		if (A.merged){continue;}	//Skip merged blocks
		for (auto& B : Big_lvl_3)
		{
			if (B.merged||A.merged||A.name==B.name){continue;}	//Skip merged blocks
			//See if A and B a good fit to be merged -- if not, change good_fit to 0
			/*ADD CODE to change good_fit*/
			if (!good_fit){continue;}
			//See if will apply vertical or horizontal or vertical composition 
			vertical = !vertical;
			/*ADD CODE to change vertical properly*/
			Big_lvl_4.push_back(shape_gen(A,B,vertical));	
		}
	}
	//Is there unmerged blocks?
	for (auto& g : Big_lvl_3)
	{
		if (!g.merged)
		{
			Big_lvl_4.push_back(g);
		}
		
	}
	cout << "//====================================================//" <<"\n\t\tAfter 4 Iterations\n"<<"//====================================================//\n";
	for (auto& g : Big_lvl_4)
	{
		//print_aspect_ratio(g);
	} 
	//==================================================================================
	cout<<endl;

	//====================================================//
	//       	Fifth iteration			      //
	//====================================================//
	vector<gate>Big_lvl_5;
	good_fit=1;
	vertical=0;
	reverse(Big_lvl_4.begin(), Big_lvl_4.end());	//Reverse the vector because the last gate that wasn't merged last iteration should be served first
	for (auto& A : Big_lvl_4)
	{
		//Start merging
		if (A.merged){continue;}	//Skip merged blocks
		for (auto& B : Big_lvl_4)
		{
			if (B.merged||A.merged||A.name==B.name){continue;}	//Skip merged blocks
			//See if A and B a good fit to be merged -- if not, change good_fit to 0
			/*ADD CODE to change good_fit*/
			if (!good_fit){continue;}
			//See if will apply vertical or horizontal or vertical composition 
			vertical = !vertical;
			/*ADD CODE to change vertical properly*/
			Big_lvl_5.push_back(shape_gen(A,B,vertical));	
		}
	}
	//Is there unmerged blocks?
	for (auto& g : Big_lvl_4)
	{
		if (!g.merged)
		{
			Big_lvl_5.push_back(g);
		}
		
	}
	cout << "//====================================================//" <<"\n\t\tAfter 5 Iterations\n"<<"//====================================================//\n";
	cout<<"\nThe Top Floorplan Slicing Tree is: "<<Big_lvl_5[0].name<<endl;
	//==================================================================================
	cout<<endl;
	
	//====================================================//
	//       	Printing Outputs		      //
	//====================================================//
	
	//Finding the minimum area 	
	int 	Min_Area 	= Big_lvl_5[0].asp_vec[0].x_dim	* Big_lvl_5[0].asp_vec[0].y_dim;
	aspect 	min_asp 	= Big_lvl_5[0].asp_vec[0];
	int 	k		= 0;
	int 	min_area_pos	= 0;	//Holds the index of the minimum area aspect ratio
	for (auto& asp : Big_lvl_5[0].asp_vec){	
		if(asp.x_dim*asp.y_dim<Min_Area){
			Min_Area = asp.x_dim*asp.y_dim;
			min_asp  = asp;
			min_area_pos = k;	
		}
		k++;
	}
	int core_area=0;
	for (auto& g : gate_arr){	
		core_area=core_area + g.asp_vec[0].x_dim * g.asp_vec[0].y_dim;
	}
	//int Min_Area = *min_element(std::begin(TOP_area_vec), std::end(TOP_area_vec));
	cout<<"The minimum area: "<<Min_Area<<"\t--\t Aspect Ratio: "<<min_asp.x_dim<<" by "<<min_asp.y_dim<<endl;
	cout<<"The core area: "<<core_area<< "\t--\tThe core utilization: "<<(double)core_area/Min_Area<<endl;
	return 0;
}