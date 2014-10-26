#include "mex.h"



void mexFunction(int output_args, mxArray *output_ptr[], int input_args, const mxArray *input_ptr[])
{


    if(input_args == 0){
        mexPrintf(
            "\n"
            "Numerical Solver\n"
            "https://github.com/PatWie/CppNumericalSolvers/\n"
            "\n"
            "Usage\n"
            "-----\n"
            "\n"
            "[x, fx] = pwie_solve(x0, obj_func, solver);\n"
            "\n"
            "\n"
            "Inputs\n"
            "------\n"
            "\n"
            "x0                                       inital guess\n"
            "obj_func                                 function handle to the objective function\n"
            "solver                                   struct containing information about solver\n"
            "\n"
            "solver-struct\n"
            "       name                              \"GradDesc\", \"NewtDesc\", \"BFGS\", \"LBFGS\", \"L-BFGS-B\" \n"
            "       [gra_func]                        function handle to the gradient\n"
            "       use_gra                           bool flag, if use provided gradient (default true)\n"
            "       [hes_func]                        function handle to the hessian\n" 
            "       use_hes                           bool flag, if use provided hessian (only NewtDesc; default: true)\n"
            "       [low_bound]                       lower bound as vector (only in L-BFGS-B; default: -INF)\n"
            "       [upp_bound]                       upper bound as vector (only in L-BFGS-B; default: +INF)\n"
            "       [max_iter]                        maximum of iterations (default: 100000)\n"
            "       [m]                               size of hessian approx. (only in L-BFGS-B, L-BFGS; default: 10)\n"
            "       [rate]                            step size for one iteration (default: 0.00005)\n"
            "       [verbose]                         output while optimization (default: false)\n"
            "\n"
            "       [.] means \"optional/not used by all solvers\"\n"
            "\n"
            "Outputs\n"
            "-------\n"
            "\n"
            "x                                        found minima (or current position when reach max_iter)\n"
            "fx                                       found value in x\n"
            "\n"
            "\n"
            );
        return;

    }
    // validate input/output arguments
    if (input_args < 2) {
        mexErrMsgTxt("You have to provide a inital guess and a solver-struct.");
    }
    if (mxGetClassID(input_ptr[0]) != mxDOUBLE_CLASS || mxGetClassID(input_ptr[0]) != mxSINGLE_CLASS  ) {
        mexErrMsgTxt("The inital guess 'x0' has to be single/double.");
    }
    if (mxGetClassID(input_ptr[1]) != mxFUNCTION_CLASS   ) {
        mexErrMsgTxt("The objecttive function 'obj_func' has to be a function.");
    }
    if (mxGetClassID(input_ptr[2]) != mxSTRUCT_CLASS) {
        mexErrMsgTxt("solver-struct 'solver' has to be a struct.");
    }
    if (output_args != 2) {
        mexErrMsgTxt("There are exactly two output arguments.");
    }

    // read option struct
    if (!mxIsEmpty(input_ptr[1]))
    {
        // read name
        mxArray *tmp_arr = mxGetField(prhs[1] , 0 , "name");
        char_T solver_name[100];
        mxGetString(tmp_arr, solver_name, 100);

    }


}