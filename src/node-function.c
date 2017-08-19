/* node-function.c  
   Julian F. Miller (c) 2009
   version 1.1 of first public release on 20-July-2009
   Dept. of Electronics, University of York, UK

   node_type calculates the output of a node given
   the data provided in the array in
*/

#include "cgp.h"
#include <math.h>


#ifdef DATA_IS_UNSIGNED_INT

data_type  node_type(data_type in[MAX_NUM_GENES_PER_NODE],
                     int function_gene)
{
   /* assumes 32 bit operations */
   data_type result;

   if (function_gene==0)      /* constants */
      result=0;
   else if (function_gene==1)
      result=MAXNUM;
   else if (function_gene==2) /* wire and inverter */
      result=in[0];
   else if (function_gene==3)
      result=in[1];
   else if (function_gene==4)
      result=~in[0];
   else if (function_gene==5)
      result=~in[1];
   else if (function_gene==6) /* two input gate functions */
      result=(in[0] & in[1]);  /* AND(a, b) */
   else if (function_gene==7)
      result=(in[0] & ~in[1]); /* AND (a,NOT(b)) */
   else if (function_gene==8)
      result=(~in[0] & in[1]); /* AND(NOT(a), b) */
   else if (function_gene==9)
      result=(~in[0] & ~in[1]); /* AND(NOT(a), NOT(b)) - i.e. NOR(a, b) */
   else if (function_gene==10)
      result=(in[0]^in[1]);     /* XOR(a, b) */
   else if (function_gene==11)
      result=(~in[0]^in[1]);    /* XNOR(a, b) */
   else if (function_gene==12)
      result=(in[0] | in[1]);   /* OR(a, b) */
   else if (function_gene==13)
      result=(in[0] | ~in[1]);  /* OR(a, NOT(b)) */
   else if (function_gene==14)
      result=(~in[0] | in[1]);  /* OR(NOT(a), b) */
   else if (function_gene==15)
      result=(~in[0] | ~in[1]); /* OR(NOT(a), NOT(b)) - i.e. NAND(a,b) */
   else if (function_gene==16)  /* mux functions - i.e IF statements */
      result=((in[0] & ~in[2]) | (in[1] & in[2]));
   else if (function_gene==17)
      result=((in[0] & ~in[2]) | (~in[1] & in[2]));
   else if (function_gene==18)
      result=((~in[0] & ~in[2]) | (in[1] & in[2]));
   else if (function_gene==19)
      result=((~in[0] & ~in[2]) | (~in[1] & in[2]));

   return result;
}
#endif

#ifdef DATA_IS_INT
/* Currently there are only 4 integers node functions
   implemented but up to 20 allowed in further versions
*/
data_type  node_type(data_type in[MAX_NUM_GENES_PER_NODE],
                     int function_gene)
{
   data_type result;

   switch(function_gene)
   {
		case 0: case 4: case 8: case 12: case 16:  /*   addition  */
			result = in[0] + in[1]; 
			break;
		case 1:	 case 5: case 9: case 13: case 17:  /* subtraction */                      
			result = in[0] - in[1];
			break;
		case 2: case 6: case 10: case 14: case 18:  /* multiplication */
				result = in[0]*in[1];
			break;
		case 3:	 case 7: case 11: case 15: case 19: /* protected division */
			if (in[1] == 0)
				result = in[0];
			else
				result = in[0]/in[1];
			break;
   }

   return result;
}
#endif

#ifdef DATA_IS_DOUBLE

data_type  node_type(data_type in[MAX_NUM_GENES_PER_NODE],
                     int function_gene)
{
   data_type result;

   switch(function_gene)
   {
		case 0:  /*   absolute  */
			result = fabs(in[0]); 
			break;
		case 1:  /*   protected sqrt  */
			result = sqrt(fabs(in[0])); 
			break;
		case 2:	/* protected reciprocal */
			if (fabs(in[0]) < 0.0001)
				result = in[0];
			else
				result = 1.0/in[0];
			break;
		case 3:  /*   sin  */
			result = sin(in[0]); 
			break;
		case 4:  /*   cos  */
			result = cos(in[0]); 
			break;
		case 5:  /*   protected tan  */
			if (cos(in[0]) < 0.0001)
				result = in[0];
			else
				result = tan(in[0]); 
			break;
		case 6:  /*   exp  */
			result = exp(in[0]); 
			break;
		case 7:  /*   sinh  */
			result = sinh(in[0]); 
			break;
		case 8:  /*   cosh  */
			result = cosh(in[0]); 
			break;
		case 9:  /*   tanh  */
			result = tanh(in[0]); 
			break;
		case 10:  /*   protected natural log  */
			if (in[0] < 0.0001)
				result = in[0]; 
			else
				result = log(fabs(in[0]));
			break;
		case 11:  /*   protected  log to base 10  */
			if (in[0] < 0.0001)
				result = in[0]; 
			else
				result = log10(fabs(in[0]));
			break;
		case 12:  /*   sin (a+b) */
			result = sin(in[0]+in[1]); 
			break;
		case 13:  /*   cos(a+b)  */
			result = cos(in[0]+in[1]); 
			break;
		case 14:  /*   hypoteneuse  */
			result = sqrt(in[0]*in[0]+in[1]*in[1]); 
			break;
		case 15:	/* power */
				result = pow(fabs(in[0]),in[1]);
			break;
		case 16:  /*   addition  */
			result = in[0] + in[1]; 
			break;
		case 17:	 /* subtraction */                      
			result = in[0] - in[1];
			break;
		case 18: /* multiplication */
				result = in[0]*in[1];
			break;
		case 19:	/* protected division */
			if (fabs(in[1]) < 0.0001)
				result = in[0];
			else
				result = in[0]/in[1];
			break;
   }

   return result;
}

#endif