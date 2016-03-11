//============================================================================
// Name        : robust.cpp
// Author      : Zacharie ALES
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<ilcplex/ilocplex.h>
ILOSTLBEGIN
using namespace std;
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	IloEnv env;
	try {
	    IloNumArray myCoeffs = IloNumArray(env, 2.0, 1.0, 1.0);
	    IloNumVarArray myVars(env, 2, 0.0, 1.0);
	    IloModel model(env);
	    model.add(IloMaximize(env, IloScalProd(myCoeffs, myVars)));
	    model.add(myVars[0] <= 0.75);
	    model.add(myVars[1] <= 0.5);

	    IloCplex cplex(model);
	    cplex.solve();
	    if (cplex.getStatus() == IloAlgorithm::Infeasible)
	        std::cout << "No Solution" << endl;
	    else
	        std::cout << cplex.getObjValue() << endl;
	} catch (const IloException& e){
	    cerr << e;
	    throw;
	}

	env.end();



	return 0;
}
